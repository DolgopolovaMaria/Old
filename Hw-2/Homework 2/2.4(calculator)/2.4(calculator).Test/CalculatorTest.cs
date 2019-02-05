using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _2._4_calculator_.Test
{
    [TestClass]
    public class CalculatorTest
    {
        private ListStack list;
        private ArrayStack array;
        private Calculator calcList;
        private Calculator calcArray;

       [TestInitialize]
        public void Initialize()
        {
            list = new ListStack();
            array = new ArrayStack();
            calcList = new Calculator(list);
            calcArray = new Calculator(array);
        }

        [TestMethod]
        public void CalcArrayTest1()
        {
            Assert.AreEqual(3, calcArray.GetResult("1 2 +"));
        }

        [TestMethod]
        public void CalcArrayTest2()
        {
            Assert.AreEqual(9, calcArray.GetResult("9 6 - 1 2 + *"));
        }

        [TestMethod]
        [ExpectedException(typeof(IncorrectException))]
        public void IncorrectArrayTest()
        {
           calcArray.GetResult("1 ? +");
        }

        [TestMethod]
        public void CalcListTest1()
        {
            Assert.AreEqual(3, calcList.GetResult("1 2 +"));
        }

        [TestMethod]
        public void CalcListTest2()
        {
            Assert.AreEqual(9, calcList.GetResult("9 6 - 1 2 + *"));
        }

        [TestMethod]
        [ExpectedException(typeof(IncorrectException))]
        public void IncorrectListTest()
        {
            calcList.GetResult("1 ? +");
        }
    }
}
