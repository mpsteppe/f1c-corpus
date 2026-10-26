_WORD *__thiscall sub_4B1C70(_DWORD *this, _WORD *a2)
{
  __int16 v3; // ax
  _WORD *result; // eax
  __int16 v5; // cx

  *(_BYTE *)this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[8] = 0;
  this[7] = 0;
  *((_BYTE *)this + 36) = 0;
  this[10] = 1065353216;
  this[11] = 1065353216;
  *((_WORD *)this + 12) = (__int64)((double)dword_6152E8 * 0.039999999);
  *((_WORD *)this + 13) = (__int64)((double)dword_6152EC * 0.053333335);
  v3 = -*((_WORD *)this + 12);
  *((_WORD *)this + 10) = v3;
  *((_WORD *)this + 8) = v3;
  result = a2;
  v5 = *a2;
  *((_WORD *)this + 11) = *a2;
  *((_WORD *)this + 9) = v5;
  *(_DWORD *)a2 += *((__int16 *)this + 13);
  return result;
}
