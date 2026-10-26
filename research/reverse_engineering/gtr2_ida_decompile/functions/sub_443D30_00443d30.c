void __thiscall sub_443D30(int this)
{
  long double v2; // st7
  long double v3; // st6
  int v4; // eax
  int v5; // eax
  double v6; // st6
  long double v7; // st7
  long double v8; // st7
  long double v9; // st6
  long double v10; // st5
  double *v11; // ecx
  long double v12; // st6
  double v13; // st6
  double v14; // st6
  long double v15; // st7
  long double v16; // st6
  double v18; // st7
  unsigned __int8 v19; // c0
  unsigned __int8 v20; // c3
  long double v21; // st7
  int v22; // eax
  int v23; // edi
  double v24; // st7
  bool v25; // cl
  bool v26; // al
  long double v27; // st7
  int v28; // edi
  unsigned __int8 v30; // c0
  unsigned __int8 v31; // c3
  long double v32; // st7
  double v33; // st7
  long double v34; // st7
  double v35; // st7
  double v36; // st7
  double v37; // st7
  double v38; // st7
  double v39; // st7
  double v40; // st7
  double v41; // st7
  int v42; // ecx
  double v43; // st7
  double v44; // st7
  double v45; // st7
  int v46; // ecx
  int v47; // eax
  unsigned __int8 v49; // c0
  unsigned __int8 v50; // c2
  double v51; // st7
  double v52; // st6
  unsigned __int8 v54; // c0
  unsigned __int8 v55; // c2
  double v56; // st7
  double v57; // st7
  long double v58; // [esp+18h] [ebp-20h] BYREF
  long double v59; // [esp+20h] [ebp-18h]
  long double v60; // [esp+28h] [ebp-10h]
  double v61; // [esp+30h] [ebp-8h]

  v58 = fabs(*(double *)(this + 8656));
  if ( *(double *)(this + 456) <= 0.0 )
  {
    v2 = 0.0;
  }
  else
  {
    v2 = *(double *)(this + 472) * *(double *)(this + 8) * v58;
    v3 = *(double *)(this + 456) - v2 * *(double *)(this + 480);
    *(long double *)(this + 456) = v3;
    if ( v3 <= 0.0 )
    {
      v4 = *(_DWORD *)(this + 9392) + 19272;
      *(double *)(this + 456) = 0.0;
      if ( !*(_DWORD *)(v4 + 112) )
        *(_DWORD *)(v4 + 112) = 9;
    }
    v5 = *(_DWORD *)(this + 512);
    v6 = *(double *)(this + 456) * 0.74 + 1.0;
    *(double *)(v5 + 176) = v6;
    *(double *)(v5 + 184) = 1.0 / v6;
  }
  v60 = v2 * *(double *)(this + 8920)
      + v58 * *(double *)(this + 8928)
      + (flt_FB1F2C + 273.16 - *(double *)(this + 8904)) * *(double *)(this + 8936);
  v7 = *(double *)(this + 8952);
  if ( *(double *)(this + 8912) - 10.0 < *(double *)(this + 8904) )
    v7 = v7 + v58 * *(double *)(this + 8960);
  v8 = v7 * (*(double *)(this + 8904) - *(double *)(this + 8968));
  v59 = (v60 - v8) * *(double *)(this + 136) + *(double *)(this + 8904);
  *(long double *)(this + 8904) = v59;
  v9 = v58 * 0.5358549222797928;
  if ( v59 > *(double *)(this + 8912) )
  {
    v10 = sin(*(double *)(this + 8912) * 3.141592653589793 / (v59 + v59));
    if ( v10 < 0.0 )
      v10 = 0.0;
    v9 = v9 * v10;
  }
  v11 = *(double **)(this + 6312);
  v12 = (v9 - *(double *)(this + 8944)) * *(double *)(this + 136);
  *(long double *)(this + 8944) = v12 + v12 + *(double *)(this + 8944);
  v13 = v11[15] * v11[12] + v11[14] * v11[9] + v11[6] * v11[13];
  if ( v13 >= 0.0 )
    v14 = v13 * 0.2;
  else
    v14 = -v13;
  v60 = (v8
       + (v14 * *(double *)(this + 8984) + *(double *)(this + 8976)) * (flt_FB1F2C + 273.16 - *(double *)(this + 8968)))
      * *(double *)(this + 136)
      + *(double *)(this + 8968);
  *(long double *)(this + 8968) = v60;
  v15 = v58 * 0.301625;
  if ( v60 > 373.16 )
  {
    v16 = sin(1172.316714613567 / (v60 + v60));
    if ( v16 < 0.0 )
      v16 = 0.0;
    v15 = v15 * v16;
  }
  *(long double *)(this + 8992) = (v15 - *(double *)(this + 8992)) * *(double *)(this + 136) * 4.0
                                + *(double *)(this + 8992);
  v18 = *(double *)(this + 9008);
  if ( !(v19 | v20) )
  {
    v61 = v18;
    v60 = pow(2.0, (v58 - *(double *)(this + 9016)) * *(double *)(this + 9024));
    v59 = pow(2.0, (v59 - *(double *)(this + 9032)) * *(double *)(this + 9040));
    v21 = *(double *)(this + 9008) - ((v59 + v60) * 0.5 + *(double *)(this + 9000)) * *(double *)(this + 136);
    *(long double *)(this + 9008) = v21;
    if ( v21 > 0.0 )
      return;
    v22 = *(_DWORD *)(this + 9392) + 19272;
    *(double *)(this + 9008) = 0.0;
    if ( !*(_DWORD *)(v22 + 112) )
      *(_DWORD *)(v22 + 112) = 1;
    v23 = dword_BE08A0;
    v25 = 1;
    if ( v61 == 2.225073858507201e-308 )
    {
      v24 = flt_BE0CA4[(unsigned __int8)dword_BE08A0];
      v23 = ++dword_BE08A0;
      if ( v24 <= 0.30000001 )
        v25 = 0;
    }
    v26 = *(double *)(this + 9056) == 0.0 && *(double *)(this + 9064) == 0.0 && *(double *)(this + 9072) == 0.0;
    v27 = flt_BE08A4[(unsigned __int8)v23];
    v28 = v23 + 1;
    v58 = v27;
    dword_BE08A0 = v28;
    if ( v26 )
    {
      if ( v58 < 0.5 )
      {
        if ( v25 )
        {
          if ( v30 | v31 )
            v32 = v58 - 0.04;
          else
            v32 = v58 + 0.04;
          v58 = v32;
          sub_43A0F0(&v58, 0.0, 0.5);
          if ( v58 >= 0.3 )
          {
            v35 = flt_BE0CA4[(unsigned __int8)v28];
            dword_BE08A0 = v28 + 1;
            if ( v58 >= 0.4 )
            {
              *(double *)(this + 9072) = v35 * 0.4 - 0.1;
              v34 = (v58 - 0.4) * 50.0;
            }
            else
            {
              *(double *)(this + 9064) = v35 * 0.4 - 0.1;
              v34 = (v58 - 0.3) * 450.0;
            }
          }
          else
          {
            v33 = flt_BE0CA4[(unsigned __int8)v28];
            dword_BE08A0 = v28 + 1;
            *(double *)(this + 9056) = v33 * 0.4 - 0.1;
            v34 = v58 * 1000.0;
          }
          *(long double *)(this + 9008) = v34 + 1.0;
          v36 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.1;
          *(double *)(this + 9000) = v36 + 0.15;
          return;
        }
        goto LABEL_53;
      }
      if ( v25 )
      {
        v37 = flt_BE08A4[(unsigned __int8)v28++];
        dword_BE08A0 = v28;
        if ( v37 < 0.4 )
        {
          *(double *)(this + 9056) = 1.0;
LABEL_52:
          v28 = dword_BE08A0;
          goto LABEL_53;
        }
        if ( v37 < 0.65 )
        {
          *(double *)(this + 9064) = 1.0;
          goto LABEL_52;
        }
        if ( v37 < 0.9 )
        {
          *(double *)(this + 9072) = 1.0;
          goto LABEL_52;
        }
      }
    }
LABEL_53:
    if ( *(double *)(this + 9056) == 0.0 )
    {
      if ( *(double *)(this + 9064) == 0.0 )
      {
        if ( *(double *)(this + 9072) != 0.0 )
        {
          v44 = flt_BE08A4[(unsigned __int8)v28];
          dword_BE08A0 = v28 + 1;
          *(double *)(this + 9072) = 1.0 - v44 * 0.3;
          v45 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.3;
          *(double *)(this + 9064) = 1.0 - v45;
        }
      }
      else
      {
        v40 = flt_BE08A4[(unsigned __int8)v28];
        dword_BE08A0 = v28 + 1;
        *(double *)(this + 9064) = 1.0 - v40 * 0.3;
        v41 = flt_BE08A4[(unsigned __int8)dword_BE08A0];
        v42 = ++dword_BE08A0;
        if ( v41 >= 0.2 )
        {
          if ( v41 < 0.8 )
          {
            v43 = flt_BE08A4[(unsigned __int8)v42];
            dword_BE08A0 = v42 + 1;
            *(double *)(this + 9072) = 1.0 - v43 * 0.3;
          }
        }
        else
        {
          *(double *)(this + 9056) = v41 + 0.1;
        }
      }
    }
    else
    {
      v38 = flt_BE08A4[(unsigned __int8)v28];
      dword_BE08A0 = v28 + 1;
      *(double *)(this + 9056) = 1.0 - v38 * 0.3;
      v39 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
      if ( v39 < 0.2 )
        *(double *)(this + 9064) = v39 + 0.1;
    }
    v46 = *(_DWORD *)(this + 8828);
    v47 = 0;
    *(double *)(this + 9000) = 0.0;
    if ( v46 > 0 )
    {
      do
        *(_DWORD *)(*(_DWORD *)(this + 8816) + 8 * v47++ + 4) = 0;
      while ( v47 < *(_DWORD *)(this + 8828) );
    }
    return;
  }
  if ( v18 >= -15.4 )
  {
    if ( !(v49 | v50) )
      return;
    v51 = *(double *)(this + 9008);
    v52 = v51 - *(double *)(this + 136);
    *(double *)(this + 9008) = v52;
    if ( v54 | v55 )
    {
      *(double *)(this + 9056) = 0.0;
      v56 = 0.0;
    }
    else
    {
      if ( v52 >= -10.1 || v51 < -10.1 )
        return;
      *(double *)(this + 9056) = *(double *)(this + 9056) * 0.5;
      v56 = *(double *)(this + 9064) * 0.5;
    }
    *(double *)(this + 9064) = v56;
    *(double *)(this + 9072) = 0.0;
    return;
  }
  if ( *(double *)(this + 9000) > 0.0 )
  {
    v57 = *(double *)(this + 136) * 0.002 + *(double *)(this + 9000);
    *(double *)(this + 9000) = v57;
    if ( v57 > 0.6 )
      *(double *)(this + 9000) = 0.6;
  }
}
