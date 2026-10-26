char *__cdecl _cftof2(char *Src, int Size, _DWORD *a3, char a4)
{
  int v4; // eax
  char *v5; // eax
  _BYTE *v6; // edi
  int v7; // eax
  _BYTE *v8; // edi
  int v9; // esi
  void *v10; // edi
  int v11; // esi

  v4 = a3[1] - 1;
  if ( a4 && v4 == Size )
  {
    v5 = &Src[v4 + (*a3 == 45)];
    *v5 = 48;
    v5[1] = 0;
  }
  v6 = Src;
  if ( *a3 == 45 )
  {
    *Src = 45;
    v6 = Src + 1;
  }
  v7 = a3[1];
  if ( v7 > 0 )
  {
    v8 = &v6[v7];
  }
  else
  {
    _shift(v6, 1);
    *v6 = 48;
    v8 = v6 + 1;
  }
  if ( Size > 0 )
  {
    _shift(v8, 1);
    *v8 = byte_625890;
    v9 = a3[1];
    v10 = v8 + 1;
    if ( v9 < 0 )
    {
      if ( a4 )
      {
        v11 = -v9;
      }
      else
      {
        v11 = -v9;
        if ( Size < v11 )
        {
LABEL_15:
          _shift(v10, Size);
          memset(v10, 48, Size);
          return Src;
        }
      }
      Size = v11;
      goto LABEL_15;
    }
  }
  return Src;
}
