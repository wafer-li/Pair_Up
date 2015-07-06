#include "ClearPiece.h"
#include "Map.h"
//status为访问的消除状态，color为该方块颜色
Map clearPiece(Map temporary){
	//行检查
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)//k = 2意味着首次出现三个一块
				{
					temporary.maplists[i][j].status = 1;
					temporary.maplists[i][j - 1].status = 1;
					temporary.maplists[i][j - 2].status = 1;
				}
				else if (k > 2)//之后的k每次都比2大，此时新增方块必定同色
				{
					temporary.maplists[i][j].status = 1;
				}
				if (j == 8)//防止第8和第9块同色时，继续比较而造成越界
					break;
				if (temporary.maplists[i][j].color == temporary.maplists[i][j + 1].color)//方块检查后j++调整j值
					j++;
				else
					break;//若方块颜色不对，那么不进行上述的状态调整过程
			}
		}
	}
	//列检查：方式相同
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)
				{
					temporary.maplists[j][i].status = 1;
					temporary.maplists[j - 1][i].status = 1;
					temporary.maplists[j - 2][i].status = 1;
				}
				else if (k > 2)
				{
					temporary.maplists[j][i].status = 1;
				}
				if (j == 8)
					break;
				if (temporary.maplists[j][i].color == temporary.maplists[j + 1][i].color)//color 的判断方法有待斟酌
					j++;
				else
					break;
			}
		}
	}
}