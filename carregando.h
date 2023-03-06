#include <graphics.h>

void carregar(int x1, int y1)
{
    int i, menos=30, a=0;
    int cor[8][3]= {{250,250,250},
                    {220,220,220},
                    {190,190,190},
                    {160,160,160},
                    {130,130,130},
                    {100,100,100},
                    {70,70,70},
                    {40,40,40}};
        for(i = 1; i <= 8; i++)
        {

            if (cor[0][0] == 10)
            {
                cor[0][1] = 250;
                cor[0][2] = 250;
                cor[0][3] = 250;
            }
            if (cor[1][0] == 10)
            {
                cor[1][1] = 250;
                cor[1][2] = 250;
                cor[1][3] = 250;
            }
            if (cor[2][0] == 10)
            {
                cor[2][1] = 250;
                cor[2][2] = 250;
                cor[2][3] = 250;
            }
            if (cor[3][0] == 10)
            {
                cor[3][1] = 250;
                cor[3][2] = 250;
                cor[3][3] = 250;
            }
            if (cor[4][0] == 10)
            {
                cor[4][1] = 250;
                cor[4][2] = 250;
                cor[4][3] = 250;
            }
            if (cor[5][0] == 10)
            {
                cor[5][1] = 250;
                cor[5][2] = 250;
                cor[5][3] = 250;
            }
            if (cor[6][0] == 10)
            {
                cor[6][1] = 250;
                cor[6][2] = 250;
                cor[6][3] = 250;
            }
            if (cor[7][0] == 10)
            {
                cor[7][1] = 250;
                cor[7][2] = 250;
                cor[7][3] = 250;
            }
        setfillstyle(1,COLOR(cor[0][0] - (i*30),cor[0][1] - (i*30),cor[0][2] - (i*30)));
        setcolor(COLOR(cor[0][0] - (i*30),cor[0][1] - (i*30),cor[0][2] - (i*30)));
        fillellipse(x1,y1+12,4,4);//baixo

        setfillstyle(1,COLOR(cor[1][0] - (i*30),cor[1][1] - (i*30),cor[1][2] - (i*30)));
        setcolor(COLOR(cor[1][0] - (i*30),cor[1][1] - (i*30),cor[1][2] - (i*30)));
        fillellipse(x1+8,y1+8,4,4);//INFERIOR direita

        setfillstyle(1,COLOR(cor[2][0] - (i*30),cor[2][1] - (i*30),cor[2][2] - (i*30)));
        setcolor(COLOR(cor[2][0] - (i*30),cor[2][1] - (i*30),cor[2][2] - (i*30)));
        fillellipse(x1+12,y1,4,4);//direta

        setfillstyle(1,COLOR(cor[3][0] - (i*30),cor[3][1] - (i*30),cor[3][2] - (i*30)));
        setcolor(COLOR(cor[3][0] - (i*30),cor[3][1] - (i*30),cor[3][2] - (i*30)));
        fillellipse(x1+8,y1-8,4,4);//SUPERIOR direita

        setfillstyle(1,COLOR(cor[4][0] - (i*30),cor[4][1] - (i*30),cor[4][1] - (i*30)));
        setcolor(COLOR(cor[4][0] - (i*30),cor[4][1] - (i*30),cor[4][2] - (i*30)));
        fillellipse(x1,y1-12,4,4);//baixo

        setfillstyle(1,COLOR(cor[5][0] - (i*30),cor[5][1] - (i*30),cor[5][2] - (i*30)));
        setcolor(COLOR(cor[5][0] - (i*30),cor[5][1] - (i*30),cor[5][2] - (i*30)));
        fillellipse(x1-8,y1-8,4,4);//SUPERIOR esquerda

        setfillstyle(1,COLOR(cor[6][0] - (i*30),cor[6][1] - (i*30),cor[6][2] - (i*30)));
        setcolor(COLOR(cor[6][0] - (i*30),cor[6][1] - (i*30),cor[6][2] - (i*30)));
        fillellipse(x1-12,y1,4,4);//esquerda

        setfillstyle(1,COLOR(cor[7][0] - (i*30),cor[7][1] - (i*30),cor[7][2] - (i*30)));
        setcolor(COLOR(cor[7][0] - (i*30),cor[7][1] - (i*30),cor[7][2] - (i*30)));
        fillellipse(x1-8,y1+8,4,4);//ESQUERDA esquerda

        delay(125);
        printf("%d", cor[0][0]);
        if(a == 4)
            break;
        if(i == 8)
        {
            i = 0;
            a++;
        }
        }
}

void carregar2(int x, int y, int x1, int y1, int tempo)
{
    int i;
    setcolor(0);
    setlinestyle(0,0,4);
    rectangle(x-2, y-2, x1+2, y1+2);
    setfillstyle(1,0);
    for(i = x; i <= x1; i++)
    {
        bar(x, y, i, y1);
        delay(tempo);
    }
}
void carregar3(int x,int y,int x1,int y1,int tempo)
{
    int i, j, k;
    setcolor(0);
    setlinestyle(0,1,3);
    for(k = 0; k <3; k++)
    {
        for(i = x-30; i <= x1; i++)
        {
            i++;
            setfillstyle(1,0);
            bar(i,y,i+30,y1);
            if (i <= x1 || i >= x)
            {
                setfillstyle(1,15);
                bar(x1+2,y,x1+31,y1);
                bar(x-30,y,x-2,y1);
            }

            rectangle(x,y,x1,y1);
            for(j = i-2; j <= x1; j++)
            {
                j++;
                setfillstyle(1,15);
                bar(j-1,y,i,y1);
                rectangle(x,y,x1,y1);
                break;
            }
            delay(tempo);
        }
    }
}


