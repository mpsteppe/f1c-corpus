int __cdecl sub_569550(int a1, float *a2, const void *a3)
{
  float *v3; // ecx
  float *v4; // ebx
  double v5; // st7
  float *v6; // esi
  float v8; // [esp+18h] [ebp-Ch]
  float v9; // [esp+1Ch] [ebp-8h]
  float v10; // [esp+20h] [ebp-4h]

  v4 = &v3[74 * a1 + 88];
  v8 = *a2 - v3[19];
  v9 = a2[1] - v3[20];
  v5 = a2[2] - v3[21];
  v6 = &v3[74 * a1 + 117];
  *v6 = v8;
  v10 = v5;
  v6[1] = v9;
  v6[2] = v10;
  v4[46] = v8;
  v4[47] = v9;
  v4[48] = v10;
  qmemcpy(&v3[74 * a1 + 123], a3, 0x24u);
  sub_40D5D0(&v3[74 * a1 + 123], (int)&v3[74 * a1 + 120]);
  return off_16C97F8();
}
