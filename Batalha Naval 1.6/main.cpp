#include <iostream>
#include "Classes/Controlador.cpp"

using namespace std;

// main
int main(){
	Controlador controle;
	int facil = 7, medio = 10, dificil = 15;
	int opcao, opcao2, dificuldade;
	do{
		system("clear||cls");
		cout << "==== Batalha Naval ====\n";
		cout << "1. Iniciar jogo.\n";
		cout << "2. Ranking e estatisticas.\n";
		cout << "3. Encerrar.\n\n";
		cout << "Selecionar opcao: ";
			cin >> opcao;
		switch(opcao){
			case 1:
				system("clear||cls");
					cout << "1. Facil (7x7) - 21 rodadas.\n";
					cout << "2. Medio (10x10) - 30 rodadas.\n";
					cout << "3. Dificil (15x15) - 45 rodadas.\n\n";
				do
				{	
					cout << "Escolha uma dificuldade: ";
						cin >> dificuldade;
					if((dificuldade > 3) || (dificuldade < 1))
					{
						cout << "Dificuldade invalida.\n";
					} else
					{
						switch(dificuldade)
						{
							case 1:
								controle.iniciar(facil);
								break;
							case 2:
								controle.iniciar(medio);
								break;
							case 3:
								controle.iniciar(dificil);
								break;
							default:
								break;
						}
					}
				}while((dificuldade > 3) || (dificuldade < 1));
			
				break;
			case 2:
				system("clear||cls");
				controle.getRanking();
				system("pause");
				
				break;
			case 3:
				system("clear||cls");
				break;
		}
	}while(opcao != 3);
		
	system("pause");
	return 0;
}
