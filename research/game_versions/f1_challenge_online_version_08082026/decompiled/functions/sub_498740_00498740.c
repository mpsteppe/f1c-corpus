int __thiscall sub_498740(_DWORD *this)
{
  double v2; // st7
  int result; // eax
  float v4; // [esp+4h] [ebp-8h]
  float v5; // [esp+8h] [ebp-4h]

  v4 = flt_7CB274;
  v2 = flt_7CB278;
  this[25] = dword_7CB2FC;
  this[26] = dword_7CB300;
  v5 = v2;
  this[27] = dword_7CB304;
  this[28] = sub_44F7D0(dword_7CB24C);
  this[23] = sub_587BDC(v4 * 400.0);
  result = sub_587BDC(v5 * 300.0);
  this[24] = result;
  return result;
}
