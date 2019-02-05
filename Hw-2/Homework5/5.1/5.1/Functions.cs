using System;
using System.Collections.Generic;

namespace _5._1
{
    /// <summary>
    /// функции Map, Filter, Fold
    /// </summary>
    public class Functions
    {
        /// <summary>
        /// преобразует список, применяя переданную функцию
        /// </summary>
        /// <param name="list"></param>
        /// <param name="function"></param>
        /// <returns>список, полученный применением переданной функции к каждому элементу переданного списка</returns>
        public static List<int> Map(List<int> list, Func<int, int> function)
        {
            List<int> newList = new List<int>();
            foreach (int element in list)
            {
                newList.Add(function(element));
            }

            return newList;
        }

        /// <summary>
        /// возвращает список, составленный из тех элементов переданного списка, для которых переданная функция вернула true
        /// </summary>
        /// <param name="list"></param>
        /// <param name="function"></param>
        /// <returns></returns>
        public static List<int> Filter(List<int> list, Func<int, bool> function)
        {
            List<int> newList = new List<int>();
            foreach (int element in list)
            {
                if (function(element))
                {
                    newList.Add(element);
                }
            }

            return newList;
        }

        /// <summary>
        /// переданная функция берёт текущее накопленное значение и текущий элемент списка, и возвращает следующее накопленное значение
        /// </summary>
        /// <param name="list"></param>
        /// <param name="acc">начальное значение</param>
        /// <param name="function"></param>
        /// <returns>накопленное значение, получившееся после всего прохода списка</returns>
        public static int Fold(List<int> list, int acc, Func<int, int, int> function)
        {
            foreach (int element in list)
            {
                acc = function(acc, element);
            }

            return acc;
        }
    }
}
