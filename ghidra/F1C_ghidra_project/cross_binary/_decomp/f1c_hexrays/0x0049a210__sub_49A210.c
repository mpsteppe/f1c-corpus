// f1c  0x0049a210  size=64
_DWORD *__thiscall sub_49A210(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  char *v3; // eax

  if ( !a2 )
    return 0;
  v2 = (_DWORD *)*this;
  if ( !*this )
    return 0;
  while ( 1 )
  {
    v3 = sub_499E20(v2);
    if ( !sub_588410(a2, v3) )
      break;
    v2 = (_DWORD *)sub_499E00(v2);
    if ( !v2 )
      return 0;
  }
  return v2;
}
