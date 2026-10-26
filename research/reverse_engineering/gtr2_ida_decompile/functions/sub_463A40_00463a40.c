int __thiscall sub_463A40(float *this)
{
  float *v2; // esi
  int v3; // edi
  int result; // eax
  float v5; // [esp+0h] [ebp-Ch]

  v5 = dbl_FB1D08;
  sub_4617B0(v5);
  v2 = this + 2019;
  v3 = 68;
  do
  {
    result = sub_460350(v2);
    v2 += 11;
    --v3;
  }
  while ( v3 );
  return result;
}
