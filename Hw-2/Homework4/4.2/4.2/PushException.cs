using System;

namespace _4._2
{
    /// <summary>
    /// добавление уже существующего элемента в список
    /// </summary>
    [Serializable]
    public class PushException : Exception
    {
        public PushException() { }
        public PushException(string message) : base(message) { }
        public PushException(string message, Exception inner) : base(message, inner) { }
        protected PushException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
