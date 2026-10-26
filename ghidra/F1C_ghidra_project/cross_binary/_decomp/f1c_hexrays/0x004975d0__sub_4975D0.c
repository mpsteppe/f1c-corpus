// f1c  0x004975d0  size=121
_DWORD *__thiscall sub_4975D0(_DWORD *this, _DWORD *a2, const CHAR *a3)
{
  int v5; // ecx
  int i; // eax

  if ( !a2 )
    return 0;
  a2[16] = this;
  a2[38] = 0;
  a2[39] = 0;
  a2[35] = 0;
  if ( a3 )
    sub_49AD50(a3);
  v5 = this[7];
  if ( v5 )
  {
    for ( i = *(_DWORD *)(v5 + 140); i; i = *(_DWORD *)(i + 140) )
      v5 = i;
    *(_DWORD *)(v5 + 140) = a2;
    return a2;
  }
  else
  {
    this[7] = a2;
    return a2;
  }
}
