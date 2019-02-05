using System;

namespace _2._4_calculator_
{
    /// <summary>
    /// класс стековый калькулятор
    /// </summary>
    public class Calculator
    {
        private IStack stack;

        public Calculator(IStack stack)
        {
            this.stack = stack;
        }

        /// <summary>
        /// выполняется бинарная операция
        /// </summary>
        /// <param name="value1">значение</param>
        /// <param name="value2">значение</param>
        /// <param name="mathOperator">оператор</param>
        /// <returns>результат</returns>
        private int Calculate(int value1, int value2, char mathOperator)
        {
            switch (mathOperator)
            {
                case '+':
                    {
                        return value1 + value2;
                    }
                case '-':
                    {
                        return value1 - value2;
                    }
                case '*':
                    {
                        return value1 * value2;
                    }
                case '/':
                    {
                        return value1 / value2;
                    }
                default:
                    {
                        return 0;
                    }
            }
        }

        /// <summary>
        /// обработка символа
        /// </summary>
        /// <param name="symbol"></param>
        private void Calc(char symbol)
        {
            if ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'))
            {
                int value1 = stack.Pop();
                int value2 = stack.Pop();

                int res = Calculate(value2, value1, symbol);

                stack.Push(res);
            }
            else
            {
                if ((symbol < '0') || (symbol > '9'))
                {
                    throw new IncorrectException("введен некорректный символ");
                }
                stack.Push(Convert.ToInt32(symbol - '0'));
            }
        }

        /// <summary>
        /// вычисление значения выражения
        /// </summary>
        /// <param name="str">выражение</param>
        /// <returns>результат</returns>
        public int GetResult(string str)
        {
            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] != ' ')
                {
                    Calc(str[i]);
                }
            }
            return stack.Pop();
        }
    }
}
