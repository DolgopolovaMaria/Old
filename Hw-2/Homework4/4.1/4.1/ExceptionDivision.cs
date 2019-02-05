using System;

namespace _4._1
{
    /// <summary>
    /// исключение, возникающее приделении на ноль
    /// </summary>
    [Serializable]
    public class ExceptionDivision : Exception
    {
        public ExceptionDivision() { }
        public ExceptionDivision(string message) : base(message) { }
        public ExceptionDivision(string message, Exception inner) : base(message, inner) { }
        protected ExceptionDivision(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
