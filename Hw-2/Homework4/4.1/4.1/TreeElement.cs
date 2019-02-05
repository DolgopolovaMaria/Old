using System;

namespace _4._1
{
    /// <summary>
    /// абстрактный класс Элемент дерева
    /// </summary>
    internal abstract class TreeElement
    {
        /// <summary>
        /// конструктор, создающий элемент дерева
        /// </summary>
        public TreeElement() { }

        /// <summary>
        /// распечатать элемент в строку результата
        /// </summary>
        public abstract string Print();

        /// <summary>
        /// вычислить значение
        /// </summary>
        public abstract int Count();
    }
}
