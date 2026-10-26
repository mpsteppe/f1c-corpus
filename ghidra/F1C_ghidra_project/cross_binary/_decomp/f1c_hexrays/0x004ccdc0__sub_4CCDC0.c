// f1c  0x004ccdc0  size=201
int __thiscall sub_4CCDC0(_DWORD *this, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st7
  int v5; // edx
  double v6; // st7
  float *v7; // eax
  double v8; // st7
  float v10; // [esp+0h] [ebp-18h]
  float i; // [esp+8h] [ebp-10h]
  float v12; // [esp+Ch] [ebp-Ch]
  float v13; // [esp+10h] [ebp-8h]
  float v14; // [esp+14h] [ebp-4h]

  v12 = *a3 - *a2;
  v13 = a3[1] - a2[1];
  v14 = a3[2] - a2[2];
  v3 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v10 = v3 + v3 + v12;
  v4 = flt_8AB274[(unsigned __int8)dword_8AAE70++];
  v5 = 0;
  v6 = v4 + v4 + v14;
  for ( i = v6; v5 < this[25]; v7[2] = v6 )
  {
    v7 = *(float **)(this[26] + 4 * v5);
    v8 = v10 + v7[11];
    v7 += 11;
    ++v5;
    *v7 = v8;
    v7[1] = v13 + v7[1];
    v6 = i + v7[2];
  }
  return sub_4CCB30((int)this, v6);
}
