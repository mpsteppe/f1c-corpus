_BYTE *__thiscall sub_501490(char *this, _BYTE *a2, int a3)
{
  int v4; // eax
  _BYTE *result; // eax
  char *v6; // eax
  char v7; // cl
  char *v8; // esi
  char v9[256]; // [esp+8h] [ebp-100h] BYREF

  v4 = sub_473AB0(&dword_B6CBA8);
  if ( v4 )
  {
    result = (_BYTE *)sub_630FE0(a2, v4, a3 - 1);
    a2[a3 - 1] = 0;
  }
  else
  {
    v6 = this + 20;
    *a2 = 0;
    do
    {
      v7 = *v6;
      v6[v9 - (this + 20)] = *v6;
      ++v6;
    }
    while ( v7 );
    v8 = &v9[strlen(v9)];
    if ( v8 > v9 )
    {
      while ( *v8 != 92 )
      {
        if ( --v8 <= v9 )
          goto LABEL_10;
      }
      ++v8;
    }
LABEL_10:
    result = (_BYTE *)sub_616480(v8, ".PLR");
    if ( result )
      *result = 0;
    if ( v8 )
    {
      result = (_BYTE *)sub_630FE0(a2, v8, a3 - 1);
      a2[a3 - 1] = 0;
    }
  }
  return result;
}
