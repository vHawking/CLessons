//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int i = 0; // i counter in the matrix
//    int j = 0; // j counter in the matrix
//    int sz; // size of the array
//    int t = 0; // element counter in the array
//    int isz; // i-size of the matrix
//    int jsz; // j-size of the matrix
//
//    cout<<"Vvedite kolichestvo strok:"<<endl;
//    cin>>isz;
//    cout<<"Vvedite kolichestvo stolbcov:"<<endl;
//    cin>>jsz;
//    if(isz < 1 || jsz < 1) {
//        return -1;
//    }
//    sz = isz * jsz;
//    int iceil = 0; // ceiling
//    int ifloor = isz - 1; // floor
//    int jlwall = 0; // left wall
//    int jrwall = jsz - 1; // right wall
//    int *a; // array used for storing the matrix
//
//    a = new int [sz];
//    for(; ; ) {
//        // left-to-right
//        i = iceil;
//        for(j = jlwall; j <= jrwall; j++) {
//            a[j + i * jsz] = ++t;
//        }
//        if(++iceil > ifloor) {
//            break;
//        }
//        // going down
//        j = jrwall;
//        for(i = iceil; i <= ifloor; i++) {
//            a[j + i * jsz] = ++t;
//        }
//        if(--jrwall < jlwall) {
//            break;
//        }
//        // right-to-left
//        i = ifloor;
//        for(j = jrwall; j >= jlwall; j--) {
//            a[j + i * jsz] = ++t;
//        }
//        if(--ifloor < iceil) {
//            break;
//        }
//        // going up
//        j = jlwall;
//        for(i = ifloor; i >= iceil; i--) {
//            a[j + i * jsz] = ++t;
//        }
//        if(++jlwall > jrwall) {
//            break;
//        }
//    }
//    for(i = 0; i < isz; i++) {
//        for (j = 0; j < jsz; j++)
//            cout<<a[j + i * jsz]<<" ";
//        cout<<endl;
//    }
//    delete a;
//    return 0;
//}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <iostream>

using namespace std;
//---------------------------------------------------------------------------



void Print( int **Mas, int sizeY, int sizeX )
{
    for ( int y = 0; y < sizeY; y++ )
    {
        for ( int x = 0; x < sizeX; x++ )
        {
            if ( Mas[y][x] < 10 ) cout << " " << Mas[y][x] << " ";
            else cout << Mas[y][x] << " ";
//            cout << Mas[y][x] << "\t";
        }
        cout << endl;
    }
}

void FillHelix( int **Mas, int col, int row )
{
    int sum = row * col;
    int CorrectY = 0;
    int CorrectX = 0;
    int Count = 1;
    while( col > 0 )
    {
        for ( int y = 0; y < 4; y++ ) {
            for ( int x = 0; x < ( ( row < col ) ? col : row ); x++ ) {
                if ( y == 0 && x < row - CorrectX && Count <= sum ) {
                    Mas[y + CorrectY][x + CorrectX] = Count++;
                }
                if ( y == 1 && x < col - CorrectY && x != 0 && Count <= sum ) {
                    Mas[x + CorrectY][row - 1] = Count++;
                }
                if ( y == 2 && x < row - CorrectX && x != 0 && Count <= sum ) {
                    Mas[col - 1][row - (x + 1)] = Count++;
                }
                if ( y == 3 && x < col - ( CorrectY + 1 ) && x != 0 && Count <= sum ) {
                    Mas[col - (x + 1)][CorrectY] = Count++;
                }
            }
        }
        col--;
        row--;
        CorrectY++;
        CorrectX++;
    }
}

int main(int argc, char* argv[])
{
    int row = 9;
    int col = 5;
    int **Mas = new int*[row];
    for ( int i = 0; i < row; i++ ) Mas[i] = new int[col];
    for ( int y = 0; y < row; y++ )
        for ( int x = 0; x < col; x++ ) Mas[y][x] = 0;
    FillHelix( Mas, row, col );
    Print( Mas, row, col );
    for ( int i = 0; i < row; i++ ) delete [] Mas[i];
    delete [] Mas;
    return 0;
}