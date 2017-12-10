using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai_02
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap so kWh: ");
            string strline = Console.ReadLine();
            //Chuyen doi chuoi sang so
            uint n = 1;
            if(!uint.TryParse(strline, out n))
            {
                n = 1;
            }
            Console.WriteLine();
            //goi ham tinh Sn va xuat
            Console.WriteLine("tien dien cua {0} kwh la {1}", n, TinhTien(n));
        }
        static double TinhTien(uint n)
        {
            double s = 0, temp = 0;
            if (n>400) 
            {
                temp = n - 400;
                s += temp * 2.399;
                n = 400;
            }
            if(n>300)
            {
                temp = n - 300;
                s += (temp) * 2.324;
                n = 300;
            }
            if(n>200)
            {
                temp = n - 200;
                s += temp * 2.082;
                n = 200;
            }           
            if(n>100)
            {
                temp = n - 100;
                s += temp * 1.660;
                n = 100;
            }  
            if(n>50)
            {
                temp = n - 50;
                s += temp * 1.433;
                n = 50;
            }
            s += n * 1.388;
            return s; 
        }
    }
}
