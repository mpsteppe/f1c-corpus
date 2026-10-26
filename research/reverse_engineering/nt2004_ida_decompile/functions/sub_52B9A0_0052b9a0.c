void __thiscall sub_52B9A0(_DWORD *this, float a2, float a3)
{
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  float *v15; // edx
  long double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  int v21; // ecx
  double v22; // st7
  float *v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  double v27; // st6
  double v28; // st7
  double v29; // st6
  _DWORD *v30; // eax
  _DWORD *v31; // eax
  float v32; // [esp+4h] [ebp-B8h]
  float v33; // [esp+8h] [ebp-B4h]
  float v34; // [esp+Ch] [ebp-B0h]
  float v35; // [esp+10h] [ebp-ACh]
  float v36; // [esp+10h] [ebp-ACh]
  float v37; // [esp+14h] [ebp-A8h]
  float v38; // [esp+18h] [ebp-A4h]
  float v39; // [esp+1Ch] [ebp-A0h]
  bool v40; // [esp+23h] [ebp-99h]
  float v41; // [esp+24h] [ebp-98h]
  float v42; // [esp+28h] [ebp-94h]
  float v43; // [esp+2Ch] [ebp-90h]
  float v44; // [esp+2Ch] [ebp-90h]
  float v45; // [esp+30h] [ebp-8Ch]
  float v46; // [esp+34h] [ebp-88h]
  float v47; // [esp+38h] [ebp-84h]
  char v48[32]; // [esp+3Ch] [ebp-80h] BYREF
  char String[32]; // [esp+5Ch] [ebp-60h] BYREF
  char v50[64]; // [esp+7Ch] [ebp-40h] BYREF

  v40 = 0;
  if ( !sub_4E8E50(v50, 64, aTrackType, 0) )
    v40 = sub_579060(v50, aRoad) != 0;
  sub_52B930(this);
  v35 = 25.0;
  if ( !sub_4E8E50(String, 32, aAverageDayTemp, 0) )
  {
    v4 = (atof(String) - -40.0) * 0.5555555555555556 - 40.0;
    v35 = v4;
    if ( v4 >= 0.0 )
    {
      if ( v35 > 50.0 )
        v35 = 50.0;
    }
    else
    {
      v35 = 0.0;
    }
  }
  v46 = v35 - 10.0;
  v41 = 0.34999999;
  if ( !sub_4E8E50(v48, 32, aAverageRain, 0) )
  {
    v5 = (atof(v48) - -40.0) * 0.5555555555555556 - 40.0;
    v41 = v5;
    if ( v5 >= 0.0 )
    {
      if ( v41 > 1.0 )
        v41 = 1.0;
    }
    else
    {
      v41 = 0.0;
    }
  }
  v6 = sub_4D1B00(&dword_7D3C50) * 360.0;
  v33 = v6;
  if ( v6 >= -900.0 )
  {
    if ( v33 > 900.0 )
      v33 = 900.0;
  }
  else
  {
    v33 = -900.0;
  }
  v7 = v33 * 0.25;
  v38 = v7;
  if ( v7 >= -900.0 )
  {
    if ( v38 > 900.0 )
      v38 = 900.0;
  }
  else
  {
    v38 = -900.0;
  }
  v8 = sub_4D1B00(&dword_7D3C50) * 0.40000001;
  v32 = v8;
  if ( v8 >= -1.0 )
  {
    if ( v32 > 1.0 )
      v32 = 1.0;
  }
  else
  {
    v32 = -1.0;
  }
  v9 = v32 * 0.0056250002;
  v39 = v9;
  if ( v9 >= -0.1 )
  {
    if ( v39 > 0.1 )
      v39 = 0.1;
  }
  else
  {
    v39 = -0.1;
  }
  v10 = sub_4D1B00(&dword_7D3C50) * 5.0;
  v34 = v10;
  if ( v10 >= -12.5 )
  {
    if ( v34 > 12.5 )
      v34 = 12.5;
  }
  else
  {
    v34 = -12.5;
  }
  v11 = v34 * 0.0025000002;
  v37 = v11;
  if ( v11 >= -2.0 )
  {
    if ( v37 > 2.0 )
      v37 = 2.0;
  }
  else
  {
    v37 = -2.0;
  }
  v12 = v32 + v41;
  v42 = v12;
  if ( v12 >= 0.0 )
  {
    if ( v42 > 1.0 )
      v42 = 1.0;
  }
  else
  {
    v42 = 0.0;
  }
  v13 = operator new(0x10u);
  if ( v13 )
    v14 = sub_52AC20(v13);
  else
    v14 = 0;
  this[14] = v14;
  *v14 = 0;
  v15 = (float *)this[14];
  v47 = v35 - v46;
  while ( 1 )
  {
    this[13] = v15;
    v16 = fmod(a2 + *v15, 86400.0);
    v45 = v16;
    v43 = sin(v16 * 0.0000363610260832152) * v47 + v46 - (v42 - 0.5) * 5.0;
    v17 = sub_4D1B00(&dword_7D3C50) * 0.11 + v37 - v34 * 0.0025000002;
    v37 = v17 - 0.1 * v17;
    if ( v37 >= -2.0 )
    {
      if ( v37 > 2.0 )
        v37 = 2.0;
    }
    else
    {
      v37 = -2.0;
    }
    v18 = v37 + v34;
    v34 = v18;
    if ( v18 >= -12.5 )
    {
      if ( v34 > 12.5 )
        v34 = 12.5;
    }
    else
    {
      v34 = -12.5;
    }
    v19 = sub_4D1B00(&dword_7D3C50) * 0.013 + v39 - v32 * 0.0056250002;
    v39 = v19 - 0.15000001 * v19;
    if ( v39 >= -0.1 )
    {
      if ( v39 > 0.1 )
        v39 = 0.1;
    }
    else
    {
      v39 = -0.1;
    }
    v20 = v39 + v32;
    v32 = v20;
    if ( v20 >= -1.0 )
    {
      if ( v32 > 1.0 )
        v32 = 1.0;
    }
    else
    {
      v32 = -1.0;
    }
    *(float *)(this[13] + 4) = v43 + v34;
    if ( dword_767598 != 39 && dword_767454[0] )
      *(float *)(this[13] + 4) = ((double)dword_767598 - -40.0) * 0.5555555555555556 - 40.0;
    *(float *)(this[13] + 8) = v32 + v41;
    v21 = this[13];
    v22 = *(float *)(v21 + 8);
    v23 = (float *)(v21 + 8);
    if ( v22 >= 0.0 )
    {
      if ( *v23 > 1.0 )
        *v23 = 1.0;
    }
    else
    {
      *v23 = 0.0;
    }
    if ( !v40 )
    {
      v24 = this[13];
      if ( *(float *)(v24 + 8) > 0.699 )
      {
        *(_DWORD *)(v24 + 8) = 1060303274;
        v32 = v32 - 0.001;
      }
      v25 = this[13];
      if ( *(float *)(v25 + 8) < 0.40200004 )
      {
        *(_DWORD *)(v25 + 8) = 1053676275;
        v32 = v32 + 0.001;
      }
    }
    v26 = this[13];
    v42 = *(float *)(v26 + 8);
    if ( v42 > 0.60000002 && *(float *)(v26 + 8) < 0.64999998 )
    {
      if ( *(float *)(v26 + 8) >= 0.625 )
        *(_DWORD *)(v26 + 8) = 1059481190;
      else
        *(_DWORD *)(v26 + 8) = 1058642330;
    }
    if ( *(float *)this[13] > (double)a3 )
      break;
    v27 = sub_4D1B00(&dword_7D3C50) * 500.0 + v38 - v33 * 0.25;
    v38 = v27 - v27;
    if ( v38 >= -900.0 )
    {
      if ( v38 > 900.0 )
        v38 = 900.0;
    }
    else
    {
      v38 = -900.0;
    }
    v28 = 1200.0;
    v36 = 900.0;
    if ( v45 > 28800.0 && v45 < 57600.0 )
    {
      v36 = 280.0;
      v28 = 400.0;
    }
    v33 = v38 + v33;
    v29 = -v36;
    if ( v33 >= v29 )
    {
      if ( v33 > (double)v36 )
        v33 = v36;
    }
    else
    {
      v33 = v29;
    }
    v30 = operator new(0x10u);
    if ( v30 )
      v31 = sub_52AC20(v30);
    else
      v31 = 0;
    *(_DWORD *)(this[13] + 12) = v31;
    v44 = v28 + v33;
    **(float **)(this[13] + 12) = v44 + *(float *)this[13];
    v15 = *(float **)(this[13] + 12);
  }
}
