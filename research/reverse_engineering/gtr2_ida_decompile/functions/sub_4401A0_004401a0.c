void __thiscall sub_4401A0(int this, double a2)
{
  long double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  double v10; // st6
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c2
  double *v14; // eax
  double v15; // st7
  double v16; // st7
  double v17; // st6
  double v18; // st4
  double v19; // st5
  double v20; // st5
  double v21; // st6
  double v22; // st5
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  long double v27; // st7
  double v28; // st6
  double v29; // st6
  long double v30; // st7
  double v31; // [esp+8h] [ebp-88h]
  float v32; // [esp+8h] [ebp-88h]
  double v33; // [esp+10h] [ebp-80h]
  double v34; // [esp+10h] [ebp-80h]
  double v35; // [esp+18h] [ebp-78h]
  float v36; // [esp+18h] [ebp-78h]
  long double v37; // [esp+20h] [ebp-70h]
  long double v38; // [esp+20h] [ebp-70h]
  double v39; // [esp+20h] [ebp-70h]
  double v40; // [esp+28h] [ebp-68h]
  double v41; // [esp+28h] [ebp-68h]
  double v42; // [esp+30h] [ebp-60h]
  double v43; // [esp+38h] [ebp-58h]
  double v44; // [esp+40h] [ebp-50h]
  double v45; // [esp+48h] [ebp-48h]
  double v46; // [esp+50h] [ebp-40h]
  double v47; // [esp+58h] [ebp-38h]
  double v48; // [esp+68h] [ebp-28h]
  double v49; // [esp+70h] [ebp-20h]
  double v50; // [esp+78h] [ebp-18h]
  double v51; // [esp+80h] [ebp-10h]
  double v52; // [esp+88h] [ebp-8h]

  v44 = flt_FB1F30 + 273.16;
  v43 = flt_FB1F2C + 273.16;
  if ( *(double *)(this + 864) <= 0.0 )
    v3 = 0.0;
  else
    v3 = fabs(*(double *)(this + 192)) * *(double *)(this + 1064) * *(double *)(this + 864);
  v31 = v3;
  if ( *(double *)(this + 856) <= 0.0 )
  {
    v40 = 0.0;
    v5 = 0.0;
  }
  else
  {
    if ( *(double *)(this + 336) <= 1.0 )
    {
      v4 = sqrt(*(double *)(this + 336));
      if ( v4 < 0.5 )
        v4 = v4 * v4 + 0.25;
    }
    else
    {
      v4 = 1.0;
    }
    v40 = (1.0 - v4) * *(double *)(this + 856) * *(double *)(this + 648) * *(double *)(this + 648);
    v5 = v40 * *(double *)(this + 1072);
  }
  v35 = v5;
  v6 = *(double *)(this + 1048) * *(double *)(this + 848);
  v46 = v6;
  if ( v8 | v9 )
  {
    v6 = -1.0;
  }
  else
  {
    if ( v6 <= 1.0 )
      goto LABEL_16;
    v6 = 1.0;
  }
  v46 = v6;
LABEL_16:
  v45 = *(double *)(this + 936) * *(double *)(this + 856) + *(double *)(this + 928);
  v10 = (v45 - *(double *)(this + 1000)) * *(double *)(this + 1056);
  v42 = v10;
  if ( v12 | v13 )
  {
    v10 = -1.0;
  }
  else
  {
    if ( v10 <= 1.0 )
      goto LABEL_21;
    v10 = 1.0;
  }
  v42 = v10;
LABEL_21:
  v14 = (double *)(*(_DWORD *)(this + 352) + 104);
  v50 = (0.5 * v10 - v6 + 1.5) * 0.3333333333333333;
  v51 = (1.5 - v10) * 0.3333333333333333;
  v52 = (0.5 * v10 + v6 + 1.5) * 0.3333333333333333;
  v37 = sqrt(*v14 * *v14 + v14[1] * v14[1] + v14[2] * v14[2]) * *(double *)(this + 1096) + *(double *)(this + 1088);
  v15 = sub_592960(&dword_FB1EF8) + *(double *)(this + 656) + 1.0;
  v38 = v37 * v15;
  v16 = v15 * *(double *)(this + 1080);
  v17 = *(double *)(this + 960);
  v48 = *(double *)(this + 968);
  v49 = *(double *)(this + 976);
  v47 = *(double *)(this + 984);
  v33 = v38 * a2;
  v39 = a2 * *(double *)(this + 1104);
  v18 = v35 * (a2 * v50) + a2 * v50 * v31 + v17;
  *(double *)(this + 960) = v18;
  if ( *(double *)(this + 864) > 0.0 )
    *(double *)(this + 960) = (v44 - v17) * (a2 * v50) * v16 + v18;
  v19 = (v47 - v17) * v39;
  *(double *)(this + 960) = (v43 - v17) * v33 + *(double *)(this + 960) + v19;
  *(double *)(this + 984) = *(double *)(this + 984) - v19;
  v20 = v35 * (v51 * a2) + v51 * a2 * v31 + *(double *)(this + 968);
  *(double *)(this + 968) = v20;
  if ( *(double *)(this + 864) > 0.0 )
    *(double *)(this + 968) = (v44 - v48) * (v51 * a2) * v16 + v20;
  v21 = (v47 - v48) * v39;
  *(double *)(this + 968) = (v43 - v48) * v33 + *(double *)(this + 968) + v21;
  *(double *)(this + 984) = *(double *)(this + 984) - v21;
  v22 = v35 * (v52 * a2) + v52 * a2 * v31 + *(double *)(this + 976);
  *(double *)(this + 976) = v22;
  if ( *(double *)(this + 864) > 0.0 )
    *(double *)(this + 976) = (v44 - v49) * (v52 * a2) * v16 + v22;
  v23 = (v47 - v49) * v39;
  *(double *)(this + 976) = (v43 - v49) * v33 + *(double *)(this + 976) + v23;
  *(double *)(this + 984) = *(double *)(this + 984) - v23;
  if ( *(double *)(this + 984) >= 273.16 )
  {
    if ( *(double *)(this + 984) <= 546.3200000000001 )
      goto LABEL_32;
    v24 = 546.3200000000001;
  }
  else
  {
    v24 = 273.16;
  }
  *(double *)(this + 984) = v24;
LABEL_32:
  v25 = *(double *)(this + 992) * *(double *)(this + 984);
  *(double *)(this + 1000) = v25;
  *(double *)(this + 568) = v25 * *(double *)(this + 1024) + *(double *)(this + 1016);
  v34 = (*(double *)(this + 976) + *(double *)(this + 968) + *(double *)(this + 960)) * 0.3333333333333333;
  v41 = (fabs(v42) + fabs(v46) + 4.0)
      * 0.1666666666666667
      * *(double *)(this + 1112)
      * (v34
       * *(double *)(this + 896))
      * (v34
       * *(double *)(this + 896))
      * v40
      * a2;
  v32 = (*(double *)(this + 1032) - 0.6875) * 3.2;
  v36 = (*(double *)(this + 1032) - v41 - 0.6875) * 3.2;
  if ( 1.0 != v32 )
  {
    if ( v32 <= 0.69999999 || v36 > 0.69999999 )
    {
      if ( v32 > 0.40000001 && v36 <= 0.40000001 )
        sub_4EE320(33, 0);
    }
    else
    {
      sub_4EE320(32, 0);
    }
  }
  if ( *(double *)(this + 1032) > 0.6875 )
  {
    v26 = *(double *)(this + 1032) - v41;
    *(double *)(this + 1032) = v26;
    if ( v26 <= 0.6875 )
    {
      *(double *)(this + 1032) = 0.6875;
      sub_4397B0();
    }
  }
  if ( v34 > *(double *)(this + 920) )
    sub_4397B0();
  v27 = fabs(*(double *)(this + 1000) - v45) * (*(double *)(this + 944) / v45);
  v28 = v34 - *(double *)(this + 888);
  if ( v28 >= 0.0 )
    v29 = v28 * *(double *)(this + 912);
  else
    v29 = v28 * *(double *)(this + 904);
  v30 = v27 + v29;
  if ( v30 > 1.0 )
    v30 = 1.0;
  *(long double *)(this + 1040) = (1.0 - v30 * v30 * 0.5) * *(double *)(this + 1032);
}
