using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task1._3
{
    class Program
    {
        static void CountingSort(int[] mainArray, int max)
        {
            int[] additionalArray = new int[max];

            for (int i = 0; i < mainArray.Length; i++)
            {
                additionalArray[mainArray[i]]++;
            }

            int numberOfElement = 0;
            for (int i = 0; i < additionalArray.Length; i++)
            {
                for (int j = 1; j <= additionalArray[i]; j++)
                {
                    mainArray[numberOfElement] = i;
                    numberOfElement++;
                }
            }
        }

        static bool TestSort(int[] array)
        {
            CountingSort(array, 21);
            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] < array[i - 1])
                {
                    return false;
                }
            }
            return true;
        }

        static bool Test()
        {
            const int n = 10;
            int[] array1 = new int[n] { 0, 3, 3, 3, 6, 7, 10, 11, 20, 20 };
            int[] array2 = new int[n] { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6 };
            int[] array3 = new int[n] { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
            return (TestSort(array1) && TestSort(array2) && TestSort(array3));
        }

        static void Main(string[] args)
        {
            if (!Test())
            {
                Console.WriteLine("error!");
                return;
            }

            const int max = 21;
            const int lengthOfArray = 10;
            int[] array = new int[lengthOfArray];

            Console.WriteLine("enter values from 0 to 20");
            for (int i = 0; i < lengthOfArray; i++)
            {
                Int32.TryParse(Console.ReadLine(), out array[i]);
            }

            CountingSort(array, max);

            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
        }
    }
}
