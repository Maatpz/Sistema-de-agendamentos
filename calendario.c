#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIAS 366

int AgendamentosPorDia[MAX_DIAS] = {0};

 void limparTela() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        }
        void desenharLinha(int largura) {
            for (int i = 0; i < largura; i++) {
                printf("-");
            }
            printf("\n");
        }
        void imprimirCentralizado(const char* texto, int largura) {
            int espacos = (largura - strlen(texto)) / 2;
            for (int i = 0; i < espacos; i++) {
                printf(" ");
            }
            printf("%s\n", texto);
        }
        void exibirCabecalho(const char* titulo) {
            limparTela();
            desenharLinha(60);
            imprimirCentralizado(titulo, 60);
            desenharLinha(60);
        }


int calendario(int ano, int diaInicio);
int calendarioComAgendamentos(int ano, int diaInicio);
int inserirAgendamento(int diaAgendamento, int mesAgendamento, int anoAgendamento, int diasTratamento);
int bisexto(int y);

int main(void) {
    int diaSemana = 0;
    int diasTratamento = 0;
    int anoAgendamento = 0;
    int diaAgendamento = 0;
    int mesAgendamento = 0;

    do {
        printf("Informe o 1º dia da semana de janeiro do ano atual! Digite 1-Domingo, 2-Segunda, 3-Terça, 4-Quarta, 5-Quinta, 6-Sexta, 7-Sábado: \n");
        scanf("%d", &diaSemana);
    } while (diaSemana < 1 || diaSemana > 7);

    printf("Digite o ano atual no formato YYYY: ");
    scanf("%d", &anoAgendamento);
    
    int opcao;
    do {
        exibirCabecalho("Menu Principal");
        printf("1. Mostrar calendário\n");
        printf("2. Inserir agendamento\n");
        printf("3. Mostrar calendário com agendamentos\n");
        printf("4. Sair\n");
        desenharLinha(60);
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirCabecalho("Calendário");
                calendario(anoAgendamento, diaSemana);
                break;
            case 2:
                exibirCabecalho("Inserir Agendamento");
                printf("Digite o ano do agendamento no formato YYYY: ");
                scanf("%d", &anoAgendamento);
                printf("Digite o mês do agendamento no formato MM: ");
                scanf("%d", &mesAgendamento);
                printf("Digite o dia do agendamento no formato DD: ");
                scanf("%d", &diaAgendamento);
                printf("Digite a duração do tratamento em dias: ");
                scanf("%d", &diasTratamento);
                inserirAgendamento(diaAgendamento, mesAgendamento, anoAgendamento, diasTratamento);
                break;
            case 3:
                exibirCabecalho("Calendário com Agendamentos");
                calendarioComAgendamentos(anoAgendamento, diaSemana);
            break;
            case 4:
                exibirCabecalho("Saindo");
                printf("Obrigado por usar o Sistema de Agendamentos!\n");
                break;
            default:
                exibirCabecalho("Erro");
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
        if (opcao != 4) {
            printf("\nPressione Enter para continuar");
            getchar(); 
            getchar();
        }
    } while (opcao != 4);

    return 0;
}

int calendario(int ano, int diaInicio) {
    const char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                           "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int diasnoMes[] = {31, 28 + bisexto(ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Calendario de %d:\n\n", ano);

    for (int mesNum = 0; mesNum < 12; mesNum++) {
        printf("%s\n", meses[mesNum]);
        printf(" Dom Seg Ter Qua Qui Sex Sab\n");
        
        for (int espacos = 0; espacos < diaInicio; espacos++) {
            printf("    ");
        }
        
        for (int diaAtual = 1; diaAtual <= diasnoMes[mesNum]; diaAtual++) {
            printf("%4d", diaAtual);
            if ((diaAtual + diaInicio) % 7 == 0 || diaAtual == diasnoMes[mesNum]) {
                printf("\n");
            }
        }
        
        diaInicio = (diaInicio + diasnoMes[mesNum]) % 7;
        printf("\n");
    }
    return 0;
}

int calendarioComAgendamentos(int ano, int diaInicio) {
    const char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", 
                           "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int diasnoMes[] = {31, 28 + bisexto(ano), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Calendario de %d com agendamentos:\n\n", ano);
    int numeroDoDiaNoAno = 1;

    for (int mesNum = 0; mesNum < 12; mesNum++) {
        printf("%s\n", meses[mesNum]);
        printf(" Dom Seg Ter Qua Qui Sex Sab\n");
        
        for (int espacos = 0; espacos < diaInicio; espacos++) {
            printf("    ");
        }
        
        for (int diaAtual = 1; diaAtual <= diasnoMes[mesNum]; diaAtual++) {
            printf("%4d", AgendamentosPorDia[numeroDoDiaNoAno-1]);
            if ((diaAtual + diaInicio) % 7 == 0 || diaAtual == diasnoMes[mesNum]) {
                printf("\n");
            }
            numeroDoDiaNoAno++;
        }
        
        diaInicio = (diaInicio + diasnoMes[mesNum]) % 7;
        printf("\n");
    }
    return 0;
}

int bisexto(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int inserirAgendamento(int diaAgendamento, int mesAgendamento, int anoAgendamento, int diasTratamento) {
    int mo[] = {31,28+bisexto(anoAgendamento),31,30,31,30,31,31,30,31,30,31};
    int numeroDiaDoAno = 0;

    for (int i = 0; i < (mesAgendamento-1); i++) {
        numeroDiaDoAno += mo[i];
    }

    numeroDiaDoAno += diaAgendamento;

    for (int i = 0; i < diasTratamento; i++) {
        if (numeroDiaDoAno - 1 + i >= MAX_DIAS) {
            printf("Erro: Tentativa de agendar além do limite do ano.\n");
            return 1;
        }
        if (AgendamentosPorDia[numeroDiaDoAno - 1 + i] < 5) {
            AgendamentosPorDia[numeroDiaDoAno - 1 + i]++;
        } else {
            printf("Não foi possível agendar seu atendimento para o dia %d/%d por conflito na Agenda. Por favor escolha outra data.\n\n", 
                   diaAgendamento + i, mesAgendamento);
        }
    }
    return 0;
}