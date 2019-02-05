using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _7._1;
using static _7._1.Stack<int>;

namespace _7._1_.Test
{
    [TestClass]
    public class StackTest
    {
        [TestInitialize]
        public void Initialize()
        {
            stack = new Stack<int>();
        }

        [TestMethod]
        public void PushTest()
        {
            stack.Push(1);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestMethod]
        public void PopTest1()
        {
            stack.Push(1);
            Assert.AreEqual(1, stack.Pop());
        }

        [TestMethod]
        public void PopTest2()
        {
            stack.Push(1);
            stack.Push(2);
            Assert.AreEqual(2, stack.Pop());
            Assert.AreEqual(1, stack.Pop());
        }

        [TestMethod]
        [ExpectedException(typeof(DeleteException))]
        public void PopTest3()
        {
            stack.Pop();
        }

        private Stack<int> stack;
    }
}
