#include <stdio.h>

int AgendamentosPorDia[366] = {0};
int diaAgendamento = 0; int mesAgendamento = 0; int anoAgendamento = 0;

int calendario(int ano, int diaInicio);
int calendarioComAgendamentos(int ano, int diaInicio);
int inserirAgendamento(int diaAgendamento, int mesAgendamento, int anoAgendamento, int diasTratamento);
int bisexto(int y);

int main(void){
    int diaSemana = 0;
    char anoBi;
    int diasTratamento = 0;

    // Dia semana e ano bissexto passados pelo usuário
    printf("Informe o 1º dia da semana de janeiro do ano atual! Digite 1-Domingo, 2-Segunda, 3-Terça: \n");
    scanf("%d", &diaSemana);
    printf("O ano atual é bissexto? Digite 's' para sim ou 'n' para não: ");
    scanf(" %c", &anoBi);

    // Verificar se o ano é bissexto
    if (anoBi == 's'){
        int anoAgendamento[366] = {0};
    }
    else{
        int anoAgendamento[365] = {0};
    }
    
    //loop em do-while do menu
    int opcao;
    do{
        printf("\n******Menu******\n");
        printf("1. Mostrar calendário\n");
        printf("2. Inserir agendamento\n");
        printf("3. Mostrar calendário com agendamentos\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            calendario(anoAgendamento, diaSemana);
            break;
        case 2:
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
            calendarioComAgendamentos(2024, 1);
            break;
        case 4:
            printf("Obrigado\n");
            break;
        }
    } while (opcao != 4);
}

// Função para exibir o calendario!
int calendario(int ano, int diaInicio){
    int diaAtual;
    int diasnoMes[12] = {31, 28 + (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Calendario de %d:\n\n", anoAgendamento);

    for (int mesNum = 0; mesNum < 12; mesNum++){
        if (mesNum == 0)
            printf("Janeiro\n");
        else if (mesNum == 1)
            printf("Fevereiro\n");
        else if (mesNum == 2)
            printf("Março\n");
        else if (mesNum == 3)
            printf("Abril\n");
        else if (mesNum == 4)
            printf("Maio\n");
        else if (mesNum == 5)
            printf("Junho\n");
        else if (mesNum == 6)
            printf("Julho\n");
        else if (mesNum == 7)
            printf("Agosto\n");
        else if (mesNum == 8)
            printf("Setembro\n");
        else if (mesNum == 9)
            printf("Outubro\n");
        else if (mesNum == 10)
            printf("Novembro\n");
        else if (mesNum == 11)
            printf("Dezembro\n");

        printf(" Dom Seg Ter Qua Qui Sex Sab\n");
        for (int espacos = 0; espacos < diaInicio; espacos++){
            printf("    ");
        }
        diaAtual = 1;

        while (diaAtual <= diasnoMes[mesNum]){
            printf("%4d", diaAtual);
            if ((diaAtual + diaInicio) % 7 == 0){
                printf("\n");
            }
            diaAtual++;
        }
        diaInicio = (diaInicio + diasnoMes[mesNum]) % 7;
        printf("\n\n");
    }
};

// Calendario com o agendamento!
int calendarioComAgendamentos(int ano, int diaInicio){
    int diaAtual;
    int diasnoMes[12] = {31, 28 + (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("Calendario de %d:\n\n", ano);
    int numeroDoDiaNoAno = 1;

    for (int mesNum = 0; mesNum < 12; mesNum++){
        if (mesNum == 0)
            printf("Janeiro\n");
        else if (mesNum == 1)
            printf("Fevereiro\n");
        else if (mesNum == 2)
            printf("Março\n");
        else if (mesNum == 3)
            printf("Abril\n");
        else if (mesNum == 4)
            printf("Maio\n");
        else if (mesNum == 5)
            printf("Junho\n");
        else if (mesNum == 6)
            printf("Julho\n");
        else if (mesNum == 7)
            printf("Agosto\n");
        else if (mesNum == 8)
            printf("Setembro\n");
        else if (mesNum == 9)
            printf("Outubro\n");
        else if (mesNum == 10)
            printf("Novembro\n");
        else if (mesNum == 11)
            printf("Dezembro\n");

        printf(" Dom Seg Ter Qua Qui Sex Sab\n");
        for (int espacos = 0; espacos < diaInicio; espacos++){
            printf("    ");
        }
        diaAtual = 1;

        while (diaAtual <= diasnoMes[mesNum]){
            printf("%4d", AgendamentosPorDia[numeroDoDiaNoAno-1]);
            if ((diaAtual + diaInicio) % 7 == 0){
                printf("\n");
            }
            diaAtual++;
            numeroDoDiaNoAno++;
        }
        diaInicio = (diaInicio + diasnoMes[mesNum]) % 7;
        printf("\n\n");
    }   
};

//funçao para verificar se o ano e bisexto
int bisexto(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
};

//Função para adicionar agendamentos
int inserirAgendamento(int diaAgendamento, int mesAgendamento, int anoAgendamento, int diasTratamento){
    int mo[12] = {31,28+bisexto(anoAgendamento),31,30,31,30,31,31,30,31,30,31};
    int i;
    int numeroDiaDoAno=0;

    for (i=0; i<(mesAgendamento-1); i++) {
        numeroDiaDoAno += mo[i];
    }

    numeroDiaDoAno += diaAgendamento;

    for (int i=0; i< diasTratamento; i++) {
        if ((AgendamentosPorDia[numeroDiaDoAno - 1+i]) < 5) {
            AgendamentosPorDia[numeroDiaDoAno - 1+i]= AgendamentosPorDia[numeroDiaDoAno - 1 +i] + 1;
        } else {
            printf("%s%d%s%d%s","Não foi possível agendar seu atendimento para o dia ", diaAgendamento+i, "/", mesAgendamento,  " por conflito na Agenda. Por favor escolha outra data.\n\n");
        }
    }
};
