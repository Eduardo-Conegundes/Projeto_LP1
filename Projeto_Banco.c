#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define deposito(a,b) ((a)+(b))
#define pagamento(a,b) ((a)-(b))
#define saque(a,b) ((a)-(b))


struct dados_operacao{
    char operacao[30];
    float valor;
};
struct dados_operacao banco;

typedef struct{
    char titular[30];
    int conta;
    float saldo;
    struct dados_operacao banco[100];
}dados_cliente;
dados_cliente pessoa[100];

int menu();
void extrato (dados_cliente x[],int y,int z);
void cadastro(dados_cliente x[],int y);

int main(){
    int opcao,conta_cad=0,conta,op_bank=0,i,j;
    do{
        system("cls");
        printf("===BEM VINDO===\n");
        printf("Digite a opcao desejada:\n");
        opcao=menu();
        switch(opcao){
            case 1:{
                system("cls");
                printf("===CADASTRO===\n");
                cadastro(pessoa,conta_cad);
                conta_cad++;
                system("pause");
            break;
            }
            case 2:{
				system("cls");
				printf("===SAQUE===\n");
				if(conta_cad==0){
					printf("NENHUM CADASTRO ENCONTRADO!\n");
    			}else{
					printf("Numero da conta: ");
					scanf("%d",&conta);
			        for(i=0;i<=conta_cad-1;i++){
						if(conta==pessoa[i].conta){
							strcpy(pessoa[i].banco[op_bank].operacao,"SAQUE");
							printf("Digite o valor do saque: ");
							scanf("%f",&pessoa[i].banco[op_bank].valor);
							pessoa[i].saldo=saque(pessoa[i].saldo,pessoa[i].banco[op_bank].valor);
						    system("cls");
							printf("OPERACAO FOI FINALIZADA COM EXITO\n");
							op_bank++;
						}
						
					}
				}
				system("pause");
            break;
            }
            case 3:{
            	system("cls");
				printf("===DEPOSITO===\n");
				if(conta_cad==0){
					printf("NENHUM CADASTRO NO SISTEMA!\n");
    			}else{
					printf("Numero da conta: ");
					scanf("%d",&conta);
					for(i=0;i<=conta_cad-1;i++){
						if(conta==pessoa[i].conta ){
							strcpy(pessoa[i].banco[op_bank].operacao,"DEPOSITO");
							printf("Digite o valor do deposito:   ");
							scanf("%f",&pessoa[i].banco[op_bank].valor);
							pessoa[i].saldo=deposito(pessoa[i].saldo,pessoa[i].banco[op_bank].valor);
			                system("cls");
							printf("OPERACAO FOI FINALIZADA COM EXITO\n");
							op_bank++;
						}
						
					}
				}
				system("pause");
			break;
			}
			case 4:{
				system("cls");
				printf("===PAGAR===\n");
				if(conta_cad==0){
					printf("NENHUM CADASTRO NO SISTEMA!\n");
    			}else{
    				printf("Numero da conta: ");
					scanf("%d",&conta);
					for(i=0;i<=conta_cad-1;i++){
						if(conta==pessoa[i].conta ){
							strcpy(pessoa[i].banco[op_bank].operacao,"PAGAMENTO");
							printf("Digite o valor do pagamento: ");
							scanf("%f",&pessoa[i].banco[op_bank].valor);
							pessoa[i].saldo=pagamento(pessoa[i].saldo,pessoa[i].banco[op_bank].valor);
						    system("cls");
							printf("OPERACAO FINALIZADA COM EXITO\n");
							op_bank++;
						}
				
					}
				}
				system("pause");
			break;
			}
			case 5:{
				system("cls");
				printf("===EXTRATO===\n");
				extrato(pessoa,conta_cad,op_bank);
				system("pause");
			break;
			}
			case 6:{
				system("cls");
				printf("===LISTAR===\n");
				if(conta_cad==0){
					printf("NENHUM CADASTRO ENCONTRADO!\n");
    			}else{
    				printf("Clientes cadastrados:\n");
					for(i=0;i<=conta_cad-1;i++){
						printf("Nome: %s\n",pessoa[i].titular);
					}
				}
				system("pause");
			break;
			}
			case 0:{
				system("cls");
				printf("SAINDO...\n");
				system("pause");
			break;
			}
			default:{
				printf("Opcao nao permitida!\n");
				break;
			}
        }
    }while(opcao!=0);
return 0;
}
int menu(){
    int op;
    printf("[1]CADASTRO\n[2]SAQUE\n[3]DEPOSITO\n[4]PAGAMENTO\n[5]EXTRATO\n[6]LISTAR\n[0]SAIR\n---> ");
    scanf("%d",&op);
    return op;
}
void cadastro (dados_cliente x[],int y){
    printf("Digite o nome do cliente: ");
    fflush(stdin);
    gets(x[y].titular);
    printf("Digite o numero da sua conta: ");
    scanf("%i", &x[y].conta);
    printf("Digite o valor que deseja iniciar sua conta: ");
    scanf("%f",&x[y].saldo);
    if(x[y].saldo>0){
    	printf("Cadastro realizado!\n");
	}
}

void extrato (dados_cliente x[],int y,int z){
	int conta,senha,i,j,teste=0;
	if(y==0){
		printf("NENHUM CADASTRO ENCONTRADO\n");
  	}else{
		printf("Numero da conta: ");
		scanf("%d",&conta);
		for(i=0;i<=y-1;i++){
			if(conta==x[i].conta){
				system("cls");
				printf("===EXTRATO===\n\n");
				for(j=0;j<=z-1;j++){
					printf("Foi feito um %s com valor de R$ %.2f\n",x[i].banco[j].operacao, x[i].banco[j].valor);
					teste++;
				}
				if(teste==0){
					printf("Nenhuma operacao foi realizada!");
				}
				printf("\nSALDO DE: %.2f\n",x[i].saldo);
				printf("\nFINALIZANDO...\n");
			}
		}
	}
}
