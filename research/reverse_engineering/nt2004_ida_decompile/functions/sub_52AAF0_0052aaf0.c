__int16 __thiscall sub_52AAF0(float *this, _WORD *a2)
{
  __int16 result; // ax
  float v4; // [esp+10h] [ebp+4h]
  float v5; // [esp+10h] [ebp+4h]

  *a2 = (__int64)(*this * 65535.0);
  a2[1] = (__int64)(this[1] * 65535.0);
  a2[2] = (__int64)(this[2] * 65535.0);
  a2[3] = (__int64)(this[3] * 65535.0);
  v4 = this[4] * 128.0;
  result = (int)v4;
  a2[4] = result;
  v5 = this[5] * 128.0;
  a2[5] = (int)v5;
  return result;
}
