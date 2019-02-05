using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _7._2;

namespace Set.Test
{
    [TestClass]
    public class TreeTest
    {
        private Tree<int> tree;

        [TestInitialize]
        public void Initialize()
        {
            tree = new Tree<int>();
        }

        private void AddElements()
        {
            tree.Add(4);
            tree.Add(5);
            tree.Add(2);
            tree.Add(1);
            tree.Add(3);
        }

        [TestMethod]
        public void AddTest()
        {
            AddElements();

            Assert.IsFalse(tree.IsEmpty());
        }

        [TestMethod]
        public void DeleteElementFromRootTest()
        {
            AddElements();
            tree.DeleteElement(4);

            Assert.IsFalse(tree.IsContaining(4));
        }

        [TestMethod]
        public void DeleteElementTest()
        {
            AddElements();
            tree.DeleteElement(2);

            Assert.IsFalse(tree.IsContaining(2));
        }

        [TestMethod]
        public void DeleteElementFromNodeTest()
        {
            AddElements();
            tree.DeleteElement(1);

            Assert.IsFalse(tree.IsContaining(1));
        }

        [TestMethod]
        public void IsContainingTest()
        {
            AddElements();

            Assert.IsTrue(tree.IsContaining(1));
            Assert.IsTrue(tree.IsContaining(2));
            Assert.IsTrue(tree.IsContaining(3));
            Assert.IsTrue(tree.IsContaining(4));
            Assert.IsTrue(tree.IsContaining(5));
            Assert.IsFalse(tree.IsContaining(6));
        }

        [TestMethod]
        public void DeleteNonexistentElementTest()
        {
            AddElements();

            Assert.IsFalse(tree.DeleteElement(6));
        }

        [TestMethod]
        public void ForeachTest()
        {
            AddElements();

            int value = 5;
            int count = 5;
            foreach (var i in tree.Order())
            {
                Assert.AreEqual(i, value);
                value--;
                count--;
            }
            Assert.AreEqual(0, count);
        }
    }
}
