using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _4._1.Test
{
    [TestClass]
    public class CalculateTreeTest
    {
        private CalculationTree tree;

        [TestInitialize]
        public void Initialize()
        {
            tree = new CalculationTree();
        }

        [TestMethod]
        public void PrintTest()
        {
            tree.Build("(* (+ 1 1 ) 2 )");
            string str = tree.PrintTree();

            Assert.AreEqual("(* (+ 1 1 ) 2 )", str);
        }

        [TestMethod]
        public void CalculateTest1()
        {
            Assert.AreEqual(4, tree.Calculate("(* (+ 1 1 ) 2 )"));
        }

        [TestMethod]
        public void CalculateTest2()
        {
            Assert.AreEqual(6, tree.Calculate("- (+ 4 5 ) 3"));
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionDivision))]
        public void ExceptionDivisionTest()
        {
            tree.Calculate("/ 9 0 ");
        }
    }
}
