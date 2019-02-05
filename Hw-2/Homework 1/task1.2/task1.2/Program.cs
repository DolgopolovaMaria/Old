using System;

namespace task1._2
{
    class Program
    {
        static int Fibonacci(int number)
        {
            if((number == 1) || (number == 2))
            {
                return 1;
            }

            int n1 = 1;
            int n2 = 1;
            int n3 = 2;
            for (int i = 4; i <= number; i++)
            {
                n1 = n2;
                n2 = n3;
                n3 = n1 + n2;
            }
            return n3;
        }

        static bool Test()
        {
            if ((Fibonacci(1) == 1) && (Fibonacci(5) == 5) && (Fibonacci(10) == 55))
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

            Console.WriteLine("enter the number");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine("Fibonacci(" + n + ") = " + Fibonacci(n));
        }
    }
}
