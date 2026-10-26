int __thiscall sub_4A3390(_DWORD *this, char a2)
{
  int result; // eax
  int v4; // ebx
  int v5; // ebp
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // ecx

  if ( (*(_BYTE *)this & 1) == 0 )
  {
    result = this[3];
    v4 = 0;
    if ( result > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this[4];
        v7 = *(_DWORD *)(v6 + v5 + 100);
        v8 = v5 + v6;
        if ( v7 )
        {
          sub_4A2840(v8, 0.0);
          if ( !a2 || *(_BYTE *)(v8 + 3) )
          {
            v9 = *(_DWORD *)(v8 + 100);
            if ( *(_BYTE *)(v8 + 2) )
              BitClear(v9);
            else
              Bit12FlagSet(v9);
          }
          if ( *(_DWORD *)(v8 + 72) != -1 && *(_DWORD *)(v8 + 100) )
            sub_5506A0(0, 0, 0);
        }
        result = this[3];
        ++v4;
        v5 += 120;
      }
      while ( v4 < result );
    }
    if ( dword_7CF884 >= 2 )
    {
      if ( this[5] )
        result = UIWidgetRecursiveStateUpdate(1, 0, 0);
    }
    *this |= 1u;
  }
  return result;
}
