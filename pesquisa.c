/*
Autor: Alisson Rodrigues de Carvalho Santos
Componente Curricular: Algoritmos I
Concluido em: /10/2011
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.   */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	int idade,continuar=0,proxQuestionario=0,controle_menu=0;
    char sexo,curso,resposta,resp,escolha_menu;
    int total_escolhas=0; //variavel usada na frequencia absoluta,que é zerada após ser usada em cada questão para ser reutilizada//
    float acumulador_de_apoio_1=0,acumulador_de_apoio_2=0,acumulador_de_apoio_3=0;
    
    //variaveis contadoras
	int cF1=0,cF2=0,cF3=0,Chomem=0,Cmulher=0,ContE=0,ContH=0,ContM=0,ContL=0;
	int contador_total=0; // variavel que conta o total de participantes e que é usada como referencia no total da frequencia absoluta//
	
	//*variaveis contadoras para cada questão da primeira cartegoria de perguntas**//
	float q1a,q2a,q3a,q4a,q5a,q1b,q2b,q3b,q4b,q5b,q1c,q2c,q3c,q4c,q5c,q1d,q2d,q3d,q4d,q5d,q1e,q2e,q3e,q4e,q5e,q1f,q2f,q3f,q4f,q5f;
	float q6a,q7a,q8a,q9a,q10a,q11a,q12a,q6b,q7b,q8b,q9b,q10b,q11b,q12b,q6c,q7c,q8c,q9c,q10c,q11c,q12c,q6d,q7d,q8d,q9d,q10d,q11d,q12d,q6e,q7e,q8e,q9e,q10e,q11e,q12e,q6f,q7f,q8f,q9f,q10f,q11f,q12f;
	float q13a,q14a,q15a,q16a,q17a,q13b,q14b,q15b,q16b,q17b,q13c,q14c,q15c,q16c,q17c,q13d,q14d,q15d,q16d,q17d,q13e,q14e,q15e,q16e,q17e,q13f,q14f,q15f,q16f,q17f;
	//* zerando as variaveis contadoras para evitar erros*//
	 q1a=q2a=q3a=q4a=q5a=q1b=q2b=q3b=q4b=q5b=q1c=q2c=q3c=q4c=q5c=q1d=q2d=q3d=q4d=q5d=q1e=q2e=q3e=q4e=q5e=q1f=q2f=q3f=q4f=q5f=0;
	 q6a=q7a=q8a=q9a=q10a=q11a=q12a=q6b=q7b=q8b=q9b=q10b=q11b=q12b=q6c=q7c=q8c=q9c=q10c=q11c=q12c=q6d=q7d=q8d=q9d=q10d=q11d=q12d=q6e=q7e=q8e=q9e=q10e=q11e=q12e=q6f=q7f=q8f=q9f=q10f=q11f=q12f=0;
	 q13a=q14a=q15a=q16a=q17a=q13b=q14b=q15b=q16b=q17b=q13c=q14c=q15c=q16c=q17c=q13d=q14d=q15d=q16d=q17d=q13e=q14e=q15e=q16e=q17e=q13f=q14f=q15f=q16f=q17f=0;
	float score1homem,score2homem,score3homem,iparel_homem,IPAhomem,score1mulher,score2mulher,score3mulher,iparel_mulher,IPAmulher,score1f1=0,score2f1=0,score3f1=0,iparel_f1,IPAf1;
	float score1f2=0,score2f2,score3f2,iparel_f2,IPAf2,score1f3=0,score2f3,score3f3,iparel_f3,IPAf3,score1H,score2H,score3H,iparel_H,IPAH,score1M,score2M,score3M,iparel_M,IPAM;
	float score1E,score2E,score3E,iparel_E,IPAE,score1L,score2L,score3L,iparel_L,IPAL;
	
		do{ 	//Laço principal que contem o cadastro e pesquisa//
			
			do{     //cadastro da idade//
				printf("Digite sua idade:");
				scanf("%d" ,&idade);
				if(idade>=18){
					printf("continue o cadastro\n");
					continuar++;
				}
				else if(idade<18 || idade<=0){
					printf("Voce nao pode participar da pesquisa\n");
				}
				else{
					printf("Digite um numero valido\n");
				}				
			}while(continuar<1); //chave do-while//
			
			//incrementando o contador de faixa etaria acordo a idade//
			if(idade<21){
				cF1+=1;
			}	
			else if(idade<23){
				cF2+=1;
			}
			else if(idade>=23){
			cF3+=1;
			}
			system("cls"); //funcao que apaga a tela anterior,serve para deixar o programa mais bonito//	
			//cadastro do sexo//
			do{
				printf("Informe seu sexo\n(F) Para Feminino\n(M) Para Masculino\n");
				getchar();   // as vezes o scanf lê a tecla ENTER  causando erros no programa, a função getchar evita esse erro pois lê valor antes de scanf
				scanf("%c" ,&sexo);
				switch(sexo){
					case 'f':
					case 'F':
						Cmulher++;
						sexo='F';
						continuar++;
					break;
					case 'm':
					case 'M':
						Chomem++;
						sexo='M';
						continuar++;
					break;
				default:
					printf("Digite M ou F!!");
				break;				
				}		
			}while(continuar<2);
			
			system("cls");
			
			//Cadastro do curso//
			do{
			printf("Escolha seu curso\n(E)Engenharia Civil\n(L)Letras Vernaculas\n(M)Medicina\n(H)Historia\n");
			getchar();
			scanf("%c" ,&curso);
			switch(curso){
				case 'e':
				case 'E':
					ContE+=1;
					curso='E';
					continuar++;
					break;
				case 'L':
				case 'l':
					ContL++;
					curso='L';
					continuar++;
					break;
				case 'M':
				case 'm':
					ContM++;
					curso='M';
					continuar++;
					break;
				case 'H':
				case 'h':
					ContH++;
					curso='h';
					continuar++;
					break;	
				default:
					printf("Informe um valor valido\n");
					continuar=2;
					break;				
			}		
		}while(continuar<3);//chave do-while
		
		system("cls");
		contador_total+=1; //após o cadastro essa variavel contabiliza mais um inscrito para pesquisa, e serve como referencia pois indica que 17 questões serão respondidas
		
		//terminado o cadastro de dados dermograficos comeca a pesquisa//
		
		//-----Pesquisa------//
		printf("RESPONDA O QUESTIONARIO\n");
		while(proxQuestionario==0){
			printf("Q1)-O que este pais necessita, principalmente, antes de leis ou planos politicos, eh de alguns lideres valentes, incansaveis e dedicados em quem o povo possa depositar a sua fe\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q1a++;  // contadador da frequencia absoluta,cada vez que um usuario escolhe a variavel é incrementada
					proxQuestionario++; //variavel de controle do laço, quando o valor é certo encerrar o laço atual
					acumulador_de_apoio_1+=6;  //acumulador que recebe o valor apropiado a escolha, eh usado no final da cartegorias de perguntas e alguns testes condicionais//
				break;
				case 'b':
				case 'B':
					q1b++;
					proxQuestionario++;
					acumulador_de_apoio_1+=5;
				break;
				case 'c':
				case 'C':
					q1c++;
					proxQuestionario++;
					acumulador_de_apoio_1+=4;
				break;
				case 'd':
				case 'D':
					q1d++;
					proxQuestionario++;
					acumulador_de_apoio_1+=3;
				break;
				case 'e':
				case 'E':
					q1e++;
					proxQuestionario++;
					acumulador_de_apoio_1+=2;
				break;
				case 'f':
				case 'F':
					q1f++;
					proxQuestionario++;
					acumulador_de_apoio_1+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n"); //caso o usuario informe um valor errado,o laçõ volta e ele pode escolher novamente//
				break;		
			}
		}//chave do while
		system("cls"); // apaga a tela anterior e deixa a interface mais legivel//
		while(proxQuestionario==1){
			printf("Q2)-A obediencia e o respeito a autoridade sao as principais virtudes que devemos ensinar as nossas criancas\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q2a++;
					proxQuestionario++;
					acumulador_de_apoio_1+=6;
				break;
				case 'b':
				case 'B':
					q1b++;
					proxQuestionario++;
					acumulador_de_apoio_1+=5;
				break;
				case 'c':
				case 'C':
					q1c++;
					proxQuestionario++;
					acumulador_de_apoio_1+=4;
				break;
				case 'd':
				case 'D':
					q1d++;
					proxQuestionario++;
					acumulador_de_apoio_1+=3;
				break;
				case 'e':
				case 'E':
					q1e++;
					proxQuestionario++;
					acumulador_de_apoio_1+=2;
				break;
				case 'f':
				case 'F':
					q1f++;
					proxQuestionario++;
					acumulador_de_apoio_1+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		system("cls");
			while(proxQuestionario==2){
			printf("Q3)-Nao ha nada pior do que uma pessoa que nao sente profundo amor, gratidao e respeito por seus pais\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
			case 'a':
				case 'A':
					q2a++;
					proxQuestionario++;
					acumulador_de_apoio_1+=6;
				break;
				case 'b':
				case 'B':
					q1b++;
					proxQuestionario++;
					acumulador_de_apoio_1+=5;
				break;
				case 'c':
				case 'C':
					q1c++;
					proxQuestionario++;
					acumulador_de_apoio_1+=4;
				break;
				case 'd':
				case 'D':
					q1d++;
					proxQuestionario++;
					acumulador_de_apoio_1+=3;
				break;
				case 'e':
				case 'E':
					q1e++;
					proxQuestionario++;
					acumulador_de_apoio_1+=2;
				break;
				case 'f':
				case 'F':
					q1f++;
					proxQuestionario++;
					acumulador_de_apoio_1+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		system("cls");
		while(proxQuestionario==3){
			printf("Q4)-Nenhuma pessoa decente, normal e em seu sao juizo pensaria em ofender um amigo ou parente proximo\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q2a++;
					proxQuestionario++;
					acumulador_de_apoio_1+=6;
				break;
				case 'b':
				case 'B':
					q1b++;
					proxQuestionario++;
					acumulador_de_apoio_1+=5;
				break;
				case 'c':
				case 'C':
					q1c++;
					proxQuestionario++;
					acumulador_de_apoio_1+=4;
				break;
				case 'd':
				case 'D':
					q1d++;
					proxQuestionario++;
					acumulador_de_apoio_1+=3;
				break;
				case 'e':
				case 'E':
					q1e++;
					proxQuestionario++;
					acumulador_de_apoio_1+=2;
				break;
				case 'f':
				case 'F':
					q1f++;
					proxQuestionario++;
					acumulador_de_apoio_1+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		system("cls");
		while(proxQuestionario==4){
			printf("Q5)-O policial eh um guerreiro de Deus para impor a ordem e proteger as pessoas de bem\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q2a++;
					proxQuestionario++;
					acumulador_de_apoio_1+=6;
				break;
				case 'b':
				case 'B':
					q1b++;
					proxQuestionario++;
					acumulador_de_apoio_1+=5;
				break;
				case 'c':
				case 'C':
					q1c++;
					proxQuestionario++;
					acumulador_de_apoio_1+=4;
				break;
				case 'd':
				case 'D':
					q1d++;
					proxQuestionario++;
					acumulador_de_apoio_1+=3;
				break;
				case 'e':
				case 'E':
					q1e++;
					proxQuestionario++;
					acumulador_de_apoio_1+=2;
				break;
				case 'f':
				case 'F':
					q1f++;
					proxQuestionario++;
					acumulador_de_apoio_1+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;	
			}
		}//chave do while
		system("cls");
		
		//Segunda etapa de perguntas//
		while(proxQuestionario==5){
			printf("Q6)-A maioria de nossos problemas sociais estaria resolvida se pudessemos nos livrar das pessoas imorais, dos marginais e dos pervertidos\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		system("cls");
		while(proxQuestionario==6){
			printf("Q7)-Se falassemos menos e trabalhassemos mais, todos estariamos melhor\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
			case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		
		system("cls");
		while(proxQuestionario==7){
			printf("Q8)-Deve-se castigar sempre todo insulto a nossa honra\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		
		system("cls");
		while(proxQuestionario==8){
			printf("Q9)-Os crimes sexuais tais como o estupro ou ataques a criancas merecem mais que prisao; quem comete esses crimes deveria receber punicao fisica publicamente ou receber um castigo pior\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}		
		}//chave do while
		system("cls");
		while(proxQuestionario==9){
			printf("Q10)-Os homossexuais sao quase criminosos e deveriam receber um castigo severo\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while//
		system("cls");
		while(proxQuestionario==10){
			printf("Q11)-As vezes, os jovens tem ideias rebeldes que, com os anos, deverao superar para acalmar os seus pensamentos\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while//
		system("cls");
		while(proxQuestionario==11){
			printf("Q12)-Hoje em dia, as pessoas se intrometem cada vez mais em assuntos que deveriam ser somente pessoais e privados\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q6a++;
					proxQuestionario++;
					acumulador_de_apoio_2+=6;
				break;
				case 'b':
				case 'B':
					q5b++;
					proxQuestionario++;
					acumulador_de_apoio_2+=5;
				break;
				case 'c':
				case 'C':
					q6c++;
					proxQuestionario++;
					acumulador_de_apoio_2+=4;
				break;
				case 'd':
				case 'D':
					q6d++;
					proxQuestionario++;
					acumulador_de_apoio_2+=3;
				break;
				case 'e':
				case 'E':
					q6e++;
					proxQuestionario++;
					acumulador_de_apoio_2+=2;
				break;
				case 'f':
				case 'F':
					q6f++;
					proxQuestionario++;
					acumulador_de_apoio_2+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while
		
		//Terceira etapa de perguntas//
		system("cls");
		while(proxQuestionario==12){
			printf("Q13)A ciencia tem o seu lugar, mas ha muitas coisas importantes que a mente humana jamais podera compreender\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q13a++;
					proxQuestionario++;
					acumulador_de_apoio_3+=6;
				break;
				case 'b':
				case 'B':
					q13b++;
					proxQuestionario++;
					acumulador_de_apoio_3+=5;
				break;
				case 'c':
				case 'C':
					q13c++;
					proxQuestionario++;
					acumulador_de_apoio_3+=4;
				break;
				case 'd':
				case 'D':
					q13d++;
					proxQuestionario++;
					acumulador_de_apoio_3+=3;
				break;
				case 'e':
				case 'E':
					q13e++;
					proxQuestionario++;
					acumulador_de_apoio_3+=2;
				break;
				case 'f':
				case 'F':
					q13f++;
					proxQuestionario++;
					acumulador_de_apoio_3+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
   	   }//chave do while
    system("cls");
    	while(proxQuestionario==13){
			printf("Q14)-Os homens podem ser divididos em duas classes definidas: os fracos e os fortes\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q13a++;
					proxQuestionario++;
					acumulador_de_apoio_3+=6;
				break;
				case 'b':
				case 'B':
					q13b++;
					proxQuestionario++;
					acumulador_de_apoio_3+=5;
				break;
				case 'c':
				case 'C':
					q13c++;
					proxQuestionario++;
					acumulador_de_apoio_3+=4;
				break;
				case 'd':
				case 'D':
					q13d++;
					proxQuestionario++;
					acumulador_de_apoio_3+=3;
				break;
				case 'e':
				case 'E':
					q13e++;
					proxQuestionario++;
					acumulador_de_apoio_3+=2;
				break;
				case 'f':
				case 'F':
					q13f++;
					proxQuestionario++;
					acumulador_de_apoio_3+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
		}//chave do while//
	system("cls");
		while(proxQuestionario==14){
			printf("Q15)-Um individuo de mas maneiras, maus costumes e ma educacao dificilmente pode fazer amizade com pessoas decentes\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q13a++;
					proxQuestionario++;
					acumulador_de_apoio_3+=6;
				break;
				case 'b':
				case 'B':
					q13b++;
					proxQuestionario++;
					acumulador_de_apoio_3+=5;
				break;
				case 'c':
				case 'C':
					q13c++;
					proxQuestionario++;
					acumulador_de_apoio_3+=4;
				break;
				case 'd':
				case 'D':
					q13d++;
					proxQuestionario++;
					acumulador_de_apoio_3+=3;
				break;
				case 'e':
				case 'E':
					q13e++;
					proxQuestionario++;
					acumulador_de_apoio_3+=2;
				break;
				case 'f':
				case 'F':
					q13f++;
					proxQuestionario++;
					acumulador_de_apoio_3+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
   	}//chave do while
   	system("cls");
		while(proxQuestionario==15){
			printf("Q16)-Todos devemos ter fe absoluta em um poder sobrenatural, cujas decisoes devemos acatar\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q13a++;
					proxQuestionario++;
					acumulador_de_apoio_3+=6;
				break;
				case 'b':
				case 'B':
					q13b++;
					proxQuestionario++;
					acumulador_de_apoio_3+=5;
				break;
				case 'c':
				case 'C':
					q13c++;
					proxQuestionario++;
					acumulador_de_apoio_3+=4;
				break;
				case 'd':
				case 'D':
					q13d++;
					proxQuestionario++;
					acumulador_de_apoio_3+=3;
				break;
				case 'e':
				case 'E':
					q13e++;
					proxQuestionario++;
					acumulador_de_apoio_3+=2;
				break;
				case 'f':
				case 'F':
					q13f++;
					proxQuestionario++;
					acumulador_de_apoio_3+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
   		}//chave do while
   	system("cls");
		while(proxQuestionario==16){
			printf("Q17)-Pobreza eh consequencia da falta de vontade de querer trabalhar\n");
			printf("(a)Concordo totalmente\n(b)Concordo\n(c)Concordo parcialmente\n(d)Discordo parcialmente\n(e)Discordo\n(f)Discordo totalmente\n");
			getchar();
			scanf("%c" ,&resp);
			switch(resp){
				case 'a':
				case 'A':
					q13a++;
					proxQuestionario++;
					acumulador_de_apoio_3+=6;
				break;
				case 'b':
				case 'B':
					q13b++;
					proxQuestionario++;
					acumulador_de_apoio_3+=5;
				break;
				case 'c':
				case 'C':
					q13c++;
					proxQuestionario++;
					acumulador_de_apoio_3+=4;
				break;
				case 'd':
				case 'D':
					q13d++;
					proxQuestionario++;
					acumulador_de_apoio_3+=3;
				break;
				case 'e':
				case 'E':
					q13e++;
					proxQuestionario++;
					acumulador_de_apoio_3+=2;
				break;
				case 'f':
				case 'F':
					q13f++;
					proxQuestionario++;
					acumulador_de_apoio_3+=1;
				break;
				default:
					printf("Digite uma das escolhas validas\n");
				break;
			}
   		}//chave do while//
   	system("cls");	
   	/*Calculo dos escores das perguntas*/
		if(idade<21){
			score1f1+=acumulador_de_apoio_1/5;
			score2f1+=acumulador_de_apoio_2/7;
			score3f1+=acumulador_de_apoio_3/5;
		}
		else if(idade<23){
			score1f2+=acumulador_de_apoio_1/5;
			score2f2+=acumulador_de_apoio_2/7;
			score3f2+=acumulador_de_apoio_3/5;
		}
		else{
			score1f3+=acumulador_de_apoio_1/5;
			score2f3+=acumulador_de_apoio_2/7;
			score3f3+=acumulador_de_apoio_3/5;
		}
		
		if(sexo=='F'){
			score1mulher+=acumulador_de_apoio_1/5;
			score2mulher+=acumulador_de_apoio_2/7;
			score3mulher+=acumulador_de_apoio_3/5;
		}
		else{
			score1homem+=acumulador_de_apoio_1/5;
			score2homem+=acumulador_de_apoio_2/7;
			score3homem+=acumulador_de_apoio_3/5;
		}
			
		if(curso=='H'){
			score1H+=acumulador_de_apoio_1/5;
			score2H+=acumulador_de_apoio_2/7;
			score3H+=acumulador_de_apoio_3/5;
		}
		else if(curso=='E'){
			score1E+=acumulador_de_apoio_1/5;
			score2E+=acumulador_de_apoio_2/7;
			score3E+=acumulador_de_apoio_3/5;
		}
		else if(curso=='L'){
			score1L+=acumulador_de_apoio_1/5;
			score2L+=acumulador_de_apoio_2/7;
			score3L+=acumulador_de_apoio_3/5;
		}
		else{
			score1M+=acumulador_de_apoio_1/5;
			score2M+=acumulador_de_apoio_2/7;
			score3M+=acumulador_de_apoio_3/5;
		}	
	continuar=0,proxQuestionario=0;
   	printf("\n ---Realizar outra pesquisa?---\n Se sim digite: S\n Se nao digite outro valor\n");
   	getchar();
   	scanf("%c" ,&resposta);
	}while(resposta=='S' || resposta=='s');
	/* Terminado a pesquisa os valores dos escores reais e o indicie de propensão ao autoritarismo eh calculado*/
	
	score1f1=score1f1/cF1, score2f1=score2f1/cF1 ,score3f1=score3f1/cF1, iparel_f1=(score1f1+score2f1+score3f1)/3,  IPAf1=(iparel_f1-1)*2;
	score1f2=score1f2/cF2, score2f2=score2f2/cF2 ,score3f2=score3f2/cF2, iparel_f2=(score1f2+score2f2+score3f2)/3,  IPAf2=(iparel_f2-1)*2;
	score1f3=score1f3/cF3, score2f3=score2f3/cF3 ,score3f3=score3f3/cF3, iparel_f3=(score1f3+score2f3+score3f3)/3,  IPAf3=(iparel_f3-1)*2;
	score1homem=score1homem/Chomem,  score2homem=score2homem/Chomem, score3homem=score3homem/Chomem, iparel_homem=(score1homem+score2homem+score3homem)/3, IPAhomem=(iparel_homem-1)*2;
	score1mulher=score1mulher/Cmulher,  score2mulher=score2mulher/Cmulher,  score3mulher=score3mulher/Cmulher, iparel_mulher=(score1mulher+score2mulher+score3mulher)/3 ,IPAmulher=(iparel_mulher-1)*2;
	score1H=score1H/ContH, score2H=score2H/ContH, score3H=score3H/ContH, iparel_H=(score1H+score2H+score3H)/3, IPAH=(iparel_H-1)*2;
	score1E=score1E/ContE, score2E=score2E/ContE, score3E=score3E/ContE, iparel_E=(score1E+score2E+score3E)/3, IPAE=(iparel_E-1)*2;
	score1L=score1L/ContL, score2L=score2L/ContL, score3L=score3L/ContL, iparel_L=(score1L+score2L+score3L)/3, IPAL=(iparel_L-1)*2;
	score1M=score1M/ContM, score2M=score2M/ContM, score3M=score3M/ContM, iparel_M=(score1M+score2M+score3M)/3, IPAM=(iparel_M-1)*2;
	
	//menu para exibição dos dados de saida,para que possam ser exibidos de maneira organizada pois são muitos dados para o usuario ver
	//hora dos printfs
		system("cls");
		  //essa variavel recebe a soma das vezes que uma opção foi escolhida e se torna o tanto de vezes que a questão foi respondida//
			printf("-----Frequencia absoluta e relativa-----\n");
			printf("Questao 1)           frequencia absoluta---frequencia relativa(porcentagem)\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n",q1a, (q1a*100)/contador_total);    //essa operação no final calcula a frequencia relativa
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q1b,(q1b*100)/contador_total);   //usando do contador_total que tambem indica o total de perguntas
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q1c,(q1c*100)/contador_total);	// respondidas                                                         //	
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q1d,(q1d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q1e,(q1e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q1f,(q1f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 2//
			printf("Questao 2)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n",q2a,(q2a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n",q2b,(q2b*100)/contador_total);
			printf("Concordo parcialmente          %.0f        ---%.2f porc.\n" ,q2c,(q2c*100)/contador_total);
			printf("Discordo parcialmente          %.0f        ---%.2f porc.\n" ,q2d,(q2d*100)/contador_total);
			printf("discordo                       %.0f        ---%.2f porc.\n" ,q2e,(q2e*100)/contador_total);
			printf("discordo totalmente            %.0f        ---%.2f porc.\n" ,q2f,(q2f*100)/contador_total);
			printf("Total                          %d          ---%.2f porc.\n" ,contador_total,100.00);
			//questão 3
			printf("Questao 3)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q3a,(q3a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q3b,(q3b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q3c,(q3c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q3d,(q3d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q3e,(q3e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q3f,(q3f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 4
			printf("Questao 4)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f        ---%.2f porc.\n" ,q4a,(q4a*100)/contador_total);
			printf("Concordo                       %.0f        ---%.2f porc.\n" ,q4b,(q4b*100)/contador_total);
			printf("Concordo parcialmente          %.0f        ---%.2f porc.\n" ,q4c,(q4c*100)/contador_total);
			printf("Discordo parcialmente          %.0f        ---%.2f porc.\n" ,q4d,(q4d*100)/contador_total);
			printf("discordo                       %.0f        ---%.2f porc.\n" ,q4e,(q4e*100)/contador_total);
			printf("discordo totalmente            %.0f        ---%.2f porc.\n" ,q4f,(q4f*100)/contador_total);
			printf("Total                          %d          ---%.2f porc.\n" ,contador_total,100.00);
			//questão 5//
			printf("Questao 1)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q5a,(q5a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q5b,(q5b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q5c,(q5c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q5d,(q5d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q5e,(q5e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q5f,(q5f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 6
			printf("Questao 6)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q6a,(q6a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q6b,(q6b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q6c,(q6c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q6d,(q6d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q6e,(q6e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q6f,(q6f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.f\n" ,contador_total,100.00);
			//questão 7
			printf("Questao 7)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q7a,(q7a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q7b,(q7b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q7c,(q7c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q7d,(q7d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q7e,(q7e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q7f,(q7f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 8//
			printf("Questao 8)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q8a,(q8a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q8b,(q8b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q8c,(q8c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q8d,(q8d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q8e,(q8e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q8f,(q8f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 9//
			printf("Questao 9)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q9a,(q9a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q9b,(q9b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q9c,(q9c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q9d,(q9d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q9e,(q9e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q9f,(q9f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 10//
			printf("Questao 10)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q10a,(q10a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q10b,(q10b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q10c,(q10c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q10d,(q10d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q10e,(q10e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q10f,(q10f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 11//
			printf("Questao 11)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q11a,(q11a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q11b,(q11b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q11c,(q11c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q11d,(q11d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q11e,(q11e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q11f,(q11f*100)/contador_total);
			printf("Total                          %.0f         ---%.2f porc.\n" ,contador_total,100.00);
			//questão 12//
			printf("Questao 12)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q12a,(q12a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q12b,(q12b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q12c,(q12c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q12d,(q12d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q12e,(q12e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q12f,(q12f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 13//
			printf("Questao 13)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q13a,(q13a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q13b,(q13b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q13c,(q13c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q13d,(q13d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q13e,(q13e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q13f,(q13f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 14
			printf("Questao 14)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q14a,(q14a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q14b,(q14b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q14c,(q14c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q14d,(q14d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q14e,(q14e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q14f,(q14f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 15
			printf("Questao 15)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q15a,(q15a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q15b,(q15b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q15c,(q15c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q15d,(q15d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q15e,(q15e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q15f,(q15f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 16
			printf("Questao 16)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q16a,(q16a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q16b,(q16b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q16c,(q16c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q16d,(q16d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q16e,(q16e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q16f,(q16f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			//questão 17//
			printf("Questao 17)           frequencia absoluta---frequencia relativa\n");
			printf("Concordo totalmente            %.0f         ---%.2f porc.\n" ,q17a,(q17a*100)/contador_total);
			printf("Concordo                       %.0f         ---%.2f porc.\n" ,q17b,(q17b*100)/contador_total);
			printf("Concordo parcialmente          %.0f         ---%.2f porc.\n" ,q17c,(q17c*100)/contador_total);
			printf("Discordo parcialmente          %.0f         ---%.2f porc.\n" ,q17d,(q17d*100)/contador_total);
			printf("discordo                       %.0f         ---%.2f porc.\n" ,q17e,(q17e*100)/contador_total);
			printf("discordo totalmente            %.0f         ---%.2f porc.\n" ,q17f,(q17f*100)/contador_total);
			printf("Total                          %d           ---%.2f porc.\n" ,contador_total,100.00);
			printf("\n \n tecle enter para exibir os scores\n");
			// para os scores//
			
			system("pause");// o comando sytem(pause) espera o usuario teclar algo para prosseguir o programa
			system("cls");
			printf("---Escores e IPA para as cartergorias de idade,sexo,curso\n");
			printf("Faixa etaria-1 18 a 21 anos: escore1=%.2f escore2=%.2f escore3=%.2f  IPA=%.2f\n" ,score1f1,score2f1,score3f1,IPAf1);	
			printf("Faixa etaria-2 21 a 23 anos: escore1=%.2f escore2=%.2f escore3=%.2f  IPA=%.2f\n" ,score1f2,score2f2,score3f2,IPAf2);
			printf("Faixa etaria-3 acima de 23 anos: escore1=%.2f escore2=%.2f escore3=%.2f  IPA=%.2f\n" ,score1f3,score2f3,score3f3,IPAf3);
			printf("Mulheres  escore1=%.2f  escore2=%.2f  escore3=%.2f IPA=%.2f\n" ,score1mulher,score2mulher,score3mulher,IPAmulher);
			printf("Homens  escore1=%.2f  escore2=%.2f  escore3=%.2f IPA=%.2f\n" ,score1homem,score2homem,score3homem,IPAhomem);
			printf("Curso de historia  escore1=%.2f  escore2=%.2f  escore3=%.2f IPA=%.2f\n" ,score1H,score2H,score3H,IPAH);
			printf("Curso de letras vernaculas escore1=%.2f  escore2=%.2f  escore3=%.2f IPA=%.2f\n" ,score1L,score2L,score3L,IPAL);
			printf("Curso de engenharia civil  escore1=%.2f  escore2=%.2f  escore3=%.2f IPA=%.2f\n" ,score1E,score2E,score3E,IPAE);
			printf("Curso de medicina  escore1=%.2f  escore2=%.2f  escore3=%.2f IPA=%.2f\n" ,score1M,score2M,score3M,IPAM);
			system("pause");
	return 0;		
}
