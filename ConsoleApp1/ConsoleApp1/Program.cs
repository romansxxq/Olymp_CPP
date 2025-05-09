using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Microsoft.VisualBasic;

namespace Zavd3
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();

            int n = 0;
            if (!InputInt(ref n, "Введіть кількість елементів масиву N") || n <= 0)
                return;

            double[] array = new double[n];
            for (int i = 0; i < n; i++)
            {
                if (!InputDouble(ref array[i], "Введіть елемент масиву X[" + i.ToString() + "]"))
                    return;
            }

            // Сортуємо масив
            Array.Sort(array);

            double key = 0;
            if (!InputDouble(ref key, "Введіть елемент для пошуку"))
                return;

            // Пошук усіх позицій
            List<int> positions = FindAllPositions(array, key);

            // Виведення
            string res = "Відсортований масив:\n";
            for (int i = 0; i < array.Length; i++)
                res += "X[" + i.ToString() + "] = " + array[i].ToString() + "\n";

            res += "\nРезультати пошуку:\n";
            if (positions.Count > 0)
                res += "Елемент " + key + " знайдено на позиціях: " + string.Join(", ", positions);
            else
                res += "Елемент " + key + " не знайдено в масиві.";

            MessageBox.Show(res, "Результати", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        static bool InputInt(ref int x, string prompt)
        {
            string s = x.ToString();
        retry:
            s = Interaction.InputBox(prompt, "Ввід", s);
            try
            {
                x = Convert.ToInt32(s);
            }
            catch
            {
                if (MessageBox.Show("Ви ввели неціле число. Повторити?", "Помилка", MessageBoxButtons.YesNo) == DialogResult.Yes)
                    goto retry;
                return false;
            }
            return true;
        }

        static bool InputDouble(ref double x, string prompt)
        {
            string s = x.ToString();
        retry:
            s = Interaction.InputBox(prompt, "Ввід", s);
            try
            {
                x = Convert.ToDouble(s);
            }
            catch
            {
                if (MessageBox.Show("Ви ввели недійсне число. Повторити?", "Помилка", MessageBoxButtons.YesNo) == DialogResult.Yes)
                    goto retry;
                return false;
            }
            return true;
        }

        static List<int> FindAllPositions(double[] arr, double key)
        {
            List<int> result = new List<int>();
            double tolerance = 1e-9;

            int left = 0, right = arr.Length - 1;
            int foundIndex = -1;

            // Бінарний пошук
            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (Math.Abs(arr[mid] - key) < tolerance)
                {
                    foundIndex = mid;
                    break;
                }
                else if (arr[mid] < key)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            // Якщо знайдено, обходимо всі входження
            if (foundIndex != -1)
            {
                int i = foundIndex;
                while (i >= 0 && Math.Abs(arr[i] - key) < tolerance)
                {
                    result.Add(i);
                    i--;
                }

                i = foundIndex + 1;
                while (i < arr.Length && Math.Abs(arr[i] - key) < tolerance)
                {
                    result.Add(i);
                    i++;
                }

                result.Sort(); // Позиції у порядку зростання
            }

            return result;
        }
    }
}
