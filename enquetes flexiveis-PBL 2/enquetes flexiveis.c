/*
Autor: Alisson Rodrigues de Carvalho Santos
Componente Curricular: Algoritmos e programação I
Concluido em: 19/01/2019
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct escala{
	int qtd_niveis,codigo_escala;
	char escalas[400];
}Escala;
typedef struct questao{
	char pergunta[400];
	int codigo_escala;
	Escala *escala_questao;
}Questao;
typedef struct entrevistado{
	char curso[50];
	char sexo[10];
	int respostas[100],idade;		
}Entrevistado;
/*Prototipos para funções principais*/
void pesquisa();
void entrevista(Questao questoes[],Escala escalas[], int qtd_questoes,int qtd_escalas);
void tabela_frequencia();
void dados_estatisticos();
/*Funções de leitura dos arquivos de texto*/
Questao *leitura_de_dados_1(int *Total_questoes);
Escala *leitura_de_dados_2(int *Total_escalas);
Entrevistado *leitura_de_dados_3(int *Total_entrevistados);
/*Funções secundarias e de apoio*/
void agrupa_questoes_e_escalas(Questao questoes[],Escala escalas[], int qtd_questoes,int qtd_escalas);
void triagem(Entrevistado *pesquisado);
void imprime_escolhas(Escala *escalas_questao);
int separa_escala(char escalas[],char escala_saida[],int posicao_virgula);
void escreve_respostas(Entrevistado pesquisado,int qtd_questoes);
int **aloca_matriz(int linhas,int colunas);
int libera_matriz(int **matriz_alocada,int linhas,int colunas);
void conta_respostas(int** matriz_contadores,int qtd_questoes,int qtd_participantes, Entrevistado pesquisados[]);
void calcula_media(Entrevistado entrevistados[],int qtd_entrevistados,int qtd_questoes);
void imprime_moda(Entrevistado entrevistados[],Questao questoes[],int qtd_entrevistados,int qtd_questoes);
void calcula_moda(int** contadores,Entrevistado entrevistados[],Questao questoes[],int qtd_entrevistados,int qtd_questoes);
float calcula_escore(Entrevistado entrevistado,int qtd_questoes,int questoes[]);
void moda_escores(float escores[],int qtd_entrevistados);
/*Funções para os calculos de escores*/
void escore_individual(Entrevistado entrevistados[],int qtd_questoes,int qtd_entrevistados);
void escore_por_idade(Entrevistado entrevistados[],int qtd_questoes,int qtd_entrevistados);
void escore_sexo_curso(Entrevistado entrevistados[],int qtd_questoes,int qtd_entrevistados);
main(){
	int escolha_menu_principal;
		setlocale(LC_ALL,"portuguese");
		do{
			system("cls");
			printf("Escolha a opcao correspodente\n");
			printf("1-Realizar pesquisa\n2-Tabela de frequencia\n3-Estatisticas\n4-Sair da pesquisa\n");
			printf("Escolha: ");
			scanf("%d",&escolha_menu_principal);
			switch(escolha_menu_principal){
				case 1:
					pesquisa();//Chama a Função que realiza a pesquisa
					break;
				case 2:
					 tabela_frequencia(); //Chama a função que imprime a frequencia absoluta
					break;
				case 3:
					dados_estatisticos();//Chama a funcao para dados estatisticos
					break;
				case 4:
					//encerra o codigo o exit é opcional
					break;
				default:
					printf("Informe uma opcao valida");
					break;	
			}
		}while(escolha_menu_principal!=4);
	return 0;
}
/*Função leitura de dados 1
	Lê o arquivo de questões*/
Questao *leitura_de_dados_1(int *Total_questoes){
	Questao *questoes;
	FILE *arquivo_1;
	int i,j,qtd_questoes;
		if((arquivo_1=fopen("questoes.txt","r"))==NULL){
			printf("Arquivo nao pode ser aberto!!\n\n");
			exit(1);
		}
		qtd_questoes=50;
		questoes=(Questao*) malloc(qtd_questoes*sizeof(Questao));
		i=0;
		while((feof(arquivo_1))==0){
			fgets(questoes[i].pergunta,400,arquivo_1);
			fscanf(arquivo_1,"%d",&questoes[i].codigo_escala);
			fgetc(arquivo_1);
			i++;
			if(i>qtd_questoes){
				qtd_questoes*=2; //dobra a quantidade de questoes
				questoes=(Questao*) realloc(questoes,qtd_questoes*sizeof(Questao));
			}
		}
		fclose(arquivo_1);
		*Total_questoes=i;	//salva a quantidade total de perguntas
		/*aloca a quantidade exata de questões no vetor*/
		questoes=(Questao*) realloc(questoes,i*sizeof(Questao));
	return questoes;
}
/* Função leitura de dados 2
	Lê o arquivo com as escalas*/
Escala *leitura_de_dados_2(int *Total_escalas){
	Escala *escalas;
	FILE *arquivo_2;
	int i,j,qtd_escalas;
		if((arquivo_2=fopen("escalas.txt","r"))==NULL){
			printf("Arquivo nao pode ser aberto!!\n\n");
			exit(1);
		}
		qtd_escalas=20;
		i=0;
		j=0;
		escalas=(Escala*) malloc(qtd_escalas * sizeof(Escala));
		while((feof(arquivo_2))==0){
			fscanf(arquivo_2,"%d",&escalas[i].codigo_escala);
			fscanf(arquivo_2,"%d",&escalas[i].qtd_niveis);
			fgetc(arquivo_2);
			fgets(escalas[i].escalas,400,arquivo_2);
			i++;
			/*verifica se a quantidade estipulada de escalas foi ultrapassada*/
			if(i>qtd_escalas){
				qtd_escalas*=2;
				escalas=(Escala*) realloc(escalas,qtd_escalas * sizeof(Escala));
			}
		}
		fclose(arquivo_2);
		*Total_escalas=i;	//salva a quantidade total de escalas
		/*aloca a quantidade exata de escalas no vetor*/
		escalas=(Escala*) realloc(escalas,i*sizeof(Escala));
	return escalas;
}	
/*Função leitura de dados 3
 	Lê o arquivo com as respostas*/
Entrevistado *leitura_de_dados_3(int *Total_entrevistados){
	Entrevistado *entrevistados;
	FILE * arquivo_3;
	int i,j,k,qtd_entrevistados;
		if((arquivo_3=fopen("respostas.txt","r"))==NULL){
			printf("Arquivo nao pode ser aberto!!\n\n");
			exit(1);
		}
		qtd_entrevistados=50;
		entrevistados=(Entrevistado*) malloc(qtd_entrevistados *sizeof(Entrevistado));
		i=0;
		while((feof(arquivo_3))==0){
			fgets(entrevistados[i].curso,50,arquivo_3);
			fgets(entrevistados[i].sexo,10,arquivo_3);
			fscanf(arquivo_3,"%d",&entrevistados[i].idade);
			for(j=0;j<15;j++){
				fscanf(arquivo_3,"%d ",&entrevistados[i].respostas[j]);
			}
			i++;
			if(i>qtd_entrevistados){
				qtd_entrevistados*=2;
				entrevistados=(Entrevistado*) realloc(entrevistados,qtd_entrevistados* sizeof(Entrevistado));
			}
		}
		fclose(arquivo_3);
		*Total_entrevistados=i;	//salva a quantidade total de entrevistados
		/*aloca a quantidade exata de entrevistados no vetor*/
		entrevistados=(Entrevistado*) realloc(entrevistados,i*sizeof(Entrevistado));
	return entrevistados;
}
/*Função pesquisa
	Realiza a pesquisa*/
void pesquisa(){
	Questao *questoes;
	Escala *escalas;
	int i,j,apoio,qtd_questoes,qtd_escalas,qtd_entrevistados;
		/*recebe os dados de entrada*/
		questoes=leitura_de_dados_1(&qtd_questoes);
		escalas=leitura_de_dados_2(&qtd_escalas);
		agrupa_questoes_e_escalas(questoes,escalas,qtd_questoes,qtd_escalas);	//linka as questões com suas referentes escalas
		/*realiza a entrevista*/
		system("cls");
		entrevista(questoes,escalas,qtd_questoes,qtd_escalas);
		free(questoes);
		free(escalas);
}
/*Função tabela de frequencia
	imprime na tela a frequecia absoluta para cada questao*/
void tabela_frequencia(){
	Questao *questoes;
	Escala *escalas;
	Entrevistado *entrevistados;
	int qtd_questoes,qtd_escalas,qtd_entrevistados;
	int i,j,**contadores_frequencia,nivel_concordancia;	
		
		questoes=leitura_de_dados_1(&qtd_questoes);
		escalas=leitura_de_dados_2(&qtd_escalas);
		entrevistados=leitura_de_dados_3(&qtd_entrevistados);
		agrupa_questoes_e_escalas(questoes,escalas,qtd_questoes,qtd_escalas);
		contadores_frequencia=aloca_matriz(qtd_questoes,10);
		conta_respostas(contadores_frequencia,qtd_questoes,qtd_entrevistados,entrevistados);
		for(i=0;i<qtd_questoes;i++){
			printf("numero das alternativas\n1 2 3 4 5 6 7 8 9 10\n");
			puts("--------------------------------------");
			for(j=0;j<10;j++){
				printf("%d ",contadores_frequencia[i][j]);
			}			
			printf("\n");
			imprime_escolhas(questoes[i].escala_questao);
			system("pause");
			system("cls");
		}
		/*libera a memoria armazenada dinamicamente*/
		free(questoes);
		free(escalas);
		free(entrevistados);	
		libera_matriz(contadores_frequencia,qtd_questoes,10);
}
/*Função dados estatisticos
	reponssavel pelo calculo dos escores individuais,por cartegoria */
void dados_estatisticos(){
	int escolha_menu,qtd_entrevistados,qtd_questoes,qtd_escalas;
	Entrevistado *entrevistados;
	Questao *questoes;
	Escala *escalas;
		entrevistados=leitura_de_dados_3(&qtd_entrevistados);
		questoes=leitura_de_dados_1(&qtd_questoes);
		escalas=leitura_de_dados_2(&qtd_escalas);
		agrupa_questoes_e_escalas(questoes,escalas,qtd_questoes,qtd_escalas);
		do{
			system("cls");
			printf("Escolha a opção\n1-Media aririmetica das questões\n2-Moda\n3-escores\n4-voltar ao menu\nescolha:");
			scanf("%d",&escolha_menu);
			switch(escolha_menu){
				case 1:
					calcula_media(entrevistados,qtd_entrevistados,qtd_questoes);
					break;
				case 2:
					imprime_moda(entrevistados,questoes,qtd_entrevistados,qtd_questoes);
					system("pause");
					break;
				case 3:
					system("cls");
					printf("Menu dos escores\n1-escores individuais\n2-escores por faixa de idade\n3-escores por sexo ou curso\n4-sair do menu\nescolha:");
					scanf("%d",&escolha_menu);
					switch(escolha_menu){
						case 1:
							system("cls");
							escore_individual(entrevistados,qtd_questoes,qtd_entrevistados);
							system("pause");
							break;
						case 2:
							system("cls");
							escore_por_idade(entrevistados,qtd_questoes,qtd_entrevistados);
							system("pause");
							break;
						case 3:
							escore_sexo_curso(entrevistados,qtd_questoes,qtd_entrevistados);
							system("cls");
							break;
						case 4:
							break;
					}
					break;
				case 4: 
					break;
			}
		}while(escolha_menu!=4);
		free(entrevistados);
		free(questoes);
		free(escalas);
}
/*Função entrevista*
	Realiza a entrevista */
void entrevista(Questao questoes[],Escala escalas[], int qtd_questoes,int qtd_escalas){
	int i,j,continuar;
	Entrevistado pesquisado;
		triagem(&pesquisado);
		system("cls");
		/*imprime cada questão e espera a resposta*/
		for(i=0;i<qtd_questoes;i++){
				system("cls");
				printf("%d-)%s",i+1,questoes[i].pergunta);
				imprime_escolhas(questoes[i].escala_questao);
				printf("escolha: ");
				scanf("%d",&pesquisado.respostas[i]);
		}
		system("cls");
		escreve_respostas(pesquisado,qtd_questoes);
}
/*Função agrupa questoes e escalas
 	coloca em cada struct questao o ponteiro para a escala referente a ela*/
void agrupa_questoes_e_escalas(Questao questoes[],Escala escalas[], int qtd_questoes,int qtd_escalas){
	int i,j;
	/* primeiro laço serve para buscar a escala de cada questão*/
	 for(i=0;i<qtd_questoes;i++){
	 	/*o segundo laço busca a escala da questão que está no indicie i*/
	 	for(j=0;j<qtd_escalas;j++){
	 		if(questoes[i].codigo_escala==escalas[j].codigo_escala){
	 			questoes[i].escala_questao=&escalas[j];
	 			break;
			 } 
		 }
	 }
}
/*Função triagem
	realiza o cadastro dos dados dermograficos*/
void triagem(Entrevistado *pesquisado){
	int i,controle_do_laco=0;
	char sexo,cursos[28][100];
	FILE *arquivo_4;
		/*leitura do arquivo de texto com os cursos*/
		if((arquivo_4=fopen("cursos.txt","r"))==NULL){
			printf("Erro na abertura do arquivo!!");
			exit(1);
		}
		for(i=0;i<28;i++){
			fgets(cursos[i],100,arquivo_4);
		}
		fclose(arquivo_4); 	//fim da leitura
		do{		//leitura da idade
			printf("Informe sua idade: ");
			scanf("%d",&pesquisado->idade);
			getchar();
			controle_do_laco++;
		}while(controle_do_laco==0);
		system("cls");
		do{		//leitura do sexo
			printf("informe seu sexo\n[M]-Masculino\n[F]-Feminino\nEscolha:");
			scanf("%c",&sexo);
			getchar();
			switch(sexo){
				case 'M':
					strcpy(pesquisado->sexo,"masculino");
					controle_do_laco++;
					break;
				case 'F':
					strcpy(pesquisado->sexo,"feminino");
					controle_do_laco++;
					break;
				default:
					printf("\n\nDigite M ou F!!\n\n");
					break;		
			}
		}while(controle_do_laco==1);
		system("cls");
			for(i=0;i<28;i++){  //leitura do curso
				printf("%s",cursos[i]);
			}
			printf("\nEscreva o seu curso(da mesma maneira que o exemplo acima)\n->");
			gets(pesquisado->curso);
			getchar();
}
/*Função imprime escala questão
	Imprime os niveis de concorancia da questao*/
void imprime_escolhas(Escala *escalas_questao){
	int i,posicao_virgula=0;
	char escala_separada[100];	
		for(i=0;i<escalas_questao->qtd_niveis;i++){
			printf("|%d|",i+1);
			posicao_virgula=separa_escala(escalas_questao->escalas,escala_separada,posicao_virgula);
			printf("%s\n",escala_separada);
		}
}
/*Função separa escalas
	separa a escala até a virgula e retorna a posição da virgula*/
int separa_escala(char escalas[],char escala_saida[],int posicao_virgula){
	int i,j;
		if(escalas[i]=='\0')
			return 0; //indica o fim da string
		else if(posicao_virgula==0)
			i=0;
		else
			i=posicao_virgula+1;
		/*busca a posição da virgula*/
		j=0;
		while(escalas[i]!=',' && escalas[i]!='\0'){
			escala_saida[j]=escalas[i];
			i++;
			j++;
		}
		escala_saida[j]='\0';
		if(escalas[i]==',')
			return i;	//retorna a posição da virgula;
		else
			return 0; 	//retorna zero indicando que a string terminou
}
/* Função escreve respostas
	Anexa no arquivo de respostas uma entrevista realizada*/
void escreve_respostas(Entrevistado pesquisado,int qtd_questoes){
	FILE *arquivo_3;
	int i,j;
		if((arquivo_3=fopen("respostas.txt","a"))==NULL){
			printf("Erro na abertura do arquivo\n\n");
			exit(1);
		}
		fprintf(arquivo_3,"\n%s\n",pesquisado.curso);
		fprintf(arquivo_3,"%s\n",pesquisado.sexo);
		fprintf(arquivo_3,"%d\n",pesquisado.idade);
		for(i=0;i<qtd_questoes;i++){
			fprintf(arquivo_3,"%d ",pesquisado.respostas[i]);
		}
		fclose(arquivo_3);
}
/*Função aloca matriz
	aloca dinamicamente uma matriz de tamanho m x n onde m é o numero de linhas e n o de colunas*/
int **aloca_matriz(int linhas,int colunas){
	int **matriz;	//esta é uma matriz de ponteiros para o tipo inteiro
	int i,j;
		matriz=(int**) malloc(linhas*sizeof(int*));	//é alocada o total de linhas da matriz
		for(i=0;i<linhas;i++){
			matriz[i]=(int*) calloc(colunas,sizeof(int));
		}
	return matriz;
}
/*Função libera matriz
	libera a memoria armazenada na matriz*/
int libera_matriz(int **matriz_alocada,int linhas,int colunas){
	int i;
		for(i=0;i<linhas;i++){
			free(matriz_alocada[i]);
		}
		free(matriz_alocada);
	return 0;
}	
/* Função conta respostas
	incrementa os contadores*/
void conta_respostas(int** matriz_contadores,int qtd_questoes,int qtd_participantes, Entrevistado pesquisados[]){
	int i,j,nivel_concordancia;
		for(i=0;i<qtd_questoes;i++){
			for(j=0;j<qtd_participantes;j++){
				nivel_concordancia=(pesquisados[j].respostas[i])-1;	//busca a posição da resposta
				matriz_contadores[i][nivel_concordancia]++;	//incrementa o contador 
			}
		}	
}
/*Função calcula media
	calcula a media aritimetica para cada questão*/
void calcula_media(Entrevistado entrevistados[],int qtd_entrevistados,int qtd_questoes){
	int questao,entrevistado,i;
	float *medias;
		medias=(float*) calloc(qtd_questoes,sizeof(float));
		for(questao=0;questao<qtd_questoes;questao++){
			for(entrevistado=0;entrevistado<qtd_entrevistados;entrevistado++){
				medias[questao]+=entrevistados[entrevistado].respostas[questao];	//cada vez adiciona a resposta de um entrevistado para a mesma questão
			}
			medias[questao]/=qtd_entrevistados;
		}
		/*imprime as medias*/
		for(i=0;i<qtd_questoes;i++){
			printf("Media da questão %d:%.2f\n",i+1,medias[i]);
		}
		free(medias);
		system("pause");
}
/*Função imprime moda
	imprime a moda das questoes*/
void imprime_moda(Entrevistado entrevistados[],Questao questoes[],int qtd_entrevistados,int qtd_questoes){
	int i,j,**contadores;
		contadores=aloca_matriz(qtd_questoes,10);
		calcula_moda(contadores,entrevistados,questoes,qtd_entrevistados,qtd_questoes);
		libera_matriz(contadores,qtd_questoes,10);
}
/*Função calcula moda
	calcula e retorna a moda de cada questão*/
void calcula_moda(int** contadores,Entrevistado entrevistados[],Questao questoes[],int qtd_entrevistados,int qtd_questoes){
	int i,j,k,*maior,**modas;
		maior=(int*) malloc(qtd_questoes*sizeof(int));
		modas=aloca_matriz(qtd_questoes,10);
		conta_respostas(contadores,qtd_questoes,qtd_entrevistados,entrevistados);
		for(i=0;i<qtd_questoes;i++){ //busca o maior elemento da matriz
			maior[i]=contadores[i][0];
			for(j=0;j<10;j++){
				if(contadores[i][j]>=maior[i]){
					maior[i]=contadores[i][j];
				}
			}
		}
		for(i=0;i<qtd_questoes;i++){
			k=0;
			for(j=0;j<10;j++){
				if(contadores[i][j]==maior[i]){	// se o contador for igual a maior essa alternativa é moda da questão
					modas[i][k]=j+1;
					k++;
				}
			}
		}
		for(i=0;i<qtd_questoes;i++){	//imprime a moda de cada questão
			j=0;
			while(modas[i][j]!=0){
				printf("A questão %d tem a alternativa %d como moda\n",i+1,modas[i][j]);
				j++;
			}
			imprime_escolhas(questoes[i].escala_questao);
			system("pause");
			system("cls");
		}
		free(maior);
		libera_matriz(modas,qtd_questoes,10);
}
/*Função escores individual
	calcula o escores individual de cada entrevistado*/
void escore_individual(Entrevistado entrevistados[],int qtd_questoes,int qtd_entrevistados){
	int i,j,total_questoes,*questoes;
	float *escores,media_escores=0;
		printf("informe o total de questões para o escores");
		scanf("%d",&total_questoes);
		questoes=(int*) malloc(total_questoes*sizeof(int));
		for(i=0;i<total_questoes;i++){
			printf("Informe o numero da questão %d para o escore:",i+1);
			scanf("%d",&questoes[i]);
		}
		system("cls");
		escores=(float*) calloc(qtd_entrevistados,sizeof(float));
		for(i=0;i<qtd_entrevistados;i++){
			for(j=0;j<total_questoes;j++){
				escores[i]+=entrevistados[i].respostas[(questoes [j]-1)];
			}
			escores[i]/=total_questoes;
			puts("--------------------------------------------------");
			printf("escore do entrevistado %d é:%.2f\n",i+1,escores[i]);
			media_escores+=escores[i];	//a variavel acumula os valores do escore para depois ser calculada a media;
		}
		media_escores/=qtd_entrevistados;
		puts("--------------------------------------");
		printf("Media dos escores de cada participante é:%.2f\n",media_escores);
		moda_escores(escores,qtd_entrevistados);
		free(escores);
		free(questoes);
}
/*Função escores por idade
 	calcula os escores para uma determinada faixa etaria de idade*/
void escore_por_idade(Entrevistado entrevistados[],int qtd_questoes,int qtd_entrevistados){
	int i,j,total_questoes,idade_minima,idade_maxima,*questoes;
	int indicie;
	float *escores,media_escores=0;
		printf("informe o total de questões para o escores:");	//pergunta o total de questões para o escore
		scanf("%d",&total_questoes);
		questoes=(int*) malloc(total_questoes*sizeof(int));
		for(i=0;i<total_questoes;i++){	//pergunta e armazena as questões para o calculo dos escores
			printf("Informe o numero da questão %d para o escore:",i+1);
			scanf("%d",&questoes[i]);
		}
		printf("\n\n informe a idade minima da faixa:");
		scanf("%d",&idade_minima); // recebe o extremo menor da faixa
		printf("\n informe a idade maxima da faixa");
		scanf("%d",&idade_maxima);	//recebe o extremao maior da faixa
		system("cls");
		escores=(float*) calloc (qtd_entrevistados,sizeof(float));
		indicie=0;
		for(i=0;i<qtd_entrevistados;i++){
			if(entrevistados[i].idade>=idade_minima && entrevistados[i].idade<=idade_maxima){
				escores[indicie]=calcula_escore(entrevistados[i],total_questoes,questoes);
				media_escores+=escores[indicie];
				indicie++;
			}
		}
		media_escores/=indicie;
		for(i=0;i<indicie;i++){
			puts("-----------------------------");
			printf("escore do participante %d da faixa é:%.2f\n",i+1,escores[i]);
		}
		printf("A media dos escores é:%.2f\n",media_escores);
		moda_escores(escores,indicie);
		free(escores);
		free(questoes);
}
/*Função escores por sexo e curso
	leva ao menu para escolher a cartegoriqa em que o escore é calculado*/
void escore_sexo_curso(Entrevistado entrevistados[],int qtd_questoes,int qtd_entrevistados){
	int i,j,total_questoes,escolha_menu,comparacao=0,*questoes,indicie,escolha,controle=0;
	float *escores,media_escores=0;
	char cursos[28][100],curso[100],sexo[20],escolha_sexo;
	FILE *arquivo_4;
		/*leitura do arquivo de texto com os cursos*/
		if((arquivo_4=fopen("cursos.txt","r"))==NULL){
			printf("Erro na abertura do arquivo!!");
			exit(1);
		}
		for(i=0;i<28;i++){
			fgets(cursos[i],100,arquivo_4);
		}
		/*Pegunta e salva o total de questões e as questões*/
		printf("informe o total de questões para o escores:");	//pergunta o total de questões para o escore
		scanf("%d",&total_questoes);
		questoes=(int*) malloc(total_questoes*sizeof(int));
		for(i=0;i<total_questoes;i++){	//pergunta e armazena as questões para o calculo dos escores
			printf("Informe o numero da questão %d para o escore:",i+1);
			scanf("%d",&questoes[i]);
		}
		system("cls");
		escores=(float*) calloc(qtd_entrevistados,sizeof(float));
		/*Menu para escolha da cartegoria*/
		printf("1-escore por curso\n2-escore por sexo\nescolha:");
		scanf("%d",&escolha_menu);
		getchar();
		indicie=0;
		switch(escolha_menu){
			case 1:
				printf("Escolha o curso:");
				for(i=0;i<28;i++){
					printf("%s\n",cursos[i]);
				}
					gets(curso);
					strcat(curso,"\n");
					system("cls");
					for(i=0;i<qtd_entrevistados;i++){
						if((comparacao=strcmp(entrevistados[i].curso,curso))==0){
							escores[indicie]=calcula_escore(entrevistados[i],total_questoes,questoes);
							media_escores+=escores[indicie];
							indicie++;
						}
					}
					if(indicie!=0)
						media_escores/=indicie;
					for(i=0;i<indicie;i++){
						printf("escore do entrevistado %d é:%.2f\n",i+1,escores[i]);
					}
					if(indicie!=0){
						printf("\nA media dos escores eh %.2f\n",media_escores);
						moda_escores(escores,indicie);
					}
					system("pause");
				break;
			case 2:
				system("cls");
				do{
					printf("informe seu sexo\n[M]-Masculino\n[F]-Feminino\nEscolha:");
					scanf("%c",&escolha_sexo);
					getchar();
					switch(escolha_sexo){
						case 'M':
							strcpy(sexo,"masculino");
							controle++;
							break;
						case 'F':
							strcpy(sexo,"feminino\n");
							controle++;						
						break;
					default:
						printf("\n\nDigite M ou F!!\n\n");
						break;		
					}
				}while(controle==0);
				system("cls");
				for(i=0;i<qtd_entrevistados;i++){
					if((comparacao=strcmp(entrevistados[i].sexo,sexo))==0){
						escores[indicie]=calcula_escore(entrevistados[i],total_questoes,questoes);
						media_escores+=escores[indicie];
						indicie++;
					}
				}
				if(indicie!=0)
					media_escores/=indicie;
				for(i=0;i<indicie;i++){
					printf("escore do entrevistado %d é:%.2f\n",i+1,escores[i]);
				}
				if(indicie!=0){
					printf("\nA media dos escores eh %.2f\n",media_escores);
					moda_escores(escores,indicie);
				}
					
				system("pause");
				break;
		}	
		free(questoes);	
		free(escores);
}
/*Função calcula escores
	calcula escores de questões especificas*/
float calcula_escore(Entrevistado entrevistado,int qtd_questoes,int questoes[]){
	int i,j;
	float escore=0;
		for(i=0;i<qtd_questoes;i++){
			escore+=entrevistado.respostas[(questoes[i]-1)];
		}
		escore/=qtd_questoes;
	return escore;
}
/*Função moda escores
	calcula a moda dos escores*/
void moda_escores(float escores[],int qtd_entrevistados){
	float *escores_absolutos,escore;
	int i,j,parada,cont=0,*contadores,maior;
		escores_absolutos=(float*) calloc(qtd_entrevistados,sizeof(float));
		/*separa os valores repitidos do escore*/
		for(i=0;i<qtd_entrevistados;i++){
			escore=escores[i];
			j=0;
			parada=0;
			while(parada==0){
				if(escore==escores_absolutos[j])
					parada++;
				else if(escore!=escores_absolutos[j] && escores_absolutos[j]==0){
					escores_absolutos[j]=escore;
					parada++;
					cont++;
				}
				else
					j++;
			}
		}
		/*preenche os contadores*/
		contadores=(int*) calloc(cont,sizeof(int));
		for(i=0;i<cont;i++){
			for(j=0;j<qtd_entrevistados;j++){
				if(escores[j]==escores_absolutos[i])
					contadores[i]++;
			}
		}
		/*Busca o maior elemento do vetor*/
		maior=contadores[0];
		for(i=0;i<cont;i++){
			if(contadores[i]>maior){
				maior=contadores[i];
			}
		}
		for(i=0;i<cont;i++){
			if(contadores[i]==maior){
				printf("A moda dos escores eh %.2f\n",escores[i]);
			}
		}
		free(escores_absolutos);
		free(contadores);
}
