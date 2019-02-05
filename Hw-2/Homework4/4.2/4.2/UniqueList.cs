using System;

namespace _4._2
{
    /// <summary>
    /// класс список, который не содержит повторяющихся значений
    /// </summary>
    public class UniqueList : List
    {
        /// <summary>
        /// добавить элемент в голову
        /// </summary>
        /// <param name="value">значение</param>
        public override void AddToHead(int value)
        {
            if (IsContaining(value))
            {
                throw new PushException("Попытка добавить в список уже существующий элемент");
            }
            base.AddToHead(value);
        }

        /// <summary>
        /// удалить значение из списка
        /// </summary>
        /// <param name="value">значение</param>
        public override void DeleteElement(int value)
        {
            if (!IsContaining(value))
            {
                throw new DeleteException("Попытка удаления из списка несуществующего элемента");
            }
            base.DeleteElement(value);
        }
    }
}
