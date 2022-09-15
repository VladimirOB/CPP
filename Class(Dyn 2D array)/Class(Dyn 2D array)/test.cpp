//#include "pch.h"
//
//int main(void)
//{
//	int rows, cols;
//	FILE* file_r = fopen("Matrix_Load.txt", "r");
//	if (file_r != NULL)
//	{
//		/*char str[4];
//		fgets(str, 4, file_r);
//		char columns[1] = { str[2] };
//		rows = atoi(str);
//		cols = atoi(columns);*/
//
//		char str[4];
//		fgets(str, 4, file_r);
//		rows = str[0]-48;
//		cols = str[2]-48;
//		//rows = atoi(str);
//		//cols = atoi(str);
//
//		
//
//
//		int** arr = new int* [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			arr[i] = new int[cols];
//		}
//
//		//fseek(file_r, 5, SEEK_SET); // rewind(file_r) << аналог fseek(file_r, 0, SEEK_SET);
//
//		for (int i = 0; i < rows; i++)
//		{
//			for (int k = 0; k < cols; k++)
//			{
//				fscanf(file_r, "%d", &arr[i][k]);
//			}
//		}
//
//		for (int i = 0; i < rows; i++)
//		{
//			for (int k = 0; k < cols; k++)
//			{
//				cout << arr[i][k] << " ";
//			}
//			cout << endl;
//		}
//
//		fclose(file_r);
//	}
//	else
//		puts("Error open");
//}