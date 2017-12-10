using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap n: ");
            string strline = Console.ReadLine();
            //Chuyển chuỗi sang số
            uint n = 1;
            if(!uint.TryParse(strline, out n))
            {
                n = 1;
            }
            Console.WriteLine();
            //goi ham tinh Sn va xuat
            Console.WriteLine("S({0})={1}", n, TinhSn(n));
        }
        static double TinhSn(uint n)
        {
            double s = 0;
            for (uint i = n; i > 0; i--) 
            {
                s +=i;
            }
            return s;
        }
    }
}
