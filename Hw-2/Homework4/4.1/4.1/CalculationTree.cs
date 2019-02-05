using System;

namespace _4._1
{
    /// <summary>
    /// класс дерево разбора
    /// </summary>
    public class CalculationTree
    {
        private Operator root;

        public CalculationTree() { }

        /// <summary>
        /// построение дерева разбора
        /// </summary>
        /// <param name="str">выражение</param>
        private Operator BuildTree(string str)
        {
            TreeElement leftChild = null;
            TreeElement rightChild = null;

            int index = 0;

            if (str[index] == '(')
            {
                string newStr = str.Substring(1, str.Length - 2);
                str = newStr;
            }

            if (str[index] == ' ')
            {
                index++;
            }

            char operate = str[index];

            index++;
            if (str[index] == ' ')
            {
                index++;
            }

            if (str[index] == '(')
            {
                string newstr = GetExpression(str, ref index);

                leftChild = BuildTree(newstr);

                index++;
                if (str[index] == ' ')
                {
                    index++;
                }
            }
            else
            {
                if (str[index] == ' ')
                {
                    index++;
                }

                if ((str[index] >= '0') && (str[index] <= '9'))
                {
                    leftChild = new Operand(Convert.ToInt32(str[index]) - Convert.ToInt32('0'));
                }

                index++;

                if (str[index] == ' ')
                {
                    index++;
                }
            }

            if (str[index] == ' ')
            {
                index++;
            }

            if (str[index] == '(')
            {
                string newstr = GetExpression(str, ref index);

                rightChild = BuildTree(newstr);

                if (str[index] == ' ')
                {
                    index++;
                }
            }
            else
            {
                if (str[index] == ' ')
                {
                    index++;
                }

                if ((str[index] >= '0') && (str[index] <= '9'))
                {
                    rightChild = new Operand(Convert.ToInt32(str[index]) - Convert.ToInt32('0'));
                }

                index++;

                if ((index < str.Length - 1) && (str[index] == ' '))
                {
                    index++;
                }
            }

            var newOperator = new Operator(operate);
            newOperator.Left = leftChild;
            newOperator.Right = rightChild;
            return newOperator;
        }

        private string GetExpression(string str, ref int index)
        {
            int ind = 1;
            string newstr = "(";
            while (ind != 0)
            {
                index++;

                if (str[index] == '(')
                {
                    ind++;
                }
                if (str[index] == ')')
                {
                    ind--;
                }

                newstr = newstr + str[index];
            }
            return newstr;
        }

        /// <summary>
        /// построить дерево разбора
        /// </summary>
        /// <param name="expression">выражение</param>
        public void Build(string expression) => this.root = BuildTree(expression);
        
        /// <summary>
        /// посчитать выражение
        /// </summary>
        /// <param name="expression">выражение</param>
        /// <returns>результат вычисления</returns>
        public int Calculate(string expression)
        {
            this.Build(expression);
            return root.Count();
        }

        /// <summary>
        /// распечатать дерево
        /// </summary>
        /// <returns></returns>
        public string PrintTree() => root.Print();
    }
}
