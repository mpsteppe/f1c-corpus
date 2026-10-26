__int64 __thiscall sub_4AE730(_DWORD *this)
{
  double v2; // st7
  __int64 result; // rax
  float v4; // [esp+4h] [ebp-8h]
  float v5; // [esp+8h] [ebp-4h]

  v4 = flt_762A60;
  v2 = flt_762A64;
  this[24] = dword_762AE8;
  this[25] = dword_762AEC;
  v5 = v2;
  this[26] = dword_762AF0;
  this[27] = sub_451D60(dword_762A38);
  this[22] = (__int64)(v4 * 400.0);
  result = (__int64)(v5 * 300.0);
  this[23] = result;
  return result;
}
