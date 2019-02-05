using System;

namespace _2._3_hashTable_
{
    /// <summary>
    /// интерфейс Хеш-функция
    /// </summary>
    public interface IHashFunction
    {
        /// <summary>
        /// получить хэш-функцию
        /// </summary>
        /// <param name="value">значение</param>
        /// <returns>хэш-функция</returns>
        int GetHashFunction(int value);
    }
}
