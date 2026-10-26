int __thiscall sub_4A1AC0(_DWORD *this, char *Source)
{
  char *v4; // ebp
  size_t v5; // esi
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // al
  _BYTE *v8; // eax
  _BYTE *v9; // edx

  if ( !Source )
    return -1;
  v4 = (char *)this[199];
  if ( !strcmp(v4, Source) )
    return -1;
  v5 = this[201] - 1;
  strncpy(v4, Source, v5);
  v4[v5] = 0;
  v6 = (unsigned __int8 *)this[199];
  v7 = *v6;
  if ( *v6 )
  {
    while ( sub_4A17C0((int)this, v7) )
    {
      v7 = *++v6;
      if ( !v7 )
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
