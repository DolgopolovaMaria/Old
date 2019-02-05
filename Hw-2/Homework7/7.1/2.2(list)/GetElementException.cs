using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _7._1
{
    /// <summary>
    /// исключение, возникающее при вводе некорректной позиции
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
