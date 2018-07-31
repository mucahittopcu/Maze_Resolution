#include <stdio.h>
#include <stdlib.h>

struct yigin
{

    int verim;
    int verin;
    struct yigin* sonraki;

};

int satir,sutun;
int main()
{
    srand(time(NULL));
    printf("\t\t\t\t\t LABIRENTE HOSGELDINIZ!\n");
    int i,j,a,b;
    B:
        printf("Matrisin boyutunu giriniz?...\n");
        scanf("%d", &a);
        scanf("%d", &b);


        if(a>0 && a<=40 && b>0 && b<=105)
        {

            satir=a+2;
            sutun=b+2;
            int matris[a+2][b+2];
            int kontrolmatris[a+2][b+2];

            for(i=0; i<a+2; i++)
            {
                for(j=0; j<b+2; j++)
                {
                    matris[i][j]=rand() % 2;
                }

            }

            for(i=0; i<a+2; i++)
            {
                for(j=0; j<b+2; j++)
                {
                    if(i==0 || j ==0 || i==a+1 || j==b+1)
                        matris[i][j]=0;
                }

            }

            for(i=1; i<a+1; i++)
            {
                for(j=1; j<b+1; j++)
                {
                    printf("%d ", matris[i][j]);
                }
                printf("\n");
            }

            for(i=0; i<a+2; i++)
            {
                for(j=0; j<b+2; j++)
                {
                    kontrolmatris[i][j]=0;
                }

            }
            gez(matris,kontrolmatris);
        }
        else
        {
            printf("!!! Lutfen satir sayisi en fazla 40 sutun sayisini en fazla 105 olarak giriniz!... ");
            goto B;
        }


}
int gez(int matris[satir][sutun],int kontrolmatris[satir][sutun]){

    int c,d,e,f,i,j;

    struct yigin* kok = NULL;

    printf("Hangi satir ve sutunda baslasin?\n");
    scanf("%d %d",&c, &d);
    printf("Hangi satir ve sutunda bitsin?\n");
    scanf("%d %d",&e, &f);
    printf("\n");

    int x=c+1,y=d+1,z=0;

    if(matris[x][y]==1 && kontrolmatris[x][y]==0)
    {
        kontrolmatris[x][y]=1;
        ekle(&kok,x-1,y-1);
        A:
        if(x==e+1 && y==f+1){
            printf("\nYol bulundu!....\n\n");
            yazdir(&kok);
            system("color a");
            goto Q;
        }
        //Saga gidiliyor mu diye bakar
        y++;
        if(matris[x][y]==1 && kontrolmatris[x][y]==0)
        {
            kontrolmatris[x][y]=1;
            ekle(&kok,x-1,y-1);
            goto A;
        }
        else if((matris[x][y]==0) || kontrolmatris[x][y]==1)
        {   y--;

            if(kontrolmatris[x][y+1]==1 && z==1){


                al(&kok);
                matris[x][y]=0;
                kontrolmatris[x][y]=0;
                y++;
                z--;
                goto A;
            }

            //Asagi gidiliyor mu diye bakar
            x++;
            if(matris[x][y]==1 && kontrolmatris[x][y]==0)
            {
                kontrolmatris[x][y]=1;
                ekle(&kok,x-1,y-1);
                goto A;
            }
            else if(matris[x][y]==0 || kontrolmatris[x][y]==1)
            {   x--;

                if(z==1 && kontrolmatris[x+1][y]==1){

                    al(&kok);
                    matris[x][y]=0;
                    kontrolmatris[x][y]=0;
                    x++;
                    z--;
                    goto A;
                }

                //Sola gidiliyor mu diye bakar
                y--;
                if(matris[x][y]==1 && kontrolmatris[x][y]==0)
                {
                    kontrolmatris[x][y]=1;
                    ekle(&kok,x-1,y-1);
                    goto A;
                }
                else if(matris[x][y]==0 || kontrolmatris[x][y]==1)
                {   y++;


                    if(z==1 && kontrolmatris[x][y-1]==1){

                        al(&kok);
                        matris[x][y]=0;
                        kontrolmatris[x][y]=0;
                        y--;
                        z--;

                        goto A;
                    }

                    //Yukary gidiliyor mu diye bakar
                    x--;
                    if(matris[x][y]==1 && kontrolmatris[x][y]==0)
                    {
                        kontrolmatris[x][y]=1;
                        ekle(&kok,x-1,y-1);
                        goto A;
                    }
                    else if(matris[x][y]==0 || kontrolmatris[x][y]==1 )
                    {
                        x++;
                        //Eger her yöne bakip 1 bulamazsa bunlari yapar...

                        if(z==1 && kontrolmatris[x-1][y]==1){
                            al(&kok);
                            matris[x][y]=0;
                            kontrolmatris[x][y]=0;
                            x--;
                            z--;
                            goto A;
                        }
                        z++;

                        if(z==2){
                            printf("Yol yok!...");
                            system("color c");
                            goto Q;
                        }
                        if(z==1){
                            goto A;
                        }
                    }
                }


            }

        }

    }else{
         printf("Yol yok!...\n");
         system("color c");

    }
    printf("\n");
    Q:


    printf("\n");

    return 0;
}
struct yigin* yeni(int veri1,int veri2)
{
    struct yigin* yigindugum = (struct yigin*) malloc(sizeof(struct yigin));
    yigindugum->verim = veri1;
    yigindugum->verin = veri2;
    yigindugum->sonraki = NULL;
    return yigindugum;
}
void ekle(struct yigin** kok, int verix,int veriy)
{

    struct yigin* yigindugum = yeni(verix,veriy);
    yigindugum->sonraki = *kok;
    *kok = yigindugum;
    printf("++[ %d ] [ %d ] yigina eklendi\n", verix, veriy );
}

void al(struct yigin** kok)
{

    struct yigin* sil = *kok;
    *kok = (*kok)->sonraki;

    printf("--[ %d ] [ %d ] yigindan silindi\n", sil->verim , sil->verin);
    free(sil);

}
void yazdir(struct yigin** kok){

    struct yigin* kes = *kok;
    int i,j;
    int sonuc[satir][sutun];
    for(i=0; i<satir; i++)
    {
        for(j=0; j<sutun; j++)
        {
            sonuc[i][j]=0;
        }

    }

    while(kes!=NULL){

        //printf("- [%d][%d]  -\n", kes->verim,kes->verin);
        sonuc[kes->verim][kes->verin]=1;
        kes = kes->sonraki;
    }

    for(i=0; i<satir-2; i++)
    {
        for(j=0; j<sutun-2; j++)
        {

            printf("%d ", sonuc[i][j]);

        }
        printf("\n");
    }


}
