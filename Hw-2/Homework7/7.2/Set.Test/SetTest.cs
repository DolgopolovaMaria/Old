using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using _7._2;
//using static _7._2.Set<int>;


namespace Set.Test
{
    [TestClass]
    public class SetTest
    {
        private Set<int> set;

        private Set<int> set1;
        private Set<int> set2;

        [TestInitialize]
        public void Initialize()
        {
            set = new Set<int>();
            set1 = new Set<int>();
            set2 = new Set<int>();
        }

        private void AddElements()
        {
            set.AddElement(1);
            set.AddElement(2);
            set.AddElement(3);
            set.AddElement(4);
        }

        [TestMethod]
        public void AddTest()
        {
            AddElements();

            Assert.IsFalse(set.IsEmpty());
        }

        [TestMethod]
        public void IsContainingTest()
        {
            AddElements();

            Assert.IsTrue(set.IsContaining(2));
            Assert.IsFalse(set.IsContaining(5));
        }

        [TestMethod]
        public void DeleteElementTest()
        {
            AddElements();
            set.DeleteElement(2);
            set.DeleteElement(4);

            Assert.IsFalse(set.IsContaining(2));
            Assert.IsFalse(set.IsContaining(4));
        }

        [TestMethod]
        public void UnionTest1()
        {
            Set<int> result = Set<int>.Union(set1, set2);

            Assert.IsTrue(result.IsEmpty());
        }

        [TestMethod]
        public void UnionTest2()
        {
            set1.AddElement(1);
            set1.AddElement(2);
            Set<int> result = Set<int>.Union(set1, set2);

            Assert.IsTrue(result.IsContaining(1));
            Assert.IsTrue(result.IsContaining(2));
            Assert.AreEqual(result.Length, 2);
        }

        [TestMethod]
        public void UnionTest3()
        {
            set1.AddElement(1);
            set1.AddElement(2);
            set2.AddElement(3);
            set2.AddElement(2);
            Set<int> result = Set<int>.Union(set1, set2);

            Assert.IsTrue(result.IsContaining(1));
            Assert.IsTrue(result.IsContaining(2));
            Assert.IsTrue(result.IsContaining(3));
            Assert.AreEqual(result.Length, 3);
        }

        [TestMethod]
        public void IntersectionTest1()
        {
            Set<int> result = Set<int>.Intersection(set1, set2);

            Assert.IsTrue(result.IsEmpty());
        }

        [TestMethod]
        public void IntersectionTest2()
        {
            set1.AddElement(1);
            set1.AddElement(2);
            Set<int> result = Set<int>.Intersection(set1, set2);

            Assert.IsTrue(result.IsEmpty());
        }

        [TestMethod]
        public void IntersectionTest3()
        {
            set1.AddElement(1);
            set1.AddElement(2);
            set1.AddElement(3);
            set2.AddElement(4);
            set2.AddElement(5);
            set2.AddElement(6);
            Set<int> result = Set<int>.Intersection(set1, set2);

            Assert.IsTrue(result.IsEmpty());
        }

        [TestMethod]
        public void IntersectionTest4()
        {
            set1.AddElement(1);
            set1.AddElement(2);
            set1.AddElement(3);
            set2.AddElement(4);
            set2.AddElement(2);
            set2.AddElement(3);
            Set<int> result = Set<int>.Intersection(set1, set2);

            Assert.IsTrue(result.IsContaining(2));
            Assert.IsTrue(result.IsContaining(3));
            Assert.AreEqual(result.Length, 2);
        }
    }
}
