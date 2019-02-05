using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _7._1;
using static _7._1.List<int>;

namespace _7._1.Test
{
    [TestClass]
    public class ListTest
    {
        private List<int> list;

        [TestInitialize]
        public void Initialize()
        {
            list = new List<int>();
        }

        private void AddElements()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(3);
            list.AddToHead(4);
        }

        [TestMethod]
        public void AddTest()
        {
            AddElements();

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
            AddElements();
            list.DeleteElementPosition(1);

            Assert.IsFalse(list.IsContaining(3));
        }

        [TestMethod]
        public void IsContainingTest()
        {
            AddElements();

            Assert.IsTrue(list.IsContaining(2));
            Assert.IsFalse(list.IsContaining(5));
        }

        [TestMethod]
        public void DeleteElementTest()
        {
            AddElements();
            list.DeleteElement(2);
            list.DeleteElement(4);

            Assert.IsFalse(list.IsContaining(2));
            Assert.IsFalse(list.IsContaining(4));
        }

        [TestMethod]
        public void DeleteListTest()
        {
            AddElements();
            list.DeleteList();

            Assert.IsTrue(list.IsEmpty());
        }

        [TestMethod]
        public void ForeachTest()
        {
            AddElements();
            
            int value = 4;
            foreach (var i in list)
            {
                Assert.AreEqual(i, value);
                value--;
                list.DeleteElement(i);
            }

            Assert.IsTrue(list.IsEmpty());
        }
    }
}
