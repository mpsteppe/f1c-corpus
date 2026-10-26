// positive sp value has been detected, the output may be wrong!
void __cdecl sub_598630()
{
  int v0; // ecx
  int v1; // esi
  int v2; // eax
  int v3; // edi
  int v4; // ebp
  double v5; // st7
  char v6; // bl
  double v7; // st6
  int v8; // edx
  double v9; // st7
  int v10; // ecx
  double v11; // st6
  double v12; // st6
  double v13; // st6
  double v14; // st6
  double v15; // st6
  double v16; // st6
  double v17; // st6
  double v18; // st6
  double v19; // st6
  double v20; // st6
  int v21; // ecx
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  int v26; // edx
  float *v27; // eax
  double v28; // st7
  float *v29; // eax
  double v30; // st7
  double v31; // st7
  double v32; // st7
  int v33; // ecx
  int *v34; // esi
  int v35; // eax
  int v36; // ecx
  int i; // edx
  float v38; // [esp-2D14h] [ebp-2D30h]
  float v39; // [esp-2D10h] [ebp-2D2Ch]
  int v40; // [esp-2CF8h] [ebp-2D14h]
  float v41; // [esp-2CF8h] [ebp-2D14h]
  float v42; // [esp-2CF8h] [ebp-2D14h]
  float v43; // [esp-2CF8h] [ebp-2D14h]
  float v44; // [esp-2CF8h] [ebp-2D14h]
  float v45; // [esp-2CF8h] [ebp-2D14h]
  float v46; // [esp-2CF8h] [ebp-2D14h]
  float v47; // [esp-2CF8h] [ebp-2D14h]
  float v48; // [esp-2CF8h] [ebp-2D14h]
  float v49; // [esp-2CF8h] [ebp-2D14h]
  float v50; // [esp-2CF8h] [ebp-2D14h]
  float v51; // [esp-2CF8h] [ebp-2D14h]
  float v52; // [esp-2CF4h] [ebp-2D10h]
  float v53; // [esp-2CF0h] [ebp-2D0Ch]
  float v54; // [esp-2CECh] [ebp-2D08h]
  float v55; // [esp-2CECh] [ebp-2D08h]
  int v56; // [esp-2CE8h] [ebp-2D04h]
  float v57; // [esp-2CE8h] [ebp-2D04h]
  _BYTE v58[11492]; // [esp-2CE4h] [ebp-2D00h]

  sub_631BD0();
  v1 = v0;
  v2 = *(_DWORD *)(v0 + 64);
  v3 = 0;
  if ( v2 )
  {
    sub_592B20(v0, *(float *)(v2 + 8));
    *(_DWORD *)(v1 + 60) = *(_DWORD *)(v1 + 64);
    *(_DWORD *)(v1 + 4) = 0;
    v4 = dword_757C10;
    v5 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.125;
    v6 = 0;
    v56 = 0;
    do
    {
      v54 = v5 + 0.47499999;
      v7 = *(float *)(v1 + 40) - v54;
      *(float *)&v58[4 * v3] = v7;
      if ( v7 > 0.0 )
        v6 = 1;
      v39 = ((double)v56 * 30.0 + 30.0) * *(float *)v1;
      v38 = *(float *)v1 * 30.0;
      sub_5936E0((_DWORD *)v1, v38, v39, v4);
      v56 = ++v3;
    }
    while ( v3 < 2880 );
    if ( dword_B70618[0] != 1 && (dword_B70618[0] != 2 || flt_B70858 >= 0.80000001) && v6 )
    {
      v8 = dword_BE08A0;
      v57 = 0.0;
      while ( 1 )
      {
        v9 = 3.4028235e38;
        v10 = 0;
        v53 = 0.0;
        v40 = 0;
        do
        {
          if ( *(float *)&v58[4 * v10] <= 0.0 )
            goto LABEL_22;
          v41 = fabs(v57 - (double)v40 * 30.0);
          if ( v41 == 0.0 )
          {
LABEL_17:
            v11 = 0.0049999999;
            goto LABEL_18;
          }
          v11 = *(float *)&v58[4 * v10] / v41;
          if ( v11 >= 0.0 )
          {
            if ( v11 > 0.0049999999 )
              goto LABEL_17;
          }
          else
          {
            v11 = 0.0;
          }
LABEL_18:
          if ( v53 < v11 )
            v53 = v11;
          if ( v9 > v41 )
            v9 = v41;
LABEL_22:
          if ( *(float *)&v58[4 * v10 + 4] <= 0.0 )
            goto LABEL_32;
          v42 = fabs(v57 - (double)(v10 + 1) * 30.0);
          if ( v42 == 0.0 )
          {
LABEL_27:
            v12 = 0.0049999999;
            goto LABEL_28;
          }
          v12 = *(float *)&v58[4 * v10 + 4] / v42;
          if ( v12 >= 0.0 )
          {
            if ( v12 > 0.0049999999 )
              goto LABEL_27;
          }
          else
          {
            v12 = 0.0;
          }
LABEL_28:
          if ( v53 < v12 )
            v53 = v12;
          if ( v9 > v42 )
            v9 = v42;
LABEL_32:
          if ( *(float *)&v58[4 * v10 + 8] <= 0.0 )
            goto LABEL_42;
          v43 = fabs(v57 - (double)(v10 + 2) * 30.0);
          if ( v43 == 0.0 )
          {
LABEL_37:
            v13 = 0.0049999999;
            goto LABEL_38;
          }
          v13 = *(float *)&v58[4 * v10 + 8] / v43;
          if ( v13 >= 0.0 )
          {
            if ( v13 > 0.0049999999 )
              goto LABEL_37;
          }
          else
          {
            v13 = 0.0;
          }
LABEL_38:
          if ( v53 < v13 )
            v53 = v13;
          if ( v9 > v43 )
            v9 = v43;
LABEL_42:
          if ( *(float *)&v58[4 * v10 + 12] <= 0.0 )
            goto LABEL_52;
          v44 = fabs(v57 - (double)(v10 + 3) * 30.0);
          if ( v44 == 0.0 )
          {
LABEL_47:
            v14 = 0.0049999999;
            goto LABEL_48;
          }
          v14 = *(float *)&v58[4 * v10 + 12] / v44;
          if ( v14 >= 0.0 )
          {
            if ( v14 > 0.0049999999 )
              goto LABEL_47;
          }
          else
          {
            v14 = 0.0;
          }
LABEL_48:
          if ( v53 < v14 )
            v53 = v14;
          if ( v9 > v44 )
            v9 = v44;
LABEL_52:
          if ( *(float *)&v58[4 * v10 + 16] <= 0.0 )
            goto LABEL_62;
          v45 = fabs(v57 - (double)(v10 + 4) * 30.0);
          if ( v45 == 0.0 )
          {
LABEL_57:
            v15 = 0.0049999999;
            goto LABEL_58;
          }
          v15 = *(float *)&v58[4 * v10 + 16] / v45;
          if ( v15 >= 0.0 )
          {
            if ( v15 > 0.0049999999 )
              goto LABEL_57;
          }
          else
          {
            v15 = 0.0;
          }
LABEL_58:
          if ( v53 < v15 )
            v53 = v15;
          if ( v9 > v45 )
            v9 = v45;
LABEL_62:
          if ( *(float *)&v58[4 * v10 + 20] <= 0.0 )
            goto LABEL_72;
          v46 = fabs(v57 - (double)(v10 + 5) * 30.0);
          if ( v46 == 0.0 )
          {
LABEL_67:
            v16 = 0.0049999999;
            goto LABEL_68;
          }
          v16 = *(float *)&v58[4 * v10 + 20] / v46;
          if ( v16 >= 0.0 )
          {
            if ( v16 > 0.0049999999 )
              goto LABEL_67;
          }
          else
          {
            v16 = 0.0;
          }
LABEL_68:
          if ( v53 < v16 )
            v53 = v16;
          if ( v9 > v46 )
            v9 = v46;
LABEL_72:
          if ( *(float *)&v58[4 * v10 + 24] <= 0.0 )
            goto LABEL_82;
          v47 = fabs(v57 - (double)(v10 + 6) * 30.0);
          if ( v47 == 0.0 )
          {
LABEL_77:
            v17 = 0.0049999999;
            goto LABEL_78;
          }
          v17 = *(float *)&v58[4 * v10 + 24] / v47;
          if ( v17 >= 0.0 )
          {
            if ( v17 > 0.0049999999 )
              goto LABEL_77;
          }
          else
          {
            v17 = 0.0;
          }
LABEL_78:
          if ( v53 < v17 )
            v53 = v17;
          if ( v9 > v47 )
            v9 = v47;
LABEL_82:
          if ( *(float *)&v58[4 * v10 + 28] <= 0.0 )
            goto LABEL_92;
          v48 = fabs(v57 - (double)(v10 + 7) * 30.0);
          if ( v48 == 0.0 )
          {
LABEL_87:
            v18 = 0.0049999999;
            goto LABEL_88;
          }
          v18 = *(float *)&v58[4 * v10 + 28] / v48;
          if ( v18 >= 0.0 )
          {
            if ( v18 > 0.0049999999 )
              goto LABEL_87;
          }
          else
          {
            v18 = 0.0;
          }
LABEL_88:
          if ( v53 < v18 )
            v53 = v18;
          if ( v9 > v48 )
            v9 = v48;
LABEL_92:
          if ( *(float *)&v58[4 * v10 + 32] <= 0.0 )
            goto LABEL_102;
          v49 = fabs(v57 - (double)(v10 + 8) * 30.0);
          if ( v49 == 0.0 )
          {
LABEL_97:
            v19 = 0.0049999999;
            goto LABEL_98;
          }
          v19 = *(float *)&v58[4 * v10 + 32] / v49;
          if ( v19 >= 0.0 )
          {
            if ( v19 > 0.0049999999 )
              goto LABEL_97;
          }
          else
          {
            v19 = 0.0;
          }
LABEL_98:
          if ( v53 < v19 )
            v53 = v19;
          if ( v9 > v49 )
            v9 = v49;
LABEL_102:
          if ( *(float *)&v58[4 * v10 + 36] <= 0.0 )
            goto LABEL_112;
          v50 = fabs(v57 - (double)(v10 + 9) * 30.0);
          if ( v50 == 0.0 )
          {
LABEL_107:
            v20 = 0.0049999999;
            goto LABEL_108;
          }
          v20 = *(float *)&v58[4 * v10 + 36] / v50;
          if ( v20 >= 0.0 )
          {
            if ( v20 > 0.0049999999 )
              goto LABEL_107;
          }
          else
          {
            v20 = 0.0;
          }
LABEL_108:
          if ( v53 < v20 )
            v53 = v20;
          if ( v9 > v50 )
            v9 = v50;
LABEL_112:
          v10 += 10;
          v40 = v10;
        }
        while ( v10 < 2880 );
        if ( v53 > 0.0 && v9 < 300.0 )
        {
          v21 = (unsigned __int8)v8++;
          v52 = v9 * 0.0033333334;
          v22 = flt_BE08A4[v21];
          dword_BE08A0 = v8;
          if ( v22 < 0.12 - v52 * 0.059999999 )
          {
            v23 = flt_BE08A4[(unsigned __int8)v8++];
            dword_BE08A0 = v8;
            v24 = v53 * 200.0 * 0.25 + 0.80000001 - v52 * 0.30000001 - v23 * 0.34999999;
            v51 = v24;
            if ( v24 > 0.0 )
            {
              if ( v51 > 1.0 )
                v51 = 1.0;
              v25 = flt_BE08A4[(unsigned __int8)v8];
              v26 = v8 + 1;
              dword_BE08A0 = v26;
              v55 = v52 * 0.5;
              if ( v25 < flt_B712C0 - v55 )
              {
                v27 = (float *)operator new(0xCu);
                v27[2] = v51;
                *v27 = v57;
                *((_DWORD *)v27 + 1) = 1;
                sub_5FDFB0(v27, 1);
                v26 = dword_BE08A0;
              }
              v28 = flt_BE08A4[(unsigned __int8)v26];
              v8 = v26 + 1;
              dword_BE08A0 = v8;
              if ( v28 < flt_B712E4 - v55 )
              {
                v29 = (float *)operator new(0xCu);
                v30 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
                v29[2] = v51;
                v29[1] = 0.0;
                *v29 = (v52 + 1.0) * v30 + v52 * 10.0 + v57;
                sub_5FDFB0(v29, 1);
                v8 = dword_BE08A0;
              }
            }
          }
        }
        v31 = flt_BE08A4[(unsigned __int8)v8++];
        dword_BE08A0 = v8;
        v32 = v31 + v31 + 2.0 + v57;
        v57 = v32;
        if ( v32 >= 86400.0 )
        {
          v33 = *(_DWORD *)(v1 + 96);
          v34 = (int *)(v1 + 96);
          v35 = sub_5969D0(v33);
          v36 = v35;
          *v34 = v35;
          if ( v35 )
          {
            for ( i = *(_DWORD *)(v35 + 4); i; i = *(_DWORD *)(i + 4) )
              v36 = i;
          }
          v34[1] = v36;
          v34[2] = v35;
          return;
        }
      }
    }
  }
}
