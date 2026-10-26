void __thiscall sub_4DED40(float *this, int a2, float a3)
{
  int v4; // esi
  float *v5; // eax
  float v6; // edx
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st3
  long double v12; // st7
  long double v13; // st7
  double v14; // st7
  long double v15; // st6
  double v17; // st5
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c3
  long double v20; // st6
  long double v21; // st7
  long double v22; // st6
  long double v23; // st6
  long double v24; // st7
  long double v25; // st6
  double v26; // st5
  double v27; // st4
  long double v28; // st6
  double v29; // st4
  double v30; // st3
  long double v31; // st2
  long double v32; // st2
  long double v33; // st7
  long double v34; // st6
  int v35; // eax
  float v36; // [esp+4h] [ebp-84h]
  float v37; // [esp+4h] [ebp-84h]
  float v38; // [esp+4h] [ebp-84h]
  float v39; // [esp+8h] [ebp-80h]
  float v40; // [esp+8h] [ebp-80h]
  float v41; // [esp+Ch] [ebp-7Ch]
  float v42; // [esp+Ch] [ebp-7Ch]
  float v43; // [esp+Ch] [ebp-7Ch]
  float v44; // [esp+10h] [ebp-78h]
  float v45; // [esp+10h] [ebp-78h]
  float v46; // [esp+14h] [ebp-74h]
  float v47; // [esp+14h] [ebp-74h]
  float v48; // [esp+18h] [ebp-70h]
  float v49; // [esp+18h] [ebp-70h]
  float v50; // [esp+1Ch] [ebp-6Ch]
  float v51; // [esp+1Ch] [ebp-6Ch]
  float v52; // [esp+20h] [ebp-68h]
  float v53; // [esp+20h] [ebp-68h]
  float v54; // [esp+20h] [ebp-68h]
  float v55; // [esp+20h] [ebp-68h]
  float v56; // [esp+24h] [ebp-64h]
  float v57; // [esp+24h] [ebp-64h]
  float v58; // [esp+24h] [ebp-64h]
  float v59; // [esp+28h] [ebp-60h]
  float v60; // [esp+28h] [ebp-60h]
  float v61; // [esp+2Ch] [ebp-5Ch]
  float v62; // [esp+30h] [ebp-58h]
  float v63; // [esp+34h] [ebp-54h]
  float v64; // [esp+38h] [ebp-50h]
  float v65; // [esp+38h] [ebp-50h]
  float v66; // [esp+3Ch] [ebp-4Ch]
  float v67; // [esp+40h] [ebp-48h]
  float v68; // [esp+44h] [ebp-44h]
  float v69; // [esp+50h] [ebp-38h]
  float v70; // [esp+54h] [ebp-34h]
  float v71; // [esp+58h] [ebp-30h]
  float v72; // [esp+5Ch] [ebp-2Ch]
  float v73; // [esp+60h] [ebp-28h]
  float v74; // [esp+60h] [ebp-28h]
  float v75; // [esp+60h] [ebp-28h]
  float v76; // [esp+64h] [ebp-24h]
  float v77; // [esp+68h] [ebp-20h]
  float v78; // [esp+6Ch] [ebp-1Ch]
  float v79; // [esp+70h] [ebp-18h]
  float v80; // [esp+74h] [ebp-14h]
  float v81; // [esp+78h] [ebp-10h]
  float v82[3]; // [esp+7Ch] [ebp-Ch] BYREF

  if ( dword_767310 >= 1 )
  {
    if ( fabs(a3 - this[56]) >= 2.0 )
    {
      if ( fabs(a3 - this[55]) >= 9.0 )
      {
        this[56] = a3;
        v50 = *(float *)(a2 + 17604);
        v52 = *(float *)(a2 + 17608);
        v56 = *(float *)(a2 + 17612);
        v44 = *(float *)(a2 + 17628);
        v46 = *(float *)(a2 + 17632);
        v4 = *(_DWORD *)this + 84;
        v36 = *(float *)(*(_DWORD *)this + 17604);
        v48 = *(float *)(a2 + 17636);
        v59 = v50 - v36;
        v39 = *(float *)(*(_DWORD *)this + 17608);
        v41 = *(float *)(*(_DWORD *)this + 17612);
        v81 = v52 - v39;
        v66 = *(float *)(*(_DWORD *)this + 17628);
        v67 = *(float *)(*(_DWORD *)this + 17632);
        v68 = *(float *)(*(_DWORD *)this + 17636);
        v64 = v56 - v41;
        v78 = v44 - v66;
        v79 = v46 - v67;
        v80 = v48 - v68;
        v73 = v41 + v56;
        v51 = (v36 + v50) * 0.5;
        v82[0] = v51;
        v53 = (v39 + v52) * 0.5;
        v82[1] = v53;
        v57 = v73 * 0.5;
        v82[2] = v57;
        v5 = sub_403D10(&flt_628F60, v82, *(_DWORD *)(v4 + 19000));
        v37 = v5[53];
        v6 = v5[54];
        v42 = v5[55];
        v7 = v42 * v5[15] - v6 * v5[16];
        v8 = v37 * v5[16] - v42 * v5[14];
        v9 = v6 * v5[14] - v37 * v5[15];
        v10 = v5[47];
        v11 = v37 * v10;
        v54 = v6 * v10;
        v58 = v42 * v10;
        v72 = v46 - v54;
        v74 = v48 - v58;
        v61 = v42 * v74 + v6 * v72 + (v44 - v11) * v37;
        v77 = v48 * v9 + v46 * v8 + v7 * v44;
        v62 = v42 * v64 + v6 * v81 + v37 * v59;
        v63 = v9 * v64 + v8 * v81 + v7 * v59;
        v70 = v42 * (v68 - v58) + v6 * (v67 - v54) + (v66 - v11) * v37;
        v76 = v68 * v9 + v67 * v8 + v7 * v66;
        v45 = v64 * *(float *)(v4 + 17508) + v81 * *(float *)(v4 + 17496) + v59 * *(float *)(v4 + 17484);
        v38 = v45;
        v47 = v64 * *(float *)(v4 + 17512) + v81 * *(float *)(v4 + 17500) + v59 * *(float *)(v4 + 17488);
        v40 = v47;
        v49 = v64 * *(float *)(v4 + 17516) + v81 * *(float *)(v4 + 17504) + v59 * *(float *)(v4 + 17492);
        v43 = v49;
        v12 = v45 * v45 + v49 * v49 + v47 * v47;
        if ( v12 > 0.0 )
        {
          v13 = 1.0 / sqrt(v12);
          v38 = v45 * v13;
          v40 = v47 * v13;
          v43 = v13 * v49;
        }
        v14 = 0.0;
        if ( this[50] > 0.0 )
          v14 = this[50] * 0.050000001;
        v15 = fabs(v77 * 0.071428575);
        v17 = v61;
        if ( v18 | v19 )
          v20 = v15 - v17 * 0.014285714;
        else
          v20 = v15 + v17 * 0.055555556;
        if ( v20 <= 1.0 )
          v21 = v14 + 0.5 - v20;
        else
          v21 = v14 - 0.5;
        v22 = fabs(v76 * 0.028571429);
        if ( v70 <= 0.0 )
          v23 = v22 - v61 * 0.0044444446;
        else
          v23 = v22 + v70 * 0.025;
        if ( v23 <= 1.0 )
          v24 = v21 + v23;
        else
          v24 = v21 + 1.0;
        v25 = v63;
        v26 = 0.0;
        v69 = v62;
        v27 = v63 * v63 + v62 * v62;
        if ( v27 > 0.0 )
        {
          v65 = v27;
          v28 = 1.0 / sqrt(v65);
          v60 = v28;
          v25 = v28 * v63;
          v26 = v60 * 0.0;
          v69 = v60 * v62;
        }
        v55 = 0.0;
        v29 = v76 - v77;
        v30 = v70 - v61;
        v31 = v30 * v30 + v29 * v29;
        if ( v31 > 0.0 )
        {
          v32 = 1.0 / sqrt(v31);
          v29 = v29 * v32;
          v55 = 0.0 * v32;
          v30 = v30 * v32;
        }
        v71 = -*(float *)(v4 + 17680);
        v75 = *(float *)(v4 + 17684) * 0.75 - (*(float *)(v4 + 17676) + *(float *)(v4 + 17676));
        v33 = v24
            + (v30 * v69 + v55 * v26 + v29 * v25) * 0.22499999
            + (v43 * v75 + v38 * v71 + v40 * 0.0) * 0.25
            + (*(float *)(v4 + 18516) + *(float *)(v4 + 18268) + *(float *)(v4 + 18020) + *(float *)(v4 + 17772) - 2.0)
            * 0.25
            * 0.25;
        if ( v43 > 0.0 )
          v33 = v33 - sqrt(v43) * 0.25;
        v34 = sqrt(v80 * v80 + v79 * v79 + v78 * v78);
        if ( v34 < 12.0 )
          v33 = v33 * (v34 * 0.083333336);
        v35 = *(_DWORD *)(a2 + 25248);
        this[59] = v33;
        this[58] = a3;
        *((_DWORD *)this + 57) = v35;
        this[60] = sub_51C630(a2 + 84);
        this[61] = v43;
      }
    }
    else
    {
      this[56] = a3;
    }
  }
}
