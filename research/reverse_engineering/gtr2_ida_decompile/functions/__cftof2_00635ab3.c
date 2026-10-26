char *__usercall _cftof2@<eax>(_DWORD *a1@<eax>, char *a2, int Size, char a4)
{
  int v5; // eax
  char *v6; // eax
  char *v7; // ebx
  int v8; // eax
  char *v9; // ebx
  int v10; // esi
  char *v11; // ebx
  int v12; // esi

  v5 = a1[1] - 1;
  if ( a4 && v5 == Size )
  {
    v6 = &a2[v5 + (*a1 == 45)];
    *v6 = 48;
    v6[1] = 0;
  }
  v7 = a2;
  if ( *a1 == 45 )
  {
    *a2 = 45;
    v7 = a2 + 1;
  }
  v8 = a1[1];
  if ( v8 > 0 )
  {
    v9 = &v7[v8];
  }
  else
  {
    _shift(v7, 1);
    *v7 = 48;
    v9 = v7 + 1;
  }
  if ( Size > 0 )
  {
    _shift(v9, 1);
    *v9 = byte_9131A4;
    v10 = a1[1];
    v11 = v9 + 1;
    if ( v10 < 0 )
    {
      v12 = -v10;
      if ( a4 || Size >= v12 )
        Size = v12;
      _shift(v11, Size);
      memset(v11, 48, Size);
    }
  }
  return a2;
}
