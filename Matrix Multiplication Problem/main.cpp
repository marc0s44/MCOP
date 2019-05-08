#include <iostream> 
#include<iomanip> 
#include<cstdio> 
using namespace std; 
int counter = 0; 
void print_matrix(int m[5][5] , int n)
{ 
	for(int i = 0 ; i< n ; i++)
	{ 
		for(int j = 0 ; j< n ; j++)
	{ 
			cout << setw(10) << m[i][j]; 
	} 
	cout << endl; 
	} 
} 
char ccc[50]; 
int cc = 0; 
void print(int s[5][5],int l,int h) 
{ 
	if(s[l][h]!=0) 
	{ 
		printf("(parenthesis[%d][%d] = %d) != 0 " , l,h ,s[l][h]);
		cout << " , then print ( and call function again\n";
		///cout<<"("; 
		ccc[cc] = '(';
		cc++; print(s,l,s[l][h]);
	} 
	if(s[l][h]==0)
	{
		///cout << "A" << ++counter;
		++counter;
		ccc[cc] = 'A';
		cc++;
		ccc[cc] = counter + '0';
		cc++; 
		printf("(parenthesis[%d][%d] = %d) == 0 " ,l,h , s[l][h]);
		cout << " , then print matrix " << "A" << counter << endl;
	} 
	if(s[l][h]!=0) 
	{
		print(s,s[l][h]+1,h);
		printf("(parenthesis[%d][%d] = %d) != 0 ", l,h , s[l][h]); 
		cout << " ,call function again and then print ) \n";
		///cout<<")";
		ccc[cc] = ')'; cc++; 
	} 
} 
int main()
{
	int n = 5, i;
	int p[] = { 12,7,8,5,3 };
	int m[5][5] = { 0 };
	int s[5][5] = { 0 };
	int j, q;
	cout << "All Matrix Dimensions : \nmatrix_size = ";
	for (int i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	for (int d = 1; d < n - 1; d++)
	{
		for (int i = 1; i < n - d; i++)
		{
			j = i + d; m[i][j] = 9999;
			cout << "storing minimum total multiplications from matrix " << i << " to matrix " << j << endl << endl;
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				printf("total multiplication = cost_matrix[%d][%d] + cost_matrix[%d][%d] + matrix_size[%d] * matrix_size[%d] * matrix_size[%d] = %d + %d + %d*%d*%d = %d\n", i, k, k + 1, j, i - 1, k, j, m[i][k], m[k + 1][j], p[i - 1], p[k], p[j], q);
				if (q < m[i][j]) {
					m[i][j] = q; s[i][j] = k;
				}
			}
			printf(" ==> minimum total multiplication ( cost_matrix[%d][%d] ) = %d\n", i, j, m[i][j]); cout << endl;
			print_matrix(m, n);
			printf("\nmatrix for parenthesis ( parenthesis[%d][%d] ) = %d\n", i, j, s[i][j]);
			print_matrix(s, n);
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
		}
	}
	cout << "TOTAL MULTIPLICATIONS : " << m[1][n - 1] << " \n\n";
	cout << "\n\n\n\nPARENTHESIS : \n";
	print(s, 1, 4);
	cout << endl << endl;
	cout << "\nFinal Parenthesis : ";
	for (int i = 0; i < cc; i++)
		cout << ccc[i];
	cout << endl << endl << endl << endl << endl;
}