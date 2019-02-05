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
        private List[] hashLists;

        /// <summary>
        /// хэш-функция
        /// </summary>
        private IHashFunction hashFunction;

        /// <summary>
        /// конструктор, создающий хэш-таблицу
        /// </summary>
        public HashTable(IHashFunction hashFunction)
        {
            hashLists = new List[sizeOfTable];

            for (int i = 0; i < sizeOfTable; i++)
            {
                hashLists[i] = new List();
            }

            this.hashFunction = hashFunction;
        }

        /// <summary>
        /// добавить элемент в таблицу
        /// </summary>
        /// <param name="value">значение</param>
        public void AddElement(int value) => hashLists[Math.Abs(hashFunction.GetHashFunction(value)) % sizeOfTable].Push(value);

        /// <summary>
        /// удалить элемент из таблицы
        /// </summary>
        /// <param name="value">значение</param>
        public void DeleteElement(int value) => hashLists[hashFunction.GetHashFunction(value)].DeleteElement(value);

        /// <summary>
        /// проверить, есть ли такой элемент в таблице
        /// </summary>
        /// <param name="value">элемент есть в таблице</param>
        /// <returns></returns>
        public bool IsContainingElement(int value) => hashLists[hashFunction.GetHashFunction(value)].IsContaining(value);
    }
}
