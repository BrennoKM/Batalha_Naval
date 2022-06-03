#include <iostream>
#include <cstring>
#include "Campo.cpp"

using namespace std;

// funcoes
void limparTela(){
	system("clear||cls");
}
	


// Classe campo
class Controlador{
	private:

		
	public:
		Controlador();
		~Controlador();
		void iniciar();
		void iniciar(int dificuldade);
		void getRanking();
};

	//construtor	
	Controlador::Controlador(){
		
	}
	
	//destrutor
	Controlador::~Controlador(){
		
	}
	
	// Metodos	
	
	void Controlador::iniciar(int dificuldade){
		string nomeJogador1, nomeJogador2;
		bool teste;
		int opcao, opcao2, controle;
		int rodadas = dificuldade*3;
		
		int embarcacoesJ1 = dificuldade*2;
		int pontosJ1;
		
		int embarcacoesJ2 = dificuldade*2;
		int pontosJ2;
		
		cout << "Digite o nome do primeiro jogador: ";
			cin >> nomeJogador1;
		cout << "Digite o nome do segundo jogador: ";
			cin >> nomeJogador2;
		
		Campo jogador1(dificuldade, nomeJogador1);
		Campo jogador2(dificuldade, nomeJogador2);
		
		// montar campo
		limparTela();
		cout << nomeJogador1 << " monte seu campo.\n";
		system("pause");
		do{
			limparTela();
			cout << "Posicoes restantes: " << embarcacoesJ1 << endl;
			cout << "\n1. Bote (1 posicao).\n";
			cout << "2. Rebocador (2 posicoes)\n";
			cout << "3. Cruzador (3 posicoes)\n";
			cout << "4. Porta Avioes (8 posicoes)\n";
			cout << "5. Mostrar o campo.\n\n";
			cout << "Escolha uma embarcacao: ";
				cin >> opcao;
			if((opcao < 1) || (opcao > 4)){
				if(opcao==5){
					jogador1.getCampoRevelado();
					system("pause");		
				} else {
					cout << "Opcao invalida!";
				} 
			} else {
				jogador1.getCampoRevelado();
				switch(opcao){
					case 1:
						if(embarcacoesJ1 - opcao < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							jogador1.setBote();
							embarcacoesJ1 = embarcacoesJ1 - opcao;
						}
						break;
					case 2:
						if(embarcacoesJ1 - opcao < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							controle = 0;
							do{
								cout << "1. Vertical.\n";
								cout << "2. Horizontal.\n";
								cout << "Escolha a direcao: ";
									cin >> opcao2;
								if((opcao2 < 1) || (opcao2 > 2)){
									cout << "Direcao invalida!\n";
								} else if (opcao2 == 1){
									jogador1.setRebocador_vertical();
									embarcacoesJ1 = embarcacoesJ1 - opcao;
									controle = 1;
								} else if (opcao2 == 2){
									jogador1.setRebocador_horizontal();
									embarcacoesJ1 = embarcacoesJ1 - opcao;
									controle = 1;
								}
							}while(controle == 0);
						}
						break;
					case 3:
						if(embarcacoesJ1 - opcao < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							controle = 0;
							do{
								cout << "1. Vertical.\n";
								cout << "2. Horizontal.\n";
								cout << "Escolha a direcao: ";
									cin >> opcao2;
								if((opcao2 < 1) || (opcao2 > 2)){
									cout << "Direcao invalida!\n";
								} else if (opcao2 == 1){
									jogador1.setCruzador_vertical();
									embarcacoesJ1 = embarcacoesJ1 - opcao;
									controle = 1;
								} else if (opcao2 == 2){
									jogador1.setCruzador_horizontal();
									embarcacoesJ1 = embarcacoesJ1 - opcao;
									controle = 1;
								}
							}while(controle == 0);
						}
						break;
					case 4:
						if(embarcacoesJ1 - opcao*2 < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							controle = 0;
							do{
								cout << "1. Vertical.\n";
								cout << "2. Horizontal.\n";
								cout << "Escolha a direcao: ";
									cin >> opcao2;
								if((opcao2 < 1) || (opcao2 > 2)){
									cout << "Direcao invalida!\n";
								} else if (opcao2 == 1){
									jogador1.setPortaviao_vertical();
									embarcacoesJ1 = embarcacoesJ1 - opcao*2;
									controle = 1;
								} else if (opcao2 == 2){
									jogador1.setPortaviao_horizontal();
									embarcacoesJ1 = embarcacoesJ1 - opcao*2;
									controle = 1;
								}
							}while(controle == 0);
						}
						break;
				}
				system("pause");
			}
		}while(embarcacoesJ1 > 0);

		limparTela();
		cout << nomeJogador2 << " monte seu campo.\n";
		system("pause");
		do{
			limparTela();
			cout << "Posicoes restantes: " << embarcacoesJ2 << endl;
			cout << "\n1. Bote (1 posicao).\n";
			cout << "2. Rebocador (2 posicoes)\n";
			cout << "3. Cruzador (3 posicoes)\n";
			cout << "4. Porta Avioes (8 posicoes)\n";
			cout << "5. Mostrar o campo.\n\n";
			cout << "Escolha uma embarcacao: ";
				cin >> opcao;
			if((opcao < 1) || (opcao > 4)){
				if(opcao==5){
					jogador1.getCampoRevelado();
					system("pause");		
				} else {
					cout << "Opcao invalida!";
				} 
			} else {
				jogador2.getCampoRevelado();
				switch(opcao){
					case 1:
						if(embarcacoesJ2 - opcao < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							jogador2.setBote();
							embarcacoesJ2 = embarcacoesJ2 - opcao;
						}
						break;
					case 2:
						if(embarcacoesJ2 - opcao < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							controle = 0;
							do{
								cout << "1. Vertical.\n";
								cout << "2. Horizontal.\n";
								cout << "Escolha a direcao: ";
									cin >> opcao2;
								if((opcao2 < 1) || (opcao2 > 2)){
									cout << "Direcao invalida!\n";
								} else if (opcao2 == 1){
									jogador2.setRebocador_vertical();
									embarcacoesJ2 = embarcacoesJ2 - opcao;
									controle = 1;
								} else if (opcao2 == 2){
									jogador2.setRebocador_horizontal();
									embarcacoesJ2 = embarcacoesJ2 - opcao;
									controle = 1;
								}
							}while(controle == 0);
						}
						break;
					case 3:
						if(embarcacoesJ2 - opcao < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							controle = 0;
							do{
								cout << "1. Vertical.\n";
								cout << "2. Horizontal.\n";
								cout << "Escolha a direcao: ";
									cin >> opcao2;
								if((opcao2 < 1) || (opcao2 > 2)){
									cout << "Direcao invalida!\n";
								} else if (opcao2 == 1){
									jogador2.setCruzador_vertical();
									embarcacoesJ2 = embarcacoesJ2 - opcao;
									controle = 1;
								} else if (opcao2 == 2){
									jogador2.setCruzador_horizontal();
									embarcacoesJ2 = embarcacoesJ2 - opcao;
									controle = 1;
								}
							}while(controle == 0);
						}
						break;
					case 4:
						if(embarcacoesJ2 - opcao*2 < 0){
							cout << "Embarcacao invalida!\n";
						} else {
							controle = 0;
							do{
								cout << "1. Vertical.\n";
								cout << "2. Horizontal.\n";
								cout << "Escolha a direcao: ";
									cin >> opcao2;
								if((opcao2 < 1) || (opcao2 > 2)){
									cout << "Direcao invalida!\n";
								} else if (opcao2 == 1){
									jogador2.setPortaviao_vertical();
									embarcacoesJ2 = embarcacoesJ2 - opcao*2;
									controle = 1;
								} else if (opcao2 == 2){
									jogador2.setPortaviao_horizontal();
									embarcacoesJ2 = embarcacoesJ2 - opcao*2;
									controle = 1;
								}
							}while(controle == 0);
						}
						break;
				}
				system("pause");
			}
		}while(embarcacoesJ2 > 0);
		
		// rodadas
		limparTela();
		cout << "A partida ira iniciar.\n";
		system("pause");
		for(int i = 1; i <= rodadas; i++){
			if(i%2 == 0){
				limparTela();
				jogador1.getCampo();
				cout << "Vez de " << nomeJogador2 << ".\n\n Tente acertar uma embarcacao.\n";
				jogador1.setTiro();
				teste = jogador1.verificarVitoria();
				if(teste == true){
					limparTela();
					cout << "\n\nO jogo acabou.\n\n";
					cout << "A pontuacao sera somada!!";
					pontosJ1 = jogador2.getPontuacao();
					pontosJ2 = jogador1.getPontuacao();
					if(pontosJ1 > pontosJ2){
						cout << "O vencedor eh " << nomeJogador1 << "!!!!!! Sua pontuação foi de " << pontosJ1;
					} else {
						cout << "O vencedor eh " << nomeJogador2 << "!!!!!! Sua pontuação foi de " << pontosJ2;
					}		
					i = dificuldade*2;						
				}
			} else {
				limparTela();
				jogador2.getCampo();
				cout << "Vez de " << nomeJogador1 << ".\n\n Tente acertar uma embarcacao.";
				jogador2.setTiro();
				teste = jogador2.verificarVitoria();
				if(teste == true){
					limparTela();
					cout << "\n\nO jogo acabou.\n\n";
					cout << "A pontuacao sera somada!!";
					pontosJ1 = jogador2.getPontuacao();
					pontosJ2 = jogador1.getPontuacao();
					if(pontosJ1 > pontosJ2){
						cout << "O vencedor eh " << nomeJogador1 << "!!!!!! Sua pontuação foi de " << pontosJ1;
					} else {
						cout << "O vencedor eh " << nomeJogador2 << "!!!!!! Sua pontuação foi de " << pontosJ2;
					}		
					i = dificuldade*2;
				}
				if(i == rodadas){
					limparTela();
					cout << "\n\nO jogo acabou.\n\n";
					cout << "A pontuacao sera somada!!";
					system("pause");
					pontosJ1 = jogador2.getPontuacao();
					pontosJ2 = jogador1.getPontuacao();
					if(pontosJ1 > pontosJ2){
						cout << "O vencedor eh " << nomeJogador1 << "!!!!!! Sua pontuação foi de " << pontosJ1;
					} else {
						cout << "O vencedor eh " << nomeJogador2 << "!!!!!! Sua pontuação foi de " << pontosJ2;
					}
					system("pause");	
				}
			}		
		
		}
		// encerramento
	}
	
	void Controlador::getRanking(){
	 cout << "Isso nao foi implementado :/ \n";
	}
	
	// fim dos metodos
