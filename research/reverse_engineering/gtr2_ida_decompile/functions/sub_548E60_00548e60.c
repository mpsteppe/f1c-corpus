int __thiscall sub_548E60(_DWORD *this, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st7
  int v5; // edx
  float *v6; // eax
  double v7; // st7
  float v9; // [esp+0h] [ebp-18h]
  float i; // [esp+8h] [ebp-10h]
  float v11; // [esp+Ch] [ebp-Ch]
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+14h] [ebp-4h]

  v11 = *a3 - *a2;
  v12 = a3[1] - a2[1];
  v13 = a3[2] - a2[2];
  v3 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
  v9 = v3 + v3 + v11;
  v4 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
  v5 = 0;
  for ( i = v4 + v4 + v13; v5 < this[27]; v6[2] = i + v6[2] )
  {
    v6 = *(float **)(this[28] + 4 * v5);
    v7 = v9 + v6[11];
    v6 += 11;
    ++v5;
    *v6 = v7;
    v6[1] = v12 + v6[1];
  }
  return sub_548BA0((int)this);
}
