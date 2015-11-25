using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test4
{
    class Program
    {
        /// <summary>
        /// プレイヤーキャラクター
        /// </summary>
        static string player = "★";
        /// <summary>
        /// なにもいないときに表示するキャラ
        /// </summary>
        static string blank = "　";
        /// <summary>
        /// 壁
        /// </summary>
        ///static string wall = "■";
        /// <summary>
        /// マップデータ用
        /// </summary>
        static string[] mapChip = { "　", "■", "上", "下", "扉", "穴", "宝", "空" };
        /// <summary>
        /// マップデータ
        /// </summary>
        static int[, ,] map =
        {
            {
                {1,1,1,1,1,1,1,1,1,1,},
                {1,0,0,0,0,0,1,0,2,1,},
                {1,0,1,1,1,0,0,0,1,1,},
                {1,0,1,0,0,0,1,0,0,1,},
                {1,0,1,0,1,1,1,1,1,1,},
                {1,0,1,0,1,0,0,0,0,1,},
                {1,0,0,0,0,0,1,1,6,1,},
                {1,0,1,1,1,1,1,1,0,1,},
                {1,4,0,0,0,0,0,0,0,1,},
                {1,1,1,1,1,1,1,1,1,1,},
            },
            {
                {1,1,1,1,1,1,1,1,1,1,},
                {1,7,5,0,0,0,1,0,3,1,},
                {1,0,1,1,1,0,0,0,1,1,},
                {1,0,1,0,0,0,1,0,0,1,},
                {1,0,1,0,1,1,1,1,1,1,},
                {1,0,1,0,1,0,0,0,0,1,},
                {1,0,0,0,0,0,1,1,0,1,},
                {1,0,1,1,1,1,1,1,0,1,},
                {1,0,0,0,0,0,0,0,0,1,},
                {1,1,1,1,1,1,1,1,1,1,},
            },
        };
        /// <summary>
        /// 階数（0が一階）
        /// </summary>
        static int floor = 0;
        /// <summary>
        /// プレイヤーのＭＡＰ座標
        /// </summary>
        static int[] pos = { 1, 1 };
        /// <summary>
        /// プレイヤーの直前の座標
        /// </summary>
        static int[] oldpos = { 1, 1 };

        static void Main(string[] args)
        {
            ///カーソルを画面から消す
            Console.CursorVisible = false;
            ///マップを描画する
            initMap();
            ///プレイヤーを描画する
            DisplayPlayer();
            ///キャラクターのキー入力
            keyInCheck();
        }
        /// <summary>
        /// あたり判定するキャラ番号
        /// </summary>
        static int[] hitTbl = { 1, 4, 6, 7 };
        /// <summary>
        /// マップのあたりをチェックして移動
        /// </summary>
        /// <param name="x">移動先のｘ加算情報</param>
        /// <param name="y">移動先のｙ加算情報</param>
        static void movePlayer(int x, int y)
        {
            ///あたりテーブルを全部チェックして
            ///当たらなければ移動する
            for (int i = 0; i < hitTbl.Length; i++)
            {
                if (getMapData(pos[0] + x, pos[1] + y) == hitTbl[i])
                    return;
            }
            pos[0] += x;
            pos[1] += y;
            ///階段の上り下りチェック
            updownFloorCheck();
        }
        /// <summary>
        /// 階段の上り下りチェック
        /// </summary>
        static void updownFloorCheck()
        {
            ///もしも今の場所が2なら
            ///floorを1加えてマップと
            ///キャラクターを再描画
            if (getMapData(pos[0], pos[1]) == 2)
            {
                floor++;
                initMap();
                DisplayPlayer();
            }
            ///もしも今の場所が3なら
            ///floorを１引いてマップと
            ///キャラクターを再描画
            else if (getMapData(pos[0], pos[1]) == 3)
            {
                floor--;
                initMap();
                DisplayPlayer();
            }
        }

        /// <summary>
        /// キャラクターのキー入力
        /// </summary>
        static private void keyInCheck()
        {
            /// 無限に入力を受け付ける
            while (true)
            {
                ///　キーの入力待ち
                ConsoleKeyInfo kinfo = Console.ReadKey(true);
                if (kinfo.Key == ConsoleKey.LeftArrow)
                    movePlayer(-1, 0);
                if (kinfo.Key == ConsoleKey.RightArrow)
                    movePlayer(1, 0);
                if (kinfo.Key == ConsoleKey.UpArrow)
                    movePlayer(0, -1);
                if (kinfo.Key == ConsoleKey.DownArrow)
                    movePlayer(0, 1);
                ///プレイヤーを描画する
                DisplayPlayer();
            }
        }
        /// <summary>
        /// プレイヤーの表示
        /// </summary>
        static void DisplayPlayer()
        {
            ///元の場所に空白を入れる
            Locate(oldpos[0], oldpos[1]);
            Console.Write(mapChip[getMapData(oldpos[0], oldpos[1])]);
            ///新しい場所に「☆」を入れる
            Locate(pos[0], pos[1]);
            Console.Write(player);
            ///元の場所を今いる場所に変更
            oldpos[0] = pos[0];
            oldpos[1] = pos[1];
        }
        /// <summary>
        /// マップの初期化
        /// </summary>
        static void initMap()
        {
            for (int y = 0; y < 10; y++)
            {
                for (int x = 0; x < 10; x++)
                {
                    ///カーソルの座標移動
                    Locate(x, y);
                    Console.Write(mapChip[getMapData(x, y)]);
                }
            }
        }

        /// <summary>
        /// 所定の座標にカーソルを移動
        /// </summary>
        /// <param name="x">Y座標</param>
        /// <param name="y">X座標</param>
        static void Locate(int x, int y)
        {
            Console.CursorLeft = x * 2;
            Console.CursorTop = y;
        }

        /// <summary>
        /// マップチップ情報の読み込み
        /// </summary>
        /// <param name="x">対象のｘ座標</param>
        /// <param name="y">対象のｙ座標</param>
        /// <returns>マップチップ番号</returns>
        static int getMapData(int x, int y)
        {
            return (map[floor, y, x] & 0xff);
        }

        /// <summary>
        /// マップのステータスの読み込み
        /// </summary>
        /// <param name="x">対象のｘ座標</param>
        /// <param name="y">対象のｙ座標</param>
        /// <returns>ステータス情報</returns>
        static int getMapStat(int x, int y)
        {
            return (map[floor, y, x] >> 8);
        }
    }
}
