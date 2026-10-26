// f1c  0x00403f70  size=72
_DWORD *__thiscall sub_403F70(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v4; // edx
  _DWORD *v5; // edx
  _DWORD *result; // eax

  v4 = (_DWORD *)(28 * a2 + this[85]);
  *a3 = *v4;
  a3[1] = v4[1];
  a3[2] = v4[2];
  v5 = (_DWORD *)(28 * a2 + this[85] + 12);
  result = a4;
  *a4 = *v5;
  a4[1] = v5[1];
  a4[2] = v5[2];
  return result;
}
