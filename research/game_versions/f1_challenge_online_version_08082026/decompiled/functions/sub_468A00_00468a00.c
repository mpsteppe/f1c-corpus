int __thiscall sub_468A00(_DWORD *this)
{
  int v2; // edi
  LPVOID **v3; // ebx
  char v4; // al
  LPVOID *v5; // ebp

  byte_7CFF30 = 0;
  if ( byte_7CFF32 )
    byte_7CFF30 = byte_7CFF32;
  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 60))(this, 0);
  sub_468910(this);
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
          sub_587BCF(*v5);
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  this[17] = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  sub_486F30(aExperienceLaps, -1);
  sub_486F30(aStarts, -1);
  sub_486F30(aAvgStartingPos, -1);
  sub_486F30(aAvgFinishPosit, -1);
  sub_486F30(aAvgRaceLength, -1);
  sub_486F30(aAvgOpponentStr, -1);
  sub_486F30(aPolePositions, -1);
  sub_486F30(aPoints, -1);
  sub_486F30(aWins, -1);
  sub_486F30(aWorldChampions, -1);
  sub_486F30(aCircuit, -1);
  sub_486F30(aExperienceLaps, -1);
  sub_486F30(aBestLap, -1);
  sub_489CB0(this);
  ((void (__thiscall *)(_DWORD *))loc_468640)(this);
  sub_468BF0(this);
  return 0;
}
