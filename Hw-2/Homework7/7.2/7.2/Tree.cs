using System;
using System.Collections.Generic;
using System.Linq;

namespace _7._2
{
    /// <summary>
    /// класс Дерево
    /// </summary>
    public class Tree<T>
    {
        /// <summary>
        /// класс Элемент дерева
        /// </summary>
        private class TreeElement
        {
            /// <summary>
            /// левый сын
            /// </summary>
            public TreeElement LeftChild { get; set; }

            /// <summary>
            /// правый сын
            /// </summary>
            public TreeElement RightChild { get; set; }

            /// <summary>
            /// значение
            /// </summary>
            public T Value { get; set; }

            /// <summary>
            /// конструктор, создающий элемент дерева
            /// </summary>
            /// <param name="value">значение</param>
            /// <param name="left">левый сын</param>
            /// <param name="right">правый сын</param>
            public TreeElement (T value, TreeElement left, TreeElement right)
            {
                this.Value = value;
                this.LeftChild = left;
                this.RightChild = right;
            }
        }

        /// <summary>
        /// корень дерева
        /// </summary>
        private TreeElement root;

        private void Insert(T value, TreeElement parentLocalRoot, bool right, TreeElement localRoot)
        {
            if ((parentLocalRoot == null) && (localRoot == null))
            {
                TreeElement newElement = new TreeElement(value, null, null);
                this.root = newElement;
                return;
            }
            if (localRoot == null)
            {
                TreeElement newElement = new TreeElement(value, null, null);
                localRoot = newElement;
                if (right)
                {
                    parentLocalRoot.RightChild = localRoot;
                }
                else
                {
                    parentLocalRoot.LeftChild = localRoot;
                }
                return;
            }
            if (String.Compare(value.ToString(), localRoot.Value.ToString()) < 0)
            {
                Insert(value, localRoot, false, localRoot.LeftChild);
            }
            if (String.Compare(value.ToString(), localRoot.Value.ToString()) > 0)
            {
                Insert(value, localRoot, true, localRoot.RightChild);
            }
        }

        /// <summary>
        /// добавить значение в дерево
        /// </summary>
        /// <param name="value">значение</param>
        public bool Add(T value)
        {
            if (IsContaining(value))
            {
                return false;
            }
            this.Insert(value, null, false, root);
            return true;
        }

        private bool Search(TreeElement localRoot, T value)
        {
            if (localRoot == null)
            {
                return false;
            }
            if (String.Compare(value.ToString(), localRoot.Value.ToString()) > 0)
            {
                return Search(localRoot.RightChild, value);
            }
            if (String.Compare(value.ToString(), localRoot.Value.ToString()) < 0)
            {
                return Search(localRoot.LeftChild, value);
            }
            return true;
        }

        /// <summary>
        /// проверить, содержится ли значение в дереве
        /// </summary>
        /// <param name="value">значение</param>
        /// <returns>значение содержится в дереве</returns>
        public bool IsContaining(T value) => Search(root, value);

        private void DelElement(TreeElement parentLocalRoot, bool right, TreeElement localRoot, T valueForDelete)
        {
            if (localRoot == null)
            {
                return;
            }

            if (String.Compare(valueForDelete.ToString(), localRoot.Value.ToString()) < 0)
            {
                DelElement(localRoot, false, localRoot.LeftChild, valueForDelete);
            }
            if (String.Compare(valueForDelete.ToString(), localRoot.Value.ToString()) > 0)
            {
                DelElement(localRoot, true, localRoot.RightChild, valueForDelete);
            }

            if (valueForDelete.Equals(localRoot.Value))
            {

                if ((localRoot.LeftChild == null) && (localRoot.RightChild == null))
                {
                    if (right)
                    {
                        parentLocalRoot.RightChild = null;
                    }
                    else
                    {
                        parentLocalRoot.LeftChild = null;
                    }
                    return;
                }

                if (localRoot.LeftChild == null)
                {
                    TreeElement oldElement = localRoot;
                    localRoot = oldElement.RightChild;
                    if (right)
                    {
                        parentLocalRoot.RightChild = localRoot;
                    }
                    else
                    {
                        parentLocalRoot.LeftChild = localRoot;
                    }
                    return;
                }

                if (localRoot.RightChild == null)
                {
                    TreeElement oldElement = localRoot;
                    localRoot = oldElement.LeftChild;
                    if (right)
                    {
                        parentLocalRoot.RightChild = localRoot;
                    }
                    else
                    {
                        parentLocalRoot.LeftChild = localRoot;
                    }
                    return;
                }

                TreeElement newroot = localRoot.RightChild;
                while (newroot.LeftChild != null)
                {
                    newroot = newroot.LeftChild;
                }

                localRoot.Value = newroot.Value;
                newroot.Value = valueForDelete;
                DelElement(localRoot, false, localRoot, valueForDelete);
            }
        }

        /// <summary>
        /// удалить значение из дерева
        /// </summary>
        /// <param name = "value" > значение </ param >
        /// < returns > значение содержалось в дереве</returns>
        public bool DeleteElement(T value)
        {
            if (!Search(root, value))
            {
                return false;
            }
            DelElement(root, false, root, value);
            return true;
        }

        /// <summary>
        /// проверить, пусто ли дерево
        /// </summary>
        /// <returns>дерево пусто</returns>
        public bool IsEmpty() => root == null;

        private void InOrder(TreeElement localRoot, Stack<T> stack)
        {
            if (localRoot == null)
            {
                return;
            }
            InOrder(localRoot.LeftChild, stack);
            stack.Push(localRoot.Value);
            InOrder(localRoot.RightChild, stack);
        }

        /// <summary>
        /// обход дерева
        /// </summary>
        public IEnumerable<T> Order()
        {
            Stack<T> stack = new Stack<T>();

            InOrder(root, stack);
            int count = stack.Count();
            for (int i = 0; i < count; i++)
            {
                yield return stack.Pop();
            }
        }
    }
}
