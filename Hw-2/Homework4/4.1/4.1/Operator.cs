using System;

namespace _4._1
{
    /// <summary>
    /// класс Оператор
    /// </summary>
    internal class Operator : TreeElement
    {
        /// <summary>
        /// тип оператора
        /// </summary>
        enum OperatorType {Addition, Subtraction, Multiplication, Division};
        private OperatorType operatorType;

        /// <summary>
        /// левый сын
        /// </summary>
        public TreeElement Left { get; set; }

        /// <summary>
        /// правый сын
        /// </summary>
        public TreeElement Right { get; set; }

        private void SetOperatorType(char symbol)
        {
            switch (symbol)
            {
                case '+':
                    {
                        this.operatorType = OperatorType.Addition;
                        break;
                    }
                case '-':
                    {
                        this.operatorType = OperatorType.Subtraction;
                        break;
                    }
                case '*':
                    {
                        this.operatorType = OperatorType.Multiplication;
                        break;
                    }
                case '/':
                    {
                        this.operatorType = OperatorType.Division;
                        break;
                    }
            }
        }

        private char GetOperatorType()
        {
            switch (operatorType)
            {
                case OperatorType.Addition:
                    {
                        return '+';
                    }
                case OperatorType.Subtraction:
                    {
                        return '-';
                    }
                case OperatorType.Multiplication:
                    {
                        return '*';
                    }
                case OperatorType.Division:
                    {
                        return '/';
                    }
                default:
                    {
                        return '0';
                    }
            }
        }

        /// <summary>
        /// конструктор, создающий экземпляр класса Оператор
        /// </summary>
        /// <param name="type">тип оператора</param>
        public Operator(char type) => this.SetOperatorType(type);

        /// <summary>
        /// распечатать оператор в строку результата
        /// </summary>
        public override string Print() => "(" + GetOperatorType() + " " + Left.Print() + " " + Right.Print() + " )";

        /// <summary>
        /// вычислить значение
        /// </summary>
        public override int Count()
        {
            int value1 = Left.Count();
            int value2 = Right.Count();

            switch (this.GetOperatorType())
            {
                case '+':
                    return value1 + value2;
                case '-':
                    return value1 - value2;
                case '*':
                    return value1 * value2;
                case '/':
                    if (value2 == 0)
                    {
                        throw new ExceptionDivision("деление на ноль");
                    }
                    return value1 / value2;
                default:
                    throw new IncorrectExpressionException("Некорректное выражение");
            }
        }
    }
}
