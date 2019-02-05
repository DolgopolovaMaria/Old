using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _2._3_hashTable_;

namespace _2._3_hashTable_.Test
{
    [TestClass]
    public class HashTableTest
    {

        [TestInitialize]
        public void Initialize()
        {
            hashTable = new HashTable();
        }

        private HashTable hashTable;

        [TestMethod]
        public void AddElementTest()
        {
            hashTable.AddElement(15);
            hashTable.AddElement(115);

            Assert.IsTrue(hashTable.IsContainingElement(15));
            Assert.IsTrue(hashTable.IsContainingElement(115));
        }

        [TestMethod]
        public void IsContainingTest()
        {
            hashTable.AddElement(15);
            hashTable.AddElement(72);
            hashTable.AddElement(115);

            Assert.IsTrue(hashTable.IsContainingElement(72));
            Assert.IsTrue(hashTable.IsContainingElement(15));
            Assert.IsFalse(hashTable.IsContainingElement(345));
        }

        [TestMethod]
        public void DeleteElementTest()
        {
            hashTable.AddElement(15);
            hashTable.AddElement(72);
            hashTable.AddElement(115);

            hashTable.DeleteElement(72);
            hashTable.DeleteElement(15);

            Assert.IsFalse(hashTable.IsContainingElement(72));
            Assert.IsFalse(hashTable.IsContainingElement(15));
        }
    }
}
