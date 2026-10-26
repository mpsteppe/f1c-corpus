int __thiscall sub_46CC10(float *this, float a2)
{
  double v3; // st7
  _BYTE *v4; // esi
  int v5; // edi
  int result; // eax

  v3 = a2 + this[26];
  v4 = this + 35;
  v5 = 49;
  do
  {
    result = sub_46C800(v4, (__int64)(v3 / 0.0049999999));
    v4 += 284;
    --v5;
  }
  while ( v5 );
  this[26] = v3 - (double)(int)(__int64)(v3 / 0.0049999999) * 0.0049999999;
  return result;
}
