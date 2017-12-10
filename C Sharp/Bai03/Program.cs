using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bai03
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Nhap: ");
            string strIn = Console.ReadLine();
            Console.WriteLine();
            Console.WriteLine("Chuoi nguoc: {0}", ChuoiTuNguoc(strIn));
        }
        static string ChuoiTuNguoc(string strIn)
        {
            //su dung de dao nguoc chuoi
            StringBuilder sb = new StringBuilder();
            //tach cac tu trong chuoi
            string[] arrStr = strIn.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            //dua vao tao chuoi
            for(int i=arrStr.Length-1;i>0;i--)
            {
                sb.AppendFormat("{0}", arrStr[i]+' ');
            }
            if(arrStr.Length>0)
            {
                sb.Append(arrStr[0]);
            }
            return sb.ToString();
        }
    }
}
