using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._3_hashTable_
{
    /// <summary>
    /// хэш-функция 1
    /// </summary>
    public class HashFunction2 : IHashFunction
    {
        /// <summary>
        /// размер таблицы
        /// </summary>
        private int sizeOfTable = 50;

        public int GetHashFunction(int value)
        {
            int sum = 0;
            while (value > 0)
            {
                sum = sum + (value % 10);
                value = value / 10;
            }
            return (sum % sizeOfTable);
        }
    }
}
