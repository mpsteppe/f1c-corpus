_DWORD *__thiscall sub_5D3B10(int *this)
{
  void *v2; // eax
  _DWORD *result; // eax

  v2 = operator new(0x30u);
  if ( v2 )
    result = (_DWORD *)sub_5D3A60(v2, this[5], (int)(this + 1), this[6]);
  else
    result = 0;
  result[7] = this[7];
  result[8] = this[8];
  result[9] = this[9];
  result[10] = this[10];
  result[11] = this[11];
  return result;
}
