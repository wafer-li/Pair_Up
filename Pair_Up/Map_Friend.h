#ifndef FRIEND_OF_MAP_H
#define FRIEND_OF_MAP_H

/*Friend function ClearPiece
* Judge the whole map
* Change the Piece.isClear
*/
void ClearPiece(Map & map);

/*Friend function RemovePiece
* Ergodic the whole map
* Count the number of removing-items
* Remove Piece
* Return the number of removing-items
*/
int RemovePiece(Map & map);

/*Friend function RepairPiece
* Ergodic the deque
* If the deque are not full
* Fill it
*/
void RepairPiece(Map & map);

#endif	//!FRIEND_OF_MAP