int __thiscall sub_4CE770(_DWORD *this, const char *a2)
{
  const char *v4; // ebp
  int v5; // esi
  _BYTE *v6; // esi
  _BYTE *v8; // eax
  _BYTE *v9; // ecx

  if ( !a2 )
    return -1;
  v4 = (const char *)this[199];
  if ( !strcmp(v4, a2) )
    return -1;
  v5 = this[201] - 1;
  sub_630FE0(v4, a2, v5);
  v4[v5] = 0;
  v6 = (_BYTE *)this[199];
  if ( *v6 )
  {
    while ( (unsigned __int8)((int (__thiscall *)(_DWORD *, _DWORD))byte_4CE6B0)(this, (unsigned __int8)*v6) )
    {
      if ( !*++v6 )
        goto LABEL_10;
    }
    *v6 = 0;
  }
LABEL_10:
  v8 = (_BYTE *)this[199];
  this[200] = v8;
  if ( *v8 )
  {
    do
    {
      v9 = (_BYTE *)(this[200] + 1);
      this[200] = v9;
    }
    while ( *v9 );
  }
  return 0;
}
