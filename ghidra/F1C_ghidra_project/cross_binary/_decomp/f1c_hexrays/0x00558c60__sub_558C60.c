// f1c  0x00558c60  size=69
_DWORD *__thiscall sub_558C60(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // eax

  result = (_DWORD *)a2;
  if ( a2 < this[11] )
  {
    sub_53B200((_DWORD *)(this[13] + (a2 << 7) + 16), a3, a4, a5);
    result = (_DWORD *)(this[13] + (a2 << 7));
    *result |= 0x1000u;
    this[8] &= ~0x10000u;
  }
  return result;
}
