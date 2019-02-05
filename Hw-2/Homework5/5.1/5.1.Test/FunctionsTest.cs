using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;

namespace _5._1.Test
{
    [TestClass]
    public class FunctionsTest
    {
        private List<int> list;

        [TestInitialize()]
        public void Initialize()
        {
            list = new List<int> { 1, 2, 3 };
        }

        [TestMethod]
        public void TestMap1()
        {
            List<int> newList = Functions.Map(list, x => x * 2);

            Assert.AreEqual(2, (newList[0]));
            Assert.AreEqual(4, (newList[1]));
            Assert.AreEqual(6, (newList[2]));
        }

        [TestMethod]
        public void TestMap2()
        {
            List<int> newList = Functions.Map(list, x => x + 1);

            Assert.AreEqual(2, (newList[0]));
            Assert.AreEqual(3, (newList[1]));
            Assert.AreEqual(4, (newList[2]));
        }

        [TestMethod]
        public void TestFilter1()
        {
            List<int> newList = Functions.Filter(list, x => x % 2 == 1);

            Assert.AreEqual(1, (newList[0]));
            Assert.AreEqual(3, (newList[1]));
        }

        [TestMethod]
        public void TestFilter2()
        {
            List<int> newList = Functions.Filter(list, x => x - 1 == 2);

            Assert.AreEqual(3, (newList[0]));
        }

        [TestMethod]
        public void TestFold1()
        {
            Assert.AreEqual(6, Functions.Fold(list, 1, (acc, elem) => acc * elem));
        }

        [TestMethod]
        public void TestFold2()
        {
            Assert.AreEqual(8, Functions.Fold(list, 2, (acc, elem) => acc + elem));
        }
    }
}
