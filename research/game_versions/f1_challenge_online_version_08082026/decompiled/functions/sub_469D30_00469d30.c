int __thiscall sub_469D30(_DWORD *this)
{
  int v2; // esi
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
  sub_486F30(aCircuit, -1);
  sub_486F30(aExperienceLaps, -1);
  sub_486F30(aBestLap, -1);
  sub_489CB0(this);
  sub_469900(this);
  sub_48A3B0(0);
  return 0;
}
