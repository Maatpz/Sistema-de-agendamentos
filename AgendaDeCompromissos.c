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



// // Funçao para saber em qual dia da semana inicia o ano 
// int calcularDiaInicio(int ano) {
//     int diaInicio = (ano * 365 + (ano - 1) / 4 - (ano - 1) / 100 + (ano) / 400) % 7;
//     return diaInicio;
// }

// Funçao teste para o ano bisexto
// int bisexto(int anoBisexto){
//     if ((ano % 4 == 0 && ano % 100 !=0) ano || (ano % 400 == 0)){
//         return 1;    
//     else{
//         return 0;
//     }
// }
// int main(){
//     int anoBisexto;
//     bisexto(anoBisexto);
//     // int x = bisexto(anoBisexto)
//     // return x;
// }



// // Funçao q cria um calendario e ja define quantos dias tem no mes. 
// // Troquei algumas coisas pois vez ou outra estava dando erro na compilação, o ano bisexto esta sendo feito direto pq e um calculo padrao
// // entao nao deve ter problema, testem o calendario para ver se esta tudo certo. 

// int Calendario(int ano, int diaInicio) {
//     int diaAtual;
//     int diasnoMes[12] = {31, 28 + (ano % 4 == 0 && (ano % 100!= 0 || ano % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//     printf("Calendario de %d:\n\n", ano);

//     for (int mesNum = 0; mesNum < 12; mesNum++) {
//         if (mesNum == 0)
//             printf("Janeiro\n");
//         else if (mesNum == 1) 
//             printf("Fevereiro\n");
//         else if (mesNum == 2) 
//             printf("Marco\n");
//         else if (mesNum == 3)
//             printf("Abril\n");
//         else if (mesNum == 4) 
//             printf("Maio\n");
//         else if (mesNum == 5) 
//             printf("Junho\n");
//         else if (mesNum == 6) 
//             printf("Julho\n");
//         else if (mesNum == 7) 
//             printf("Agosto\n");
//         else if (mesNum == 8) 
//             printf("Setembro\n");
//         else if (mesNum == 9) 
//             printf("Outubro\n");
//         else if (mesNum == 10) 
//             printf("Novembro\n");
//         else if (mesNum == 11) 
//             printf("Dezembro\n");

//         printf(" Dom Seg Ter Qua Qui Sex Sab\n");
//         for (int espacos = 0; espacos < diaInicio; espacos++) {
//             printf("    ");
//         }
//         diaAtual = 1;

//         while (diaAtual <= diasnoMes[mesNum]) {
//             printf("%4d", diaAtual);
//             if ((diaAtual + diaInicio) % 7 == 0) {
//                 printf("\n");
//             }
//             diaAtual++;
//         }
//         diaInicio = (diaInicio + diasnoMes[mesNum]) % 7;
//         printf("\n\n");
//     }
// }







// //  Main para teste do calendario, pode retirar depois
// int main() {
//     int ano, diaInicio;
//     printf("Qual o ano do calendario: ");
//     scanf("%d", &ano);
//     diaInicio = calcularDiaInicio(ano);
//     printf("Em qual dia da semana o ano começa(0 - Domingo, 1 - Segunda-feira..): ");
//     scanf("%d", &diaInicio);
//     Calendario(ano, diaInicio);
// }


// int agendamento[365];
// int main(){
// int opcao;
// do {
//     printf("Menu:\n");
//     printf("1. Mostrar calendário\n");
//     printf("2. Inserir agendamento\n");
//     printf("3. Mostrar calendário com agendamentos\n");
//     printf("4. Sair\n");
//     printf("Opção: ");
//     scanf("%d", &opcao);
    
//     switch (opcao) {
//           case 1:
//             calendario();
//             break;
//           case 2: {
        
//             break;
//         }
//           case 3:
            
//             break;
//           case 4:
//                 return 0;
//             default:
//                 printf("Opção inválida.\n");
//         }
//     } while (opcao != 4);
// }
