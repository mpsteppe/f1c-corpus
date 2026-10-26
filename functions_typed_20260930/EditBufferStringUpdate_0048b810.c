int __thiscall sub_48B810(_DWORD *this, const char *a2)
{
  const char *v4; // ebp
  int v5; // esi
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // al
  _BYTE *v8; // eax
  _BYTE *v9; // edx

  if ( !a2 )
    return -1;
  v4 = (const char *)this[188];
  if ( !strcmp(v4, a2) )
    return -1;
  v5 = this[190] - 1;
  sub_587DD0(v4, a2, v5);
  v4[v5] = 0;
  v6 = (unsigned __int8 *)this[188];
  v7 = *v6;
  if ( *v6 )
  {
    while ( sub_48B560((int)this, v7) )
    {
      v7 = *++v6;
      if ( !v7 )
        goto LABEL_10;
    }
    *v6 = 0;
  }
LABEL_10:
  v8 = (_BYTE *)this[188];
  this[189] = v8;
  if ( *v8 )
  {
    do
    {
      v9 = (_BYTE *)(this[189] + 1);
      this[189] = v9;
    }
    while ( *v9 );
  }
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  return 0;
}

