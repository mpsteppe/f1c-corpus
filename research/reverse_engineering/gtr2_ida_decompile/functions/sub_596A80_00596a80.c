void __thiscall sub_596A80(_DWORD *this, float a2, float a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  _DWORD *v12; // eax
  long double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  int v18; // ecx
  double v19; // st7
  float *v20; // ecx
  int v21; // ecx
  double v22; // st7
  double v23; // st6
  _DWORD *v24; // eax
  float v25; // [esp+4h] [ebp-74h]
  float v26; // [esp+8h] [ebp-70h]
  float v27; // [esp+Ch] [ebp-6Ch]
  float v28; // [esp+10h] [ebp-68h]
  float v29; // [esp+14h] [ebp-64h]
  float v30; // [esp+18h] [ebp-60h]
  float v31; // [esp+1Ch] [ebp-5Ch]
  float v32; // [esp+1Ch] [ebp-5Ch]
  float v33; // [esp+20h] [ebp-58h]
  float v34; // [esp+24h] [ebp-54h]
  float v35; // [esp+28h] [ebp-50h]
  float v36; // [esp+2Ch] [ebp-4Ch]
  float v37; // [esp+30h] [ebp-48h]
  float v38; // [esp+34h] [ebp-44h]
  float v39; // [esp+34h] [ebp-44h]
  char String[32]; // [esp+38h] [ebp-40h] BYREF
  char v41[32]; // [esp+58h] [ebp-20h] BYREF

  sub_596A40();
  v31 = 25.0;
  if ( !sub_53A2B0((int)String, 32, "Average Day Temp", 0) )
  {
    v4 = atof(String);
    v31 = v4;
    if ( v4 >= 0.0 )
    {
      if ( v31 > 50.0 )
        v31 = 50.0;
    }
    else
    {
      v31 = 0.0;
    }
  }
  v36 = v31 - 10.0;
  v33 = 0.2;
  if ( !sub_53A2B0((int)v41, 32, "Average Rain", 0) )
  {
    v5 = atof(v41);
    v33 = v5;
    if ( v5 >= 0.0 )
    {
      if ( v33 > 1.0 )
        v33 = 1.0;
    }
    else
    {
      v33 = 0.0;
    }
  }
  v6 = sub_51C800(&dword_BE08A0) * 360.0;
  v27 = v6;
  if ( v6 >= -900.0 )
  {
    if ( v27 > 900.0 )
      v27 = 900.0;
  }
  else
  {
    v27 = -900.0;
  }
  v7 = sub_51C800(&dword_BE08A0) * 0.40000001;
  v25 = v7;
  if ( v7 >= -1.0 )
  {
    if ( v25 > 1.0 )
      v25 = 1.0;
  }
  else
  {
    v25 = -1.0;
  }
  v8 = v25 * 0.0056250002;
  v30 = v8;
  if ( v8 >= -0.1 )
  {
    if ( v30 > 0.1 )
      v30 = 0.1;
  }
  else
  {
    v30 = -0.1;
  }
  v9 = sub_51C800(&dword_BE08A0) * 5.0;
  v26 = v9;
  if ( v9 >= -12.5 )
  {
    if ( v26 > 12.5 )
      v26 = 12.5;
  }
  else
  {
    v26 = -12.5;
  }
  v10 = v26 * 0.0025000002;
  v29 = v10;
  if ( v10 >= -2.0 )
  {
    if ( v29 > 2.0 )
      v29 = 2.0;
  }
  else
  {
    v29 = -2.0;
  }
  v11 = v25 + v33;
  v34 = v11;
  if ( v11 >= 0.0 )
  {
    if ( v34 > 1.0 )
      v34 = 1.0;
  }
  else
  {
    v34 = 0.0;
  }
  v12 = operator new(0x10u);
  if ( v12 )
  {
    *v12 = 0;
    v12[1] = 1101004800;
    v12[2] = 1045220557;
    v12[3] = 0;
  }
  else
  {
    v12 = 0;
  }
  this[16] = v12;
  *v12 = 0;
  this[15] = this[16];
  v37 = v31 - v36;
  while ( 1 )
  {
    v13 = fmod(a2 + *(float *)this[15], 86400.0);
    v35 = v13;
    v38 = sin(v13 * 0.0000363610260832152) * v37 + v36 - (v34 - 0.5) * 5.0;
    v14 = sub_51C800(&dword_BE08A0) * 0.19 + v29 - v26 * 0.0025000002;
    v29 = v14 - 0.1 * v14;
    if ( v29 >= -2.0 )
    {
      if ( v29 > 2.0 )
        v29 = 2.0;
    }
    else
    {
      v29 = -2.0;
    }
    v15 = v29 + v26;
    v26 = v15;
    if ( v15 >= -12.5 )
    {
      if ( v26 > 12.5 )
        v26 = 12.5;
    }
    else
    {
      v26 = -12.5;
    }
    v16 = sub_51C800(&dword_BE08A0) * 0.013 + v30 - v25 * 0.0056250002;
    v30 = v16 - 0.15000001 * v16;
    if ( v30 >= -0.1 )
    {
      if ( v30 > 0.1 )
        v30 = 0.1;
    }
    else
    {
      v30 = -0.1;
    }
    v17 = v30 + v25;
    v25 = v17;
    if ( v17 >= -1.0 )
    {
      if ( v25 > 1.0 )
        v25 = 1.0;
    }
    else
    {
      v25 = -1.0;
    }
    *(float *)(this[15] + 4) = v38 + v26;
    *(float *)(this[15] + 8) = v25 + v33;
    v18 = this[15];
    v19 = *(float *)(v18 + 8);
    v20 = (float *)(v18 + 8);
    if ( v19 >= 0.0 )
    {
      if ( *v20 > 1.0 )
        *v20 = 1.0;
    }
    else
    {
      *v20 = 0.0;
    }
    v21 = this[15];
    v34 = *(float *)(v21 + 8);
    if ( v34 > 0.60000002 && *(float *)(v21 + 8) < 0.64999998 )
    {
      if ( *(float *)(v21 + 8) >= 0.625 )
        *(_DWORD *)(v21 + 8) = 1059481190;
      else
        *(_DWORD *)(v21 + 8) = 1058642330;
    }
    if ( *(float *)this[15] > (double)a3 )
      break;
    sub_51C800(&dword_BE08A0);
    v28 = 0.0;
    if ( 0.0 >= -900.0 )
    {
      if ( 0.0 > 900.0 )
        v28 = 900.0;
    }
    else
    {
      v28 = -900.0;
    }
    v22 = 1200.0;
    v32 = 900.0;
    if ( v35 > 28800.0 && v35 < 57600.0 )
    {
      v32 = 280.0;
      v22 = 400.0;
    }
    v27 = v28 + v27;
    v23 = -v32;
    if ( v27 >= v23 )
    {
      if ( v27 > (double)v32 )
        v27 = v32;
    }
    else
    {
      v27 = v23;
    }
    v24 = operator new(0x10u);
    if ( v24 )
    {
      *v24 = 0;
      v24[1] = 1101004800;
      v24[2] = 1045220557;
      v24[3] = 0;
    }
    else
    {
      v24 = 0;
    }
    *(_DWORD *)(this[15] + 12) = v24;
    v39 = v22 + v27;
    **(float **)(this[15] + 12) = v39 + *(float *)this[15];
    this[15] = *(_DWORD *)(this[15] + 12);
  }
}
