int __thiscall sub_4B2AF0(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // esi
  const char *v5; // eax
  char v7[253]; // [esp+10h] [ebp-100h] BYREF
  __int16 v8; // [esp+10Dh] [ebp-3h]
  char v9; // [esp+10Fh] [ebp-1h]

  if ( sub_4CD660(this) != 5 )
    sub_498E00(this);
  v2 = this[217];
  if ( v2 < 0 || v2 >= this[221] )
    goto LABEL_9;
  v3 = (int *)this[218];
  if ( v2 > 0 )
  {
    while ( v3 )
    {
      v3 = (int *)v3[1];
      if ( --v2 <= 0 )
        goto LABEL_8;
    }
    goto LABEL_9;
  }
LABEL_8:
  if ( !v3 )
  {
LABEL_9:
    v4 = 0;
    goto LABEL_11;
  }
  v4 = *v3;
LABEL_11:
  memset(v7, 0, sizeof(v7));
  v8 = 0;
  v9 = 0;
  sub_501490(v7, 256);
  if ( v4 )
  {
    v5 = *(const char **)(v4 + 64);
    if ( !v5 )
      v5 = WindowName;
    if ( strcmp(v5, v7) )
    {
      sub_4A0720();
      return 0;
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  return 0;
}
