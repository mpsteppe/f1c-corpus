void __thiscall sub_442160(int this)
{
  double v2; // st7
  double v3; // st6
  int v4; // eax
  int v5; // eax
  double v6; // st6
  double v7; // st7
  double v8; // st7
  double v9; // st6
  bool v10; // c0
  bool v11; // c3
  long double v12; // st5
  int v13; // ecx
  double v14; // st6
  double v15; // st6
  double v16; // st7
  long double v17; // st6
  long double v18; // st7
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  double v23; // st7
  bool v24; // dl
  bool v25; // al
  double v26; // st7
  int v27; // ecx
  unsigned __int8 v29; // c0
  unsigned __int8 v30; // c3
  double v31; // st7
  double v32; // st6
  double v33; // st7
  double v34; // st7
  double v35; // st6
  double v36; // st6
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
  float v58; // [esp+0h] [ebp-38h]
  double v59; // [esp+18h] [ebp-20h]
  double v60; // [esp+20h] [ebp-18h]
  double v61; // [esp+28h] [ebp-10h]
  double v62; // [esp+28h] [ebp-10h]
  double v63; // [esp+30h] [ebp-8h]

  v59 = fabs(*(double *)(this + 7936));
  if ( *(double *)(this + 428) <= 0.0 )
  {
    v2 = 0.0;
  }
  else
  {
    v2 = *(double *)(this + 444) * *(double *)(this + 8) * v59;
    v3 = *(double *)(this + 428) - v2 * *(double *)(this + 452);
    *(double *)(this + 428) = v3;
    if ( v3 <= 0.0 )
    {
      v4 = *(_DWORD *)(this + 8620) + 20836;
      *(_DWORD *)(this + 428) = 0;
      *(_DWORD *)(this + 432) = 0;
      if ( !*(_DWORD *)(v4 + 60) )
        *(_DWORD *)(v4 + 60) = 8;
    }
    v5 = *(_DWORD *)(this + 484);
    v6 = *(double *)(this + 428) * 0.726 + 1.0;
    *(double *)(v5 + 172) = v6;
    *(double *)(v5 + 180) = 1.0 / v6;
  }
  v63 = v2 * *(double *)(this + 0x2000)
      + v59 * *(double *)(this + 8200)
      + (flt_7DAB0C + 273.16 - *(double *)(this + 8176)) * *(double *)(this + 8208);
  v7 = *(double *)(this + 8224);
  if ( *(double *)(this + 8184) - 10.0 < *(double *)(this + 8176) )
    v7 = v7 + v59 * *(double *)(this + 8232);
  v8 = v7 * (*(double *)(this + 8176) - *(double *)(this + 8240));
  v60 = (v63 - v8) * *(double *)(this + 136) + *(double *)(this + 8176);
  v9 = v59 * 0.5358549222797928;
  *(_DWORD *)(this + 8176) = LODWORD(v60);
  v10 = v60 < *(double *)(this + 8184);
  v11 = v60 == *(double *)(this + 8184);
  *(_DWORD *)(this + 8180) = HIDWORD(v60);
  if ( !v10 && !v11 )
  {
    v12 = sin(*(double *)(this + 8184) * 3.141592653589793 / (v60 + v60));
    if ( v12 < 0.0 )
      v12 = 0.0;
    v9 = v9 * v12;
  }
  v13 = *(_DWORD *)(this + 6164);
  *(double *)(this + 8216) = (v9 - *(double *)(this + 8216)) * *(double *)(this + 136) * 4.0 + *(double *)(this + 8216);
  v14 = *(double *)(v13 + 116) * *(double *)(v13 + 92)
      + *(double *)(v13 + 108) * *(double *)(v13 + 68)
      + *(double *)(v13 + 44) * *(double *)(v13 + 100);
  if ( v14 >= 0.0 )
    v15 = v14 * 0.2;
  else
    v15 = -v14;
  v61 = (v8
       + (v15 * *(double *)(this + 8256) + *(double *)(this + 8248)) * (flt_7DAB0C + 273.16 - *(double *)(this + 8240)))
      * *(double *)(this + 136)
      + *(double *)(this + 8240);
  *(double *)(this + 8240) = v61;
  v16 = v59 * 0.301625;
  if ( v61 > 373.16 )
  {
    v17 = sin(1172.316714613567 / (v61 + v61));
    if ( v17 < 0.0 )
      v17 = 0.0;
    v16 = v16 * v17;
  }
  *(double *)(this + 8264) = (v16 - *(double *)(this + 8264)) * *(double *)(this + 136) * 4.0 + *(double *)(this + 8264);
  if ( *(double *)(this + 8280) > 0.0 )
  {
    v62 = *(double *)(this + 8280);
    v18 = v62
        - ((pow(2.0, (v60 - *(double *)(this + 8304)) * *(double *)(this + 8312))
          + pow(2.0, (v59 - *(double *)(this + 8288)) * *(double *)(this + 8296)))
         * 0.5
         + *(double *)(this + 8272))
        * *(double *)(this + 136);
    *(long double *)(this + 8280) = v18;
    if ( v18 > 0.0 )
      return;
    *(_DWORD *)(this + 8280) = 0;
    *(_DWORD *)(this + 8284) = 0;
    sub_45D100(aEngineDamaged, 3, 16909060, 0);
    sub_4F81A0(*(_DWORD *)(this + 8620));
    v19 = *(_DWORD *)(this + 8620);
    v20 = *(_DWORD *)(v19 + 20896);
    v21 = v19 + 20836;
    if ( !v20 )
      *(_DWORD *)(v21 + 60) = 1;
    if ( dword_75CBB0 == 6 )
    {
      if ( dword_79FC40 < 1023 )
      {
        ++dword_79FC40;
        dword_7D3C44 += 208;
      }
      v58 = *(double *)(this + 128);
      sub_4D0D00(4, 41, 0, *(_DWORD *)(*(_DWORD *)(this + 8620) + 25248), LODWORD(v58), 0);
    }
    v22 = dword_7D3C50;
    v24 = 1;
    if ( v62 == 2.225073858507201e-308 )
    {
      v23 = flt_7D4054[(unsigned __int8)dword_7D3C50];
      v22 = ++dword_7D3C50;
      if ( v23 <= 0.30000001 )
        v24 = 0;
    }
    v25 = *(double *)(this + 8328) == 0.0 && *(double *)(this + 8336) == 0.0 && *(double *)(this + 8344) == 0.0;
    v26 = flt_7D3C54[(unsigned __int8)v22];
    v27 = v22 + 1;
    dword_7D3C50 = v27;
    if ( v25 )
    {
      if ( v26 < 0.5 )
      {
        if ( v24 )
        {
          if ( v29 | v30 )
            v31 = v26 - 0.04;
          else
            v31 = v26 + 0.04;
          if ( v31 < 0.0 )
          {
            v31 = 0.0;
LABEL_50:
            v35 = flt_7D4054[(unsigned __int8)v27];
            dword_7D3C50 = v27 + 1;
            *(double *)(this + 8328) = v35 * 0.4 - 0.1;
            v33 = v31 * 1000.0;
            goto LABEL_48;
          }
          if ( v31 <= 0.5 )
          {
            if ( v31 < 0.3 )
              goto LABEL_50;
            if ( v31 < 0.4 )
            {
              v36 = flt_7D4054[(unsigned __int8)v27];
              dword_7D3C50 = v27 + 1;
              *(double *)(this + 8336) = v36 * 0.4 - 0.1;
              v33 = (v31 - 0.3) * 450.0;
              goto LABEL_48;
            }
          }
          else
          {
            v31 = 0.5;
          }
          v32 = flt_7D4054[(unsigned __int8)v27];
          dword_7D3C50 = v27 + 1;
          *(double *)(this + 8344) = v32 * 0.4 - 0.1;
          v33 = (v31 - 0.4) * 50.0;
LABEL_48:
          *(double *)(this + 8280) = v33 + 1.0;
          v34 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 0.1;
          *(double *)(this + 8272) = v34 + 0.15;
          return;
        }
        goto LABEL_61;
      }
      if ( v24 )
      {
        v37 = flt_7D3C54[(unsigned __int8)v27++];
        dword_7D3C50 = v27;
        if ( v37 < 0.4 )
        {
          *(_DWORD *)(this + 8328) = 0;
          *(_DWORD *)(this + 8332) = 1072693248;
LABEL_60:
          v27 = dword_7D3C50;
          goto LABEL_61;
        }
        if ( v37 < 0.65 )
        {
          *(_DWORD *)(this + 8336) = 0;
          *(_DWORD *)(this + 8340) = 1072693248;
          goto LABEL_60;
        }
        if ( v37 < 0.9 )
        {
          *(_DWORD *)(this + 8344) = 0;
          *(_DWORD *)(this + 8348) = 1072693248;
          goto LABEL_60;
        }
      }
    }
LABEL_61:
    if ( *(double *)(this + 8328) == 0.0 )
    {
      if ( *(double *)(this + 8336) == 0.0 )
      {
        if ( *(double *)(this + 8344) != 0.0 )
        {
          v44 = flt_7D3C54[(unsigned __int8)v27];
          dword_7D3C50 = v27 + 1;
          *(double *)(this + 8344) = 1.0 - v44 * 0.3;
          v45 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 0.3;
          *(double *)(this + 8336) = 1.0 - v45;
        }
      }
      else
      {
        v40 = flt_7D3C54[(unsigned __int8)v27];
        dword_7D3C50 = v27 + 1;
        *(double *)(this + 8336) = 1.0 - v40 * 0.3;
        v41 = flt_7D3C54[(unsigned __int8)dword_7D3C50];
        v42 = ++dword_7D3C50;
        if ( v41 >= 0.2 )
        {
          if ( v41 < 0.8 )
          {
            v43 = flt_7D3C54[(unsigned __int8)v42];
            dword_7D3C50 = v42 + 1;
            *(double *)(this + 8344) = 1.0 - v43 * 0.3;
          }
        }
        else
        {
          *(double *)(this + 8328) = v41 + 0.1;
        }
      }
    }
    else
    {
      v38 = flt_7D3C54[(unsigned __int8)v27];
      dword_7D3C50 = v27 + 1;
      *(double *)(this + 8328) = 1.0 - v38 * 0.3;
      v39 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
      if ( v39 < 0.2 )
        *(double *)(this + 8336) = v39 + 0.1;
    }
    v46 = *(_DWORD *)(this + 8108);
    v47 = 0;
    *(_DWORD *)(this + 8272) = 0;
    *(_DWORD *)(this + 8276) = 0;
    if ( v46 > 0 )
    {
      do
        *(_DWORD *)(*(_DWORD *)(this + 8096) + 8 * v47++ + 4) = 0;
      while ( v47 < *(_DWORD *)(this + 8108) );
    }
    nullsub_2(*(_DWORD *)(this + 8620), 0);
    return;
  }
  if ( *(double *)(this + 8280) < -15.4 )
  {
    if ( *(double *)(this + 8272) > 0.0 )
    {
      v57 = *(double *)(this + 136) * 0.002 + *(double *)(this + 8272);
      *(double *)(this + 8272) = v57;
      if ( v57 > 0.6 )
      {
        *(_DWORD *)(this + 8272) = 858993459;
        *(_DWORD *)(this + 8276) = 1071854387;
      }
    }
  }
  else if ( v49 | v50 )
  {
    v51 = *(double *)(this + 8280);
    v52 = v51 - *(double *)(this + 136);
    *(double *)(this + 8280) = v52;
    if ( v54 | v55 )
    {
      *(_DWORD *)(this + 8328) = 0;
      *(_DWORD *)(this + 8332) = 0;
      *(_DWORD *)(this + 8336) = 0;
      *(_DWORD *)(this + 8340) = 0;
      *(_DWORD *)(this + 8344) = 0;
      *(_DWORD *)(this + 8348) = 0;
      if ( !*(_DWORD *)dword_76693C )
        sub_4BA1A0(0, -1.0);
    }
    else if ( v52 < -10.1 && v51 >= -10.1 )
    {
      v56 = *(double *)(this + 8328);
      *(_DWORD *)(this + 8344) = 0;
      *(_DWORD *)(this + 8348) = 0;
      *(double *)(this + 8328) = v56 * 0.5;
      *(double *)(this + 8336) = *(double *)(this + 8336) * 0.5;
    }
  }
}
