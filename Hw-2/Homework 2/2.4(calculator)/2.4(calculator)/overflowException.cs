using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._4_calculator_
{
    /// <summary>
    /// исключение, возникающее при переполнении стека
    /// </summary>
    [Serializable]
    public class OverflowException : Exception
    {
        public OverflowException(string message) : base(message) { }
        public OverflowException() { }
        public OverflowException(string message, Exception inner) : base(message, inner) { }
        protected OverflowException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
