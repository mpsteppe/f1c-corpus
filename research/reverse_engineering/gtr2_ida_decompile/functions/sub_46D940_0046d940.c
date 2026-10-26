int __thiscall sub_46D940(int this, float *a2, float *a3, _DWORD *a4, float a5, int a6)
{
  double v8; // st7
  long double v9; // st7
  long double v10; // st6
  double v11; // st7
  unsigned __int8 v13; // c0
  unsigned __int8 v14; // c3
  long double i; // st7
  long double v16; // st6
  double v17; // st7
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c3
  long double v21; // st7
  long double v22; // st6
  double v23; // st7
  unsigned __int8 v25; // c0
  unsigned __int8 v26; // c3
  long double v27; // st7
  float v28; // eax
  float *v29; // ecx
  _DWORD *v30; // esi
  float v32; // [esp+4h] [ebp-3Ch]
  float v33; // [esp+4h] [ebp-3Ch]
  float v34; // [esp+8h] [ebp-38h]
  float v35; // [esp+8h] [ebp-38h]
  float v36; // [esp+Ch] [ebp-34h]
  float v37; // [esp+Ch] [ebp-34h]
  float v38; // [esp+10h] [ebp-30h] BYREF
  float v39; // [esp+14h] [ebp-2Ch]
  float v40; // [esp+18h] [ebp-28h]
  float v41[9]; // [esp+1Ch] [ebp-24h] BYREF
  float v42; // [esp+48h] [ebp+8h]
  float v43; // [esp+48h] [ebp+8h]
  float v44; // [esp+50h] [ebp+10h]

  if ( *(_BYTE *)(this + 128) )
  {
    a5 = 1000.0;
    *(_BYTE *)(this + 128) = 0;
  }
  v8 = *(float *)(this + 164) + *a3;
  v39 = *(float *)(this + 168) + a3[1];
  v40 = *(float *)(this + 172) + a3[2];
  v9 = v8 - *(float *)(this + 192);
  if ( v9 <= 3.1415927 )
  {
    if ( v9 < -3.1415927 )
      v9 = v9 + 6.2831855;
  }
  else
  {
    v9 = v9 - 6.2831855;
  }
  v10 = v9 * *(float *)(this + 140) * a5;
  v42 = v10;
  if ( fabs(v9) < fabs(v10) )
    v42 = v9;
  v11 = flt_B715A8 * v42 + *(float *)(this + 192);
  *(float *)(this + 192) = v11;
  if ( v13 | v14 )
  {
    if ( v11 < -3.1415927 )
      *(float *)(this + 192) = v11 + 6.2831855;
  }
  else
  {
    *(float *)(this + 192) = v11 - 6.2831855;
  }
  for ( i = v39 - *(float *)(this + 196); i > 3.1415927; i = i - 6.2831855 )
    ;
  for ( ; i < -3.1415927; i = i + 6.2831855 )
    ;
  v16 = i * *(float *)(this + 144) * a5;
  v43 = v16;
  if ( fabs(i) < fabs(v16) )
    v43 = i;
  v17 = v43 + *(float *)(this + 196);
  *(float *)(this + 196) = v17;
  if ( v19 | v20 )
  {
    if ( v17 < -3.1415927 )
      *(float *)(this + 196) = v17 + 6.2831855;
  }
  else
  {
    *(float *)(this + 196) = v17 - 6.2831855;
  }
  if ( *(float *)(this + 148) == 0.0 )
  {
    *(_DWORD *)(this + 200) = 0;
  }
  else
  {
    v21 = v40 - *(float *)(this + 200);
    if ( v21 <= 3.1415927 )
    {
      if ( v21 < -3.1415927 )
        v21 = v21 + 6.2831855;
    }
    else
    {
      v21 = v21 - 6.2831855;
    }
    v22 = a5 * v21 * *(float *)(this + 148);
    v44 = v22;
    if ( fabs(v21) < fabs(v22) )
      v44 = v21;
    v23 = flt_B715A8 * v44 + *(float *)(this + 200);
    *(float *)(this + 200) = v23;
    if ( v25 | v26 )
    {
      if ( v23 < -3.1415927 )
        *(float *)(this + 200) = v23 + 6.2831855;
    }
    else
    {
      *(float *)(this + 200) = v23 - 6.2831855;
    }
  }
  v27 = cos(*(float *)(this + 192));
  v28 = *(float *)(this + 200);
  v38 = *(float *)(this + 192);
  v40 = v28;
  *(float *)(this + 24) = v38;
  v32 = -(sin(*(float *)(this + 196)) * v27 * *(float *)(this + 176));
  v34 = sin(*(float *)(this + 192)) * *(float *)(this + 176);
  v36 = -(cos(*(float *)(this + 196)) * v27 * *(float *)(this + 176));
  v39 = 3.1415927 - *(float *)(this + 196);
  *(float *)(this + 28) = v39;
  *(float *)(this + 32) = v40;
  sub_614A90(a3, v41);
  sub_416420(v41, a2, (float *)(this + 152), &v38);
  v29 = (float *)(this + 12);
  v30 = (_DWORD *)(this + 36);
  v33 = v32 - v38;
  *v29 = v33;
  v35 = v34 - v39;
  v29[1] = v35;
  v37 = v36 - v40;
  v29[2] = v37;
  *v30 = *a4;
  v30[1] = a4[1];
  v30[2] = a4[2];
  return 0;
}
