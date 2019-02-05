using System;

namespace _5._2
{
    /// <summary>
    /// класс, реализующий игру
    /// </summary>
    public class Game
    {
        /// <summary>
        /// сместить курсор влево
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnLeft(object sender, EventArgs e)
        {
            if (Console.CursorLeft > 0)
            {
                Console.CursorLeft--;
            }
        }

        /// <summary>
        /// сместить курсор вправо
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnRight(object sender, EventArgs e)
        {
            if (Console.CursorLeft < Console.BufferWidth - 1)
            {
                Console.CursorLeft++;
            }
        }

        /// <summary>
        /// сместить курсор вверх
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnUp(object sender, EventArgs e)
        {
            if (Console.CursorTop > 0)
            {
                Console.CursorTop--;
            }
        }

        /// <summary>
        /// сместить курсор вниз
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void OnDown(object sender, EventArgs e)
        {
            if (Console.CursorTop < Console.BufferHeight - 1)
            {
                Console.CursorTop++;
            }
        }
    }
}
