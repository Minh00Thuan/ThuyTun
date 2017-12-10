using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai4
{
    class Program
    {
        static void Main(string[] args)
        {
            //Nhap vao so n
            Console.Write("Nhap n: ");
            string strline = Console.ReadLine();
            //chuyen chuoi sang so
            int n = 1;
            if (!int.TryParse(strline, out n))
            {
                n = 1;
            }
            //phat sinh mang
            Random rd = new Random();
            //cap phat mang
            int[] arrI = new int[n];
            for(int i=0;i<n;i++)
            {
                arrI[i] = rd.Next(1000);
            }
            //Xuat mang
            Console.WriteLine("Mang: ");
            for(int i=0;i<arrI.Length;i++)
            {
                Console.Write("{0}, ", arrI[i]);
            }
            Console.WriteLine();
            TimChuoiConTangDaiNhat(arrI);
        }
        static void TimChuoiConTangDaiNhat(int[] arrI)
        {
            int MaxLong = 0, MaxStart = 0, MaxEnd = 0;//bien chinh
            int TempLong = 0, Start = 0, End = 0;//bien phu
            int i = 0;//bien dem
            bool test = true;//bien co hieu
            while(++i<arrI.Length)
            {
                if(arrI[i-1]<=arrI[i])
                {
                    if(test==true)
                    {
                        Start = i - 1;
                    }
                    test = false;
                    End = i;
                    TempLong++;
                }
                else
                {
                    test = true;
                    TempLong = 0;
                }
                if(TempLong>MaxLong)
                {
                    MaxLong = TempLong;
                    MaxStart = Start;
                    MaxEnd = End;
                }
            }
            Console.WriteLine();
            Console.Write("day con tang dai nhat: ");
            while(MaxStart<=MaxEnd)
            {
                Console.Write("{0} ", arrI[MaxStart]);
                MaxStart++;
            }
        }
    }
}
