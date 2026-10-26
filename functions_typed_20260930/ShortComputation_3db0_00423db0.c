void __thiscall sub_423DB0(float *this, float a2, int a3, float a4, float a5, int a6, float a7)
{
  double v7; // st7
  double v8; // st6
  double v9; // st5
  long double v11; // st5
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c3
  long double v14; // st5
  double v15; // st5
  long double v17; // st7
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c3
  long double v20; // st7
  float v21; // [esp+10h] [ebp+10h]
  float v22; // [esp+10h] [ebp+10h]
  float v23; // [esp+10h] [ebp+10h]
  float v24; // [esp+18h] [ebp+18h]
  float v25; // [esp+18h] [ebp+18h]

  v7 = *(float *)(*(_DWORD *)this + 13536) - a5;
  v8 = *(float *)(*(_DWORD *)this + 13544) - a7;
  v9 = a4 * v8 + a2 * v7;
  v21 = a2 * v9;
  v24 = a4 * v9;
  v11 = v24 * v24 + v21 * v21;
  if ( v12 | v13 )
    v14 = -sqrt(v11);
  else
    v14 = sqrt(v11);
  this[3] = v14;
  v22 = -a4;
  v15 = a2 * v8 - a4 * v7;
  v23 = v22 * v15;
  v25 = a2 * v15;
  v17 = v25 * v25 + v23 * v23;
  if ( v18 | v19 )
    v20 = sqrt(v17);
  else
    v20 = -sqrt(v17);
  this[1] = v20;
}

