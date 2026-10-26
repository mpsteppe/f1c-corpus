// f1c  0x00547390  size=48
_DWORD *__thiscall sub_547390(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  result = a3;
  if ( a3 == (_DWORD *)4096 )
  {
    result = (_DWORD *)this[35];
    *a2 = result;
  }
  else if ( a3 == (_DWORD *)0x2000 )
  {
    result = a2;
    *a2 = this[36];
  }
  return result;
}
