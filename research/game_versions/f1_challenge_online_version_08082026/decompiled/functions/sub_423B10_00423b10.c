void __thiscall sub_423B10(float *this, float *a2, int a3, char a4)
{
  int v4; // esi
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  long double v9; // st7
  long double v10; // st7
  double v11; // st5
  double v12; // st7
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  long double v16; // st7
  long double v17; // st7
  float v18; // [esp+0h] [ebp-Ch]
  float v19; // [esp+0h] [ebp-Ch]
  float v20; // [esp+0h] [ebp-Ch]
  float v21; // [esp+8h] [ebp-4h]
  float v22; // [esp+8h] [ebp-4h]

  if ( a4 )
  {
    v4 = *(_DWORD *)this;
    v5 = (*(float *)(*(_DWORD *)this + 13536) - a2[37]) * a2[41]
       + (*(float *)(*(_DWORD *)this + 13544) - a2[39]) * a2[43];
    v18 = a2[41] * v5;
    v21 = a2[43] * v5;
    v9 = v21 * v21 + v18 * v18;
    if ( v7 | v8 )
      v10 = -sqrt(v9);
    else
      v10 = sqrt(v9);
    this[9] = v10;
    v11 = a2[43] * a2[43] + a2[41] * a2[41];
    if ( v11 == 0.0 )
      this[12] = 0.0;
    else
      this[12] = (*(float *)(v4 + 13560) * a2[41] + *(float *)(v4 + 13568) * a2[43]) / v11;
  }
  else
  {
    v19 = -a2[43];
    v12 = (*(float *)(*(_DWORD *)this + 13544) - a2[39]) * a2[41]
        - (*(float *)(*(_DWORD *)this + 13536) - a2[37]) * a2[43];
    v20 = v19 * v12;
    v22 = a2[41] * v12;
    v16 = v22 * v22 + v20 * v20;
    if ( v14 | v15 )
      v17 = sqrt(v16);
    else
      v17 = -sqrt(v16);
    this[9] = v17;
  }
}
