using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._4_calculator_
{
    /// <summary>
    /// класс Стек на основе списка
    /// </summary>
    public class ListStack : IStack
    {
        private class ListStackElement
        {
            public int Value { get; set; }

            public ListStackElement Next { get; set; }

            /// <summary>
            /// конструктор, создающий элемент списка
            /// </summary>
            /// <param name="value">значение</param>
            /// <param name="next">следующий элемент</param>
            public ListStackElement(int value, ListStackElement next)
            {
                this.Value = value;
                this.Next = next;
            }
        }

        /// <summary>
        /// длина списка
        /// </summary>
        public int Length { get; private set; }
        
        /// <summary>
        /// голова списка
        /// </summary>
        private ListStackElement head = null;

        /// <summary>
        /// вернуть значение из головы и удалить его из стека
        /// </summary>
        /// <returns>значение</returns>
        public int Pop()
        {
            if (head == null)
            {
                throw new EmptyStackException("поппытка извлечь элемент из пустого стека");
            }
            int value = head.Value;
            head = head.Next;
            Length--;

            return value;
        }

        /// <summary>
        /// добавить значение в стек
        /// </summary>
        /// <param name="value">значение для добавления</param>
        public void Push(int value)
        {
            var newElement = new ListStackElement(value, head);
            head = newElement;
            Length++;
        }

        /// <summary>
        /// проверить список на пустоту
        /// </summary>
        /// <returns>список пуст</returns>
        public bool IsEmpty() => head == null;

        /// <summary>
        /// вернуть значение из головы
        /// </summary>
        /// <returns>значение</returns>
        public int Peek() => head.Value;

        /// <summary>
        /// проверить, принадлежит ли значение списку
        /// </summary>
        /// <param name="value">значение</param>
        /// <returns>значение принадлежит списку</returns>
        public bool IsContaining(int value)
        {
            ListStackElement element = head;
            while ((element != null) && (element.Value != value))
            {
                element = element.Next;
            }
            return ((element != null) && (element.Value == value));
        }
    }
}
