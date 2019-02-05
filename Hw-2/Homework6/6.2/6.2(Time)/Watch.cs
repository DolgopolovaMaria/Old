using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _6._2_Time_
{
    /// <summary>
    /// Класс часы
    /// </summary>
    public partial class Watch : Form
    {
        ///// <summary>
        ///// таймер
        ///// </summary>
        private Timer timer = new Timer();

        /// <summary>
        /// инициализирует форму
        /// </summary>
        public Watch()
        {
            InitializeComponent();
        }

        /// <summary>
        /// устанавливает интервал обновления таймера, запускает таймер
        /// </summary>
        private void Watch_Load(object sender, EventArgs e)
        {
            timer.Interval = 1000;
            timer.Tick += new EventHandler(timer1_Tick);
            timer.Start();
        }

        /// <summary>
        /// показывает время
        /// </summary>
        private void timer1_Tick(object sender, EventArgs e)
        {
            timeLabel.Text = DateTime.Now.ToString("HH:mm:ss");
        }
    }
}
