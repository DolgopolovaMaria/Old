using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _2._3_hashTable_;

namespace _2._3_hashTable_.Test
{
    [TestClass]
    public class HashTableTest
    {
        private HashTable hashTable1;
        private HashTable hashTable2;

        [TestInitialize]
        public void Initialize()
        {
            hashTable1 = new HashTable(new HashFunction1());
            hashTable2 = new HashTable(new HashFunction2());
        }

        /// <summary>
        /// проверить, что в хэш-таблице содержатся значения 15, 72, 115
        /// </summary>
        private void AssertsTrue(HashTable hashTable)
        {
            Assert.IsTrue(hashTable.IsContainingElement(15));
            Assert.IsTrue(hashTable.IsContainingElement(72));
            Assert.IsTrue(hashTable.IsContainingElement(115));
        }

        /// <summary>
        /// проверить, что в хэш-таблице не содержатся значения 16, 73
        /// </summary>
        private void AssertsFalse(HashTable hashTable)
        {
            Assert.IsFalse(hashTable.IsContainingElement(16));
            Assert.IsFalse(hashTable.IsContainingElement(73));
        }

        /// <summary>
        /// добавить в хэш-таблицу значения 15, 72, 115
        /// </summary>
        private void AddElements(HashTable hashTable)
        {
            hashTable.AddElement(15);
            hashTable.AddElement(72);
            hashTable.AddElement(115);
        }

        [TestMethod]
        public void AddElementTest()
        {
            AddElements(hashTable1);

            AssertsTrue(hashTable1);

            AddElements(hashTable2);

            AssertsTrue(hashTable2);
        }

        [TestMethod]
        public void IsContainingTest()
        {
            AddElements(hashTable1);

            AssertsTrue(hashTable1);
            AssertsFalse(hashTable1);

            AddElements(hashTable2);

            AssertsTrue(hashTable2);
            AssertsFalse(hashTable2);
        }

        [TestMethod]
        public void DeleteElementTest()
        {
            hashTable1.AddElement(16);
            hashTable1.AddElement(73);
            AddElements(hashTable1);

            hashTable1.DeleteElement(73);
            hashTable1.DeleteElement(16);

            AssertsFalse(hashTable1);

            hashTable2.AddElement(16);
            hashTable2.AddElement(73);
            AddElements(hashTable2);

            hashTable2.DeleteElement(73);
            hashTable2.DeleteElement(16);

            AssertsFalse(hashTable2);
        }
    }
}
