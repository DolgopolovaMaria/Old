using System;

namespace _2._2_list_
{
    /// <summary>
    /// класс Список
    /// </summary>
    public class List
    {
        private class ListElement
        {
            public int Value { get; set; }
            
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
        private ListElement head;

        /// <summary>
        /// удалить элемент по заданой позиции
        /// </summary>
        /// <param name="position"></param>
        public void DeleteElementPosition(int position)
        {
            if (position > this.Length - 1)
            {
                throw new DeleteException("некорректно введена позиция элемента для удаления");
            }
            if (position == 0)
            {
                DeleteElementFromHead();
                return;
            }
            ListElement prevElement = head;
            for (int i = 1; i < position; i++)
            {
                prevElement = prevElement.Next;
            }
            prevElement.Next = prevElement.Next.Next;
            Length--;
        }
        
        /// <summary>
        /// получить значение элемента по заданной позиции
        /// </summary>
        /// <param name="position"></param>
        /// <returns></returns>
        public int GetElement(int position)
        {
            if (position > this.Length - 1)
            {
                throw new GetElementException("некорректно введена позиция элемента");
            }
            if (position == 0)
            {
                return head.Value;
            }
            ListElement element = head.Next;
            for (int i = 1; i < position; i++)
            {
                element = element.Next;
            }
            return element.Value;
        }
        
        /// <summary>
        /// добавить элемент в голову
        /// </summary>
        /// <param name="value">значение</param>
        public void AddToHead(int value)
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
                throw new DeleteException("попытка удалить элемент из пустого списка");
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
        public void DeleteList()
        {
            head = null;
        }

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
