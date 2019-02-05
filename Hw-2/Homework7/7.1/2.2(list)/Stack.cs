using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7._1
{
    /// <summary>
    /// класс Стек
    /// </summary>
    public class Stack<T>
    {
        /// <summary>
        /// длина
        /// </summary>
        private int length;

        public int Length => this.length;

        /// <summary>
        /// элемент стека
        /// </summary>
        private class StackElement
        {
            /// <summary>
            /// значение
            /// </summary>
            private T value;

            public T Value => this.value;

            /// <summary>
            /// следующий элемент
            /// </summary>
            private StackElement next;

            public StackElement Next => this.next;

            /// <summary>
            /// конструктор, создающий элемент стека
            /// </summary>
            public StackElement(T value, StackElement next)
            {
                this.value = value;
                this.next = next;
            }
        }

        /// <summary>
        /// голова стека
        /// </summary>
        private StackElement head;

        /// <summary>
        /// добавить значение в стек
        /// </summary>
        /// <param name="value">значение для добавления</param>
        public void Push(T value)
        {
            StackElement newHead = new StackElement(value, head);
            head = newHead;
            length++;
        }

        /// <summary>
        /// взять значение из головы и удалить его из стека
        /// </summary>
        /// <returns>значение</returns>
        public T Pop()
        {
            if (head == null)
            {
                throw new DeleteException("попытка удалить элемент из пустого списка");
            }
            length--;
            T headValue = head.Value;
            head = head.Next;
            return headValue;
        }

        /// <summary>
        /// проверить, пуст ли стек
        /// </summary>
        /// <returns>стек пуст</returns>
        public bool IsEmpty() => head == null;
    }
}
