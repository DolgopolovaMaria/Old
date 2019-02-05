using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._1_stack_
{
    /// <summary>
    /// class Stack
    /// </summary>
    public class Stack
    {
        private int length;

        public int Length => this.length;
    
        private class StackElement
        {
            private int value;

            public int Value => this.value;

            private StackElement next;

            public StackElement Next => this.next;

            public StackElement(int value, StackElement next)
            {
                this.value = value;
                this.next = next;
            }
        }

        private StackElement head;

        /// <summary>
        /// Push value to a stack
        /// </summary>
        /// <param name="value">Value for pushing</param>
        public void Push(int value)
        {
            StackElement newHead = new StackElement(value, head);
            head = newHead;
            length++;
        }

        /// <summary>
        /// Take value from the head
        /// </summary>
        /// <returns>value of the head</returns>
        public int Pop()
        {
            if (head == null)
            {
                throw new DeleteException("попытка удалить элемент из пустого списка");
            }
            length--;
            int headValue = head.Value;
            head = head.Next;
            return headValue;
        }

        /// <summary>
        /// Check whether the stack is empty
        /// </summary>
        /// <returns>stack is empty</returns>
        public bool IsEmpty() => head == null;
    }
}

