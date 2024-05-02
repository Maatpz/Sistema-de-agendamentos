#include <stdio.h>

// 30 = Abril, junho, setembro e novembro
// 31 = Janeiro , março, maio, julho, agosto, outubro , dezembro
// 28/29 Fevereiro
// 1-Janeiro, 2-Fevereiro, 3-Março, 4-Abril, 5-Maio, 6-Junho, 7-Julho, 8-Agosto, 9-Setembro, 10-Outubro, 11-Novembro, 12-Dezembro

// *** Limite 5 paciente por DIA

// Total de agendamentos por ano! Cada dia representa N consultas!
int anoAgendamento[365];

int main (void){

    int diaSemana = 0; 
    int fev = 0; 
    int mesDia = 0; 
    int mesAgendamento = 0;
    char anoBi;
    
    // Dia semana e ano bissexto passados pelo usuário
    printf("Informe o 1º dia da semana de janeiro do ano atual! Digite 1-Domingo, 2-Segunda, 3-Terça...\n");
    scanf("%d", diaSemana);
    printf("O ano atual é bissexto? Digite 's' para sim ou 'n' para não: ");
    scanf(" %c", anoBi);


    printf("Digite o mês para agendamento 1-Janeiro, 2-Fevereiro, 3-Março...\n");
    scanf("%d", mesAgendamento);

    // Verificar se o ano é bissexto
    if(anoBi == 's'){
        fev = 29;
    }
    else{
        fev = 30;
    }

    // Verificar se o mês tem 30 ou 31
    if(mesAgendamento == 4 || mesAgendamento == 6 || mesAgendamento == 9 || mesAgendamento == 11){
        mesDia = 30;
    }
    else{
        mesDia = 31;
    }
    

    return 0;
}





// // Funçao q cria um calendario e ja define quantos dias tem no mes. 
// // Troquei algumas coisas pois vez ou outra estava dando erro na compilação, o ano bisexto esta sendo feito direto pq e um calculo padrao,
// // entao nao deve ter problema, testem o calendario para ver se esta tudo certo.
int calendario(int ano, int dia_Inicio);
// int calendario_Agendamentos(int ano, int dia_Inicio, int agendamento_Dia[], int agendamento_Mes[], int agendamento_Duracao[]);
int main() {
    int dia,ano,dia_Inicio,opcao;
    int agendamento_Dia[31]={0};
    int agendamento_Mes[12]={0};
    int agendamento_Duracao[24]={0};

    printf("Digite o dia da semana de 1° de Janeiro cai: ");
    scanf("%d",&dia_Inicio);
    printf("O ano e bisexto?Informe o ano: ");
    scanf("%d",&ano);

    do{
        int dia_agen;
        int mes;
        int duracao;
        int contador=0;
        printf("\nMenu:\n");
        printf("1-Mostrar Calendário:\n");
        printf("2- Inserir Agendamento:\n");
        printf("3- Mostrar Calendário com agendamentos:\n");
        printf("4- Sair\n");
        printf("Qual opção deseja:");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:
                calendario(ano,dia_Inicio);
                break;
            case 2:{
                //agendamento nao esta concluido
                printf("Qual dia do agendamento(1 ate 31):");
                scanf("%d",&dia_agen);
                printf("Qual o mes do agendamento(1 ate 12):");
                scanf("%d",&mes);
                printf("QUal duração do agendamento(horas):");
                scanf("%d",&duracao);

                for(int i=0;i<31;i++){
                    if(agendamento_Dia[i]==dia_agen && agendamento_Mes[mes-1]==mes && agendamento_Duracao[0]==duracao){
                        contador++;
                    }
                }
                if (contador<5){
                    for (int i=0;i<1;i++){
                        if(agendamento_Dia[i]==0){
                            agendamento_Dia[i]=dia_agen;
                            agendamento_Mes[mes-1]=mes;
                            agendamento_Duracao[0]=duracao;
                            printf("Agendamento concluido\n");
                        }
                    };
                } else{
                        printf("Nao e possivel");
                    }     
             
            };
             break;  
            case 3:
                //nao funciona ideia ruim 
                // calendario_Agendamentos(ano,dia_Inicio,agendamento_Dia[dia_agen],agendamento_Mes[mes],agendamento_Duracao[duracao]);
                break;
            case 4:
                return 0;
        };
    } while (opcao!=4);
    return 0;
};

int calendario(int ano, int dia_Inicio){
    int dia_Atual;
    int dias_noMes[12] = {31, 28 + (ano % 4 == 0 && (ano % 100!= 0 || ano % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    printf("Calendario de %d:\n\n", ano);
    for (int mesNum = 0; mesNum < 12; mesNum++){
        if (mesNum == 0) printf("Janeiro\n");
        else if (mesNum == 1)
            printf("Fevereiro\n");
        else if (mesNum == 2) 
            printf("Marco\n");
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
        for (int espacos = 0; espacos < dia_Inicio; espacos++){
            printf("    ");
        }
        dia_Atual = 1;
        while (dia_Atual <= dias_noMes[mesNum]){
            printf("%4d", dia_Atual);
            if ((dia_Atual + dia_Inicio) % 7 == 0){
                printf("\n");
            }
            dia_Atual++;
        }
        dia_Inicio = (dia_Inicio + dias_noMes[mesNum]) % 7;
        printf("\n\n");
    };
    return 0;
};

//nao funciona
// int calendario_Agendamentos(int ano, int dia_Inicio, int agendamento_Dia[], int agendamento_Mes[], int agendamento_Duracao[]) {
//     int dia_Atual;
//     int dias_noMes[12] = {31, 28 + (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     printf("Calendário de %d com agendamentos:\n\n", ano);
//     for (int mesNum = 0; mesNum < 12; mesNum++) {
//         switch (mesNum + 1) {
//             case 1: printf("Janeiro\n"); 
//              break;
//             case 2: printf("Fevereiro\n");
//              break;
//             case 3: printf("Março\n");
//              break;
//             case 4: printf("Abril\n");
//              break;
//             case 5: printf("Maio\n");
//              break;
//             case 6: printf("Junho\n");
//              break;
//             case 7: printf("Julho\n");
//              break;
//             case 8: printf("Agosto\n");
//              break;
//             case 9: printf("Setembro\n");
//              break;
//             case 10: printf("Outubro\n");
//              break;
//             case 11: printf("Novembro\n");
//              break;
//             case 12: printf("Dezembro\n");
//              break;
//         }
//         printf(" Dom Seg Ter Qua Qui Sex Sab\n");
//         for (int espacos = 0; espacos < dia_Inicio; espacos++) {
//             printf("    ");
//         }
//         dia_Atual = 1;
//         while (dia_Atual <= dias_noMes[mesNum]) {
//             printf("%4d", dia_Atual);
//             for (int i = 0; i < 31; i++) {
//                 if (agendamento_Dia[i] == dia_Atual && agendamento_Mes[i] == mesNum + 1 && agendamento_Duracao[i] > 0) {
//                     printf("~"); 
//                     break;
//                 }
//             }
//             if ((dia_Atual + dia_Inicio) % 7 == 0) {
//                 printf("\n");
//             }
//             dia_Atual++;
//         }
//         dia_Inicio = (dia_Inicio + dias_noMes[mesNum]) % 7;
//         printf("\n\n");
//     }
// }
