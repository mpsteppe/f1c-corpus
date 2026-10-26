void __thiscall sub_4E2610(float *this, int a2, float *a3, const void *a4, const void *a5)
{
  int v5; // ebx
  float *v6; // ebp
  double v7; // st7
  float *v8; // esi
  double v9; // st7
  long double v10; // st7
  long double v11; // st6
  double v12; // st7
  long double v13; // st7
  float v14; // [esp+10h] [ebp-Ch]
  float v15; // [esp+14h] [ebp-8h]
  float v16; // [esp+18h] [ebp-4h]

  v5 = (int)&this[74 * a2 + 53];
  v6 = &this[74 * a2 + 88];
  v14 = *a3 - this[18];
  v15 = a3[1] - this[19];
  v7 = a3[2] - this[20];
  v8 = &this[74 * a2 + 82];
  *v8 = v14;
  v16 = v7;
  v8[1] = v15;
  v8[2] = v16;
  *(float *)(v5 + 184) = v14;
  *(float *)(v5 + 188) = v15;
  *(float *)(v5 + 192) = v16;
  qmemcpy(v6, a4, 0x24u);
  v9 = this[74 * a2 + 93];
  sub_588570();
  *(float *)(v5 + 128) = -v9;
  if ( fabs(v6[5]) == 1.0 )
  {
    v10 = -v6[6];
    v11 = *v6;
    *(_DWORD *)(v5 + 136) = 0;
    *(float *)(v5 + 132) = atan2(v10, v11);
  }
  else
  {
    *(float *)(v5 + 132) = atan2(v6[2], v6[8]);
    *(float *)(v5 + 136) = atan2(v6[3], v6[4]);
  }
  qmemcpy((void *)(v5 + 208), a5, 0x24u);
  v12 = *(float *)(v5 + 228);
  sub_588570();
  *(float *)(v5 + 196) = -v12;
  if ( fabs(*(float *)(v5 + 228)) == 1.0 )
  {
    v13 = atan2(-*(float *)(v5 + 232), *(float *)(v5 + 208));
    *(_DWORD *)(v5 + 204) = 0;
    *(float *)(v5 + 200) = v13;
  }
  else
  {
    *(float *)(v5 + 200) = atan2(*(float *)(v5 + 216), *(float *)(v5 + 240));
    *(float *)(v5 + 204) = atan2(*(float *)(v5 + 220), *(float *)(v5 + 224));
  }
}
