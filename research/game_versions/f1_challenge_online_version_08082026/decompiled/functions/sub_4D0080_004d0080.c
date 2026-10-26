int __thiscall sub_4D0080(int *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  void *v7; // ebp
  int v8; // eax
  int v9; // ecx
  _BYTE *v10; // edi
  int v11; // ebx

  result = this[1];
  if ( result )
  {
    result = dword_8AFE88;
    if ( dword_8AFE88 )
    {
      result = *this;
      v3 = 0;
      if ( *this > 0 )
      {
        v4 = 0;
        do
        {
          if ( *(_DWORD *)(v4 + this[1]) )
            sub_545150(*(_DWORD *)(v4 + this[1]));
          result = *this;
          ++v3;
          v4 += 132;
        }
        while ( v3 < *this );
      }
    }
    v5 = this[1];
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 - 4);
      v7 = (void *)(v5 - 4);
      v8 = v5 + 132 * v6;
      v9 = v6 - 1;
      if ( v9 >= 0 )
      {
        v10 = (_BYTE *)(v8 + 4);
        v11 = v9 + 1;
        do
        {
          v10 -= 132;
          sub_4A2220(v10);
          --v11;
        }
        while ( v11 );
      }
      result = sub_587BCF(v7);
    }
    this[1] = 0;
  }
  *this = 0;
  return result;
}
