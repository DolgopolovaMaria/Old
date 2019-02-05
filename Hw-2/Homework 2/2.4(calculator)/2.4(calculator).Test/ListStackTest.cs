using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _2._4_calculator_;

namespace _2._4_calculator_.Test
{
    [TestClass]
    public class ListStackTest
    {
        private ListStack list;

        [TestInitialize]
        public void Initialize()
        {
            list = new ListStack();
        }

        [TestMethod]
        public void PushTest()
        {
            list.Push(1);
            list.Push(2);
            list.Push(3);

            Assert.IsTrue(list.IsContaining(1));
            Assert.IsTrue(list.IsContaining(2));
            Assert.IsTrue(list.IsContaining(3));
        }

        [TestMethod]
        public void PopTest()
        {
            list.Push(1);
            list.Push(2);
            list.Push(3);

            Assert.AreEqual(list.Pop(), 3);
            Assert.IsFalse(list.IsContaining(3));
        }

        [TestMethod]
        public void PeekTest()
        {
            list.Push(1);
            list.Push(2);
            list.Push(3);

            Assert.AreEqual(list.Peek(), 3);
            Assert.IsTrue(list.IsContaining(3));
        }

        [TestMethod]
        public void IsEmptyTest()
        {
            Assert.IsTrue(list.IsEmpty());

            list.Push(1);
            list.Push(2);

            list.Pop();
            Assert.IsFalse(list.IsEmpty());
            list.Pop();
            Assert.IsTrue(list.IsEmpty());
        }

        [TestMethod]
        [ExpectedException(typeof(EmptyStackException))]
        public void EmptyExceptionTest()
        {
            list.Pop();
        }
    }
}

