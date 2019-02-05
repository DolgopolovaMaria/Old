using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _6._1
{
    /// <summary>
    /// класс Калькулятор
    /// </summary>
    public partial class Calculator : Form
    {
        /// <summary>
        /// инициализирует форму
        /// </summary>
        public Calculator() => InitializeComponent();

        /// <summary>
        /// при нажатии кнопок с цифрами вывод соответствующей цифры
        /// </summary>
        private void OnButtonNumberClick(object sender, EventArgs e)
        {
            var button = sender as Button;
            if (textBox.Text == "Деление на 0!")
            {
                textBox.Clear();
            }
            textBox.Text += button.Text;
        }

        private void OnButtonPointClick(object sender, EventArgs e)
        {
            if ((!textBox.Text.Contains(",")) && (!(textBox.Text.Length == 0)) && (Char.IsDigit(textBox.Text[textBox.Text.Length - 1])))
            {
                textBox.Text += ",";
            }
        }

        /// <summary>
        /// значение первого введенного числа
        /// </summary>
        private float value = 0;
        
        /// <summary>
        /// результат вычислений
        /// </summary>
        private float result = 0;
        
        /// <summary>
        /// тип оператора
        /// </summary>
        private char operation = ' ';

        /// <summary>
        /// имеет значение true, если оператор уже был введен
        /// </summary>
        private bool operatorWasEntered = false;

        /// <summary>
        /// при нажатии кнопки с оператором он выводится на экран и переменной "operation" присваивается тип оператора
        /// </summary>
        private void OnButtonOperationClick(object sender, EventArgs e)
        {
            var button = sender as Button;
            string enteredOperator = button.Text;

            if ((!(textBox.Text.Length == 0)) && (Char.IsDigit(textBox.Text[textBox.Text.Length - 1])))
            {
                if (operatorWasEntered)
                {
                    Calculation();
                }
                if (textBox.Text == "Деление на 0!")
                {
                    return;
                }
                value = float.Parse(textBox.Text);
                textBox.Text += enteredOperator;
                operation = enteredOperator[0];
                operatorWasEntered = true;
            }
        }

        /// <summary>
        /// вывод результата на экран
        /// </summary>
        private void OutputResult()
        {
            textBox.Clear();
            textBox.Text = result.ToString();
        }
        
        /// <summary>
        /// вычисление введенного выражения и вывод результата
        /// </summary>
        private void Calculation()
        {
            switch (operation)
            {
                case '+':
                    {
                        result = value + float.Parse(textBox.Text.Substring(textBox.Text.IndexOf('+') + 1, textBox.Text.Length - textBox.Text.IndexOf('+') - 1));
                        OutputResult();
                        break;
                    }
                case '-':
                    {
                        result = value - float.Parse(textBox.Text.Substring(textBox.Text.IndexOf('-') + 1, textBox.Text.Length - textBox.Text.IndexOf('-') - 1));
                        OutputResult();
                        break;
                    }
                case '*':
                    {
                        result = value * float.Parse(textBox.Text.Substring(textBox.Text.IndexOf('*') + 1, textBox.Text.Length - textBox.Text.IndexOf('*') - 1));
                        OutputResult();
                        break;
                    }
                case '/':
                    {
                        float value2 = float.Parse(textBox.Text.Substring(textBox.Text.IndexOf('/') + 1, textBox.Text.Length - textBox.Text.IndexOf('/') - 1));
                        if (value2 == 0)
                        {
                            textBox.Text = "Деление на 0!";
                            operatorWasEntered = false;
                            return;
                        }
                        result = value / value2;
                        OutputResult();
                        break;
                    }
            }
        }

        /// <summary>
        /// при нажатии кнопки "=" выражение вычисляется и результат выводится на экран
        /// </summary>
        private void OnButtonResClick(object sender, EventArgs e)
        {
            if (textBox.Text == "Деление на 0!")
            {
                textBox.Clear();
                return;
            }
            Calculation();
            operatorWasEntered = false;
        }

        /// <summary>
        /// при нажатии "С" сброс введенного выражения
        /// </summary>
        private void OnButtonClearClick(object sender, EventArgs e)
        {
            textBox.Text = "";
        }

        /// <summary>
        /// удаление последнего введенного символа
        /// </summary>
        private void OnButtonDeleteClick(object sender, EventArgs e)
        {
            textBox.Text = textBox.Text.Substring(0, textBox.Text.Length - 1);
        }

        /// <summary>
        /// при нажатии "+/-" смена знака числа
        /// </summary>
        private void OnButtonNegativeClick(object sender, EventArgs e)
        {
            bool isNumber = int.TryParse(textBox.Text, out int num);
            if (isNumber)
            {
                if (float.Parse(textBox.Text) > 0)
                {
                    textBox.Text = "-" + textBox.Text;
                }
                else if (float.Parse(textBox.Text) < 0)
                {
                    textBox.Text = textBox.Text.Substring(1, textBox.Text.Length - 1);
                }
            }
        }
    }
}
