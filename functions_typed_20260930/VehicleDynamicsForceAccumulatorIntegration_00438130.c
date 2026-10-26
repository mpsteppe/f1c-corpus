void __thiscall sub_438130(int this, double a2)
{
  long double v3; // st7
  double v4; // st6
  double v5; // st5
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  double v9; // st4
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  double *v13; // eax
  double *v14; // ecx
  int v15; // esi
  double v16; // st5
  double v17; // st5
  double v18; // st4
  double v19; // st2
  double v20; // st2
  double *v21; // edx
  double v22; // st7
  double v23; // st7
  double v24; // st7
  long double v25; // st7
  double v26; // [esp+Ch] [ebp-70h]
  float v27; // [esp+Ch] [ebp-70h]
  double v28; // [esp+14h] [ebp-68h]
  float v29; // [esp+14h] [ebp-68h]
  double v30; // [esp+1Ch] [ebp-60h]
  double v31; // [esp+1Ch] [ebp-60h]
  double v32; // [esp+24h] [ebp-58h]
  double v33; // [esp+2Ch] [ebp-50h]
  double v34; // [esp+2Ch] [ebp-50h]
  double v35; // [esp+34h] [ebp-48h]
  double v36; // [esp+3Ch] [ebp-40h]
  double v37; // [esp+44h] [ebp-38h]
  double v38[2]; // [esp+4Ch] [ebp-30h]
  double v39; // [esp+5Ch] [ebp-20h]
  double v40[3]; // [esp+64h] [ebp-18h] BYREF

  v33 = flt_8AFEF4 + 273.16;
  v36 = flt_8AFEF0 + 273.16;
  if ( *(double *)(this + 804) <= 0.0 )
    v3 = 0.0;
  else
    v3 = fabs(*(double *)(this + 188)) * *(double *)(this + 932) * *(double *)(this + 804);
  if ( *(double *)(this + 796) <= 0.0 )
  {
    v4 = 0.0;
    v28 = 0.0;
  }
  else
  {
    v28 = (1.0 - *(double *)(this + 332)) * *(double *)(this + 616) * *(double *)(this + 796);
    v4 = v28 * *(double *)(this + 940);
  }
  v5 = *(double *)(this + 788) * 5.555555555555555;
  v30 = v5;
  if ( v7 | v8 )
  {
    v5 = -1.0;
  }
  else
  {
    if ( v5 <= 1.0 )
      goto LABEL_12;
    v5 = 1.0;
  }
  v30 = v5;
LABEL_12:
  v32 = *(double *)(this + 836) * *(double *)(this + 796) + *(double *)(this + 828);
  v9 = (v32 - *(double *)(this + 884)) * 0.02777777777777778;
  v26 = v9;
  if ( v11 | v12 )
  {
    v9 = -1.0;
LABEL_16:
    v26 = v9;
    goto LABEL_17;
  }
  if ( v9 > 1.0 )
  {
    v9 = 1.0;
    goto LABEL_16;
  }
LABEL_17:
  v13 = (double *)(*(_DWORD *)(this + 348) + 100);
  qmemcpy(v40, (const void *)(this + 844), sizeof(v40));
  v14 = (double *)(this + 844);
  v15 = 0;
  v38[0] = (0.5 * v9 - v5 + 1.5) * 0.3333333333333333;
  v38[1] = (1.5 - v9) * 0.3333333333333333;
  v39 = (0.5 * v9 + v5 + 1.5) * 0.3333333333333333;
  v16 = flt_8AFEE4 + *(double *)(this + 624) + 1.0;
  v37 = (sqrt(*v13 * *v13 + v13[1] * v13[1] + v13[2] * v13[2]) * *(double *)(this + 964) + *(double *)(this + 956))
      * v16;
  v17 = v16 * *(double *)(this + 948);
  v18 = *(double *)(this + 868);
  do
  {
    v19 = a2 * v38[v15];
    v35 = v19 * v4 + v19 * v3 + *v14;
    *v14 = v35;
    if ( *(double *)(this + 804) > 0.0 )
      *v14 = (v33 - v40[v15]) * v19 * v17 + v35;
    ++v15;
    ++v14;
    v20 = (v18 - v40[v15 - 1]) * a2 * 0.005;
    *(v14 - 1) = (v36 - v40[v15 - 1]) * v37 * a2 + v20 + *(v14 - 1);
    *(double *)(this + 868) = *(double *)(this + 868) - v20;
  }
  while ( v15 < 3 );
  if ( *(double *)(this + 868) < 273.16 )
  {
    *(_DWORD *)(this + 872) = 1081152143;
LABEL_25:
    *(_DWORD *)(this + 868) = 1546188227;
    goto LABEL_26;
  }
  if ( *(double *)(this + 868) > 546.3200000000001 )
  {
    *(_DWORD *)(this + 872) = 1082200719;
    goto LABEL_25;
  }
LABEL_26:
  TorqueForceProductComputation(this);
  v34 = (*(double *)(this + 860) + *(double *)(this + 852) + *v21) * 0.3333333333333333;
  v31 = (fabs(v26) + fabs(v30) + 4.0)
      * 0.1666666666666667
      * *(double *)(this + 972)
      * (v34
       / *(double *)(this + 820))
      * (v34
       / *(double *)(this + 820))
      * v28
      * a2;
  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    v27 = (*(double *)(this + 916) - 0.75) * 4.0;
    v29 = (*(double *)(this + 916) - v31 - 0.75) * 4.0;
    if ( v27 == 1.0 )
    {
      dword_5EC3BC[*(_DWORD *)(this + 120)] = 0;
    }
    else if ( v27 <= 0.69999999 || v29 > 0.69999999 )
    {
      if ( v27 > 0.40000001 && v29 <= 0.40000001 )
        PitStateSlotActivation(dword_5EB978, *(_DWORD *)(this + 120));
    }
    else
    {
      AISessionPhaseCounter(dword_5EB978, *(_DWORD *)(this + 120));
    }
  }
  if ( *(double *)(this + 916) > 0.75 )
  {
    v22 = *(double *)(this + 916) - v31;
    *(double *)(this + 916) = v22;
    if ( v22 <= 0.75 )
    {
      v23 = *(double *)(this + 900);
      *(_DWORD *)(this + 916) = 0;
      *(_DWORD *)(this + 920) = 1072168960;
      *(double *)(this + 900) = v23 * 0.18;
      *(double *)(this + 564) = *(double *)(this + 564) * 4.0;
      *(double *)(this + 1100) = *(double *)(this + 1100) * 0.7;
      *(double *)(this + 632) = *(double *)(this + 632) * 0.7;
      *(double *)(this + 1108) = *(double *)(this + 1108) * 0.7;
      *(double *)(this + 648) = *(double *)(this + 648) * 0.7;
      v24 = *(double *)(this + 892) * 0.25;
      if ( v24 > 10.0 )
        v24 = 10.0;
      *(double *)(this + 876) = v24 * 0.002778858444950814;
    }
  }
  v25 = fabs(v34 - *(double *)(this + 820)) / *(double *)(this + 820) * 0.9
      + fabs(*(double *)(this + 884) - v32) / v32 * 0.6;
  if ( v25 >= 0.0 )
  {
    if ( v25 > 1.0 )
      v25 = 1.0;
  }
  else
  {
    v25 = 0.0;
  }
  *(long double *)(this + 924) = (1.0 - v25 * v25 * 0.5) * *(double *)(this + 916);
}

