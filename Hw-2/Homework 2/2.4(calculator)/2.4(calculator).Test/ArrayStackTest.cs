using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _2._4_calculator_;

namespace _2._4_calculator_.Test
{
    [TestClass]
    public class ArrayStackTest
    {
        private ArrayStack array;

        [TestInitialize]
        public void Initialize()
        {
            array = new ArrayStack();
        }

        [TestMethod]
        public void PushTest()
        {
            array.Push(1);
            array.Push(2);
            array.Push(3);

            Assert.IsTrue(array.IsContaining(1));
            Assert.IsTrue(array.IsContaining(2));
            Assert.IsTrue(array.IsContaining(3));
        }

        [TestMethod]
        public void PopTest()
        {
            array.Push(1);
            array.Push(2);
            array.Push(3);

            Assert.AreEqual(array.Pop(), 3);
            Assert.IsFalse(array.IsContaining(3));
        }

        [TestMethod]
        public void PeekTest()
        {
            array.Push(1);
            array.Push(2);
            array.Push(3);

            Assert.AreEqual(array.Peek(), 3);
            Assert.IsTrue(array.IsContaining(3));
        }

        [TestMethod]
        public void IsEmptyTest()
        {
            array.Push(1);
            array.Push(2);

            array.Pop();
            Assert.IsFalse(array.IsEmpty());
            array.Pop();
            Assert.IsTrue(array.IsEmpty());
        }

        [TestMethod]
        [ExpectedException(typeof(EmptyStackException))]
        public void EmptyExceptionTest()
        {
            array.Pop();
        }

        [TestMethod]
        [ExpectedException(typeof(OverflowException))]
        public void OverflowExceptionTest()
        {
            for (int i = 0; i <= 100; i++)
            {
                array.Push(1);
            }
        }
    }
}
