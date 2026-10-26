int __thiscall sub_421B60(int this)
{
  float *v2; // ecx
  double v3; // st7
  double v4; // st7
  int result; // eax
  long double v6; // st7
  int v7; // [esp+0h] [ebp-10h]
  int v8; // [esp+4h] [ebp-Ch]
  float v9; // [esp+Ch] [ebp-4h]

  if ( *(_BYTE *)(this + 24208) )
  {
    v2 = *(float **)(this + 23432);
    v3 = *(float *)(this + 17636) * v2[55] + *(float *)(this + 17632) * v2[54] + *(float *)(this + 17628) * v2[53] >= flt_628F78
       ? *(float *)(this + 17636) * v2[55] + *(float *)(this + 17632) * v2[54] + *(float *)(this + 17628) * v2[53]
       : flt_628F78;
    *(float *)(this + 23760) = v3;
    if ( v3 < *(float *)(this + 24720) )
    {
      *(float *)&v8 = *(float *)(this + 23728) + 3.0;
      *(float *)&v7 = *(float *)(this + 23728) - 3.0;
      sub_529AC0(this + 23760, 0.25, v7, v8);
    }
  }
  v9 = fabs(*(float *)(this + 23728) - (sub_529A00(0) - 3.5));
  v4 = sub_529A00(1);
  result = *(_DWORD *)(this + 24024);
  v6 = fabs(*(float *)(this + 23728) - (v4 + 3.5));
  if ( result != 4 )
  {
    if ( v6 >= v9 )
      result = sub_42C0F0(6);
    else
      result = sub_42C0F0(9);
    *(float *)(this + 23788) = *(float *)(this + 23852) + 2.0;
  }
  return result;
}
