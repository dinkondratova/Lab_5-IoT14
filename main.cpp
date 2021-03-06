
#include "MyArray.h"

ostream& operator<<(ostream& os, const MyArray& dt)
{
	for (unsigned int i = 0; i < dt.size; i++)
	{
		os << dt.array[i] << ' ';
	}
	return os;
}

void MyArray::Merge(int A[], int p, int q, int r)     /*It merges two arrays */
{

	int n1 = q - p + 1, i, j, k;       /*n1 is the size of L[]*/

	int n2 = r - q;               /*n2 is the sixe of R[]*/

	int* L= new int[n1]; 
	int* R = new int[n2];

	for (i = 0; i < n1; i++)

	{
		L[i] = A[p + i];
	}

	for (j = 0; j < n2; j++)
	{
		R[j] = A[q + j + 1];
	}

	i = 0, j = 0;

	for (k = p; i < n1&&j < n2; k++)
	{
		if (L[i] < R[j])
		{
			A[k] = L[i++];
		}
		else
		{
			A[k] = R[j++];
		}
	}

	while (i < n1)             /*If L[] has more elements than R[] then it will put all the remaining elements of L[] into A[]*/
	{
		A[k++] = L[i++];
	}

	while (j < n2)             /*If R[] has more elements than L[] then it will put all the remaining elements of R[] into A[]*/
	{
		A[k++] = R[j++];
	}
}

void MyArray::MergeSort(int A[], int p, int r)    /*It will will divide the array and sort them while merging them*/
{
	int q;

	if (p < r)
	{
		q = (p + r) / 2;                      /*q is the middle element to divide the array*/
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}

}

int main(void)
{
	unsigned int i = 0;
	int product = 1;


	// Temporary row arrays initialization
	static int a0[NUM] = { 1 ,16 ,21 ,11 ,6 };
	static int a1[NUM] = { 2 ,17 ,22 ,12 ,7 };
	static int a2[NUM] = { 3 ,18 ,23 ,13 ,8 };
	static int a3[NUM] = { 4 ,19 ,24 ,14, 9 };
	static int a4[NUM] = { 5 ,20 ,25 ,15,10 };

	// Construct array of MyArray objects
	MyArray A[5] = {
		MyArray(NUM, a0),
		MyArray(NUM, a1),
		MyArray(NUM, a2),
		MyArray(NUM, a3),
		MyArray(NUM, a4),
	};

	// Display intial values of each row
	cout << "Source arrays " << endl;

	for (i = 0; i < NUM; i++)
	{
		cout << A[i] << endl;
	}
	// Sort every row
	cout << "Sorted arrays " << endl;

	for (i = 0; i < NUM; i++)
	{
		A[i].Sort();
		cout << A[i] << endl;
	}

	// Calculate median for row values laying under main diagonal

	cout << "Row median values " << endl;

	for (i = 1; i < NUM; i++)
	{
		cout << A[i].GetMedianValueUnderMainDiag(i) << endl;

		// Immediatelly calculate product of median values
		product = product * A[i].GetMedianValueUnderMainDiag(i);
	}

	cout << "Product of row median values " << endl;
	cout << product << endl;


	getchar();
}





