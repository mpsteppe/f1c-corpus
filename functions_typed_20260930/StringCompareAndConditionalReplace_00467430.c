int __thiscall StringCompareAndConditionalReplace(_DWORD *this, char *a2)
{
  char *v4; // ebp
  unsigned int v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edx

  if ( !a2 )
    return -1;
  v4 = (char *)this[188];
  if ( !strcmp(v4, a2) )
    return -1;
  v5 = this[190] - 1;
  sub_587DD0(v4, a2, v5);
  v4[v5] = 0;
  v6 = (_BYTE *)this[188];
  this[189] = v6;
  if ( *v6 )
  {
    do
    {
      v7 = (_BYTE *)(this[189] + 1);
      this[189] = v7;
    }
    while ( *v7 );
  }
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  return 0;
}

