#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int registrar_()
{
    /* Tem a Funão de criar os Arquivos com os dados */

    setlocale(LC_ALL, "Portuguese");

    /// Variaveis da Função
    char cpf[15];
    char nome[20];
    char sobrenome[40];
    char cargo[40];
    char gmail[40];
    char telefone[15];

    char arquivo[15];

    /// Menu Registro Nomes
    printf("+===================+\n");
    printf("I  Registro Nomes   I\n");
    printf("+===================+\n");

    /// Criar Arquivo e Ler CPF
    printf("Digite o CPF: ");
    scanf("%s", cpf);

    /// Ver se Arquivo Existe
    strcpy(arquivo, cpf);
    FILE *file;
    file = fopen(arquivo,"r");

    if (file != NULL)
    {
        printf("O CPF Digitado já Existe\n");
        file = fclose(file);
    }
    else
    {
        file = fclose(file); /// Arquivo pra testar Existencia

        FILE *file;
        file = fopen(arquivo, "w"); /// Escrevendo Arquivo

        /// Criando Usuário
        fprintf(file, cpf);
        fprintf(file, "^");

        printf("Digite o Nome do Usuário: ");
        scanf("%s", nome);
        fprintf(file, nome);
        fprintf(file, "^");

        printf("Digite o Sobrenome do Usuário: ");
        scanf("%s", sobrenome);
        fprintf(file, sobrenome);
        fprintf(file, "^");

        printf("Digite o cargo do Usuário: ");
        scanf("%s", cargo);
        fprintf(file, cargo);
        fprintf(file, "^");

        printf("Digite o Gmail do Usuário: ");
        scanf("%s", gmail);
        fprintf(file, gmail);
        fprintf(file, "^");

        printf("Digite o Telefone do Usuário: ");
        scanf("%s", telefone);
        fprintf(file, telefone);

        file - fclose(file);

        printf(" \n\n");
        printf("CPF Registrado com Éxito...\n");
    }


    system("pause");

}
int consutar_()
{
    /* Consulta os dados e mostra para o usuario*/

    setlocale(LC_ALL, "Portuguese");

    /// Variaveis da Função
    char cpf[15];
    char informacoesDes[200];
    char informacoescon[200];

    char *porteiro;


    /// Menu Consulta de nomes
    printf("+======================+\n");
    printf("I  Consulta de nomes   I\n");
    printf("+======================+\n");
    printf("Digite o CPF para Consultar: ");
    scanf("%s", cpf);


    /// ver se Arquivo Existe
    FILE *file;
    file = fopen(cpf,"r");

    /// Caso não Exista
    if (file == NULL)
    {
        printf("Erro: CPF não encontrado...\n");
        file = fclose(file);
        system("pause");
    }
    /// Mostrando Infomaçoes
    else
    {
        while(fgets(informacoesDes, 200, file) != NULL) /// Criando Variavel
        {
            strcpy(informacoescon, informacoesDes);
        }


        /// Processo para Printar as Infomações
        printf("+======================+\n");
        printf("I     Informações      I\n");
        printf("+======================+\n");

        porteiro = strtok(informacoescon, "^");
        printf("+  CPF: %s\n", porteiro);

        porteiro = strtok(NULL, "^");
        printf("+  Nome: %s\n", porteiro);

        porteiro = strtok(NULL, "^");
        printf("+  Sobrenome: %s\n", porteiro);

        porteiro = strtok(NULL, "^");
        printf("+  Cargo: %s\n", porteiro);

        porteiro = strtok(NULL, "^");
        printf("+  Gmail: %s\n", porteiro);

        porteiro = strtok(NULL, "^");
        printf("+  Telefone: %s\n", porteiro);


        printf("+======================+\n\n");
        system("pause");
    }
}
int deletar_()
{
    /* Deleta os dados do usuario */

    /// Variaveis da Função
    char cpf[11];
    int sair=1;

    /// Menu Deletar Nomes
    printf("+===================+\n");
    printf("I   Deletar Nomes   I\n");
    printf("+===================+\n");

    while(sair == 1)
        {

        printf("Digite o CPF que quer deletar os dados: ");
        scanf("%s", cpf);

        /// Ver se CPF existe
        FILE *file;
        file = fopen(cpf, "r");

        if (file == NULL)
        {
            file = fclose(file);
            printf("O CPF não existe! \n");
        }

        else
        {
            file = fclose(file);
            remove(cpf);
            printf("Digite 1 se quiser apagar mais dados: ");
            scanf("%d", &sair);
        }
        }

}


int main()
{
    setlocale(LC_ALL, "Portuguese");

    /// variaveis do Programa
    int respostaMenu;
    int laco = 1;

    /// Menu Principal do Programa
    for (laco=1; laco==1;)
    {
        printf("\n");
        system("cls");
        printf("+======================+\n");
        printf("I         MENU         I\n");
        printf("+======================+\n");
        printf("I[1]  Registrar nomes  I\n");
        printf("I[2]  Consultar nomes  I\n");
        printf("I[3]   Deletar nomes   I\n");
        printf("I[4] Sair do Programa  I\n");
        printf("+======================+\n\n");

        /// Escolha de Opcões do Menu
        printf("Digite sua escolha: ");
        scanf("%d", &respostaMenu);

        /// Processo de Escolha de menu
        system("cls");
        switch(respostaMenu)
        {
            /// Processo para chamar as Funçoes
            case 1:
                registrar_();
                break;
            case 2:
                consutar_();
                break;
            case 3:
                deletar_();
                break;
            case 4:
                /// Fechamento do programa
                printf("+======================+\n");
                printf("+Obrigado por usa o Programa...\n");
                printf("+======================+\n");
                printf("I  Saindo do Programa  I\n");
                printf("+======================+\n");
                laco += 1;
                break;
            default:
                printf("Erro; Digite um Numero Valido...\n");
                system("pause");
                break;

        }
    }
        return 0;
}
