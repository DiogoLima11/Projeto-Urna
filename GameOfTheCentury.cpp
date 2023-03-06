#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include "carregando.h"
#include <string.h>
#include <windows.h>


typedef struct
{
    char imagem[20];
    char nomeDoJogo[20];
    char lancamento[5];
    char descricaoL1[75];
    char descricaoL2[75];
    char descricaoL3[75];
    char descricaoL4[80];

} jogo;


void botao(int x1, int y1, int x2, int y2, char info[12]);
void botaoPressionado(int x1, int y1, int x2, int y2, char info[12]);
void jogoClicado(char nomeImg[30], int x1, int y1, int x2, int y2);
void paginaDoJogo(char imgJogo[30], char imgFundo[30], char nomeDoJogo[20], char lancamento[5], char descricaoL1[75], char descricaoL2[75], char descricaoL3[75], char descricaoL4[75], int x1, int y1, int x2, int y2);
void votacao(int x1, int y1, int x2, int y2);
void JanelaVotacao(int x1, int y1, int x2, int y2);
void BotaoBrancoComBordaColorida(int x1, int y1, int x2, int y2);
void BotaoSim(int x1, int y1, int x2, int y2);
void BotaoNao(int x1, int y1, int x2, int y2);

void JanelaDoComputando(int x1, int y1, int x2, int y2);
void proximo(int x1, int y1, int x2, int y2);
void proximoPressionado(int x1, int y1, int x2, int y2);
void PaginaDesenvolvedores();

int apuraVotos(int v[], int tamanho);
void botaofinalizar();
void botaofinalizarpressionado();

main()
{
    setlocale(LC_ALL,"Portuguese");
    jogo j[5]={"minecraftimg.jpg","Minecraft","2011","In minecraft, the players explore an open world three-dimensional",
                                                     "intentionally in blocks, pixelated and generated procedurally",
                                                     "discovering and extracting raw material, tools, build structures,",
                                                     "and lot more.",
               "gtaVimg.jpg","Grand Theft Auto V","2013","The game takes place in the fictional state of San Andreas, with the",
                                                         "story of the single player campaign following three criminals and",
                                                         "their efforts to do a robbery under pressure from a government agency,",
                                                         "the open world allows the players to do everything they want.",
               "eldenRingimg.jpg","Elden Ring","2022","In Elden Ring, you're part of the tarnished, living in in-between",
                                                      "lands with help of Grace, after you were exiled beyond the",
                                                      "Sea of Mist, this Grace, that banned your race from this place is the",
                                                      "same calling you back, asking for help, will lead you in this journey",
               "csGoimg.jpg","Counter Strike","2012","Global Offensive (CS:Go) is an online game developed by",
                                                     "Valve Corporation and Hidden Path Entretainment, beeing a",
                                                     "sequel of Couter-Strike: Source, is the fourth main title in",
                                                     "the franchise.",
               "theWitcher3img.jpg","The Witcher 3","2015","The game is an action RPG, and it means that, the same",
                                                           "time it has elements of an RPG, the battles are not turn",
                                                           "based, but battle like an action game. Geralt carries two",
                                                           "swords: one made of silver (fight monsters) and steel (fight humans). "};
    int menuJogo;
    int JogoSelecionado;
    int button;
    int a = 0;
    int votar;
    int menu = 0;
    int VotosGuardados[5] = {0,0,0,0,0};
    int sair = 0;
    int iniciar = 0;
    int vencedor = 0;
    int votosTotais = 0;
    char votosTotaisString[10];
    char maisVotosString[10];

    initwindow(1280,720,"Game Of The Century",0,0);

    while(iniciar == 0)
    {
        readimagefile("telainicialimg.jpg",0,0,1280,720);

        if(mousex() >= 205 && mousex() <= 427 && mousey() >= 431 && mousey() <= 468)
        {
           readimagefile("iniciarClicado.jpg",0,0,1280,720);
           while(iniciar == 0)
            {
                if(mousex() >= 206 && mousex() <= 445 && mousey() >= 430 && mousey() <= 470 && ismouseclick(WM_LBUTTONDOWN))
                    iniciar = 1;
                if(mousex() >= 206 && mousex() <= 445 && mousey() >= 430 && mousey() <= 470)
                    printf("");
                else
                    break;
            }
        }

        if(mousex() >= 205 && mousex() <= 835 && mousey() >= 516 && mousey() <= 554)
        {
           readimagefile("desenvolvedoresClicado.jpg",0,0,1280,720);
           while(iniciar == 0)
            {
                if(mousex() >= 204 && mousex() <= 856 && mousey() >= 515 && mousey() <= 555 && ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    PaginaDesenvolvedores();
                    readimagefile("setaVoltarDesenvolvidor.jpg",0,0,1280,720);
                    while(iniciar == 0)
                    {
                        readimagefile("setaVoltarDesenvolvidor.jpg",0,0,1280,720);
                        if(mousex() >= 12 && mousex() <= 87 && mousey() >= 12 && mousey() <= 62)
                            {
                                readimagefile("setaClicada.jpg",0,0,1280,720);
                                while(iniciar == 0)
                                {
                                    if(mousex() >= 5 && mousex() <= 96 && mousey() >= 7 && mousey() <= 66 && ismouseclick(WM_LBUTTONDOWN))
                                    {
                                        clearmouseclick(WM_LBUTTONDOWN);
                                        iniciar = 1;
                                    }
                                    if(mousex() >= 5 && mousex() <= 96 && mousey() >= 7 && mousey() <= 66)
                                        printf("");
                                    else
                                        break;
                                }
                            }
                            clearmouseclick(WM_LBUTTONDOWN);
                    }
                    iniciar = 0;
                    break;
                }
                if(mousex() >= 204 && mousex() <= 856 && mousey() >= 515 && mousey() <= 555)
                    printf("");
                else
                    break;
            }
        }
        if(mousex() >= 205 && mousex() <= 351 && mousey() >= 607 && mousey() <= 644)
        {
            readimagefile("sairClicado.jpg",0,0,1280,720);
            while(iniciar == 0)
            {
                if(mousex() >= 205 && mousex() <= 365 && mousey() >= 605 && mousey() <= 648 && ismouseclick(WM_LBUTTONDOWN))
                {
                    exit(0);
                }
                if(mousex() >= 205 && mousex() <= 365 && mousey() >= 605 && mousey() <= 648)
                    printf("");
                else
                    break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }

    readimagefile("paginainicialimg.jpg",0,0,1280,720);
    delay(200);
    readimagefile("minecraftimg.jpg",65,238,261,531);
    delay(30);
    readimagefile("gtaVimg.jpg",303,238,499,531);
    delay(200);
    readimagefile("eldenRingimg.jpg",541,238,737,531);
    delay(200);
    readimagefile("csGoimg.jpg",779,238,975,531);
    delay(200);
    readimagefile("theWitcher3img.jpg",1017,238,1213,531);


      while(sair == 0)
      {
                printf("%d %d %d %d %d\n", VotosGuardados[0],VotosGuardados[1],VotosGuardados[2],VotosGuardados[3],VotosGuardados[4]);
                votosTotais = VotosGuardados[0] + VotosGuardados[1] + VotosGuardados[2] + VotosGuardados[3] + VotosGuardados[4];
            if (mousex() >= 49 && mousex() <= 278 && mousey() >= 236 && mousey() <= 521 && ismouseclick(WM_LBUTTONDOWN) && a == 0)
                JogoSelecionado=1;
                else
            if (mousex() >= 287 && mousex() <= 516 && mousey() >= 236 && mousey() <= 521 && ismouseclick(WM_LBUTTONDOWN) && a == 0)
                JogoSelecionado=2;
                else
            if (mousex() >= 525 && mousex() <= 754 && mousey() >= 236 && mousey() <= 521 && ismouseclick(WM_LBUTTONDOWN) && a == 0)
                JogoSelecionado=3;
                else
            if (mousex() >= 763 && mousex() <= 992 && mousey() >= 236 && mousey() <= 521 && ismouseclick(WM_LBUTTONDOWN) && a == 0)
                JogoSelecionado=4;
                else
            if (mousex() >= 1001 && mousex() <= 1230 && mousey() >= 236 && mousey() <= 521 && ismouseclick(WM_LBUTTONDOWN) && a == 0)
                JogoSelecionado=5;
                else
                    if(ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 0)
                    {
                        readimagefile("paginainicialimg.jpg",0,0,1280,720);
                        readimagefile("minecraftimg.jpg",65,238,261,531);
                        readimagefile("gtaVimg.jpg",303,238,499,531);
                        readimagefile("eldenRingimg.jpg",541,238,737,531);
                        readimagefile("csGoimg.jpg",774,238,975,531);
                        readimagefile("theWitcher3img.jpg",1017,238,1213,531);
                        if (votosTotais != 0)
                            botaofinalizar();
                    }
            if (mousex() >= 1090 && mousex() <= 1275 && mousey() >= 670 && mousey() <= 700 && ismouseclick(WM_LBUTTONDOWN) && a == 0 && votosTotais != 0)
            {
                botaofinalizarpressionado();
                delay(250);
                votosTotais = VotosGuardados[0] + VotosGuardados[1] + VotosGuardados[2] + VotosGuardados[3] + VotosGuardados[4];
                vencedor = apuraVotos(VotosGuardados,5);
                itoa(votosTotais, votosTotaisString,10);
                itoa(VotosGuardados[vencedor],maisVotosString,10);
                readimagefile("fundoFinalimg.jpg",0,0,1280,720);
                readimagefile(j[vencedor].imagem,502,117,778,534);
                setcolor(15);
                settextstyle(8,HORIZ_DIR,3);
                setbkcolor(0);
                outtextxy(527,535,"Votos Totais:");
                outtextxy(720,535,votosTotaisString);
                outtextxy(570,559,"Vencedor:");
                outtextxy(703,559,maisVotosString);
                settextstyle(8,HORIZ_DIR,2);
                setfillstyle(1,0);
                bar(587,680,703,710);
                setcolor(15);
                setbkcolor(0);
                outtextxy(590,685,"ENCERRAR");
                while(sair == 0)
                {
                    if (mousex() >= 587 && mousex() <= 703 && mousey() >= 680 && mousey() <= 710 && ismouseclick(WM_LBUTTONDOWN))
                        {
                            bar(587,680,703,710);
                            setcolor(15);
                            setlinestyle(0,0,2);
                            rectangle(587,680,703,710);
                            setbkcolor(0);
                            outtextxy(590,685,"ENCERRAR");
                            delay(250);
                            sair=1;
                        }
                        clearmouseclick(WM_LBUTTONDOWN);
                }
        }


        switch(JogoSelecionado)
        {
    case 1: readimagefile("paginainicialblurimg.jpg",0,0,1280,720);
            botao(65,238,261,581, "INFORMAÇÕES");
            jogoClicado("minecraftimg.jpg",65,238,261,531);
            readimagefile("gtaVimg.jpg",303,238,499,531);
            readimagefile("eldenRingimg.jpg",541,238,737,531);
            readimagefile("csGoimg.jpg",779,238,975,531);
            readimagefile("theWitcher3img.jpg",1017,238,1213,531);
            if (votosTotais != 0)
                botaofinalizar();
            JogoSelecionado = 0;
            button = 1;
        break;
    case 2: readimagefile("paginainicialblurimg.jpg",0,0,1280,720);
            botao(303,238,499,581, "INFORMAÇÕES");
            readimagefile("minecraftimg.jpg",65,238,261,531);
            jogoClicado("gtaVimg.jpg",303,238,499,531);
            readimagefile("eldenRingimg.jpg",541,238,737,531);
            readimagefile("csGoimg.jpg",779,238,975,531);
            readimagefile("theWitcher3img.jpg",1017,238,1213,531);
            if (votosTotais != 0)
                botaofinalizar();
            JogoSelecionado=0;
            button = 2;
        break;
    case 3: readimagefile("paginainicialblurimg.jpg",0,0,1280,720);
            botao(541,238,737,581, "INFORMAÇÕES");
            readimagefile("minecraftimg.jpg",65,238,261,531);
            readimagefile("gtaVimg.jpg",303,238,499,531);
            jogoClicado("eldenRingimg.jpg",541,238,737,531);
            readimagefile("csGoimg.jpg",779,238,975,531);
            readimagefile("theWitcher3img.jpg",1017,238,1213,531);
            if (votosTotais != 0)
                botaofinalizar();
            JogoSelecionado=0;
            button = 3;
        break;
    case 4: readimagefile("paginainicialblurimg.jpg",0,0,1280,720);
            botao(779,238,975,581, "INFORMAÇÕES");
            readimagefile("minecraftimg.jpg",65,238,261,531);
            readimagefile("gtaVimg.jpg",303,238,499,531);
            readimagefile("eldenRingimg.jpg",541,238,737,531);
            jogoClicado("csGoimg.jpg",779,238,975,531);
            readimagefile("theWitcher3img.jpg",1017,238,1213,531);
            if (votosTotais != 0)
                botaofinalizar();
            JogoSelecionado=0;
            button = 4;
        break;
    case 5: readimagefile("paginainicialblurimg.jpg",0,0,1280,720);
            botao(1017,238,1213,581, "INFORMAÇÕES");
            readimagefile("minecraftimg.jpg",65,238,261,531);
            readimagefile("gtaVimg.jpg",303,238,499,531);
            readimagefile("eldenRingimg.jpg",541,238,737,531);
            readimagefile("csGoimg.jpg",779,238,975,531);
            jogoClicado("theWitcher3img.jpg",1017,238,1213,531);
            if (votosTotais != 0)
                botaofinalizar();
            JogoSelecionado=0;
            button = 5;
        break;
    case 6: if (mousex() >= 220 && mousex() <= 370 && mousey() >= 585 && mousey() <= 620 && ismouseclick(WM_LBUTTONDOWN))
                {
                    readimagefile("paginainicialimg.jpg",0,0,1280,720);
                    readimagefile("minecraftimg.jpg",65,238,261,531);
                    readimagefile("gtaVimg.jpg",303,238,499,531);
                    readimagefile("eldenRingimg.jpg",541,238,737,531);
                    readimagefile("csGoimg.jpg",779,238,975,531);
                    readimagefile("theWitcher3img.jpg",1017,238,1213,531);
                    if (votosTotais != 0)
                        botaofinalizar();
                    JogoSelecionado = 0;
                    a = 0;
                    votar=0;
                }
            if(mousex() >= 1220 && mousex() <= 1278 && mousey() >= 280 && mousey() <= 420 && ismouseclick(WM_LBUTTONDOWN))
                {
                    if(menu == 5)
                        {
                            menu = 0;
                        }
                    menu++;
                    menuJogo = menu;
                    proximoPressionado(0,0,1280,720);
                    delay(200);
                }
            if(mousex() >= 2 && mousex() <= 60 && mousey() >= 280 && mousey() <= 420 && ismouseclick(WM_LBUTTONDOWN))
                {
                    if(menu == 1)
                        {
                            menu = 6;
                        }
                    menu--;
                    menuJogo = menu;
                    proximoPressionado(0,0,1280,720);
                    delay(200);
                }
        break;
        }

        switch(button)
        {
        case 1: if (mousex() >= 49 && mousex() <= 278 && mousey() >= 574 && mousey() <= 623 && ismouseclick(WM_LBUTTONDOWN))
                    {
                        botaoPressionado(65,238,261,581, "INFORMAÇÕES");
                        jogoClicado("minecraftimg.jpg",65,238,261,531);
                        delay(200);
                        button = 0;
                        menuJogo = 1;
                        clearmouseclick(WM_LBUTTONDOWN);
                    }
            break;
        case 2: if (mousex() >= 287 && mousex() <= 516 && mousey() >= 574 && mousey() <= 623 && ismouseclick(WM_LBUTTONDOWN))
                    {
                        botaoPressionado(303,238,499,581, "INFORMAÇÕES");
                        jogoClicado("gtaVimg.jpg",303,238,499,531);
                        delay(200);
                        button = 0;
                        menuJogo = 2;
                        clearmouseclick(WM_LBUTTONDOWN);
                    }
            break;
        case 3: if (mousex() >= 525 && mousex() <= 754 && mousey() >= 574 && mousey() <= 623 && ismouseclick(WM_LBUTTONDOWN))
                    {
                        botaoPressionado(541,238,737,581, "INFORMAÇÕES");
                        jogoClicado("eldenRingimg.jpg",541,238,737,531);
                        delay(200);
                        button = 0;
                        menuJogo = 3;
                        clearmouseclick(WM_LBUTTONDOWN);
                    }
            break;
        case 4: if (mousex() >= 763 && mousex() <= 992 && mousey() >= 574 && mousey() <= 623 && ismouseclick(WM_LBUTTONDOWN))
                    {
                        botaoPressionado(779,238,975,581, "INFORMAÇÕES");
                        jogoClicado("csGoimg.jpg",779,238,975,531);
                        delay(200);
                        button = 0;
                        menuJogo = 4;
                        clearmouseclick(WM_LBUTTONDOWN);
                    }
            break;
        case 5: if (mousex() >= 1001 && mousex() <= 1230 && mousey() >= 574 && mousey() <= 623 && ismouseclick(WM_LBUTTONDOWN))
                    {
                        botaoPressionado(1017,238,1213,581, "INFORMAÇÕES");
                        jogoClicado("theWitcher3img.jpg",1017,238,1213,531);
                        delay(200);
                        button = 0;
                        menuJogo = 5;
                        clearmouseclick(WM_LBUTTONDOWN);
                    }
            break;
        }

        switch(menuJogo)
        {
    case 1: paginaDoJogo("minecraftimg.jpg", "fundominecraftimg.jpg", j[0].nomeDoJogo, j[0].lancamento, j[0].descricaoL1, j[0].descricaoL2, j[0].descricaoL3, j[0].descricaoL4, 0, 0, 1280, 720);
            JogoSelecionado = 6;
            menuJogo = 0;
            menu = 1;
            a = 1;
            votacao(0,0,1280,720);
            votar = 1;
            proximo(0,0,1280,720);
        break;
    case 2: paginaDoJogo("gtaVimg.jpg", "fundogtaVimg.jpg", j[1].nomeDoJogo, j[1].lancamento, j[1].descricaoL1, j[1].descricaoL2, j[1].descricaoL3, j[1].descricaoL4,0 ,0 , 1280, 720);
            JogoSelecionado = 6;
            menuJogo = 0;
            menu = 2;
            a = 1;
            votacao(0,0,1280,720);
            votar = 2;
            proximo(0,0,1280,720);
        break;
    case 3: paginaDoJogo("eldenRingimg.jpg", "fundoeldenRingimg.jpg", j[2].nomeDoJogo, j[2].lancamento,  j[2].descricaoL1, j[2].descricaoL2, j[2].descricaoL3, j[2].descricaoL4,0 ,0 , 1280, 720);
            JogoSelecionado = 6;
            menuJogo = 0;
            menu = 3;
            a = 1;
            votacao(0,0,1280,720);
            votar = 3;
            proximo(0,0,1280,720);
        break;
    case 4: paginaDoJogo("csGoimg.jpg", "fundocsGoimg.jpg", j[3].nomeDoJogo, j[3].lancamento, j[3].descricaoL1, j[3].descricaoL2, j[3].descricaoL3, j[3].descricaoL4, 0 ,0 , 1280, 720);
            JogoSelecionado = 6;
            menuJogo = 0;
            menu = 4;
            a = 1;
            votacao(0,0,1280,720);
            votar = 4;
            proximo(0,0,1280,720);
        break;
    case 5: paginaDoJogo("theWitcher3img.jpg", "fundotheWitcher3img.jpg", j[4].nomeDoJogo, j[4].lancamento, j[4].descricaoL1, j[4].descricaoL2, j[4].descricaoL3, j[4].descricaoL4, 0 ,0 , 1280, 720);
            JogoSelecionado = 6;
            menuJogo = 0;
            menu = 5;
            a = 1;
            votacao(0,0,1280,720);
            votar = 5;
            proximo(0,0,1280,720);
        break;
        }

        switch(votar)
        {
    case 1: if (mousex() >= 65 && mousex() <= 215 && mousey() >= 585 && mousey() <= 620 && ismouseclick(WM_LBUTTONDOWN))
            {
                JanelaVotacao(0,0,0,0);
                BotaoBrancoComBordaColorida(0,0,0,0);
                JogoSelecionado = 7;
            }

            if(mousex() >= 620 && mousex() <= 790 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoNao(0,0,0,0);
                menuJogo = 1;
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                votar = 0;
            }

            if(mousex() >= 810 && mousex() <= 980 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoSim(0,0,0,0);
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                delay(50);
                JanelaDoComputando(0,0,0,0);
                votar = 0;
                JogoSelecionado = 0;
                a = 0;
                VotosGuardados[0]++;
            }
        break;
        case 2: if (mousex() >= 65 && mousex() <= 215 && mousey() >= 585 && mousey() <= 620 && ismouseclick(WM_LBUTTONDOWN))
            {
                JanelaVotacao(0,0,0,0);
                BotaoBrancoComBordaColorida(0,0,0,0);
                JogoSelecionado = 7;
            }

            if(mousex() >= 620 && mousex() <= 790 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoNao(0,0,0,0);
                menuJogo = 2;
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                votar = 0;
            }

            if(mousex() >= 810 && mousex() <= 980 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoSim(0,0,0,0);
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                delay(50);
                JanelaDoComputando(0,0,0,0);
                votar = 0;
                JogoSelecionado = 0;
                a = 0;
                VotosGuardados[1]++;
            }
        break;
        case 3: if (mousex() >= 65 && mousex() <= 215 && mousey() >= 585 && mousey() <= 620 && ismouseclick(WM_LBUTTONDOWN))
            {
                JanelaVotacao(0,0,0,0);
                BotaoBrancoComBordaColorida(0,0,0,0);
                JogoSelecionado = 7;
            }

            if(mousex() >= 620 && mousex() <= 790 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoNao(0,0,0,0);
                menuJogo = 3;
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                votar = 0;
            }

            if(mousex() >= 810 && mousex() <= 980 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoSim(0,0,0,0);
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                delay(50);
                JanelaDoComputando(0,0,0,0);
                votar = 0;
                JogoSelecionado = 0;
                a = 0;
                VotosGuardados[2]++;
            }
        break;
        case 4: if (mousex() >= 65 && mousex() <= 215 && mousey() >= 585 && mousey() <= 620 && ismouseclick(WM_LBUTTONDOWN))
            {
                JanelaVotacao(0,0,0,0);
                BotaoBrancoComBordaColorida(0,0,0,0);
                JogoSelecionado = 7;
            }

            if(mousex() >= 620 && mousex() <= 790 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoNao(0,0,0,0);
                menuJogo = 4;
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                votar = 0;
            }

            if(mousex() >= 810 && mousex() <= 980 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoSim(0,0,0,0);
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                delay(50);
                JanelaDoComputando(0,0,0,0);
                votar = 0;
                JogoSelecionado = 0;
                a = 0;
                VotosGuardados[3]++;
            }
        break;
        case 5: if (mousex() >= 65 && mousex() <= 215 && mousey() >= 585 && mousey() <= 620 && ismouseclick(WM_LBUTTONDOWN))
            {
                JanelaVotacao(0,0,0,0);
                BotaoBrancoComBordaColorida(0,0,0,0);
                JogoSelecionado = 7;
            }

            if(mousex() >= 620 && mousex() <= 790 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoNao(0,0,0,0);
                menuJogo = 5;
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                votar = 0;
            }

            if(mousex() >= 810 && mousex() <= 980 && mousey() >= 390 && mousey() <= 425 && ismouseclick(WM_LBUTTONDOWN) && JogoSelecionado == 7)
            {
                BotaoSim(0,0,0,0);
                delay(250);
                BotaoBrancoComBordaColorida(0,0,0,0);
                delay(50);
                JanelaDoComputando(0,0,0,0);
                votar = 0;
                JogoSelecionado = 0;
                a = 0;
                VotosGuardados[4]++;
            }
        break;
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }
      closegraph();
}

void botao(int x1, int y1, int x2, int y2, char rotulo[30])
{
    setfillstyle(1,(COLOR(250, 250, 250)));
    bar(x1-16,y1-2,x2+17,y2+42);

    setbkcolor((COLOR(250, 250, 250)));
    setcolor(0);
    settextstyle(3,HORIZ_DIR,3);
    outtextxy(x1+24,y1+348,rotulo);

}

void botaoPressionado(int x1, int y1, int x2, int y2, char rotulo[30])
{
    setfillstyle(1,(COLOR(200, 200, 200)));
    bar(x1-16,y1-2,x2+17,y2+42);

    setbkcolor((COLOR(200, 200, 200)));
    setcolor(0);
    settextstyle(3,HORIZ_DIR,3);
    outtextxy(x1+24,y1+348,rotulo);
}

void jogoClicado(char nomeImg[30], int x1, int y1, int x2, int y2)
{
    readimagefile(nomeImg,x1-14,y1,x2+14,y2+42);
}

void paginaDoJogo(char imgJogo[30], char imgFundo[30], char nomeDoJogo[20], char lancamento[5], char descricaoL1[75], char descricaoL2[75], char descricaoL3[75], char descricaoL4[75], int x1, int y1, int x2, int y2)
{
    readimagefile(imgFundo, x1, y1, x2, y2);
    readimagefile(imgJogo, x1+65, y1+118, x2-910, y2-147);

    setfillstyle(1,COLOR(71,95,110));
    bar(x1+390, y1+118, x2-65, y2-147);

    setbkcolor(COLOR(71,95,110));
    setcolor(0);
    settextstyle(8,HORIZ_DIR,6);
    outtextxy(x1+401, y1+138, "NAME:");

    setbkcolor(COLOR(71,95,110));
    setcolor(15);
    settextstyle(8,HORIZ_DIR,6);
    outtextxy(x1+421, y1+185, nomeDoJogo);

    setbkcolor(COLOR(71,95,110));
    setcolor(0);
    settextstyle(8,HORIZ_DIR,6);
    outtextxy(x1+401, y1+282, "RELEASED:");

    setbkcolor(COLOR(71,95,110));
    setcolor(15);
    settextstyle(8,HORIZ_DIR,6);
    outtextxy(x1+421, y1+329, lancamento);

    setbkcolor(COLOR(71,95,110));
    setcolor(0);
    settextstyle(8,HORIZ_DIR,6);
    outtextxy(x1+401, y1+426, "DESCRIPTION:");

    setbkcolor(COLOR(71,95,110));
    setcolor(15);
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(x1+421, y1+473, descricaoL1);
    outtextxy(x1+421, y1+498, descricaoL2);
    outtextxy(x1+421, y1+523, descricaoL3);
    outtextxy(x1+421, y1+548, descricaoL4);
}

void proximo(int x1, int y1, int x2, int y2)
{
    setfillstyle(1,COLOR(250,250,250));
    bar(x1+2, y1+280, x2-1220, y2-300);
    bar(x1+1220, y1+280, x2-2, y2-300);
    setbkcolor(COLOR(250,250,250));
    settextstyle(8,HORIZ_DIR,6);
    setcolor(0);
    outtextxy(x1+13, y1+327, "<");
    outtextxy(x1+1235, y1+327, ">");
}
void proximoPressionado(int x1, int y1, int x2, int y2)
{
    setfillstyle(1,COLOR(200,200,200));
    bar(x1+2, y1+280, x2-1220, y2-300);
    bar(x1+1220, y1+280, x2-2, y2-300);
    setbkcolor(COLOR(200,200,200));
    settextstyle(8,HORIZ_DIR,6);
    setcolor(0);
    outtextxy(x1+13, y1+327, "<");
    outtextxy(x1+1235, y1+327, ">");
}

void votacao(int x1, int y1, int x2, int y2)
{
    setfillstyle(1,(COLOR(250, 250, 250)));
    bar(x1+65,y1+585,x2-1065,y2-100);
    bar(x1+220,y1+585,x2-910,y2-100);
    setbkcolor(COLOR(250,250,250));
    setcolor(0);
    settextstyle(8,HORIZ_DIR,4);
    outtextxy(x1+90,y1+585, "VOTE");
    outtextxy(x1+235,y1+585, "BACK");
}

void JanelaVotacao(int x1, int y1, int x2, int y2)
{
    settextstyle(8,HORIZ_DIR,4);
    setfillstyle(1,15);
    bar(+1000, +220, +600, +465);
    setcolor(0);
    setlinestyle(0,1,3);
    rectangle(+1000, +220, +600, +465);
    setbkcolor(15);
    outtextxy(682,282, "Tem certeza?");
}

void BotaoBrancoComBordaColorida(int x1, int y1, int x2, int y2)
{
    settextstyle(8,HORIZ_DIR,4);
    setbkcolor(15);
    setfillstyle(1,15);
    setcolor(COLOR(40, 252, 3));
    setlinestyle(0,1,5);
    rectangle(x1+810,y1+390,x2+980,y2+425);
    bar(+980,+390,+810,+425);
    setcolor(0);
    outtextxy(865,392, "Sim");

    setcolor(COLOR(252, 3, 3));
    setlinestyle(0,1,5);
    rectangle(+620,+390,+790,+425);
    bar(+620,+390,+790,+425);
    setcolor(0);
    outtextxy(675,392, "Não");
}

void BotaoSim(int x1, int y1, int x2, int y2)
{
    settextstyle(8,HORIZ_DIR,4);
    setbkcolor(COLOR(40, 252, 3));
    setfillstyle(1,COLOR(40, 252, 3));
    bar(+980,+390,+810,+425);
    setcolor(15);
    outtextxy(865,392, "Sim");
}

void BotaoNao(int x1, int y1, int x2, int y2)
{
    settextstyle(8,HORIZ_DIR,4);
    setbkcolor(COLOR(252, 3, 3));
    setfillstyle(1,COLOR(252, 3, 3));
    bar(+620,+390,+790,+425);
    setcolor(15);
    outtextxy(675,392,"Não");
}

void JanelaDoComputando(int x1, int y1, int x2, int y2)
{
    settextstyle(8,HORIZ_DIR,4);
    setfillstyle(1,15);
    bar(+1000, +220, +600, +465);
    outtextxy(648,282, "Computando voto");
    carregar2(720,360,870,380,1);

    readimagefile("paginainicialimg.jpg",0,0,1280,720);
    readimagefile("minecraftimg.jpg",65,238,261,531);
    readimagefile("gtaVimg.jpg",303,238,499,531);
    readimagefile("eldenRingimg.jpg",541,238,737,531);
    readimagefile("csGoimg.jpg",779,238,975,531);
    readimagefile("theWitcher3img.jpg",1017,238,1213,531);
    botaofinalizar();
}

void PaginaDesenvolvedores()
{
    readimagefile("wanderleiimg.jpg",0,0,1280,720);

    delay(250);
    readimagefile("luisimg.jpg",0,0,1280,720);

    delay(250);
    readimagefile("lucasimg.jpg",0,0,1280,720);

    delay(250);
    readimagefile("diogoimg.jpg",0,0,1280,720);
}

int apuraVotos(int v[], int tamanho)
{
    int maior, indice, i;
    maior = v[0];
    indice = 0;
    for (i=1; i < tamanho; i++)
    {
        if (v[i] > maior)
        {
            maior = v[i];
            indice = i;
        }
    }
    return indice;
}

void botaofinalizar()
{
    setfillstyle(1,0);
    bar(1090,670,1275,700);
    setcolor(15);
    settextstyle(8,HORIZ_DIR,1);
    setbkcolor(0);
    outtextxy(1093,675,"Encerrar Votação");
}

void botaofinalizarpressionado()
{
    setfillstyle(1,0);
    bar(1090,670,1275,700);
    setcolor(15);
    setlinestyle(0,0,2);
    rectangle(1090,670,1275,700);
    settextstyle(8,HORIZ_DIR,1);
    setbkcolor(0);
    outtextxy(1093,675,"Encerrar Votação");
}

//diogolima
