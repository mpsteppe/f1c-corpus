void __thiscall sub_43AB90(int this, double a2)
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
  double *v14; // ebx
  double *v15; // ecx
  int v16; // esi
  double v17; // st5
  double v18; // st5
  double v19; // st4
  long double v20; // st3
  double v21; // st2
  double v22; // st2
  int v23; // edx
  int v24; // ecx
  long double v25; // st7
  long double v26; // st7
  double v27; // st6
  double v28; // st6
  long double v29; // st7
  double v30; // [esp+Ch] [ebp-70h]
  double v31; // [esp+14h] [ebp-68h]
  double v32; // [esp+1Ch] [ebp-60h]
  double v33; // [esp+24h] [ebp-58h]
  long double v34; // [esp+2Ch] [ebp-50h]
  double v35; // [esp+2Ch] [ebp-50h]
  double v36; // [esp+2Ch] [ebp-50h]
  double v37; // [esp+34h] [ebp-48h]
  double v38; // [esp+3Ch] [ebp-40h]
  double v39; // [esp+44h] [ebp-38h]
  double v40[2]; // [esp+4Ch] [ebp-30h]
  double v41; // [esp+5Ch] [ebp-20h]
  double v42[3]; // [esp+64h] [ebp-18h] BYREF

  v37 = flt_7DAB10 + 273.16;
  v39 = flt_7DAB0C + 273.16;
  if ( *(double *)(this + 860) <= 0.0 )
    v3 = 0.0;
  else
    v3 = fabs(*(double *)(this + 188)) * *(double *)(this + 1056) * *(double *)(this + 860);
  if ( *(double *)(this + 852) <= 0.0 )
  {
    v4 = 0.0;
    v30 = 0.0;
  }
  else
  {
    v30 = (1.0 - *(double *)(this + 332)) * *(double *)(this + 672) * *(double *)(this + 852);
    v4 = v30 * *(double *)(this + 1064);
  }
  v5 = *(double *)(this + 1040) * *(double *)(this + 844);
  v32 = v5;
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
  v32 = v5;
LABEL_12:
  v33 = *(double *)(this + 932) * *(double *)(this + 852) + *(double *)(this + 924);
  v9 = (v33 - *(double *)(this + 992)) * *(double *)(this + 1048);
  v31 = v9;
  if ( v11 | v12 )
  {
    v9 = -1.0;
LABEL_16:
    v31 = v9;
    goto LABEL_17;
  }
  if ( v9 > 1.0 )
  {
    v9 = 1.0;
    goto LABEL_16;
  }
LABEL_17:
  v13 = (double *)(*(_DWORD *)(this + 348) + 100);
  v14 = (double *)(this + 952);
  qmemcpy(v42, (const void *)(this + 952), sizeof(v42));
  v15 = (double *)(this + 952);
  v16 = 0;
  v40[0] = (0.5 * v9 - v5 + 1.5) * 0.3333333333333333;
  v40[1] = (1.5 - v9) * 0.3333333333333333;
  v41 = (0.5 * v9 + v5 + 1.5) * 0.3333333333333333;
  v17 = flt_7DAB00 + *(double *)(this + 680) + 1.0;
  v34 = (sqrt(*v13 * *v13 + v13[1] * v13[1] + v13[2] * v13[2]) * *(double *)(this + 1088) + *(double *)(this + 1080))
      * v17;
  v18 = v17 * *(double *)(this + 1072);
  v19 = *(double *)(this + 976);
  v20 = v34 * a2;
  v38 = a2 * *(double *)(this + 1096);
  do
  {
    v21 = a2 * v40[v16];
    v35 = v21 * v4 + v21 * v3 + *v15;
    *v15 = v35;
    if ( *(double *)(this + 860) > 0.0 )
      *v15 = (v37 - v42[v16]) * v21 * v18 + v35;
    ++v16;
    ++v15;
    v22 = (v19 - v42[v16 - 1]) * v38;
    *(v15 - 1) = (v39 - v42[v16 - 1]) * v20 + *(v15 - 1) + v22;
    *(double *)(this + 976) = *(double *)(this + 976) - v22;
  }
  while ( v16 < 3 );
  if ( *(double *)(this + 976) < 273.16 )
  {
    *(_DWORD *)(this + 980) = 1081152143;
LABEL_25:
    *(_DWORD *)(this + 976) = 1546188227;
    goto LABEL_26;
  }
  if ( *(double *)(this + 976) > 546.3200000000001 )
  {
    *(_DWORD *)(this + 980) = 1082200719;
    goto LABEL_25;
  }
LABEL_26:
  sub_43AB60((double *)this);
  v36 = (*(double *)(v23 + 968) + *(double *)(v23 + 960) + *v14) * 0.3333333333333333;
  if ( *(double *)(v23 + 1024) > 0.6875 )
  {
    v25 = *(double *)(v23 + 1024)
        - v36
        * *(double *)(v23 + 892)
        * ((fabs(v31) + fabs(v32) + 4.0)
         * 0.1666666666666667
         * *(double *)(v23 + 1104)
         * (v36
          * *(double *)(v23 + 892)))
        * v30
        * a2;
    *(long double *)(v23 + 1024) = v25;
    if ( v25 <= 0.6875 )
    {
      *(_DWORD *)(v23 + 1024) = 0;
      *(_DWORD *)(v23 + 1028) = 1072037888;
      sub_43AA80(v24);
    }
  }
  if ( v36 > *(double *)(v23 + 916) )
    sub_43AA80(v23);
  v26 = fabs(*(double *)(v23 + 992) - v33) * (*(double *)(v23 + 940) / v33);
  v27 = v36 - *(double *)(v23 + 884);
  if ( v27 >= 0.0 )
    v28 = v27 * *(double *)(v23 + 908);
  else
    v28 = v27 * *(double *)(v23 + 900);
  v29 = v26 + v28;
  if ( v29 > 1.0 )
    v29 = 1.0;
  *(long double *)(v23 + 1032) = (1.0 - v29 * v29 * 0.5) * *(double *)(v23 + 1024);
}
