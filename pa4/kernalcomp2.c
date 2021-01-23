/**
 * Kernel computation of C=A*K. 
 * NOTE: In this program, we provide our own startup code and do not rely on any
 * C standard library features.
 * As such, this program compiles safely with the "-nostdlib" linker flag.
 */

asm("li sp, 0x100000"); // SP set to 1 MB
asm("jal main");        // call main
asm("mv a1, a0");       // save return value in a1
asm("li a7, 10");       // prepare ecall exit
asm("ecall");           // now your simulator should stop

//Please modify the following Ar and Ac:
#define Ar 12       // Row dimension of A matrix
#define Ac 12       // Col dimension of A matrix
#define Ks 2        // Dimension of K kernel 2X2
#define Br (Ar - 2) // Row Dimension of B matrix
#define Bc (Ac - 2) // Col Dimension of B matrix

void printstr(volatile char *ptr);

void start()
{
    char *str = "Start calculation:\n";
    printstr(str);
    return;
}

void printstr(volatile char *ptr)
{ // ptr is passed through register a0
    asm("li a7, 4");
    asm("ecall");
}

void printint(int r)
{
    asm("li a7, 1");
    asm("ecall");
}

void printmatrixA(const int a[Ar][Ac], int rsize, int csize)
{
    for (int row = 0; row < rsize; row++)
    {
        for (int col = 0; col < csize; col++)
        {
            printint(a[row][col]);
            printstr(", ");
        }
        printstr("\n");
    }
}
void printmatrixK(const int a[Ks][Ks], int rsize, int csize)
{
    for (int row = 0; row < rsize; row++)
    {
        for (int col = 0; col < csize; col++)
        {
            printint(a[row][col]);
            printstr(", ");
        }
        printstr("\n");
    }
}
void printmatrixB(const int a[Br][Bc], int rsize, int csize)
{
    for (int row = 0; row < rsize; row++)
    {
        for (int col = 0; col < csize; col++)
        {
            printint(a[row][col]);
            printstr(", ");
        }
        printstr("\n");
    }
}

void kernelcomp(const int a[Ar][Ac], const int k[Ks][Ks], int b[Br][Bc])
{
    for (int row = 0; row < Ar - 2; row += 2)
    {
        for (int col = 0; col < Ac - 2; col += 2)
        {
            for (int r_offset = 0; r_offset <= 1; r_offset++)
            {
                for (int c_offset = 0; c_offset <= 1; c_offset++)
                {

                    for (int i = 0; i <= 1; i++)
                    {
                        for (int j = 0; j <= 1; j++)
                        {
                            // printf("i = %d, j = %d\n", i, j);
                            // printf("row + r_offset + i = %d, col + c_offset + j = %d\n", row + r_offset + i, col + c_offset + j);
                            b[row + r_offset][col + c_offset] += -a[row + r_offset + i][col + c_offset + j] * k[i][j];
                            b[row + r_offset][col + c_offset] += -a[row + r_offset + i + 1][col + c_offset + j] * k[i][j];
                            b[row + r_offset][col + c_offset] += -a[row + r_offset + i][col + c_offset + j + 1] * k[i][j];
                            b[row + r_offset][col + c_offset] += -a[row + r_offset + i + 1][col + c_offset + j + 1] * k[i][j];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    static const int A[Ar][Ac] = {
        {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}};
    static const int K[Ks][Ks] = {
        {1, -1},
        {-1, 1}};
    static int B[Br][Bc] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    start();
    kernelcomp(A, K, B);
    printmatrixA(A, Ar, Ac);
    printmatrixK(K, Ks, Ks);
    printmatrixB(B, Br, Bc);
    return 0;
}
