#include <iostream>
using namespace std;

class DiagonalMatrix
{
private:
    int n;
    int *A;

public:
    DiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[n];
    };

    void Set(int i, int j, int x)
    {
        if (i == j)
            A[i - 1] = x;
    };

    int Get(int i, int j)
    {
        if (i != j)
            return 0;
        return A[i];
    };

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    cout << '0';
                else
                    cout << A[i];
            }
            cout << endl;
        }
    };

    ~DiagonalMatrix()
    {
        delete[] A;
    };
};

class LowerTriangularMatrix
{
private:
    int n;
    int *A;

public:
    LowerTriangularMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    };

    void Set(int i, int j, int x)
    {
        if (i >= j)
            A[i * (i - 1) / 2 + j - 1] = x;
    };

    int Get(int i, int j)
    {
        if (i < j)
            return 0;
        return A[i * (i - 1) / 2 + j - 1];
    };

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < j)
                    cout << '0';
                else
                    cout << A[i * (i - 1) / 2 + j - 1];
            }
            cout << endl;
        }
    };

    ~LowerTriangularMatrix()
    {
        delete[] A;
    };
};

class Element
{
public:
    int i;
    int j;
    int x;
};

class SparseMatrix
{
private:
    int m, n;
    int num;
    Element *ele;

public:
    SparseMatrix(int m = 0, int n = 0, int num = 0)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[num];
    }

    ~SparseMatrix()
    {
        delete[] ele;
    }

    friend istream &operator>>(istream &is, SparseMatrix &s);
    friend ostream &operator<<(ostream &os, const SparseMatrix &s);
    SparseMatrix operator+(const SparseMatrix &s);
};

istream &operator>>(istream &is, SparseMatrix &s)
{
    cout << "Enter row column value for each non-zero element:\n";
    for (int i = 0; i < s.num; i++)
    {
        is >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return is;
}

ostream &operator<<(ostream &os, const SparseMatrix &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (k < s.num && s.ele[k].i == i && s.ele[k].j == j)
            {
                os << s.ele[k].x << " ";
                k++;
            }
            else
            {
                os << "0 ";
            }
        }
        os << endl;
    }

    return os;
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix &s)
{
    if (m != s.m || n != s.n)
        throw invalid_argument("Matrices have different dimensions.");
    SparseMatrix sum(m, n, num + s.num);
    int i = 0, j = 0, k = 0;
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i ||
            (ele[i].i == s.ele[j].i && ele[i].j < s.ele[j].j))
        {
            sum.ele[k++] = ele[i++];
        }
        else if (ele[i].i > s.ele[j].i ||
                 (ele[i].i == s.ele[j].i && ele[i].j > s.ele[j].j))
        {
            sum.ele[k++] = s.ele[j++];
        }
        else
        {
            sum.ele[k] = ele[i];
            sum.ele[k].x = ele[i].x + s.ele[j].x;

            if (sum.ele[k].x != 0)
                k++;

            i++;
            j++;
        }
    }

    while (i < num)
        sum.ele[k++] = ele[i++];

    while (j < s.num)
        sum.ele[k++] = s.ele[j++];

    sum.num = k;
    return sum;
}

int main()
{
    DiagonalMatrix d(4);
    d.Set(1, 1, 5);
    d.Set(2, 2, 4);
    d.Set(3, 3, 3);
    d.Set(4, 4, 2);

    d.Display();

    LowerTriangularMatrix d1(3);
    d1.Set(0, 0, 4);
    d1.Set(1, 1, 3);
    d1.Set(1, 2, 2);
    d1.Set(2, 0, 3);
    d1.Set(2, 1, 5);
    d1.Set(2, 2, 2);

    d1.Display();

    SparseMatrix s1(5, 5, 4);
    SparseMatrix s2(5, 5, 4);

    cout << "Enter first matrix\n";
    cin >> s1;

    cout << "Enter second matrix\n";
    cin >> s2;

    SparseMatrix s3 = s1 + s2;

    cout << "\nFirst Matrix:\n";
    cout << s1;

    cout << "\nSecond Matrix:\n";
    cout << s2;

    cout << "\nSum:\n";
    cout << s3;
    
    return 0;
}