using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai2
{
    class Program
    {
        static void Main(string[] args)
        {
            //nhap n
            Console.Write("Nhap n: ");
            string strline = Console.ReadLine();
            //chuyen doi chuoi so
            int n = 1;
            if(!int.TryParse(strline, out n))
            {
                n = 1;
            }
            if(n<0)
            {
                n = -n;
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
            double s = TinhTBCong(arrI);
            Console.WriteLine();
            Console.WriteLine("S={0:F2}", s);
        }
        static double TinhTBCong(int[] arrI)
        {
            double s = 0;
            //dat gia tri truoc la nho nhat
           /* int vOld = int.MinValue;
            //bien giu mang con dang duyet
            int nCur = 0;
            double sCur = 0;
            //bien giu tong so phan tu mang con
            int nS = 0;
            //duyet mang
            for(int i=0;i<arrI.Length;i++)
            {
                if(arrI[i]>=vOld)
                {
                    sCur += arrI[i];
                    nCur++;             
                }
                else
                {
                    if(nCur>1)
                    {
                        s += sCur;
                        nS += nCur;
                    }
                    sCur = 0;
                    nCur = 1;
                }
                vOld = arrI[i];
            }
            //lay gia tri trung binh cong
            s /= nS;*/
            for(int i=0;i<arrI.Length;i++)
            {
                s += arrI[i];
            }
            s /= arrI.Length;
            return s;
        }
    }
}
