using System;

namespace _2._4_calculator_
{
    public interface IStack
    {
        /// <summary>
        /// вернуть значение из головы и удалить его из стека
        /// </summary>
        /// <returns>значение</returns>
        int Pop();

        /// <summary>
        /// добавить значение в стек
        /// </summary>
        /// <param name="value">значение для добавления</param>
        void Push(int value);

        /// <summary>
        /// вернуть значение из головы
        /// </summary>
        /// <returns>значение</returns>
        int Peek();

        /// <summary>
        /// проверить список на пустоту
        /// </summary>
        /// <returns>список пуст</returns>
        bool IsEmpty();

        /// <summary>
        /// проверить, принадлежит ли значение списку
        /// </summary>
        /// <param name="value">значение</param>
        /// <returns>значение принадлежит списку</returns>
        bool IsContaining(int value);
    }
}
