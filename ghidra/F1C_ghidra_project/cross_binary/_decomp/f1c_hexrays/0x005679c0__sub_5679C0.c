// f1c  0x005679c0  size=59
_DWORD *__thiscall sub_5679C0(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  char *v4; // eax

  v2 = (_DWORD *)this[2];
  if ( !a2 )
    return 0;
  for ( ; v2; v2 = (_DWORD *)v2[1] )
  {
    v4 = sub_499E20(v2);
    if ( !sub_588410(a2, v4) )
      break;
  }
  return v2;
}
