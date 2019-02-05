using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._4_calculator_
{
    /// <summary>
    /// класс Стек на основе массива
    /// </summary>
    public class ArrayStack : IStack
    {
        /// <summary>
        /// максимальный размер стека
        /// </summary>
        private const int maxSize = 100;

        /// <summary>
        /// текущий размер стека
        /// </summary>
        private int currentSize;

        /// <summary>
        /// массив
        /// </summary>
        private int[] array = new int[maxSize];

        /// <summary>
        /// добавить значение в стек
        /// </summary>
        /// <param name="value">значение для добавления в стек</param>
        public void Push(int value)
        {
            if (currentSize > maxSize - 2)
            {
                throw new OverflowException("переполненеие стека");
            }
            array[currentSize] = value;
            currentSize++;
        }

        /// <summary>
        /// вернуть значение из головы и удалить его из стека
        /// </summary>
        /// <returns>значение</returns>
        public int Pop()
        {
            if (currentSize < 1)
            {
                throw new EmptyStackException("поппытка извлечь элемент из пустого стека");
            }
            currentSize--;
            return array[currentSize];
        }

        /// <summary>
        /// проверить список на пустоту
        /// </summary>
        /// <returns>список пуст</returns>
        public bool IsEmpty() => currentSize == 0;

        /// <summary>
        /// вернуть значение из головы
        /// </summary>
        /// <returns>значение</returns>
        public int Peek() => array[currentSize - 1];

        /// <summary>
        /// проверить, принадлежит ли значение списку
        /// </summary>
        /// <param name="value">значение для проверки</param>
        /// <returns>значение принадлежит списку</returns>
        public bool IsContaining(int value)
        {
            for (int i = 0; i < currentSize; i++)
            {
                if (array[i] == value)
                {
                    return true;
                }
            }
            return false;
        }
    }
}
