using System;

namespace task1._5
{
    class Program
    {
        static void SwapColumn(int[,] array, int column1, int column2)
        {
            for (int i = 0; i < array.GetLength(0); i++)
            {
                int k = array[i, column1];
                array[i, column1] = array[i, column2];
                array[i, column2] = k;
            }
        }

        static void BubbleSort(int[,] array)
        {
            for (int i = 0; i < array.GetLength(1) - 1; i++)
            {
                for (int j = 1; j < array.GetLength(1) - i; j++)
                {
                    if (array[0,j] < array[0, j - 1])
                    {
                        SwapColumn(array, j - 1, j);
                    }
                }
            }
        }

        static bool Test()
        {
            const int n0 = 3;
            const int n1 = 3;
            int[,] array = new int[n0, n1] { { 3, 1, 2 }, { 4, 5, 6 }, { 7, 8, 9 } };
            BubbleSort(array);
            if ((array[0,0] == 1) && (array[0,1] == 2) && (array[0,2] == 3) && (array[1,0] == 5) && (array[2,2] == 7))
            {
                return true;
            }
            return false;
        }

        static void Main(string[] args)
        {
            if (!Test())
            {
                Console.WriteLine("error!");
                return;
            }

            int line = 5;
            int column = 4;
            int[,] array = new int[line, column];

            Console.WriteLine("enter values of the array");
            for (int i = 1; i <= line; i++)
            {
                Console.WriteLine("line " + i + ":");
                for (int j = 0; j < column; j++)
                {
                    array[i - 1, j] = int.Parse(Console.ReadLine());
                }
            }

            BubbleSort(array);
           
            for (int i = 0; i < line; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    Console.Write(array[i,j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
