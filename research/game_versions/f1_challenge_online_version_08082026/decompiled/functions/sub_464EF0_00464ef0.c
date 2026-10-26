int __thiscall sub_464EF0(float *this, float a2)
{
  double v3; // st7
  int v4; // ebx
  _BYTE *v5; // esi
  int v6; // edi
  int result; // eax

  v3 = a2 + this[26];
  v4 = sub_587BDC(v3);
  v5 = this + 35;
  v6 = 104;
  do
  {
    result = sub_464B10(v5, v4);
    v5 += 560;
    --v6;
  }
  while ( v6 );
  this[26] = v3 - (double)v4 * 0.0049999999;
  return result;
}
