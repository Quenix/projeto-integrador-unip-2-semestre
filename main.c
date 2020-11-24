#include <stdio.h>
#include <stdlib.h>
#define PACIENTES 200
#define UNIDADES 200
#define AGENDAMENTOS 200
#define MEDICOS 200

char login[15] = "admin";
char senha[15] = "we23we23";

char inputLogin[15];
char inputSenha[15];

int logado = 0;

int cod_paciente[PACIENTES];
char nome[PACIENTES][50];
char email[PACIENTES][50];
char cpf[PACIENTES][50];
int cod_unidade[PACIENTES];

int codigo[UNIDADES];
char unidade[UNIDADES][50];

char data_agendamento[AGENDAMENTOS][10];
int cod_paciente_agendamento[AGENDAMENTOS];
int cod_unidade_agendamento[AGENDAMENTOS];
int cod_medico_agendamento[AGENDAMENTOS];

char nome_medico[MEDICOS][50];
int cod_unidade_medico[MEDICOS];

//Mostrar o cabeçalho do sistema
void mostrarCabecalho()
{
    printf("*************************************\n\n");
    printf("******SISTEMA DA CLINICA UNITA*******\n\n");
    printf("*************************************\n\n");
}

//Função para efetuar login no sistema
//@return int
int efetuarLogin(inputLogin, inputSenha)
{

    if(strcmp(inputLogin, login) == 0 && strcmp(inputSenha, senha) == 0)
    {
        printf("Senha bateu");

        //LOGIN REALIZADO COM SUCESSO
        return 1;
    }
    else
    {

        //DADOS INCORRETOS
        printf("Dados incorretos. Tente novamente.\n\n");
        printf("Pressione ENTER para continuar.\n");

        getch(); //Pressionar o ENTER para continuar

        system("cls"); //Limpar a tela

        return 0;
    }
}

void cadastrarUnidades(){
    static int linha;

    codigo[0] = 1;
    strcpy(unidade[0], "Santo Amaro");


    codigo[1] = 2;
    strcpy(unidade[1], "Albert Einstein");

    codigo[2] = 3;
    strcpy(unidade[2], "Adalberto Ferreira");

}

void listarUnidades(){
    int i;
    for(i = 0; i < UNIDADES; i++){
        if(strlen(unidade[i]) > 0){
            printf("\n\n");

            printf("Codigo: %d \n", codigo[i]);
            printf("Unidade: %s \n", unidade[i]);

            printf("\n\n");
        }else{

        }
    }
}

void cadastrarMedico(){
    static int linha;

    printf("Digite o nome do medico: ");
    scanf("%s", nome_medico[linha]);

    printf("Digite o codigo da unidade do medico: ");
    scanf("%d", &cod_unidade_medico);

}

void listarMedicos(){
    int i;
    for(i = 0; i < MEDICOS; i++){
        if(strlen(nome_medico[i]) > 0){
            printf("\n\n");

            printf("Medico: %s \n", nome_medico[i]);
            printf("Unidade: %d \n", cod_unidade_medico[i]);

            printf("\n\n");
        }else{

        }
    }
}

void listarAgendamentos(){
int i;
    for(i = 0; i < AGENDAMENTOS; i++){
        if(strlen(data_agendamento[i]) > 0){
            printf("\n\n");

            printf("Data: %s \n", data_agendamento[i]);
            printf("Paciente: %d \n", cod_paciente_agendamento[i]);
            printf("Medico: %d \n", cod_medico_agendamento[i]);
            printf("Unidade: %d \n", cod_unidade_agendamento[i]);

            printf("\n\n");
        }else{

        }
    }
}

void cadastrarAgendamento(){
    static int linha;
    printf("Digite o codigo do paciente: ");
    scanf("%d", &cod_paciente_agendamento[linha]);

    printf("Digite o codigo da unidade: ");
    scanf("%d", &cod_unidade_agendamento[linha]);

    printf("Digite o codigo do medico responsavel: ");
    scanf("%d", &cod_medico_agendamento[linha]);

    printf("Digite a data do agendamento no formato dd/mm/yyyy: ");
    scanf("%s", &data_agendamento[linha]);
}

void cadastrarPaciente(){
    static int linha;

    printf("Digite o codigo do paciente: ");
    scanf("%d", &cod_paciente[linha]);

    printf("Digite o nome do paciente: ");
    scanf("%s", nome[linha]);

    printf("Digite o email do paciente: ");
    scanf("%s", email[linha]);

    printf("Digite o CPF do paciente: ");
    scanf("%s", cpf[linha]);

    printf("Digite o codigo da unidade do paciente: ");
    scanf("%d", &cod_unidade[linha]);

    linha++;

}

void listarPacientes(){
    int i;
    for(i = 0; i < PACIENTES; i++){
        if(strlen(nome[i]) > 0){
            printf("\n\n");

            printf("Codigo: %d \n", cod_paciente[i]);
            printf("Nome: %s \n", nome[i]);
            printf("Email: %s \n", email[i]);
            printf("CPF: %s \n", cpf[i]);
            printf("Unidade: %d \n", cod_unidade[i]);

            printf("\n\n");
        }else{

        }
    }
}

void opcaoEscolhida(opcao)
{
    switch(opcao){
    case 0:
        logado = 0;
        printf("Obrigado e ate a proxima!");
        getch();

        break;

    case 1:
        cadastrarPaciente();
        break;

    case 2:
        listarPacientes();
        break;

    case 3:
        cadastrarAgendamento();
        break;

    case 4:
        listarAgendamentos();
        break;

    case 5:
        cadastrarMedico();
        break;

    case 6:
        listarMedicos();
        break;

     case 7:
        listarUnidades();
    break;

    default :
        printf ("Valor invalido!\n");
    }

}

int main()
{

    while(logado != 1)
    {
        mostrarCabecalho();

        printf("Informe o seu login:");
        scanf("%s", inputLogin);

        printf("Informe a sua senha:");
        scanf("%s", inputSenha);

        logado = efetuarLogin(inputLogin, inputSenha);

    }

    while(logado == 1)
    {
        mostrarCabecalho();
        cadastrarUnidades();

        int opcao;

        printf("1) - CADASTRO DE PACIENTES\n");
        printf("2) - LISTAR PACIENTES\n");

        printf("3) - CADASTRO DE AGENDAMENTOS\n");

        printf("5) - CADASTRO DE MEDICOS\n");
        printf("6) - LISTAR MEDICOS\n");

        printf("7) - LISTAR UNIDADES DA REDE\n");

        printf("0) - SAIR DO SISTEMA\n\n");
        printf("DIGITE A OPCAO DESEJADA: ");

        scanf("%d", &opcao);

        opcaoEscolhida(opcao);
    }

    return 0;
}
