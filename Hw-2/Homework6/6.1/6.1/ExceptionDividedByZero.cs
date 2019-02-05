using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _6._1
{
    /// <summary>
    /// исключение, возникающее при делении на ноль
    /// </summary>
    [Serializable]
    public class ExceptionDividedByZero : Exception
    {
        public ExceptionDividedByZero() { }
        public ExceptionDividedByZero(string message) : base(message) { }
        public ExceptionDividedByZero(string message, Exception inner) : base(message, inner) { }
        protected ExceptionDividedByZero(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
