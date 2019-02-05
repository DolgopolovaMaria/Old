using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _4._2;

namespace _4._2_List_.Test
{
    [TestClass]
    public class UniqueListTest
    {
        private UniqueList list;

        [TestInitialize]
        public void Initialize()
        {
            list = new UniqueList();
        }

        [TestMethod]
        public void AddToHeadTest1()
        {
            list.AddToHead(1);

            Assert.IsFalse(list.IsEmpty());
            Assert.IsTrue(list.IsContaining(1));
        }

        [TestMethod]
        public void AddToHeadTest2()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(3);

            Assert.IsTrue(list.IsContaining(1));
            Assert.IsTrue(list.IsContaining(2));
            Assert.IsTrue(list.IsContaining(3));
        }

        [TestMethod]
        public void DeleteElementTest1()
        {
            list.AddToHead(1);
            list.DeleteElement(1);

            Assert.IsFalse(list.IsContaining(1));
        }

        [TestMethod]
        public void DeleteElementTest2()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(3);
            list.DeleteElement(2);

            Assert.IsFalse(list.IsContaining(2));
        }

        [TestMethod]
        [ExpectedException(typeof(PushException))]
        public void PushExceptionTest1()
        {
            list.AddToHead(1);
            list.AddToHead(1);
        }

        [TestMethod]
        [ExpectedException(typeof(PushException))]
        public void PushExceptionTest2()
        {
            list.AddToHead(1);
            list.AddToHead(2);
            list.AddToHead(1);
        }

        [TestMethod]
        [ExpectedException(typeof(DeleteException))]
        public void DeleteExceptoinTest1()
        {
            list.DeleteElement(1);
        }

        [TestMethod]
        [ExpectedException(typeof(DeleteException))]
        public void DeleteExceptoinTest2()
        {
            list.AddToHead(2);
            list.DeleteElement(1);
        }
    }
}
