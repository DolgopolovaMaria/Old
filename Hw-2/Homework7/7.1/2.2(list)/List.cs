using System;
using System.Collections;
using System.Collections.Generic;

namespace _7._1
{
    /// <summary>
    /// класс Список
    /// </summary>
    public class List<T> : IEnumerable<T>
    {
        /// <summary>
        /// класс Элемент Списка
        /// </summary>
        private class ListElement
        {
            /// <summary>
            /// значение
            /// </summary>
            public T Value { get; set; }

            /// <summary>
            /// следующий элемент
            /// </summary>
            public ListElement Next { get; set; }
           
            /// <summary>
            /// конструктор, создающий элемент списка
            /// </summary>
            /// <param name="value">значение</param>
            /// <param name="next">следующий элемент</param>
            public ListElement(T value, ListElement next)
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
        public T GetElement(int position)
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
        public void AddToHead(T value)
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
        public void DeleteElement(T value)
        {
            while ((head != null) && (head.Value.Equals(value)))
            {
                DeleteElementFromHead();
            }

            ListElement element = head;
            while (element != null)
            {
                while ((element.Next != null) && (element.Next.Value.Equals(value)))
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
            while ((element != null) && (!element.Value.Equals(value)))
            {
                element = element.Next;
            }
            return ((element != null) && (element.Value.Equals(value)));
        }

        /// <summary>
        /// получить энумератор
        /// </summary>
        /// <returns>энумератор</returns>
        public IEnumerator<T> GetEnumerator() => new ListEnumerator(this);

        /// <summary>
        /// получить энумератор
        /// </summary>
        /// <returns>энумератор</returns>
        IEnumerator IEnumerable.GetEnumerator() => new ListEnumerator(this);

        /// <summary>
        /// класс, реализующий IEnumerator для списка
        /// </summary>
        private class ListEnumerator :  IEnumerator<T>
        {
            /// <summary>
            /// текущий элемент
            /// </summary>
            private ListElement currentElement;

            /// <summary>
            /// голова списка
            /// </summary>
            private ListElement head;

            /// <summary>
            /// конструктор ListEnumerator
            /// </summary>
            /// <param name="list">список</param>
            public ListEnumerator(List<T> list)
            {
                this.head = list.head;
                this.currentElement = null;
            }

            /// <summary>
            /// возвращает текущий элемент
            /// </summary>
            public T Current => currentElement.Value;

            /// <summary>
            /// возвращает элемент коллекции
            /// </summary>
            object IEnumerator.Current { get => Current; }

            /// <summary>
            /// перейти на следующий элемент
            /// </summary>
            /// <returns>false, если коллекция уже закончилась</returns>
            public bool MoveNext()
            {
                if (currentElement == null)
                {
                    if (head == null)
                    {
                        return false;
                    }
                    currentElement = head;
                    return true;
                }
                if (currentElement.Next == null)
                {
                    return false;
                }
                currentElement = currentElement.Next;
                return true;
            }

            /// <summary>
            /// ставит энумератор на начальную позицию
            /// </summary>
            public void Reset() => currentElement = null;

            public void Dispose() { }
        }
    }
}
;