int __thiscall sub_4A5820(_DWORD *this, int a2)
{
  int v2; // ebp
  int v4; // ebx
  int i; // esi
  int result; // eax

  v2 = a2;
  if ( a2 > 0 )
  {
    v4 = 0;
    if ( (int)this[87] >= 0 )
      v4 = CompoundIndexLookup(this[87]);
    for ( i = 0; i < *(_DWORD *)(this[86] + 16); ++i )
    {
      result = CompoundIndexLookup(i);
      if ( *(_BYTE *)(result + 20) )
      {
        if ( dword_7C56A4 <= 0 || dword_7C56A4 > 5 || dword_8AFED4 )
          goto LABEL_12;
      }
      else if ( !v4 || v4 == result )
      {
LABEL_12:
        if ( !--v2 )
          return result;
      }
    }
  }
  return 0;
}

