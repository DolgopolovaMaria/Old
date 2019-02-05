using System;

namespace task1._1
{
    class Program
    {
        private static int Factorial(int n)
        {
            if ((n == 1) || (n == 0))
            {
                return 1;
            }

            return n * Factorial(n - 1);
        }

        private static bool Test()
        {
            if ((Factorial(0) == 1) && (Factorial(1) == 1) && (Factorial(5) == 120) && (Factorial(8) == 40320))
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
            Console.WriteLine("Factorial(" + n + ") = " + Factorial(n));
        }
    }
}
