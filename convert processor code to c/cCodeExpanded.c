int main()
{
    int A[9];
    int B[10];
    int C[10];
    FILE *ff = fopen("f1", "r");
    for (int i=0; i<9; i++)
        fscanf(ff, "%d", &A[i]);
    close(ff);
    for(int i=0; i<9; i++)
        printf("%d", A[i]);
    for(int i=0; i<9; i++)
        A[i] = B[i];
    for(int i=0; i<10; i++)
        B[i] = 5;
    for(int i=0; i<10; i++)
        C[i] = A[i] + B[i];
    for(int i=0; i<10; i++)
        C[i] = 2 * B[i];
    for(int i=0; i<10; i++)
        C[i] = A[i] / 5;
    for(int i=0; i<10; i++)
        printf("%d", C[i]);
}
