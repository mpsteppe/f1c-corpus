int __thiscall sub_616B50(_DWORD *this, char *String2)
{
  int result; // eax
  int *v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v7; // eax
  int *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  int v11; // edx

  result = -1;
  if ( String2 )
  {
    v4 = (int *)this[9];
    this[11] = v4;
    if ( !v4 )
      goto LABEL_13;
    v5 = *v4;
    if ( !*v4 )
      goto LABEL_13;
    while ( 1 )
    {
      v6 = *(const char **)v5;
      if ( !*(_DWORD *)v5 )
        v6 = WindowName;
      if ( !_stricmp(v6, String2) )
        break;
      v7 = this[11];
      if ( v7 )
        this[11] = *(_DWORD *)(v7 + 4);
      v8 = (int *)this[11];
      if ( v8 )
      {
        v5 = *v8;
        if ( *v8 )
          continue;
      }
      goto LABEL_13;
    }
    result = *(_DWORD *)(v5 + 8);
    if ( result == -1 )
    {
LABEL_13:
      v9 = operator new(0xCu);
      v10 = 0;
      if ( v9 )
      {
        v11 = this[13];
        this[13] = v11 + 1;
        v10 = sub_616520(v9, String2, v11);
      }
      sub_5FDFB0(this + 9, (int)v10, 1);
      return v10[2];
    }
  }
  return result;
}
