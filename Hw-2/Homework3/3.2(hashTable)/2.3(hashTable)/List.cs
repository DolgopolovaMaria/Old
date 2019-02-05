using System;

namespace _2._3_hashTable_
{
    /// <summary>
    /// класс список
    /// </summary>
    public class List
    {
        /// <summary>
        /// элемент списка
        /// </summary>
        private class ListElement
        {
            /// <summary>
            /// значение элемента
            /// </summary>
            public int Value { get; set; }

            /// <summary>
            /// следующий элемент
            /// </summary>
            public ListElement Next { get; set; }

            /// <summary>
            /// конструктор, создающий элемент списка
            /// </summary>
            /// <param name="value">значение</param>
            /// <param name="next">следующий элемент</param>
            public ListElement(int value, ListElement next)
            {
                this.Value = value;
                this.Next = next;
            }
        }

        /// <summary>
        /// длина списка
        /// </summary>
        public int Length { get; set; }

        /// <summary>
        /// голова списка
        /// </summary>
        private ListElement head = null;

        /// <summary>
        /// добавить элемент в голову
        /// </summary>
        /// <param name="value">значение</param>
        public void Push(int value)
        {
            var newElement = new ListElement(value, head);
            head = newElement;
            Length++;
        }

        /// <summary>
        /// проверить, пустой ли список
        /// </summary>
        /// <returns>список пуст</returns>
        public bool IsEmpty() => head == null;

        /// <summary>
        /// удалить элемент из головы
        /// </summary>
        public void DeleteElementFromHead()
        {
            if (head == null)
            {
                return;
            }
            head = head.Next;
            Length--;
        }

        /// <summary>
        /// распечатать список
        /// </summary>
        public void PrintList()
        {
            ListElement element = head;
            while (element != null)
            {
                Console.WriteLine(element.Value);
                element = element.Next;
            }
        }

        /// <summary>
        /// удалить значение из списка
        /// </summary>
        /// <param name="value">значение для удаления</param>
        public void DeleteElement(int value)
        {
            while ((head != null) && (head.Value == value))
            {
                DeleteElementFromHead();
            }

            ListElement element = head;
            while (element != null)
            {
                while ((element.Next != null) && (element.Next.Value == value))
                {
                    element.Next = element.Next.Next;
                    Length--;
                }
                element = element.Next;
            }
        }

        /// <summary>
        /// удалить список
        /// </summary>
        public void DeleteList() => head = null;

        /// <summary>
        /// проверяет, есть ли такое значение в списке
        /// </summary>
        /// <param name="value">значение</param>
        /// <returns></returns>
        public bool IsContaining(int value)
        {
            ListElement element = head;
            while ((element != null) && (element.Value != value))
            {
                element = element.Next;
            }
            return ((element != null) && (element.Value == value));
        }
    }
}