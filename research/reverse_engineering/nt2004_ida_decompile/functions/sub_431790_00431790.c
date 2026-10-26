void __thiscall sub_431790(_BYTE *this, int a2, int a3)
{
  int v4; // ebp
  int v5; // esi
  int v6; // ecx

  v4 = *(_DWORD *)&this[64 * a2 + 3012];
  v5 = (int)&this[64 * a2 + 2992];
  if ( a3 > 0 )
  {
    v6 = *(_DWORD *)&this[64 * a2 + 3008];
    if ( a3 < v6 )
      *(_DWORD *)(v5 + 20) = a3;
    else
      *(_DWORD *)(v5 + 20) = v6 - 1;
  }
  else
  {
    *(_DWORD *)&this[64 * a2 + 3012] = 0;
  }
  sub_430ED0((int)this, 4, a2);
  if ( *(_DWORD *)(v5 + 20) != v4 )
  {
    *this = 1;
    if ( a2 )
    {
      if ( a2 != 4 && a2 != 51 && a2 != 52 && a2 != 53 && a2 != 54 )
        this[6564] = 1;
    }
  }
}
