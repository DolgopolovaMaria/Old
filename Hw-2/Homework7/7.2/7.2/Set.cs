using System;
using System.Collections;
using System.Collections.Generic;

namespace _7._2
{
    /// <summary>
    /// класс Множество
    /// </summary>
    public class Set<T>
    {
        private Tree<T> tree;

        public Set() => tree = new Tree<T>();

        /// <summary>
        /// размер множества
        /// </summary>
        public int Length { get; set; }

        /// <summary>
        /// добавить элемент в множество
        /// </summary>
        /// <param name="value">значение</param>
        public void AddElement(T value)
        {
            if (tree.Add(value))
            {
                Length++;
            }
        }

        /// <summary>
        /// проверить, пусто ли множество
        /// </summary>
        /// <returns>множество пусто</returns>
        public bool IsEmpty() => tree.IsEmpty();

        /// <summary>
        /// удалить значение из множества
        /// </summary>
        /// <param name="value">значение для удаления</param>
        public void DeleteElement(T value)
        {
            if (tree.DeleteElement(value))
            {
                Length--;
            }
        }

        /// <summary>
        /// проверяет, есть ли такое значение в множестве
        /// </summary>
        /// <param name = "value" > значение </ param >
        /// < returns ></ returns >
        public bool IsContaining(T value) => tree.IsContaining(value);

        /// <summary>
        /// объединение множеств
        /// </summary>
        /// <param name="set1">множество 1</param>
        /// <param name="set2">множество 2</param>
        /// <returns>множество, являющееся объединением множеств</returns>
        public static Set<T> Union(Set<T> set1, Set<T> set2)
        {
            Set<T> result = new Set<T>();
            foreach (var value in set1.tree.Order())
            {
                result.AddElement(value);
            }
            foreach (var value in set2.tree.Order())
            {
                result.AddElement(value);
            }

            return result;
        }

        /// <summary>
        /// пересечение множеств
        /// </summary>
        /// <param name="set1">множество 1</param>
        /// <param name="set2">множество 2</param>
        /// <returns>множество, являющееся пересечением множеств</returns>
        public static Set<T> Intersection(Set<T> set1, Set<T> set2)
        {
            Set<T> result = new Set<T>();
            foreach (var value in set1.tree.Order())
            {
                if (set2.IsContaining(value))
                {
                    result.AddElement(value);
                }
            }

            return result;
        }
    }
}
