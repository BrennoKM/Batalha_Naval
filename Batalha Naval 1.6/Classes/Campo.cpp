#include <iostream>
#include <cstring>

using namespace std;

// constantes gerais
const int base = 64;
const int usuarioburro = 48;
///////////////////////////

// enums
enum Navio {nenhum = 0, 
			bote, 
			rebocador_horizontal, rebocador_vertical, 		
			cruzador_horizontal, cruzador_vertical,
			portaviao_horizontal, portaviao_vertical};
			
enum Status {agua = 1, erro = 2, acerto = 3};
///////////////////////////

// funcoes
void limparBuffer(){
	fflush(stdin);
}
///////////////////////////

// estrutura
struct indice{
	Navio navio;
	Status status;
	char borda;
};
///////////////////////////

// Classe campo
class Campo{
	private:
		
		string nomeJogador;
		indice** campo = NULL;
		int TAM;
		 
		int qntBotes;
		int qntRebocadores;
		int qntCruzadores;
		int qntPortavioes; 
		int qntEmbarcacoes;
		int pontuacao; 
		
		 
		 
		// constantes internas 
		const int bote_qnt_linhas = 1;
		const int bote_qnt_colunas = 1;
		const int bote_pontuacao = 20;
		const int bote_casas = 1;
		
		const int rebocador_horizontal_qnt_linhas = 1;
		const int rebocador_horizontal_qnt_colunas = 1;
		const int rebocador_vertical_qnt_linhas = 2;
		const int rebocador_vertical_qnt_colunas = 1;
		const int rebocador_pontuacao = 10;
		const int rebocador_casas = 2;
		
		const int cruzador_horizontal_qnt_linhas = 1;
		const int cruzador_horizontal_qnt_colunas = 3;
		const int cruzador_vertical_qnt_linhas = 3;
		const int cruzador_vertical_qnt_colunas = 1;
		const int cruzador_pontuacao = 9;
		const int cruzador_casas = 3;
		
		const int portaviao_horizontal_qnt_linhas = 2;
		const int portaviao_horizontal_qnt_colunas = 4;
		const int portaviao_vertical_qnt_linhas = 4;
		const int portaviao_vertical_qnt_colunas = 2;
		const int portaviao_pontuacao = 16;
		const int portaviao_casas = 8;
		
	public:
		
		Campo(int tam, string jogador);
		~Campo();
		
		void getNomeJogador();
		
		void setBordas(int tam);
		void resetCampo();
		bool verificarVitoria();
		void somarPontos(Navio navio);
		int getPontuacao();
		void getCampo();
		void getCampoRevelado();
		
		void setBorda(int linha, int coluna, char borda);
		void getBorda(int linha, int coluna);
		
		
		void setStatus(int linha, int coluna, Status status); 
		Status getStatusValor(int linha, int coluna);
		void getStatus(int linha, int coluna);
		
		bool testarTiro(int linha, int coluna);
		void setTiro();
		
		int escolherLinha();
		int escolherColuna();
		
		void setNavio(int linha, int coluna, Navio navio);
		Navio getNavioValor(int linha, int coluna);
		void getNavio(int linha, int coluna);
			
		bool verificarPosicao(Navio navio, int linha, int coluna, int linhaFim, int colunaFim);
		
		void setBote();
		
		void setRebocador_horizontal();
		void setRebocador_vertical();
		
		void setCruzador_horizontal();
		void setCruzador_vertical();
		
		void setPortaviao_horizontal();
		void setPortaviao_vertical();
		
};

	//construtor
	Campo::Campo(int tam, string jogador){
		
		int i;
		TAM = tam;
		
		nomeJogador = jogador;
		
		campo = new indice*[tam+1];	// Aloca linhas

		for(i=0; i < tam+1; i++) {
			campo[i] = new indice[tam+1];	// Aloca colunas
		}
		
		system("clear||cls");
		
		setBordas(tam);
		resetCampo();
	}
	
	//destrutor
	Campo::~Campo(){
		
		// Desalocar da memoria
		for(int i=0; i < TAM; i++) {
			delete[] campo[i];
		}
	
   		delete[] campo;
		
	}
	
	// Metodos
	
	void Campo::getNomeJogador(){
		cout << nomeJogador;
	}
	
	void Campo::setBordas(int tam){
		char c;
		campo[0][0].borda = '@';
		for(int linha = 1; linha < TAM; linha++){
			setBorda(linha, 0, linha);
		}
		for(int coluna = 1; coluna <= TAM; coluna++){
			c = char(base+coluna);	
			setBorda(0, coluna, c);
			
		}
	}
	
	void Campo::resetCampo (){
		qntBotes = 0;
		qntRebocadores = 0;
		qntCruzadores = 0;
		qntPortavioes = 0; 
		qntEmbarcacoes = 0;
		pontuacao = 0;
		for(int linha = 1; linha <= TAM; linha++){
			for(int coluna = 1; coluna <= TAM; coluna++){
				campo[linha][coluna].status = agua;
				campo[linha][coluna].navio = nenhum;
			}
		}
	}
	
	
	bool Campo::verificarVitoria(){
		int cont = 0;
		qntEmbarcacoes = (qntBotes*bote_casas) + (qntRebocadores*rebocador_casas) + (qntCruzadores*cruzador_casas) + (qntPortavioes*portaviao_casas);
		for(int linha = 1; linha <= TAM; linha++){
			for(int coluna = 1; coluna <= TAM; coluna++){
				if((campo[linha][coluna].status == acerto) && (campo[linha][coluna].navio != nenhum)){
					cont++;	
				}
			}
		}
		if(cont == qntEmbarcacoes){
			return true;
		} else {
			return false;
		}
	}
	
	void Campo::somarPontos(Navio navio){
		switch(navio){
				case 1: // bote (1x1)
					pontuacao = pontuacao + (bote_pontuacao/bote_casas);
				case 2:	// rebocador_horizontal (1x2)
					pontuacao = pontuacao + (rebocador_pontuacao/rebocador_casas);
					break;
				case 3:	// rebocador_vertical (2x1)
					pontuacao = pontuacao + (rebocador_pontuacao/rebocador_casas);
					break;
				case 4:	// cruzador_horizontal (1x3)
					pontuacao = pontuacao + (cruzador_pontuacao/cruzador_casas);
					break;
				case 5:	// cruzador_vertical (3x1)
					pontuacao = pontuacao + (cruzador_pontuacao/cruzador_casas);
					break;
				case 6:	// portaviao_horizontal (2x4)
					pontuacao = pontuacao + (portaviao_pontuacao/portaviao_casas);
					break;
				case 7:	// portaviao_vertical (4x2)
					pontuacao = pontuacao + (portaviao_pontuacao/portaviao_casas);
					break;
				default:
					break;	
					
			}
	}
	
	int Campo::getPontuacao(){
		return pontuacao;
	}
	
	void Campo::getCampo(){
		cout << "\t\t\t\t\t\t";
		getBorda(0, 0);  
		cout << "\t";
			for(int coluna = 1; coluna <= TAM; coluna++){
				getBorda(0, coluna);
				cout << " ";
			}
		cout << endl;
			for(int linha = 1; linha <= TAM; linha++){
			cout << "\t\t\t\t\t\t" << linha << "\t";
					for(int coluna = 1; coluna <= TAM; coluna++){
						getStatus(linha, coluna);
					}
			cout << endl;
			}
	}
	
	void Campo::setBorda(int linha, int coluna, char borda){
		campo[linha][coluna].borda = borda;
	}
		
	void Campo::getBorda(int linha, int coluna){
		cout << campo[linha][coluna].borda;
	}
	
	void Campo::getCampoRevelado(){
		cout << "\t\t\t\t\t\t";
		getBorda(0, 0);  
		cout << "\t";
			for(int coluna = 1; coluna <= TAM; coluna++){
				getBorda(0, coluna);
				cout << " ";
			}
		cout << endl;
			for(int linha = 1; linha <= TAM; linha++){
			cout << "\t\t\t\t\t\t" << linha << "\t";
					for(int coluna = 1; coluna <= TAM; coluna++){
						switch(getNavioValor(linha, coluna)){
							case 0:
								switch(getStatusValor(linha, coluna)){
									case 1:
										cout << "~ ";
										break;
									case 2:
										cout << "X ";
										break;
									case 3:
										cout << "# ";
										break;
									default:
										cout << "^ ";
										break;
								}
								break;
							case 1:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "B ";
								}
								break;
							case 2:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "R ";
								}
								break;
							case 3:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "R ";
								}
								break;
							case 4:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "C ";
								}
								break;
							case 5:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "C ";
								}
								break;
							case 6:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "P ";
								}
								break;
							case 7:
								if(getStatusValor(linha, coluna) == 3 ){
									cout << "# ";	
								} else {
									cout << "P ";
								}
								break;
							default:
								cout << "";
								break;			
						}
					}
			cout << endl;
			}	
	}
	
	void Campo::setStatus(int linha, int coluna, Status status){
		campo[linha][coluna].status = status;
	}
	
	Status Campo::getStatusValor(int linha, int coluna){
		return campo[linha][coluna].status;
	}
	
	void Campo::getStatus(int linha, int coluna){
		switch(getStatusValor(linha, coluna)){
			case 1:	// agua
				cout << "~ ";
				break;
			case 2:	// errou o tiro
				cout << "X ";
				break;
			case 3:	// acertou o tiro
				cout << "# ";
				break;
			default:
				cout << "^ ";
				break;
		}
	}
	
	bool Campo::testarTiro(int linha, int coluna){
		if((linha<1) || (linha>TAM) || (coluna<1) || (coluna>TAM)){
			cout << "Lugar invalido, digite novamente.\n";
			return false;
		} else {
			if(campo[linha][coluna].status!=agua){
				cout << "Lugar invalido, digite novamente.\n";
				return false;
			} else {
				return true;
			}
		}
	}
	
	void Campo::setTiro(){
		int linha = 0, coluna = 0;
		bool teste;
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();		
		teste = testarTiro(linha, coluna);	
			if(teste == true){
				if (getNavioValor(linha, coluna) == nenhum){
					setStatus(linha, coluna, erro);
					cout << "\n\nErrouuuu!!!\n\n";
					system("pause");
					pontuacao--;
				} else {
					setStatus(linha, coluna, acerto);
					cout << "\n\nVoce acertou um ";
					getNavio(linha, coluna);
					cout << "!!!\n\n";
					system("pause");
					somarPontos(getNavioValor(linha, coluna));	
				}
			}
		}while (teste!=true);
	}
	
	int Campo::escolherLinha(){
		int linha;
		char l;
		bool teste;
		do{
			cout << "Digite a linha (1-" << TAM << "): ";
			cin >> l;
			linha = int(l-usuarioburro);
			if((linha >= 1) && (linha <= TAM)){
				teste = true;
			} else {
				cout << "Linha invalida!\n";
				teste = false;
			}
		}while(teste!=true);
		return linha;
	}
	
	int Campo::escolherColuna(){
		int coluna;
		char c;
		bool teste;
		do{
			cout << "Digite a Coluna (A-" << char(base+TAM) << "): ";
			limparBuffer();
			cin >> c;
			c = toupper(c);
			coluna = int(c)-base;
			if((coluna >= 1) && (coluna <= TAM)){
				teste = true;
			} else {
				cout << "Coluna invalida!\n";
				teste = false;
			}
		}while(teste!=true);
		
		return coluna;
	}
	
	void Campo::setNavio(int linha, int coluna, Navio navio){
		campo[linha][coluna].navio = navio;
	} 
	
	Navio Campo::getNavioValor(int linha, int coluna){	
		return campo[linha][coluna].navio;
	}

	void Campo::getNavio(int linha, int coluna){
			switch(campo[linha][coluna].navio){
			case 0:
				cout << "Nenhum";
				break;
			case 1:
				cout << "Bote";
				break;
			case 2:
				cout << "Rebocador";
				break;
			case 3:
				cout << "Rebocador";
				break;
			case 4:
				cout << "Cruzador";
				break;
			case 5:
				cout << "Cruzador";
				break;
			case 6:
				cout << "Porta avioes";
				break;
			case 7:
				cout << "Porta avioes";
				break;
			default:
				cout << "\n\nBug metodo getNavio\n\n";
				break;
		}	
	}
	
	bool Campo::verificarPosicao(Navio navio, int linha, int coluna, int linhaFim, int colunaFim){
		if((linha<1) || (linha>TAM) || (coluna<1) || (coluna>TAM) || (linhaFim<1) || (linhaFim>TAM) || (colunaFim<1) || (colunaFim>TAM)){
			cout << "Lugar invalido, digite novamente.\n";
			return false;
		} else {
			switch(navio){
				case 1: // bote (1x1)
					if(getNavioValor(linha, coluna) != nenhum){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				case 2:	// rebocador_horizontal (1x2)
					if((getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha, coluna+1) != nenhum)){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				case 3:	// rebocador_vertical (2x1)
					if((getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha+1, coluna) != nenhum)){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				case 4:	// cruzador_horizontal (1x3)
					if((getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha+1, coluna) != nenhum) || (getNavioValor(linha+2, coluna) != nenhum)){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				case 5:	// cruzador_vertical (3x1)
					if((getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha, coluna+1) != nenhum) || (getNavioValor(linha, coluna+2) != nenhum)){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				case 6:	// portaviao_horizontal (2x4)
					if(		(getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha, coluna+1) != nenhum)
						||  (getNavioValor(linha, coluna+2) != nenhum) || (getNavioValor(linha, coluna+3) != nenhum)
						||  (getNavioValor(linha+1, coluna) != nenhum) || (getNavioValor(linha+1, coluna+1) != nenhum)
						||  (getNavioValor(linha+1, coluna+2) != nenhum) || (getNavioValor(linha+1, coluna+3) != nenhum)){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				case 7:	// portaviao_vertical (4x2)
					if(		(getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha+1, coluna) != nenhum)
						||  (getNavioValor(linha+2, coluna) != nenhum) || (getNavioValor(linha+3, coluna) != nenhum)
						||  (getNavioValor(linha, coluna) != nenhum) || (getNavioValor(linha+1, coluna+1) != nenhum)
						||  (getNavioValor(linha+2, coluna+1) != nenhum) || (getNavioValor(linha+3, coluna+1) != nenhum)){
						cout << "Lugar invalido, digite novamente.\n";
						return false;
					} else {
						return true;
					}
					break;
				default:
					break;	
					
			}
		}
	}
	
	void Campo::setBote(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha;
		colunaFim = coluna;
		
		teste = verificarPosicao(bote, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = bote;
						qntBotes++;
			}
		}while (teste!=true);	
	}

	void Campo::setRebocador_horizontal(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha;
		colunaFim = coluna+1;
		
		teste = verificarPosicao(rebocador_horizontal, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = rebocador_horizontal;
						campo[linha][coluna+1].navio = rebocador_horizontal;
						qntRebocadores++;
			}
		}while (teste!=true);	
	}
	
	void Campo::setRebocador_vertical(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha+1;
		colunaFim = coluna;
		
		teste = verificarPosicao(rebocador_vertical, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = rebocador_vertical;
						campo[linha+1][coluna].navio = rebocador_vertical;
						qntRebocadores++;
			}
		}while (teste!=true);
	}
	
	void Campo::setCruzador_horizontal(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha;
		colunaFim = coluna+2;
		
		teste = verificarPosicao(cruzador_horizontal, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = cruzador_horizontal;
						campo[linha][coluna+1].navio = cruzador_horizontal;
						campo[linha][coluna+2].navio = cruzador_horizontal;
						qntCruzadores++;
			}
		}while (teste!=true);
	}	
	
	void Campo::setCruzador_vertical(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha+2;
		colunaFim = coluna;
		
		teste = verificarPosicao(cruzador_vertical, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = cruzador_vertical;
						campo[linha+1][coluna].navio = cruzador_vertical;
						campo[linha+2][coluna].navio = cruzador_vertical;
						qntCruzadores++;
			}
		}while (teste!=true);
	}
	
	void Campo::setPortaviao_horizontal(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha+1;
		colunaFim = coluna+3;
		
		teste = verificarPosicao(portaviao_horizontal, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = portaviao_horizontal;
						campo[linha][coluna+1].navio = portaviao_horizontal;
						campo[linha][coluna+2].navio = portaviao_horizontal;
						campo[linha][coluna+3].navio = portaviao_horizontal;
						campo[linha+1][coluna].navio = portaviao_horizontal;
						campo[linha+1][coluna+1].navio = portaviao_horizontal;
						campo[linha+1][coluna+2].navio = portaviao_horizontal;
						campo[linha+1][coluna+3].navio = portaviao_horizontal;
						qntPortavioes++;
			}
		}while (teste!=true);
	}
	
	void Campo::setPortaviao_vertical(){
		int linha = 0, coluna = 0, linhaFim = 0, colunaFim = 0;
		bool teste;
		
		do{
		linha = escolherLinha();
		coluna =  escolherColuna();
		linhaFim = linha+3;
		colunaFim = coluna+1;
		
		teste = verificarPosicao(portaviao_vertical, linha, coluna, linhaFim, colunaFim);	
			if(teste == true){
						campo[linha][coluna].navio = portaviao_vertical;
						campo[linha+1][coluna].navio = portaviao_vertical;
						campo[linha+2][coluna].navio = portaviao_vertical;
						campo[linha+3][coluna].navio = portaviao_vertical;
						campo[linha][coluna+1].navio = portaviao_vertical;
						campo[linha+1][coluna+1].navio = portaviao_vertical;
						campo[linha+2][coluna+1].navio = portaviao_vertical;
						campo[linha+3][coluna+1].navio = portaviao_vertical;
						qntPortavioes++;
			}
		}while (teste!=true);
	}
	
// fim dos metodos
