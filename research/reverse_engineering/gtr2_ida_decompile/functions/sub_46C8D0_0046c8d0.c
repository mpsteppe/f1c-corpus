_DWORD *__thiscall sub_46C8D0(float *this, float *a2, float *a3, _DWORD *a4, float a5, float a6)
{
  double v8; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c3
  double v11; // st7
  double v13; // st7
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  double v16; // st7
  double v18; // st7
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c3
  double v21; // st7
  double v23; // st7
  unsigned __int8 v24; // c0
  unsigned __int8 v25; // c3
  double v26; // st7
  double v27; // st7
  double v28; // st6
  double v29; // st7
  double v30; // st7
  _DWORD *result; // eax
  int v32[4]; // [esp+4h] [ebp-30h] BYREF
  int v33[4]; // [esp+14h] [ebp-20h] BYREF
  _BYTE v34[16]; // [esp+24h] [ebp-10h] BYREF
  float v35; // [esp+38h] [ebp+4h]
  float v36; // [esp+38h] [ebp+4h]
  int v37; // [esp+3Ch] [ebp+8h]

  v8 = *a2;
  if ( v9 | v10 )
  {
    if ( v8 >= -3.1415927 )
      goto LABEL_6;
    v11 = *a2 + 6.2831855;
  }
  else
  {
    v11 = v8 - 6.2831855;
  }
  *a2 = v11;
LABEL_6:
  v13 = a2[1];
  if ( v14 | v15 )
  {
    if ( v13 >= -3.1415927 )
      goto LABEL_11;
    v16 = a2[1] + 6.2831855;
  }
  else
  {
    v16 = v13 - 6.2831855;
  }
  a2[1] = v16;
LABEL_11:
  v18 = *a3;
  if ( v19 | v20 )
  {
    if ( v18 >= -3.1415927 )
      goto LABEL_16;
    v21 = *a3 + 6.2831855;
  }
  else
  {
    v21 = v18 - 6.2831855;
  }
  *a3 = v21;
LABEL_16:
  v23 = a3[1];
  if ( v24 | v25 )
  {
    if ( v23 >= -3.1415927 )
      goto LABEL_21;
    v26 = a3[1] + 6.2831855;
  }
  else
  {
    v26 = v23 - 6.2831855;
  }
  a3[1] = v26;
LABEL_21:
  v27 = fabs(*a2 - *a3);
  v28 = fabs(a2[1] - a3[1]);
  if ( v27 <= 3.1415927 )
  {
    if ( v27 < -3.1415927 )
      v27 = v27 + 6.2831855;
  }
  else
  {
    v27 = 6.2831855 - v27;
  }
  if ( v28 <= 3.1415927 )
  {
    if ( v28 < -3.1415927 )
      v28 = v28 + 6.2831855;
  }
  else
  {
    v28 = 6.2831855 - v28;
  }
  v35 = v28 + v27;
  if ( this[53] >= 1.0 )
    v29 = this[53];
  else
    v29 = 1.0;
  *(float *)&v37 = v29 * v35 * a5 * a6;
  if ( v35 <= (double)*(float *)&v37 || v35 <= 0.0 )
  {
    result = a4;
    *a4 = *(_DWORD *)a2;
    a4[1] = *((_DWORD *)a2 + 1);
    a4[2] = *((_DWORD *)a2 + 2);
  }
  else
  {
    v30 = *(float *)&v37 / v35;
    v36 = v30;
    if ( v30 > 1.0 )
      v36 = 1.0;
    ((void (*)(void))sub_614DD0)();
    sub_614DD0(a2, v32);
    sub_615280((int)v33, (int)v32, v36);
    return (_DWORD *)sub_614DB0(v34, a4);
  }
  return result;
}
