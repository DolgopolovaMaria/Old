using System;

namespace _5._2
{
    /// <summary>
    /// класс, обрабатывающий события
    /// </summary>
    public class EventLoop
    {
        /// <summary>
        /// событие при нажатии стрелки влево
        /// </summary>
        public event EventHandler LeftHandler;

        /// <summary>
        /// событие при нажатии стрелки вправо
        /// </summary>
        public event EventHandler RightHandler;

        /// <summary>
        /// событие при нажатии стрелки вверх
        /// </summary>
        public event EventHandler UpHandler;

        /// <summary>
        /// событие при нажатии стрелки вниз
        /// </summary>
        public event EventHandler DownHandler;

        /// <summary>
        /// запускает игру
        /// </summary>
        public void Run()
        {
            bool exit = false;
            while (!exit)
            {
                var key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case ConsoleKey.LeftArrow:
                    {
                        LeftHandler(this, EventArgs.Empty);
                        break;
                    }
                    case ConsoleKey.RightArrow:
                    {
                        RightHandler(this, EventArgs.Empty);
                        break;
                    }
                    case ConsoleKey.UpArrow:
                    {
                        UpHandler(this, EventArgs.Empty);
                        break;
                    }
                    case ConsoleKey.DownArrow:
                    {
                        DownHandler(this, EventArgs.Empty);
                        break;
                    }
                    case ConsoleKey.Escape:
                    {
                        exit = true;
                        break;
                    }
                }
            }
        }
    }

}
