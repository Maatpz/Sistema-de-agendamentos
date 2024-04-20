#include <stdio.h>

// O fisioterapeuta trata de pacientes com dores urgentes de todos os tipos, para isso ele trabalha todos os dias. 
// Ele faz planos de pacotes de atendimentos diários para cada paciente. Ou seja, 
// um paciente pode solicitar 10 dias de tratamento, 15 dias, etc… O fisioterapeuta só consegue atender 5 pacientes por dia. 
// O problema é que ele está se perdendo ao fazer agendamentos de pacientes para ao longo do ano, 
// eventualmente ele acaba com mais de 5 pacientes por dia e precisa cancelar. Para resolver esse problema ele precisa que você crie 
// uma agenda que que cadastre agendamentos e indique quantos pacientes ele deve atender em cada dia do ano

// Escreva um programa em C que exiba um calendário de um ano e gerencie agendamentos. 
//Ao iniciar, o programa deve solicitar ao usuário o dia da semana em que 1º de janeiro cai e se o ano é bissexto ou não. 
// Com essas informações pode-se montar todo o calendário. Depois disso, o programa deve permitir em um menu: 

// (i) mostrar o calendário.

// (ii) inserir agendamentos.  Esta função deve solicitar ao usuário a data de início e a duração do agendamento. Em um dado dia, não se pode ter mais do que 5 pacientes agendados. 
//Caso ocorra um conflito, deve-se dizer que não pode agendar naquele dia.  

// (iii) mostrar o calendário com agendamentos.

// No `main()`, você deve ter um array de agendamentos que vai controlar quais dias tem quantos agendamentos. 
// O array deve ter o tamanho do ano. Este array deve ser acessado pelas funções.

// Janeiro
// Dom Seg Ter Qua Qui Sex Sab
//                   1   2   3
//   4   5   6   7   8   9  10
//  11  12  13  14  15  16  17
//  18  19  20  21  22  23  24
//  25  26  27  28  29  30  31


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