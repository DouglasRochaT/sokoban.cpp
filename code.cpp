//--------------------Jogo desenvolvido por Douglas da Rocha - 29/06/2019-------------------

#include "iostream"
#include "conio.h"
#include "windows.h"

using namespace std;

int main()
{
	CONSOLE_CURSOR_INFO ch;                              //Posionamento do mouse
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ch);
	ch.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ch);

	int mapa[13][14];
	int mapa1[13][14] = { 0,0,1,1,1,1,1,0,0,0,0,0,0,0,
						  1,1,1,0,0,0,1,0,0,0,0,0,0,0,
						  1,0,2,0,1,0,1,1,0,0,0,0,0,0,
						  1,0,1,0,0,3,0,1,0,0,0,0,0,0,
						  1,0,3,0,0,1,0,1,0,0,0,0,0,0,
						  1,1,2,1,3,2,0,1,0,0,0,0,0,0,
						  0,1,0,0,0,1,1,1,0,0,0,0,0,0,
						  0,1,1,1,1,1,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int mapa2[13][14] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						  1,3,3,3,3,1,0,0,0,0,0,0,0,1,
						  1,4,3,3,3,1,0,2,0,2,0,2,0,1,
						  1,3,3,1,1,1,1,0,0,2,0,0,0,1,
						  1,3,3,1,0,0,1,0,0,0,2,2,0,1,
						  1,3,3,2,0,0,1,1,0,1,0,0,0,1,
						  1,0,2,1,0,0,2,0,0,1,1,1,1,1,
						  1,0,0,1,0,0,1,0,0,0,0,0,0,1,
						  1,1,0,1,1,1,1,0,1,1,0,1,0,1,
						  1,0,2,0,0,0,0,2,0,1,0,0,0,1,
						  1,0,1,2,1,2,1,0,0,1,1,1,1,1,
						  1,0,0,0,0,0,0,0,1,1,0,0,0,0,
						  1,1,1,1,1,1,1,1,1,0,0,0,0,0 };

	int i, j, jx, jy, tecla;					     	 //Variáveis de posicionamento do jogador e entradas de teclas
	int conto = 0, contm = 0;						     //Contadores de Objetivos restantes e de Movimentos
	int m = 0, selm = 0, c = 0, r = 0;				     //Variáveis de seleção no menu
	string em1 = "Não concluido", em2 = "Não concluido"; //Estado de conclusão dos mapas
	jx = 6, jy = 2;									     //Posição inicial do jogador

	while (1) {
		//------------------------------------------Menu Principal-------------------------------------------------
		while (m == 0) { 
			setlocale(LC_ALL, "Portuguese");
			if (c == 1) {
				system("cls");
				c = 0;
			}
			if (_kbhit()) {
				tecla = _getch();
				switch (tecla) {
				case 'i': //Instruções
					system("cls");
					selm = 1;
					break;
				case 'j': //Jogar
					system("cls");
					selm = 2;
					break;
				case 'v': //Voltar
					system("cls");
					selm = 0;
					break;
				case 's': //Sair
					if (selm == 0) {
						return 0;
					}
					break;
				case '1': //Mapa 1
					system("cls");
					m = 1;
					r = 1;
					selm = 4;
					break;
				case '2': //Mapa 2
					system("cls");
					m = 2;
					r = 1;
					selm = 4;
					break;
				}
			}
			if (selm == 0) {
				cout << "Sokoban V2" << endl;
				cout << "Jogo criado por Douglas da Rocha" << endl;
				cout << "I - Instruções" << endl;
				cout << "J - Jogar" << endl;
				cout << "S - Sair" << endl;
			}
			else if (selm == 1) {
				cout << "Este é um jogo de Sokoban," << endl;
				cout << "Seu objetivo é levar todas as caixas do mapa até seu destino," << endl;
				cout << "Use as teclas 'W A S D' para se movimentar no mapa," << endl;
				cout << "A caixa é identificada como '#'," << endl;
				cout << "O objetivo é identificado como 'o'," << endl;
				cout << "Lembrando que você não pode atravessar as paredes e nem caixas," << endl;
				cout << "Bom jogo!" << endl << endl;
				cout << "V - Voltar ao Menu";
			}
			else if (selm == 2) {
				cout << "Selecione entre os dois mapas utilizando o número referênte:" << endl << endl;
				cout << "Mapa 1 - Estado: " << em1 << endl;
				cout << "Mapa 2 - Estado: " << em2 << endl << endl;
				cout << "V - Voltar ao Menu";
			}
			else if (selm == 3) {
				cout << "Parabéns, você finalizou o mapa com " << contm << " movimentos." << endl << endl;
				cout << "V - Voltar ao Menu";
			}
			setlocale(LC_ALL, "C");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
		}
		//--------------------------Transferência do mapa para a matriz de jogo-------------------------------------
		if (r == 1) {
			for (i = 0; i < 13; i++) {
				for (j = 0; j < 14; j++) {
					if (m == 1) {
						mapa[i][j] = mapa1[i][j];
						jx = 6, jy = 2;
					}
					else {
						mapa[i][j] = mapa2[i][j];
						jx = 10, jy = 7;
					}
				}
			}
			contm = 0;
			r = 0;
		}

		//------------------------------------Movimentação do Personagem---------------------------------------------
		if (_kbhit()) {
			tecla = _getch();
			switch (tecla) {
			case 'w': case 72: //Cima
				if (mapa[jx - 2][jy] != 1 and mapa[jx - 2][jy] != 2 and mapa[jx - 2][jy] != 4) {
					if (mapa[jx - 1][jy] == 2 and mapa[jx - 2][jy] != 3) {
						mapa[jx - 1][jy] = 0;
						mapa[jx - 2][jy] = 2;
					}
					else if (mapa[jx - 1][jy] == 2 and mapa[jx - 2][jy] == 3) {
						mapa[jx - 1][jy] = 0;
						mapa[jx - 2][jy] = 4;
					}
					else if (mapa[jx - 1][jy] == 4) {
						mapa[jx - 1][jy] = 3;
						if (mapa[jx - 2][jy] == 0) {
							mapa[jx - 2][jy] = 2;
						}
						else {
							mapa[jx - 2][jy] = 4;
						}
					}
				}
				if (mapa[jx - 1][jy] == 0 or mapa[jx - 1][jy] == 3) {
					jx--;
					contm++;
				}
				break;
			case 's': case 80: //Baixo
				if (mapa[jx + 2][jy] != 1 and mapa[jx + 2][jy] != 2 and mapa[jx + 2][jy] != 4) {
					if (mapa[jx + 1][jy] == 2 and mapa[jx + 2][jy] != 3) {
						mapa[jx + 1][jy] = 0;
						mapa[jx + 2][jy] = 2;
					}
					else if (mapa[jx + 1][jy] == 2 and mapa[jx + 2][jy] == 3) {
						mapa[jx + 1][jy] = 0;
						mapa[jx + 2][jy] = 4;
					}
					else if (mapa[jx + 1][jy] == 4) {
						mapa[jx + 1][jy] = 3;
						if (mapa[jx + 2][jy] == 0) {
							mapa[jx + 2][jy] = 2;
						}
						else {
							mapa[jx + 2][jy] = 4;
						}
					}
				}
				if (mapa[jx + 1][jy] == 0 or mapa[jx + 1][jy] == 3) {
					jx++;
					contm++;
				}
				break;
			case 'a': case 75: //Esquerda
				if (mapa[jx][jy - 2] != 1 and mapa[jx][jy - 2] != 2 and mapa[jx][jy - 2] != 4) {
					if (mapa[jx][jy - 1] == 2 and mapa[jx][jy - 2] != 3) {
						mapa[jx][jy - 1] = 0;
						mapa[jx][jy - 2] = 2;
					}
					else if (mapa[jx][jy - 1] == 2 and mapa[jx][jy - 2] == 3) {
						mapa[jx][jy - 1] = 0;
						mapa[jx][jy - 2] = 4;
					}
					else if (mapa[jx][jy - 1] == 4) {
						mapa[jx][jy - 1] = 3;
						if (mapa[jx][jy - 2] == 0) {
							mapa[jx][jy - 2] = 2;
						}
						else {
							mapa[jx][jy - 2] = 4;
						}
					}
				}
				if (mapa[jx][jy - 1] == 0 or mapa[jx][jy - 1] == 3) {
					jy--;
					contm++;
				}
				break;
			case 'd': case 77: //Direita
				if (mapa[jx][jy + 2] != 1 and mapa[jx][jy + 2] != 2 and mapa[jx][jy + 2] != 4) {
					if (mapa[jx][jy + 1] == 2 and mapa[jx][jy + 2] != 3) {
						mapa[jx][jy + 1] = 0;
						mapa[jx][jy + 2] = 2;
					}
					else if (mapa[jx][jy + 1] == 2 and mapa[jx][jy + 2] == 3) {
						mapa[jx][jy + 1] = 0;
						mapa[jx][jy + 2] = 4;
					}
					else if (mapa[jx][jy + 1] == 4) {
						mapa[jx][jy + 1] = 3;
						if (mapa[jx][jy + 2] == 0) {
							mapa[jx][jy + 2] = 2;
						}
						else {
							mapa[jx][jy + 2] = 4;
						}
					}
				}
				if (mapa[jx][jy + 1] == 0 or mapa[jx][jy + 1] == 3) {
					jy++;
					contm++;
				}
				break;
			case 'm': //Menu
				c = 1;
				m = 0;
				selm = 0;
				break;

			case 'r': //Resetar
				r = 1;
				break;
			}
		}
		//---------------------------------------Impressão do Mapa-----------------------------------------------
		for (i = 0; i < 13; i++) {
			for (j = 0; j < 14; j++) {
				if (i == jx and j == jy) { //Personagem
					cout << "@";
				}
				else if (mapa[i][j] == 0) { //Espaço vasio
					cout << " ";
				}
				else if (mapa[i][j] == 1) { //Parede
					cout << "°";
				}
				else if (mapa[i][j] == 2) { //Caixa
					cout << "#";
					conto++;
				}
				else if (mapa[i][j] == 3) { //Objetivo
					cout << "o";
				}
				else if (mapa[i][j] == 4) { //Caixa no Objetivo
					cout << char(254);
				}
			}
			cout << endl;
		}
		if (conto == 0) {
			if (m == 1) {
				em1 = "Concluído";
			}
			else {
				em2 = "Concluído";
			}
			m = 0;
			c = 1;
			selm = 3;
			Sleep(1000);
		}
		else {
			conto = 0;
		}
		cout << "Movimentos: " << contm << endl;
		cout << endl << "Pressione 'R' para resetar o mapa.";		
		cout << endl << "Pressione 'M' para retornar ao menu.";
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}

}
