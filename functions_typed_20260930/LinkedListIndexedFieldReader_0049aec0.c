char __thiscall sub_49AEC0(_DWORD *this, int a2, _WORD *a3, _WORD *a4)
{
  int v4; // esi
  char result; // al
  int v6; // edx
  _WORD **v7; // ecx
  _WORD *v8; // ecx

  v4 = a2;
  result = 0;
  if ( a2 < 0 || a2 >= this[3] )
  {
    this[2] = 0;
  }
  else
  {
    this[2] = *this;
    if ( a2 > 0 )
    {
      do
      {
        v6 = this[2];
        if ( !v6 )
          break;
        --v4;
        this[2] = *(_DWORD *)(v6 + 4);
      }
      while ( v4 > 0 );
    }
  }
  v7 = (_WORD **)this[2];
  if ( v7 && (v8 = *v7) != 0 )
  {
    *a3 = *v8;
    *a4 = v8[1];
    return 1;
  }
  else
  {
    *a3 = 0;
    *a4 = 0;
  }
  return result;
}

