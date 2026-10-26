_BYTE *__thiscall sub_614590(int **this, char *String2, char a3)
{
  int *v4; // eax
  bool v5; // zf
  int v6; // esi
  const char *v7; // eax
  int *v8; // eax
  int *v9; // eax
  _DWORD *v10; // eax
  _BYTE *v11; // esi
  _DWORD *v13; // eax

  v4 = *this;
  v5 = *this == 0;
  this[2] = *this;
  if ( v5 || (v6 = *v4) == 0 )
  {
LABEL_9:
    v10 = operator new(0x1Cu);
    if ( v10 )
    {
      v10[1] = 0;
      v10[2] = -1;
      *(_BYTE *)v10 = 0;
      v10[3] = 0;
      v10[4] = 0;
      v10[5] = 0;
      v10[6] = 0;
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    sub_615860(String2);
    *v11 = 1;
    v13 = operator new(0xCu);
    if ( v13 )
    {
      *v13 = v11;
      v13[1] = 0;
      *((_BYTE *)v13 + 8) = 1;
    }
    else
    {
      v13 = 0;
    }
    if ( *this )
    {
      this[1][1] = (int)v13;
    }
    else
    {
      *this = v13;
      this[2] = v13;
    }
    this[1] = v13;
    this[3] = (int *)((char *)this[3] + 1);
    return v11;
  }
  else
  {
    while ( 1 )
    {
      v7 = *(const char **)(v6 + 4);
      if ( !v7 )
        v7 = WindowName;
      if ( !_stricmp(v7, String2) )
        break;
      v8 = this[2];
      if ( v8 )
      {
        v9 = (int *)v8[1];
        this[2] = v9;
        if ( v9 )
        {
          v6 = *v9;
          if ( *v9 )
            continue;
        }
      }
      goto LABEL_9;
    }
    if ( *(_BYTE *)v6 )
    {
      return 0;
    }
    else
    {
      if ( a3 )
        *(_DWORD *)(v6 + 24) = *(_DWORD *)(v6 + 20);
      else
        sub_6138B0(v6);
      sub_615860(String2);
      *(_BYTE *)v6 = 1;
      return (_BYTE *)v6;
    }
  }
}
