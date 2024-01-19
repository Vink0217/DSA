#include <stdio.h>
#include <stdlib.h>

// Diagonal Matrix

struct Matrix
{
    // Static declaration of array
    int *A;
    int n;
};

void setDiag(struct Matrix *m, int i, int j, int data)
{
    // Creation of diagonal matrix by storing only nonzero diagonal elements
    if (i==j)
    {
        m->A[i-1] = data;
    }
}

void getDiag(struct Matrix m, int i, int j)
{
    // Retrieval of diagonal elements
    if (i==j)
    {
        printf("%d ", m.A[i-1]);
    }
    else
    {
        printf("0 ");
    }
}

void displaydiag(struct Matrix m)
{
    // Printing diagonal matrix
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i==j)
            {
                printf("%d ", m.A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Row Major of Upper Triangular = Column Major of Lower Triangular & vice versa

// Lower Triangular Matrix
void Setlower(struct Matrix *m, int i, int j, int data)
{
    // Input taken only for nonzero elements in rows
    if (i>=j)
    {
        // Row Major Order for Accessing Lower Diagonal Elements
        m->A[i*(i-1)/2 + j-1] = data;
        // Column Major Order
        // m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = data;
    }
}

void displaylower(struct Matrix m)
{
    // Printing lower diagonal Matrix
    int i, j;
    printf("\nMatrix: \n");
    // Starting from (1,1)
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i>=j)
            {
                printf("%d ", m.A[i*(i-1)/2 + (j-1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int getlower(struct Matrix m, int i, int j)
{
    if (i>=j)
    {
        return("%d", m.A[i * (i - 1) / 2 + (j - 1)]);
    }
    else
    {
        return 0;
    }
}

void Setupper(struct Matrix *m, int i, int j, int data)
{
    // Input taken only for nonzero elements in rows
    if (i<=j)
    {
        // Row Major Order for Accessing Lower Diagonal Elements
        // m->A[j*(j-1)/2 + i-j] = data;
        // Column Major Order
        m->A[m->n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i] = data;
    }
}

void displayupper(struct Matrix m)
{
    // Printing lower diagonal Matrix
    int i, j;
    printf("\nMatrix: \n");
    // Starting from (1,1)
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i<=j)
            {
                printf("%d ", m.A[m.n*(i-1)+(i-2)*(i-1)/2+j-i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int getupper(struct Matrix m, int i, int j)
{
    if (i<=j)
    {
        return("%d", m.A[m.n*(i-1)+(i-2)*(i-1)/2+j-i]);
    }
    else
    {
        return 0;
    }
}

// For symmetric matrix take upper triangular input and reverse the input for lower triangular




void main()
{
    struct Matrix m;

    int i, j, data;
    printf("Enter no. of rows: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n - 1) / 2 * sizeof(int));

    // Diagonal Matrix

    // setDiag(&m, 1, 1, 5);
    // setDiag(&m, 2, 2, 8);
    // setDiag(&m, 3, 3, 9);
    // setDiag(&m, 4, 4, 12);
    // displaydiag(m);

    // printf("\n");
    // getDiag(m, 2,3);
    // printf("\n");

    for (i = 1; i <= m.n; i++)
    {
        printf("Row: \n");
        for (j = 1; j <= m.n; j++)
        {
            printf("Enter data for element [%d][%d]:  ", i, j);
            scanf("%d", &data);
            Setupper(&m, i, j, data);
        }
        printf("\n");
    }

    // displaylower(m);
    // printf("\n %d", getlower(m, 2, 1));

    displayupper(m);
    printf("\n%d", getupper(m, 2, 3));
}