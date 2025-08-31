#include <stdio.h>
#include <math.h>
#define max 100
int i,j,k,n,r1,r2,c1,c2;
int mat1[max][max],mat2[max][max];
FILE *fp;
void take_size_1 ()
{
    printf ("Matrix's row size   : ");
    scanf ("%d",&r1);
    printf ("Matrix's Column size: ");
    scanf ("%d",&c1);
}
void take_size_2 ()
{
    printf ("1st matrix's row size   : ");
    scanf ("%d",&r1);
    printf ("1st matrix's Column size: ");
    scanf ("%d",&c1);
    printf ("2nd matrix's row size   : ");
    scanf ("%d",&r2);
    printf ("2nd matrix's column size: ");
    scanf ("%d",&c2);
}
void take_mat1 (int r, int c)
{
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
}
void take_mat2 (int r, int c)
{
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
}
void sum (int r, int c)
{
    int mats[r][c];
    printf("Result of addition:\n");
    fprintf(fp,"Result of addition:\n");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            mats[i][j]=mat1[i][j]+mat2[i][j];
            printf("%d ",mats[i][j]);
            fprintf(fp,"%d ",mats[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
}
void sub (int r, int c)
{
    int mats[r][c];
    printf("Result of subtraction:\n");
    fprintf(fp,"Result of subtraction:\n");
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            mats[i][j]=mat1[i][j]-mat2[i][j];
            printf("%d ",mats[i][j]);
            fprintf(fp,"%d ",mats[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
}
void multi (int r1, int c1, int c2)
{
    int matm[r1][c2];
    for (i=0; i<r1; i++)
    {
        for (j=0; j<c2; j++)
        {
            matm[i][j]=0;
            for (k=0; k<c1; k++)
            {
                matm[i][j]+=(mat1[i][k]*mat2[k][j]);
            }
        }
    }
    printf("Result of multiplication:\n");
    fprintf(fp,"Result of multiplication:\n");
    for (i=0; i<r1; i++)
    {
        for (j=0; j<c2; j++)
        {
            printf("%d ",matm[i][j]);
            fprintf(fp,"%d ",matm[i][j]);
        }
        printf("\n");
        fprintf(fp,"\n");
    }
}
void trans (int r, int c)
{
    printf("Transpose matrix:\n");
    fprintf(fp,"Transpose matrix:\n");
    for (i=0; i<c; i++)
    {
        for (j=0; j<r; j++)
        {
            printf("%d ",mat1[j][i]);
            fprintf(fp,"%d ",mat1[j][i]);
        }
        printf("\n");
        fprintf(fp,"\n");

    }
}
int determinant(int mat[max][max], int n)
{
    int det=0;
    int submat[max][max];
    if (n==1)
    {
        return mat[0][0];
    }
    else if (n==2)
    {
        return (mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0]);
    }
    else
    {
        for (int x=0; x<n; x++)
        {
            int subi=0;
            for (i=1; i<n; i++)
            {
                int subj=0;
                for (j=0; j<n; j++)
                {
                    if (j==x)
                        continue;
                    submat[subi][subj]=mat[i][j];
                    subj++;
                }
                subi++;
            }
            det+=((x%2==0?1:-1)*mat[0][x]*determinant(submat,n-1));
        }
    }
    return det;
}
void diagonals (int n)
{
    int sump=0,sums=0;
    printf("Primary diagonal elements          : ");
    fprintf(fp,"Primary diagonal elements          : ");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i==j)
            {
                printf("%d ",mat1[i][j]);
                fprintf(fp,"%d ",mat1[i][j]);
                sump+=mat1[i][j];
            }
        }
    }
    printf("\nSum of primary diagonal elements   : %d\n",sump);
    fprintf(fp,"\nSum of primary diagonal elements   : %d\n",sump);
    printf("Secondary diagonal elements        : ");
    fprintf(fp,"Secondary diagonal elements        : ");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i+j==n-1)
            {
                printf("%d ",mat1[i][j]);
                fprintf(fp,"%d ",mat1[i][j]);
                sums=sums+mat1[i][j];
            }
        }
    }
    printf("\nSum of secondary diagonal elements : %d\n",sums);
    fprintf(fp,"\nSum of secondary diagonal elements : %d\n",sums);
}
int trace (int n)
{
    int sum=0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i==j)
                sum+=mat1[i][j];
        }
    }
    return sum;
}
float normal (int n)
{
    float sum=0.0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            sum+=(mat1[i][j]*mat1[i][j]);
        }
    }
    return sqrt(sum);
}
int saddle (int r, int c)
{
    int ma,mi,p;
    for (i=0; i<r; i++)
    {
        p=0;
        mi=mat1[i][0];
        for (j=0; j<c; j++)
        {
            if (mi>mat1[i][j])
            {
                mi=mat1[i][j];
                p=j;
            }
        }
        ma=0;
        for(j=0; j<c; j++)
        {
            if (ma<mat1[j][p])
            {
                ma=mat1[j][p];
            }
        }
        if (mi==ma)
            return mi;
    }
    return -1;
}
int identity (int n)
{
    int count1=0,count2=0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (mat1[i][j]==1)
                count1++;
            else if (mat1[i][j]==0)
                count2++;
        }
    }
    if (count1==n && count2==(n*n)-n)
        return 1;
    else
        return 0;
}
int symmetric (int n)
{
    int count=0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            mat2[i][j]=mat1[j][i];
        }
    }
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (mat1[i][j]==mat2[i][j])
                count++;
        }
    }
    if (count==n*n)
        return 1;
    else
        return 0;
}
void min_max (int r, int c)
{
    int ma=mat1[0][0];
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            if (mat1[i][j]>ma)
            {
                ma=mat1[i][j];
            }
        }
    }
    int mi=mat1[0][0];
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            if (mat1[i][j]<mi)
            {
                mi=mat1[i][j];
            }
        }
    }
    printf ("The maximum value of the matrix: %d\n",ma);
    printf ("The minimum value of the matrix: %d\n",mi);
    fprintf (fp,"The maximum value of the matrix: %d\n",ma);
    fprintf (fp,"The minimum value of the matrix: %d\n",mi);
}
int occurrence (int r, int c, int s)
{
    int count=0;
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            if (mat1[i][j]==s)
            {
                count++;
            }
        }
    }
    if (count==0)
        return 0;
    else
        return count;
}
void sum_rc (int r, int c)
{
    int sumr=0,sumc=0;
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            sumr+=mat1[i][j];
        }
        printf ("Sum of row%d is    : %d\n",i+1,sumr);
        fprintf (fp,"Sum of row%d is    : %d\n",i+1,sumr);
        sumr=0;
    }
    for (i=0; i<c; i++)
    {
        for (j=0; j<r; j++)
        {
            sumc+=mat1[j][i];
        }
        printf ("Sum of column%d is : %d\n",i+1,sumc);
        fprintf (fp,"Sum of column%d is : %d\n",i+1,sumc);
        sumc=0;
    }
}
void sort (int r, int c, int n)
{
    int temp[n];
    int k=0;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            temp[k++]=mat1[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (temp[i]<temp[j])
            {
                int t=temp[i];
                temp[i]=temp[j];
                temp[j]=t;
            }
        }
    }
    k=0;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            mat1[i][j]=temp[k++];
        }
    }
    printf ("Sorted matrix:\n");
    fprintf (fp,"Sorted matrix:\n");
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            printf ("%d ",mat1[i][j]);
            fprintf (fp,"%d ",mat1[i][j]);
        }
        printf ("\n");
        fprintf (fp,"\n");
    }
}
int compare (int r, int c)
{
    int count=0;
    for (int i=0; i<r1; i++)
    {
        for (int j=0; j<c1; j++)
        {
            if (mat1[i][j]==mat2[i][j])
                count++;
        }
    }
    if (count==r1*c1)
        return 1;
    else
        return 0;
}
int path (int r, int c)
{
    int i,j,ma;
    int a[r][c];
    for (i=0; i<r; i++)
    {
        a[i][0]=1;
    }
    for (j=0; j<c; j++)
    {
        a[0][j]=1;
    }
    for (i=1; i<r; i++)
    {
        for (j=1; j<c; j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    return ma=a[r-1][c-1];
}
int main()
{
    fp = fopen("History.txt","w");
    printf("----------//Welcome to Matrix Calculator\\\\----------\n\n");
    while (1)
    {
        printf("What kind of calculation do you need?\n");
        printf("1  - Matrix Addition\n");
        printf("2  - Matrix Subtraction\n");
        printf("3  - Matrix Multiplication\n");
        printf("4  - Transpose Matrix\n");
        printf("5  - Determinant\n");
        printf("6  - Diagonal of Matrix\n");
        printf("7  - Trace of Matrix\n");
        printf("8  - Normal of Matrix\n");
        printf("9  - Saddle Point of Matrix\n");
        printf("10 - Is Identity Matrix\n");
        printf("11 - Is Symmetric Matrix\n");
        printf("12 - Minimum and Maximum Element\n");
        printf("13 - Occurrence of Element\n");
        printf("14 - Sum of Row and Column\n");
        printf("15 - Sort Matrix\n");
        printf("16 - Compare Matrix\n");
        printf("17 - Find possible path\n");
        printf("0  - If you want to exit\n");
        printf("------------------------------------------------------\n");
        printf("Enter number according to your choice: ");
        scanf("%d",&n);
        printf("------------------------------------------------------\n");
        switch (n)
        {
        case 0:
            printf("Thank you.\n");
            break;
        case 1:
            printf("Give Informations:\n");
            take_size_2();
            if (r1!=r2 || c1!=c2)
            {
                printf("Sorry! Addition is not possible.\n");
                fprintf(fp,"Sorry! Addition is not possible.\n");
                break;
            }
            printf ("Enter 1st Matrix:\n");
            take_mat1(r1,c1);
            printf ("Enter 2nd Matrix:\n");
            take_mat2(r2,c2);
            sum(r1,c1);
            break;
        case 2:
            printf("Give Informations:\n");
            take_size_2();
            if (r1!=r2 || c1!=c2)
            {
                printf("Sorry! Subtraction is not possible.\n");
                fprintf(fp,"Sorry! Subtraction is not possible.\n");
                break;
            }
            printf ("Enter 1st Matrix:\n");
            take_mat1(r1,c1);
            printf ("Enter 2nd Matrix:\n");
            take_mat2(r2,c2);
            sub(r1,c1);
            break;
        case 3:
            printf("Give Informations:\n");
            take_size_2();
            if (c1!=r2)
            {
                printf("Sorry! Multiplication is not possible.\n");
                fprintf(fp,"Sorry! Multiplication is not possible.\n");
                break;
            }
            printf ("Enter 1st Matrix:\n");
            take_mat1(r1,c1);
            printf ("Enter 2nd Matrix:\n");
            take_mat2(r2,c2);
            multi(r1,c1,c2);
            break;
        case 4:
            printf("Give Informations:\n");
            take_size_1();
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            trans(r1,c1);
            break;
        case 5:
            printf("Give Informations:\n");
            take_size_1();
            if (r1!=c1)
            {
                printf("Sorry! Not a square matrix.\n");
                fprintf(fp,"Sorry! Not a square matrix.\n");
                break;
            }
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            printf("Result of determinant: %d\n",determinant(mat1,r1));
            fprintf(fp,"Result of determinant: %d\n",determinant(mat1,r1));
            break;
        case 6:
            printf("Give Informations:\n");
            take_size_1();
            if (r1!=c1)
            {
                printf("Sorry! Not a square matrix.\n");
                fprintf(fp,"Sorry! Not a square matrix.\n");
                break;
            }
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            diagonals(r1);
            break;
        case 7:
            printf("Give Informations:\n");
            take_size_1();
            if (r1!=c1)
            {
                printf("Sorry! Not a square matrix.\n");
                fprintf(fp,"Sorry! Not a square matrix.\n");
                break;
            }
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            printf("Trace of the matrix: %d\n",trace(r1));
            fprintf(fp,"Trace of the matrix: %d\n",trace(r1));
            break;
        case 8:
            printf("Give Informations:\n");
            take_size_1();
            if (r1!=c1)
            {
                printf("Sorry! Not a square matrix.\n");
                fprintf(fp,"Sorry! Not a square matrix.\n");
                break;
            }
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            printf("Normal of the matrix: %.2f\n",normal(r1));
            fprintf(fp,"Normal of the matrix: %.2f\n",normal(r1));
            break;
        case 9:
            printf("Give Informations:\n");
            take_size_1();
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            int point=saddle(r1,c1);
            if (point!=-1)
            {
                printf("Saddle point of the matrix: %d\n",point);
                fprintf(fp,"Saddle point of the matrix: %d\n",point);
            }
            else
            {
                printf("No saddle point found\n");
                fprintf(fp,"No saddle point found\n");
            }
            break;
        case 10:
            printf("Give Informations:\n");
            take_size_1();
            if (r1!=c1)
            {
                printf("Sorry! Not a square matrix.\n");
                fprintf(fp,"Sorry! Not a square matrix.\n");
                break;
            }
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            if (identity(r1))
            {
                printf ("The given matrix is an identity matrix\n");
                fprintf (fp,"The given matrix is an identity matrix\n");
            }
            else
            {
                printf ("The given matrix is not an identity matrix\n");
                fprintf (fp,"The given matrix is not an identity matrix\n");
            }
            break;
        case 11:
            printf("Give Informations:\n");
            take_size_1();
            if (r1!=c1)
            {
                printf("Sorry! Not a square matrix.\n");
                fprintf(fp,"Sorry! Not a square matrix.\n");
                break;
            }
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            if (symmetric(r1))
            {
                printf ("The given matrix is symmetric.\n");
                fprintf (fp,"The given matrix is symmetric.\n");
            }
            else
            {
                printf ("The given matrix is not symmetric.\n");
                fprintf (fp,"The given matrix is not symmetric.\n");
            }
            break;
        case 12:
            printf("Give Informations:\n");
            take_size_1();
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            min_max(r1,c1);
            break;
        case 13:
            printf("Give Informations:\n");
            take_size_1();
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            int s;
            printf ("Enter the search element: ");
            scanf ("%d",&s);
            int c=occurrence(r1,c1,s);
            if (c!=0)
            {
                printf ("The searched element's occurrence: %d\n",c);
                fprintf (fp,"The searched element's occurrence: %d\n",c);
            }
            else
            {
                printf ("The element is not found\n");
                fprintf (fp,"The element is not found\n");
            }
            break;
        case 14:
            printf("Give Informations:\n");
            take_size_1();
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            sum_rc(r1,c1);
            break;
        case 15:
            printf("Give Informations:\n");
            take_size_1();
            printf("Enter The Matrix:\n");
            take_mat1(r1,c1);
            sort(r1,c1,r1*c1);
            break;
        case 16:
            printf("Give Informations:\n");
            take_size_2();
            if (r1!=r2 || c1!=c2)
            {
                printf("Matrices will not be equal.\n");
                fprintf(fp,"Matrices will not be equal.\n");
                break;
            }
            printf ("Enter 1st Matrix:\n");
            take_mat1(r1,c1);
            printf ("Enter 2nd Matrix:\n");
            take_mat2(r2,c2);
            if (compare(r1,c1))
            {
                printf("Given matrices are equal.\n");
                fprintf(fp,"Given matrices are equal.\n");
            }
            else
            {
                printf("Given matrices are not equal.\n");
                fprintf(fp,"Given matrices are not equal.\n");
            }
            break;
        case 17:
            printf("Give Informations:\n");
            printf("Enter row position: ");
            scanf("%d",&r1);
            printf("Enter column position: ");
            scanf("%d",&c1);
            printf("Given matrices are not equal.\n");
            fprintf(fp,"Given matrices are not equal.\n");
            break;
        default:
            printf("Wrong Entry\n");
            printf("------------------------------------------------------\n");
            printf("Choice carefully\n");
        }
        printf("------------------------------------------------------\n");
        if (n==0)
            break;
        printf("Do you want to calculate another conversion?\n");
        printf("1 - Yes\n");
        printf("0 - No\n");
        printf("------------------------------------------------------\n");
        printf("Make your choice: ");
        scanf("%d",&n);
        if (n==0)
        {
            printf("------------------------------------------------------\n");
            printf("Thank you.\n");
            break;
        }
        else
        {
            printf("------------------------------------------------------\n");
            continue;
        }
    }
    fclose(fp);
    printf("\n------------------------------------------------------\n");
    printf("Here's the history:\n");
    printf("------------------------------------------------------\n");
    char ch;
    fp = fopen("History.txt","r");
    while (!feof(fp))
    {
        ch=getc(fp);
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}
