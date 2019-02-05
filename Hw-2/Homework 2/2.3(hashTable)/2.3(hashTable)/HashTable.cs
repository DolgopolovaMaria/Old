using System;

namespace _2._3_hashTable_
{
    public class HashTable
    {
        /// <summary>
        /// размер таблицы
        /// </summary>
        private int sizeOfTable = 50;

        /// <summary>
        /// массив списков
        /// </summary>
        public List[] HashLists { get; set; }

        /// <summary>
        /// подсчет хэш-функции
        /// </summary>
        /// <param name="value">значение хэш-функции</param>
        /// <returns></returns>
        public int HashFunction(int value) => (Math.Abs(value) % sizeOfTable);

        /// <summary>
        /// конструктор, создающий хэш-таблицу
        /// </summary>
        public HashTable()
        {
            HashLists = new List[sizeOfTable];

            for (int i = 0; i < sizeOfTable; i++)
            {
                HashLists[i] = new List();
            }
        }

        /// <summary>
        /// добавить элемент в таблицу
        /// </summary>
        /// <param name="value">значение</param>
        public void AddElement(int value)
        {
            HashLists[HashFunction(value)].Push(value);
        }

        /// <summary>
        /// удалить элемент из таблицы
        /// </summary>
        /// <param name="value">значение</param>
        public void DeleteElement(int value)
        {
            HashLists[HashFunction(value)].DeleteElement(value);
        }

        /// <summary>
        /// проверить, есть ли такой элемент в таблице
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public bool IsContainingElement(int value) => HashLists[HashFunction(value)].IsContaining(value);
    }
}
