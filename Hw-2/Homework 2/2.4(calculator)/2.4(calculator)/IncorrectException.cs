using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._4_calculator_
{
    /// <summary>
    /// исключение, возникающее при вводе некорректного символа
    /// </summary>
    [Serializable]
    public class IncorrectException : Exception
    {
        public IncorrectException() { }
        public IncorrectException(string message) : base(message) { }
        public IncorrectException(string message, Exception inner) : base(message, inner) { }
        protected IncorrectException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
