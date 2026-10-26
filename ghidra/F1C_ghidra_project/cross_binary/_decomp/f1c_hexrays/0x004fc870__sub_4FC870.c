// f1c  0x004fc870  size=145
__int16 __thiscall sub_4FC870(float *this, _WORD *a2)
{
  __int16 result; // ax
  float v5; // [esp+10h] [ebp+4h]
  float v6; // [esp+10h] [ebp+4h]

  *a2 = sub_587BDC(*this * 65535.0);
  a2[1] = sub_587BDC(this[1] * 65535.0);
  a2[2] = sub_587BDC(this[2] * 65535.0);
  a2[3] = sub_587BDC(this[3] * 65535.0);
  v5 = this[4] * 128.0;
  result = (int)v5;
  a2[4] = result;
  v6 = this[5] * 128.0;
  a2[5] = (int)v6;
  return result;
}
