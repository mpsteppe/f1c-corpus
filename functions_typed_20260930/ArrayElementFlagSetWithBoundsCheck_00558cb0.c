_DWORD *__thiscall sub_558CB0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // eax

  result = (_DWORD *)a2;
  if ( a2 < this[11] )
  {
    sub_53B330((_DWORD *)(this[13] + (a2 << 7) + 16), a3, a4, a5);
    result = (_DWORD *)(this[13] + (a2 << 7));
    *result |= 0x4000u;
  }
  return result;
}

