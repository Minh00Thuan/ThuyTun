using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai3
{
    class Program
    {
        static void Main(string[] args)
        {
            //nhap thang
            Console.Write("Nhap thang: ");
            string strngay = Console.ReadLine();
            //Chuyen chuoi sang so
            uint thang = 1;
            if (!uint.TryParse(strngay, out thang))
            {
                thang = 1;
            }
            Console.WriteLine();

            //nhap nam
            Console.Write("Nhap nam: ");
            string strnam = Console.ReadLine();
            //Chuyen chuoi song so
            uint nam = 1;
            if(!uint.TryParse(strnam, out nam))
            {
                nam = 1;
            }
            Console.WriteLine();    
            //Ham Xuat
            Console.WriteLine("thang {0} nam {1} co {2} ngay", thang, nam, TinhNgay(thang, nam));
        }
        static double TinhNgay(uint thang, uint nam)
        {
            if(thang>12||thang<0)
            {
                return 0;
            }
            else
            {
                if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12)
                {
                    return 31;
                }
                else if(thang==2)
                {
                    if(nam%4==0&&nam%100!=0||nam%400==0)
                    {
                        return 29;
                    }
                    return 28;
                }
                else
                {
                    return 30;
                }
            }
        }
    }
}
