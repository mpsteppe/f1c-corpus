int __thiscall sub_5935A0(float *this, _WORD *a2)
{
  int result; // eax
  float v4; // [esp+0h] [ebp-Ch]
  float v5; // [esp+0h] [ebp-Ch]

  *a2 = (unsigned __int64)(*this * 65535.0);
  a2[1] = (unsigned __int64)(this[1] * 65535.0);
  a2[2] = (unsigned __int64)(this[2] * 65535.0);
  a2[3] = (unsigned __int64)(this[3] * 65535.0);
  v4 = this[4] * 128.0;
  a2[4] = sub_4015C0(v4);
  v5 = this[5] * 128.0;
  result = sub_4015C0(v5);
  a2[5] = result;
  return result;
}
