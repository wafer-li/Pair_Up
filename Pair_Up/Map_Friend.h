#ifndef FRIEND_OF_MAP
#define FRIEND_OF_MAP

/*Friend function clearPiece
* Judge the whole map
* Change the Piece.isClear
*/
void ClearPiece(Map & map);//传入Map类，返回需要消去的Map类
int RemovePiece(Map & map);
void RepairPiece(Map & map);
#endif