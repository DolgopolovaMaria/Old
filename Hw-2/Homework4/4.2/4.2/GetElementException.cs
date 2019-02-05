using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4._2
{
    /// <summary>
    /// исключение, возникающее при вводе некорректной позиции элемента
    /// </summary>
    [Serializable]
    public class GetElementException : Exception
    {
        public GetElementException() { }
        public GetElementException(string message) : base(message) { }
        public GetElementException(string message, Exception inner) : base(message, inner) { }
        protected GetElementException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
