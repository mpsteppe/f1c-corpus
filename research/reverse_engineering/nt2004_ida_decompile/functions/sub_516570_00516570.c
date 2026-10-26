int __thiscall sub_516570(int this)
{
  int v2; // ebx
  float *v3; // edi
  int result; // eax
  char *v5; // ebp
  float v6; // eax
  double v7; // st7
  float v8; // ecx
  float *v9; // ebx
  double v10; // st7
  double v11; // st6
  float *v12; // edi
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st7
  long double v17; // st6
  long double v18; // st7
  signed int v19; // ecx
  double v20; // st7
  int v21; // edx
  int v22; // eax
  double v23; // st7
  long double v24; // st7
  long double v25; // st7
  long double v26; // st4
  double v27; // st7
  double v28; // st6
  int v29; // eax
  int v30; // eax
  double v31; // st7
  double v32; // st7
  double v33; // st6
  double v34; // st7
  double v35; // st6
  double v36; // st7
  int v37; // eax
  int v38; // eax
  double v39; // st7
  double v40; // st6
  double v41; // st5
  double v42; // st4
  float v43; // ecx
  double v44; // rtt
  double v45; // st4
  double v46; // st5
  double v47; // st7
  double v48; // st6
  double v49; // st7
  double v50; // st6
  long double v51; // st5
  long double v52; // st5
  double v53; // st4
  float v54; // [esp+10h] [ebp-168h] BYREF
  float v55; // [esp+14h] [ebp-164h]
  float v56; // [esp+18h] [ebp-160h] BYREF
  float v57; // [esp+1Ch] [ebp-15Ch]
  float v58; // [esp+20h] [ebp-158h]
  float v59; // [esp+24h] [ebp-154h] BYREF
  float v60; // [esp+28h] [ebp-150h]
  float v61; // [esp+2Ch] [ebp-14Ch]
  float v62; // [esp+30h] [ebp-148h]
  int v63; // [esp+34h] [ebp-144h]
  float v64; // [esp+38h] [ebp-140h] BYREF
  float v65; // [esp+3Ch] [ebp-13Ch]
  float v66; // [esp+40h] [ebp-138h]
  float v67; // [esp+44h] [ebp-134h]
  float v68; // [esp+48h] [ebp-130h]
  float v69; // [esp+4Ch] [ebp-12Ch]
  float v70; // [esp+50h] [ebp-128h]
  float *v71; // [esp+54h] [ebp-124h]
  float v72; // [esp+58h] [ebp-120h]
  float v73; // [esp+5Ch] [ebp-11Ch]
  float v74; // [esp+60h] [ebp-118h]
  signed int v75; // [esp+64h] [ebp-114h]
  float v76; // [esp+68h] [ebp-110h]
  float v77; // [esp+6Ch] [ebp-10Ch]
  float v78; // [esp+70h] [ebp-108h]
  float v79; // [esp+74h] [ebp-104h] BYREF
  float v80; // [esp+78h] [ebp-100h]
  float v81; // [esp+7Ch] [ebp-FCh]
  float v82; // [esp+80h] [ebp-F8h]
  float v83; // [esp+84h] [ebp-F4h] BYREF
  float v84; // [esp+88h] [ebp-F0h]
  float v85; // [esp+8Ch] [ebp-ECh]
  float v86; // [esp+90h] [ebp-E8h]
  float v87[4]; // [esp+94h] [ebp-E4h] BYREF
  float v88; // [esp+A4h] [ebp-D4h]
  float v89; // [esp+B0h] [ebp-C8h]
  float v90; // [esp+B4h] [ebp-C4h]
  float v91; // [esp+BCh] [ebp-BCh]
  float v92; // [esp+C0h] [ebp-B8h]
  float v93; // [esp+C8h] [ebp-B0h]
  float v94; // [esp+CCh] [ebp-ACh]
  double v95; // [esp+D0h] [ebp-A8h] BYREF
  double v96; // [esp+D8h] [ebp-A0h] BYREF
  _BYTE v97[8]; // [esp+E0h] [ebp-98h] BYREF
  int v98; // [esp+E8h] [ebp-90h]
  int v99; // [esp+F0h] [ebp-88h]
  int v100; // [esp+F8h] [ebp-80h]
  float v101; // [esp+104h] [ebp-74h]
  float v102; // [esp+108h] [ebp-70h]
  float v103; // [esp+10Ch] [ebp-6Ch]
  float v104; // [esp+110h] [ebp-68h]
  float v105; // [esp+114h] [ebp-64h]
  float v106; // [esp+118h] [ebp-60h]
  double v107[3]; // [esp+124h] [ebp-54h] BYREF
  double v108[3]; // [esp+13Ch] [ebp-3Ch] BYREF
  double v109[4]; // [esp+154h] [ebp-24h] BYREF
  float v110; // [esp+174h] [ebp-4h]

  v2 = 0;
  v3 = (float *)(this + 19032);
  v63 = 0;
  v71 = (float *)(this + 19032);
  do
  {
    result = sub_5A1240(v2, v97);
    if ( !result )
      goto LABEL_73;
    if ( v2 >= 10 && v2 < 12 && *(_BYTE *)(this + 19228) && (!*(_DWORD *)(this + 3432) || !*(_BYTE *)(this + 3496)) )
    {
      result = sub_5A1290(v2);
      goto LABEL_73;
    }
    v5 = (char *)sub_515BF0();
    v68 = v104;
    v6 = v104;
    v69 = v105;
    v7 = v106;
    *((_DWORD *)v5 + 5) = v100;
    v8 = v69;
    *(_DWORD *)v5 = v2;
    *((float *)v5 + 6) = v6;
    *((float *)v5 + 7) = v8;
    v70 = v7;
    *((float *)v5 + 8) = v70;
    v9 = (float *)(v5 + 36);
    *((float *)v5 + 9) = *(float *)(this + 17488) * *v3
                       + *(float *)(this + 17492) * v3[1]
                       + *(float *)(this + 17484) * *(v3 - 1);
    *((float *)v5 + 10) = *(float *)(this + 17500) * *v3
                        + *(float *)(this + 17504) * v3[1]
                        + *(float *)(this + 17496) * *(v3 - 1);
    *((float *)v5 + 11) = *(float *)(this + 17512) * *v3
                        + *(float *)(this + 17516) * v3[1]
                        + *(float *)(this + 17508) * *(v3 - 1);
    *((float *)v5 + 9) = *(float *)(this + 17520) + *((float *)v5 + 9);
    *((float *)v5 + 10) = *(float *)(this + 17524) + *((float *)v5 + 10);
    *((float *)v5 + 11) = *(float *)(this + 17528) + *((float *)v5 + 11);
    v72 = v68 - *((float *)v5 + 9);
    v73 = v69 - *((float *)v5 + 10);
    v74 = v70 - *((float *)v5 + 11);
    v10 = v68 + *((float *)v5 + 9);
    v11 = v69 + *((float *)v5 + 10);
    v12 = (float *)(v5 + 60);
    v110 = v70 + *((float *)v5 + 11);
    v80 = v10 * 0.5;
    *((float *)v5 + 9) = v80;
    v81 = v11 * 0.5;
    v13 = v110;
    *((float *)v5 + 10) = v81;
    v82 = v13 * 0.5;
    *((float *)v5 + 11) = v82;
    v14 = v103;
    v15 = v102;
    *((float *)v5 + 15) = v101;
    *((float *)v5 + 16) = v15;
    *((float *)v5 + 17) = v14;
    if ( (*(_BYTE *)(v98 + 60) & 0x10) == 0x10 )
      goto LABEL_13;
    v60 = *(float *)(this + 17508) * *((float *)v5 + 17)
        + *(float *)(this + 17496) * *((float *)v5 + 16)
        + *(float *)(this + 17484) * *((float *)v5 + 15);
    v61 = *(float *)(this + 17488) * *((float *)v5 + 15)
        + *(float *)(this + 17512) * *((float *)v5 + 17)
        + *(float *)(this + 17500) * *((float *)v5 + 16);
    v62 = *(float *)(this + 17492) * *((float *)v5 + 15)
        + *(float *)(this + 17516) * *((float *)v5 + 17)
        + *(float *)(this + 17504) * *((float *)v5 + 16);
    if ( v63 < 8 )
    {
      if ( fabs(v61) < 0.1 )
      {
        v16 = v61 * 0.0625;
        v17 = 1.0 / sqrt(v62 * v62 + v60 * v60 + v16 * v16);
        v60 = v60 * v17;
        v61 = v17 * v16;
        v18 = v62 * v17;
        *v12 = v61 * *(float *)(this + 17488) + v18 * *(float *)(this + 17492) + v60 * *(float *)(this + 17484);
        *((float *)v5 + 16) = v60 * *(float *)(this + 17496)
                            + v61 * *(float *)(this + 17500)
                            + v18 * *(float *)(this + 17504);
        *((float *)v5 + 17) = v60 * *(float *)(this + 17508)
                            + v61 * *(float *)(this + 17512)
                            + v18 * *(float *)(this + 17516);
      }
LABEL_13:
      *(float *)&v19 = 0.0;
      v20 = v74 * *((float *)v5 + 17);
      v54 = 0.0;
      *((float *)v5 + 2) = v20 + v73 * *((float *)v5 + 16) + v72 * *v12;
      v75 = NumOfElements;
      if ( (int)NumOfElements <= 0 )
        goto LABEL_32;
      while ( v98 != *(_DWORD *)(dword_75AAD0[v19] + 1896) )
      {
        if ( ++v19 >= (int)NumOfElements )
        {
          v54 = *(float *)&v19;
          goto LABEL_32;
        }
      }
      v54 = *(float *)&v19;
      v75 = v19;
      if ( v19 >= (int)NumOfElements )
      {
LABEL_32:
        v29 = sub_417C70(dword_6291D0, v98);
        if ( v29 )
        {
          *((_DWORD *)v5 + 3) = 2;
        }
        else
        {
          *((_DWORD *)v5 + 3) = 9;
          v54 = 0.0;
          if ( v99 )
            sub_599770(&v54, 4096);
          v29 = LODWORD(v54);
        }
        *((_DWORD *)v5 + 4) = v29;
        goto LABEL_38;
      }
      v21 = *(_DWORD *)(this + 16500);
      v22 = dword_75AAD0[v19];
      v55 = *(float *)&v22;
      if ( v21 )
      {
        if ( *(_DWORD *)(v22 + 16584) )
        {
LABEL_27:
          v65 = *(float *)(this + 17520) - *(float *)(v22 + 17604);
          v66 = *(float *)(this + 17524) - *(float *)(v22 + 17608);
          v23 = *(float *)(this + 17528) - *(float *)(v22 + 17612);
          v67 = v23;
          v24 = sqrt(v23 * v67 + v66 * v66 + v65 * v65);
          if ( v24 > 0.0 )
          {
            v25 = 6.0 / v24;
            v91 = v25 * v66;
            v92 = v25 * v67;
            *v12 = v65 * v25 + *v12;
            *((float *)v5 + 16) = v91 + *((float *)v5 + 16);
            *((float *)v5 + 17) = v92 + *((float *)v5 + 17);
            v26 = sqrt(*v12 * *v12 + *((float *)v5 + 16) * *((float *)v5 + 16) + *((float *)v5 + 17)
                                                                               * *((float *)v5 + 17));
            if ( v26 <= 0.0 )
            {
              *v12 = v65;
              *((float *)v5 + 16) = v66;
              *((float *)v5 + 17) = v67;
            }
            else
            {
              *v12 = 1.0 / v26 * *v12;
              *((float *)v5 + 16) = 1.0 / v26 * *((float *)v5 + 16);
              *((float *)v5 + 17) = 1.0 / v26 * *((float *)v5 + 17);
            }
          }
          v27 = v74 * *((float *)v5 + 17) + v73 * *((float *)v5 + 16);
          v28 = v72 * *v12;
          *((_DWORD *)v5 + 3) = 6;
          *((float *)v5 + 2) = v27 + v28;
          *((_DWORD *)v5 + 4) = dword_6291E0 + 40 * *(_DWORD *)(dword_75AAD0[v19] + 88);
LABEL_38:
          sub_519A30(v5 + 36, v5 + 60, &v59, &v64, &v56);
          v30 = *((_DWORD *)v5 + 3);
          if ( v30 == 6 )
          {
            sub_519A30(v5 + 36, v5 + 60, &v83, &v79, v87);
            v59 = v59 - v83;
            v64 = v79 + v64;
            v56 = v56 - v87[0];
            v57 = v57 - v87[1];
            v31 = v58 - v87[2];
          }
          else
          {
            if ( v30 != 2 )
            {
LABEL_43:
              if ( v59 < 0.0 )
              {
                v32 = -1.0 / v59;
              }
              else
              {
                v32 = 0.0;
                v59 = 0.0;
              }
              v54 = -(v59 / v64);
              v55 = sqrt(v56 * v56 + v57 * v57 + v58 * v58);
              if ( v55 <= 8.0 )
                v33 = v55;
              else
                v33 = 8.0;
              if ( v33 * v32 <= 1.0 )
              {
                if ( v55 <= 8.0 )
                  v35 = v55;
                else
                  v35 = 8.0;
                v34 = v32 * v35;
              }
              else
              {
                v34 = 1.0;
              }
              if ( v55 > v34 )
              {
                v36 = v34 / v55;
                v56 = v56 * v36;
                v57 = v57 * v36;
                v58 = v36 * v58;
              }
              v37 = *((_DWORD *)v5 + 3);
              if ( v37 == 6 || v37 == 9 && (v38 = *((_DWORD *)v5 + 4)) != 0 && *(_BYTE *)(v38 + 41) )
              {
                v39 = v55 * 0.0078125 + v54 * 0.00048828125 - 0.1;
                if ( v39 > 0.0 )
                {
                  if ( v39 > 1.0 )
                    v39 = 1.0;
                  if ( v39 > *(float *)(this + 164) )
                  {
                    v40 = *v9 - *(float *)(this + 17520);
                    v41 = *((float *)v5 + 10) - *(float *)(this + 17524);
                    v42 = *((float *)v5 + 11) - *(float *)(this + 17528);
                    v84 = v42 * *(float *)(this + 17508)
                        + v41 * *(float *)(this + 17496)
                        + v40 * *(float *)(this + 17484);
                    v85 = v42 * *(float *)(this + 17512)
                        + v41 * *(float *)(this + 17500)
                        + v40 * *(float *)(this + 17488);
                    v43 = v85;
                    v44 = v42 * *(float *)(this + 17516);
                    v45 = v41 * *(float *)(this + 17504);
                    v46 = v40 * *(float *)(this + 17492);
                    *(float *)(this + 172) = v84;
                    *(float *)(this + 176) = v43;
                    v86 = v44 + v45 + v46;
                    *(float *)(this + 180) = v86;
                    *(float *)(this + 164) = v39;
                    *(float *)(this + 168) = v55 * 0.00390625 + 0.875;
                  }
                }
              }
              v47 = v54 * 0.25;
              v93 = v47 * v57;
              v94 = v47 * v58;
              v48 = v54 * *v12;
              v89 = v54 * *((float *)v5 + 16);
              v90 = v54 * *((float *)v5 + 17);
              v49 = v48 - v56 * v47;
              v88 = v89 - v93;
              v50 = v90 - v94;
              v51 = sqrt(v50 * v50 + v88 * v88 + v49 * v49);
              *((float *)v5 + 1) = v51;
              if ( v51 <= 0.0 )
              {
                *((_DWORD *)v5 + 12) = 0;
                *((_DWORD *)v5 + 13) = 0;
                *((_DWORD *)v5 + 14) = 0;
              }
              else
              {
                v52 = 1.0 / v51;
                v76 = v52 * v49;
                v53 = v88;
                *((float *)v5 + 12) = v76;
                v77 = v53 * v52;
                *((float *)v5 + 13) = v77;
                v78 = v52 * v50;
                *((float *)v5 + 14) = v78;
              }
              if ( v75 < (int)NumOfElements )
                sub_41B600(flt_629328, *(_DWORD *)this, dword_75AAD0[v75], *((float *)v5 + 1));
              result = sub_5A1290(v63);
              goto LABEL_72;
            }
            v109[0] = *v9;
            v109[1] = *((float *)v5 + 10);
            v109[2] = *((float *)v5 + 11);
            v107[0] = *v12;
            v107[1] = *((float *)v5 + 16);
            v107[2] = *((float *)v5 + 17);
            sub_57C270(v109, v107, &v95, &v96, v108);
            v59 = v59 - v95;
            v64 = v96 + v64;
            v31 = v58 - v108[2];
            v56 = v56 - v108[0];
            v57 = v57 - v108[1];
          }
          v58 = v31;
          goto LABEL_43;
        }
        sub_4DED40((float *)(v22 + 20836), *(_DWORD *)this, *(float *)(this + 17480));
      }
      else
      {
        sub_4DED40((float *)(*(_DWORD *)this + 20836), v22, *(float *)(this + 17480));
      }
      *(float *)&v22 = v55;
      *(float *)&v19 = v54;
      goto LABEL_27;
    }
    if ( v63 >= 12 || fabs(v60) <= 0.69999999 || fabs(*((float *)v5 + 16)) >= 0.80000001 )
      goto LABEL_13;
    result = sub_5A1290(v63);
    --dword_7D8358;
LABEL_72:
    v2 = v63;
    v3 = v71;
LABEL_73:
    ++v2;
    v3 += 3;
    v63 = v2;
    v71 = v3;
  }
  while ( v2 < 13 );
  return result;
}
