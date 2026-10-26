void __thiscall sub_423CA0(float *this, float a2, int a3, float a4, float a5)
{
  float *v5; // edx
  double v6; // st7
  double v7; // st7
  long double v9; // st7
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c3
  long double v12; // st7
  double v13; // st6
  long double v15; // st7
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  long double v18; // st7
  float v19; // [esp+0h] [ebp-10h]
  float v20; // [esp+4h] [ebp-Ch]
  float v21; // [esp+4h] [ebp-Ch]
  float v22; // [esp+Ch] [ebp-4h]
  float v23; // [esp+Ch] [ebp-4h]

  v5 = (float *)(*(_DWORD *)this + 13560);
  v6 = a4 * a4 + a2 * a2;
  v19 = v6;
  if ( v6 == 0.0 )
    v7 = 0.0;
  else
    v7 = (a4 * *(float *)(*(_DWORD *)this + 13568) + a2 * *(float *)(*(_DWORD *)this + 13560)) / v19;
  v20 = a2 * v7;
  v22 = a4 * v7;
  v9 = v22 * v22 + v20 * v20;
  if ( v10 | v11 )
    v12 = -sqrt(v9);
  else
    v12 = sqrt(v9);
  this[6] = v12;
  this[6] = this[6] - a5;
  if ( v19 == 0.0 )
    v13 = 0.0;
  else
    v13 = (a2 * v5[2] - a4 * *v5) / v19;
  v21 = v13 * -a4;
  v23 = a2 * v13;
  v15 = v23 * v23 + v21 * v21;
  if ( v16 | v17 )
    v18 = sqrt(v15);
  else
    v18 = -sqrt(v15);
  this[4] = v18;
}

