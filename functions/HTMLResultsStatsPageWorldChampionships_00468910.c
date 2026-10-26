int __thiscall sub_468910(_DWORD *this)
{
  int v2; // edi
  LPVOID **v3; // ebx
  char v4; // al
  LPVOID *v5; // ebp

  v2 = this[17];
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( *v5 )
          FreeWrapper_7bcf(*v5);
        FreeWrapper_7bcf(v5);
      }
    }
    FreeWrapper_7bcf(v3);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  LinkedListInsertWithNodeAllocation(aExperienceLaps, -1);
  LinkedListInsertWithNodeAllocation(aStarts, -1);
  LinkedListInsertWithNodeAllocation(aAvgStartingPos, -1);
  LinkedListInsertWithNodeAllocation(aAvgFinishPosit, -1);
  LinkedListInsertWithNodeAllocation(aAvgRaceLength, -1);
  LinkedListInsertWithNodeAllocation(aAvgOpponentStr, -1);
  LinkedListInsertWithNodeAllocation(aPolePositions, -1);
  LinkedListInsertWithNodeAllocation(aPoints, -1);
  LinkedListInsertWithNodeAllocation(aWins, -1);
  LinkedListInsertWithNodeAllocation(aWorldChampions, -1);
  ((void (__thiscall *)(_DWORD *))loc_468640)(this);
  return 0;
}
