using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _4._2;

namespace _4._2_List_.Test
{
    [TestClass]
    public class ListTest
    {
        private List list;

        [TestInitialize]
        public void Initialize()
        {
            list = new List();
        }

        [TestMethod]
        public void AddTest()
        {
            list.AddToHead(1);

            Assert.IsFalse(list.IsEmpty());
        }

        [TestMethod]
        public void DeleteElementFromHeadTest()
        {
            list.AddToHead(1);
            list.DeleteElementFromHead();

            Assert.IsTrue(list.IsEmpty());
        }

        [TestMethod]
        public void DeleteElementPositionTest()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(3);
            list.DeleteElementPosition(1);

            Assert.IsFalse(list.IsContaining(2));
        }

        [TestMethod]
        public void IsContainingTest()
        {
            list.AddToHead(1);
            list.AddToHead(2);

            Assert.IsTrue(list.IsContaining(2));
            Assert.IsFalse(list.IsContaining(3));
        }

        [TestMethod]
        public void DeleteElementTest()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(3);
            list.AddToHead(4);
            list.DeleteElement(2);
            list.DeleteElement(4);

            Assert.IsFalse(list.IsContaining(2));
            Assert.IsFalse(list.IsContaining(4));
        }

        [TestMethod]
        public void DeleteListTest()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(3);
            list.AddToHead(4);
            list.DeleteList();

            Assert.IsTrue(list.IsEmpty());
        }
    }
}
