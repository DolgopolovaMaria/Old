using System;

namespace _4._1
{
    /// <summary>
    /// класс Операнд
    /// </summary>
    internal class Operand : TreeElement
    {
        /// <summary>
        /// значение
        /// </summary>
        private int value;

        /// <summary>
        /// конструктор, создающий экземпляр класса Операнд
        /// </summary>
        /// <param name="value">значение</param>
        public Operand(int value) => this.value = value;

        /// <summary>
        /// распечатать операнд в строку результата
        /// </summary>
        public override string Print() => value.ToString();

        /// <summary>
        /// вычислить значение
        /// </summary>
        public override int Count() => value;
    }
}
