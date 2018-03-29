//#include <stdio.h>
//
//void fun_spiral (int a[10][10], int str, int stb)
//{
//    int z, b, x = 0, y = 1, chislo = 1, xx = (10-str)/2, yy = (10-stb)/2;
//
//    z = str*stb;
//
//    while (chislo != z+1)
//    {
//        for (b = x; b < stb; b++)
//        {
//            a[x+xx][b+yy] = chislo;
//            chislo++;
//        }//for
//
//        for (b = y; b < str; b++)
//        {
//            a[b+xx][(stb-1)+yy] = chislo;
//            chislo++;
//        }//for
//
//        if (chislo == z+1)
//        {
//            break;
//        }//if
//
//        y++;
//        stb--;
//
//        for (b = stb-1; b > x; b--)
//        {
//            a[str-1+xx][b+yy] = chislo;
//            chislo++;
//        }//for
//
//        for (b = str-1; b > x; b--)
//        {
//            a[b+xx][x+yy] = chislo;
//            chislo++;
//        }//for
//
//        x++;
//        str--;
//    }//while
//}//fun_spiral
//
//int main ()
//{
//    setbuf(stdout, NULL);
//    int str, stb, mass_a[10][10] = {};
//
//    printf ("Vvedite razmer matrizi \n");
//    scanf ("%i %i", &str, &stb);
//
//    fun_spiral (mass_a, str, stb);
//
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            if (mass_a[i][j] == 0)
//            {
//                printf (" \t");
//            }//if
//            else
//            {
//                printf ("%i\t", mass_a[i][j]);
//            }//else
//        }//for
//        printf ("\n");
//    }//for str
//
//    return (0);
//}//main
//
#include <locale.h>

#include <stdio.h>
#include <stdlib.h>

//#include <stdio.h>
//#include <conio.h>
//int i,j, n, nsqr, q ;
//int dx[9], dy[9], h[29][29] ;
//void prnt(void)
//{
//    int p, r ;
//    for ( p = 1 ; p<=n ; p++)
//    {
//        for ( r = 1 ; r<=n ; r++ )
//            printf("%2d ", h[p][r] ) ;
//        printf("\n") ;
//    }
//    printf("\n") ;
//}
//int t ( int i, int x, int y)
//// возвращает 1, если доска заполнена, 0 - если нет продолжений
//{
//    int j, u, v , q1=0 ;
//    for(j=1; (!q1) && (j<=8); j++)
//    {
//        u = x+dx[j] ; v = y +dy[j] ;
//        if ( 1<= u && u <=n && 1 <=v && v<=n && h[u][v]==0)
//        {
//            h[u][v] = i ;
//            if (i<nsqr)
//            {q1 = t (i+1, u, v) ;
//                if (q1==0) h[u][v]=0 ;
//            } else q1 = 1 ;
//        }
//    }
//    return q1 ;
//}
//main()
//{
//    dx[1] =  2; dx[2] =  1; dx[3] = -1; dx[4] = -2;
//    dx[5] = -2; dx[6] = -1; dx[7] =  1; dx[8] =  2;
//    dy[1] =  1; dy[2] =  2; dy[3] =  2; dy[4] =  1;
//    dy[5] = -1; dy[6] = -2; dy[7] = -2; dy[8] = -1;
//    n=8 ;
//    nsqr = n*n ;
//    //clrscr() ;
//    h[1][1]=1 ;
//    if (t (2, 1, 1)==0) printf("\nнет решений") ;
//    else prnt() ;
//    getch() ;
//}
