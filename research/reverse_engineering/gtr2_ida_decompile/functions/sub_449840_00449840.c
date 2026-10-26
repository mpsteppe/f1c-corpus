void __thiscall sub_449840(int this, float *a2)
{
  char *v3; // edi
  float *v4; // esi
  long double v5; // st7
  double v6; // st7
  int v7; // eax
  double v8; // st7
  int v9; // ecx
  double *v10; // eax
  double v11; // st7
  int v12; // edx
  double v13; // st6
  double v14; // st7
  double v15; // st6
  float *v16; // ecx
  double *v17; // eax
  double v18; // st7
  double v19; // st7
  double v20; // st6
  double v21; // st7
  double v22; // st6
  double v23; // st7
  double v24; // st6
  float *v25; // ecx
  double v26; // st6
  double v27; // st6
  double v28; // st6
  double v29; // st5
  double v30; // st7
  double *v31; // eax
  double v32; // st4
  double v33; // st7
  double v34; // st6
  int v35; // eax
  int v36; // eax
  double *v37; // eax
  int v38; // edx
  double v39; // st7
  double v40; // st6
  int v41; // edi
  double *v42; // esi
  double *v43; // eax
  double v44; // st7
  double v45; // st6
  double v46; // st7
  double v47; // st6
  double v48; // st7
  double v49; // st6
  double v50; // st7
  double v51; // st7
  double v52; // st7
  double v53; // st7
  double v54; // st7
  float v55; // [esp+0h] [ebp-13Ch]
  float v56; // [esp+4h] [ebp-138h]
  float v57; // [esp+18h] [ebp-124h]
  float v58; // [esp+20h] [ebp-11Ch]
  int v59; // [esp+20h] [ebp-11Ch]
  float v60; // [esp+24h] [ebp-118h]
  double *v61; // [esp+24h] [ebp-118h]
  int v62; // [esp+28h] [ebp-114h] BYREF
  float v63; // [esp+2Ch] [ebp-110h]
  float v64; // [esp+30h] [ebp-10Ch]
  double v65; // [esp+34h] [ebp-108h] BYREF
  int v66[2]; // [esp+3Ch] [ebp-100h] BYREF
  double v67; // [esp+44h] [ebp-F8h]
  double v68; // [esp+4Ch] [ebp-F0h]
  int v69; // [esp+54h] [ebp-E8h] BYREF
  float v70; // [esp+58h] [ebp-E4h]
  float v71; // [esp+5Ch] [ebp-E0h]
  int v72[3]; // [esp+60h] [ebp-DCh] BYREF
  int v73[2]; // [esp+6Ch] [ebp-D0h]
  int v74[2]; // [esp+74h] [ebp-C8h] BYREF
  double v75; // [esp+7Ch] [ebp-C0h]
  double v76; // [esp+84h] [ebp-B8h]
  double v77; // [esp+94h] [ebp-A8h]
  int v78[2]; // [esp+9Ch] [ebp-A0h] BYREF
  float v79; // [esp+A4h] [ebp-98h]
  float v80; // [esp+A8h] [ebp-94h]
  float v81; // [esp+ACh] [ebp-90h]
  float v82; // [esp+B0h] [ebp-8Ch]
  int v83; // [esp+B4h] [ebp-88h]
  float v84; // [esp+B8h] [ebp-84h]
  float v85; // [esp+BCh] [ebp-80h]
  double v86[9]; // [esp+C4h] [ebp-78h] BYREF
  double v87; // [esp+11Ch] [ebp-20h]

  v3 = (char *)&unk_B66468;
  v4 = a2 + 96;
  do
  {
    if ( *((double *)v3 - 4) <= 0.0 )
    {
      v5 = 0.0;
    }
    else
    {
      v5 = 1.0 - sqrt(*((double *)v3 - 3));
      if ( v5 > 0.66000003 )
      {
        *(v4 - 1) = (v5 - 0.66000003) * 2.941176697457143;
        goto LABEL_7;
      }
    }
    *(v4 - 1) = 0.0;
LABEL_7:
    if ( v5 <= 0.38999999 )
      *v4 = 0.0;
    else
      *v4 = (v5 - 0.38999999) * 1.639344223850808;
    v6 = *v4;
    v7 = *((_DWORD *)v4 - 1);
    v4[3] = *v4;
    *((_DWORD *)v4 + 2) = v7;
    *((_DWORD *)v4 + 5) = (unsigned __int64)(v6 * 16.0);
    if ( *((double *)v3 - 4) <= 0.0 )
      v8 = 0.0;
    else
      v8 = *((double *)v3 + 38);
    v4[1] = v8;
    v4[4] = 0.0;
    if ( v8 > 0.0 )
    {
      *(v4 - 1) = 0.0;
      v4[2] = 0.0;
      v4[3] = 0.0;
    }
    v9 = *((_DWORD *)v3 + 72);
    if ( v9 )
    {
      v10 = *(double **)v3;
      v11 = *(double *)(*(_DWORD *)v3 + 24);
      v12 = *(_DWORD *)(this + 9392);
      v13 = *(double *)(*(_DWORD *)v3 + 16);
      *(float *)&v74[1] = *(double *)(*(_DWORD *)v3 + 8);
      *(float *)&v75 = v13;
      *((float *)&v75 + 1) = v11;
      v14 = v10[15];
      v15 = v10[14];
      *(float *)&v66[1] = v10[13];
      *(float *)&v67 = v15;
      *((float *)&v67 + 1) = v14;
      v57 = *(double *)(this + 128);
      sub_545B60((int)(v4 - 8), v57, (int)&v74[1], (int)&v66[1], v9, *(_DWORD *)(v12 + 22468));
    }
    v3 += 1280;
    v4 += 74;
  }
  while ( (int)v3 < (int)byte_B67868 );
  if ( *(double *)(this + 9056) == 0.0
    && *(double *)(this + 9064) == 0.0
    && *(double *)(this + 9072) == 0.0
    && *(double *)(this + 8904) <= *(double *)(this + 9048) )
  {
    v16 = a2;
    a2[41] = 0.0;
    a2[46] = 0.0;
    a2[51] = 0.0;
  }
  else
  {
    v17 = *(double **)(this + 6312);
    v18 = v17[6] * *(double *)(this + 9096) + v17[5] * *(double *)(this + 9088) + v17[4] * *(double *)(this + 9080);
    *(double *)v66 = v17[9] * *(double *)(this + 9096)
                   + v17[8] * *(double *)(this + 9088)
                   + v17[7] * *(double *)(this + 9080);
    v67 = v17[12] * *(double *)(this + 9096) + v17[11] * *(double *)(this + 9088) + v17[10] * *(double *)(this + 9080);
    v19 = v18 + v17[1];
    v20 = *(double *)v66 + v17[2];
    v67 = v67 + v17[3];
    *(float *)v72 = v19;
    *(float *)&v72[1] = v20;
    *(float *)&v72[2] = v67;
    v21 = v17[15];
    v22 = v17[14];
    *(float *)&v62 = v17[13];
    v63 = v22;
    v64 = v21;
    v23 = *(double *)(this + 8656) / *(double *)(this + 8784) * *(double *)(this + 8) * -1.0;
    if ( v23 >= -1.0 )
    {
      if ( v23 > 0.0 )
        v23 = 0.0;
    }
    else
    {
      v23 = -1.0;
    }
    if ( *(double *)(this + 9056) <= 0.0 )
      v24 = v23 * *(double *)(this + 9056);
    else
      v24 = *(double *)(this + 9056);
    v25 = a2 + 41;
    a2[41] = v24;
    if ( *(double *)(this + 9064) <= 0.0 )
      v26 = v23 * *(double *)(this + 9064);
    else
      v26 = *(double *)(this + 9064);
    a2[46] = v26;
    if ( *(double *)(this + 9072) <= 0.0 )
      v27 = v23 * *(double *)(this + 9072);
    else
      v27 = *(double *)(this + 9072);
    a2[51] = v27;
    if ( *(double *)(this + 8904) > *(double *)(this + 9048) )
    {
      v28 = (*(double *)(this + 8904) - *(double *)(this + 9048)) * 0.050000001;
      if ( v28 > 0.30000001 )
        v28 = 0.30000001;
      v29 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * v28;
      v30 = v29 - v23 * 0.2;
      if ( v30 > *v25 )
        *v25 = v30;
    }
    v56 = *(double *)(this + 128);
    sub_546440((int)v25, v56, (int)v72, (int)&v62, *(_DWORD *)(*(_DWORD *)(this + 9392) + 22468));
    v16 = a2;
  }
  v31 = *(double **)(this + 6312);
  v32 = v31[13] * v31[13] + v31[14] * v31[14] + v31[15] * v31[15];
  if ( v32 < 800.0 )
  {
    *((float *)&v68 + 1) = 1.0 - v32 * 0.00125;
    if ( *((float *)&v68 + 1) != 0.0 && *(_BYTE *)(this + 8650) && *(double *)(this + 9008) > 0.0 )
    {
      v58 = *(double *)(this + 8904) - 273.16;
      v33 = 0.0;
      if ( *(double *)(this + 8656) >= 0.0 )
      {
        if ( *(double *)(this + 8656) <= *(double *)(this + 8808) )
          v34 = *(double *)(this + 8656);
        else
          v34 = *(double *)(this + 8808);
      }
      else
      {
        v34 = 0.0;
      }
      v60 = v34;
      if ( v58 < 50.0 && v60 > 10.0 )
      {
        v33 = (50.0 - v58) * 0.050000001;
        if ( v33 > 1.0 )
          v33 = 1.0;
      }
      v16[56] = v60 / *(double *)(this + 8784) * *((float *)&v68 + 1) + v33;
      if ( v16[56] >= 0.0 )
      {
        if ( v16[56] > 1.0 )
          v16[56] = 1.0;
      }
      else
      {
        v16[56] = 0.0;
      }
      v35 = *((_DWORD *)v16 + 760);
      if ( v35 != 2 && v35 != 1 )
      {
        v36 = *(_DWORD *)(this + 6312);
        qmemcpy(v86, (const void *)(v36 + 32), sizeof(v86));
        sub_43A370((double *)(v36 + 32), (double *)(v36 + 8), (double *)(this + 6328), &v65);
        v37 = *(double **)(this + 6312);
        v38 = *(_DWORD *)(this + 9392);
        *(float *)v78 = v86[0];
        *(float *)&v78[1] = v86[1];
        v79 = v86[2];
        v80 = v86[3];
        v81 = v86[4];
        v82 = v86[5];
        *(float *)&v83 = v86[6];
        v84 = v86[7];
        v85 = v86[8];
        *(float *)&v69 = v65;
        v70 = *(double *)v66;
        v71 = v67;
        v39 = v37[15];
        v40 = v37[14];
        *(float *)&v62 = v37[13];
        v63 = v40;
        v64 = v39;
        v55 = *(double *)(this + 128);
        sub_546900((int)(a2 + 56), v55, (int)&v69, (int)v78, (int)&v62, *(_DWORD *)(v38 + 22468));
        v16 = a2;
      }
    }
  }
  v41 = 0;
  v59 = this + 6856;
  v61 = (double *)(this + 6904);
  v42 = (double *)(this + 6456);
  do
  {
    if ( *v61 < 0.0 )
    {
      if ( *(_DWORD *)v59 )
      {
        if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)v59 + 84) + 40) )
        {
          v43 = *(double **)(this + 6312);
          v44 = v43[5] * *v42 + v43[6] * v42[1] + *(v42 - 1) * v43[4];
          v45 = v43[8] * *v42 + v43[9] * v42[1] + v43[7] * *(v42 - 1);
          v87 = v43[11] * *v42 + v43[12] * v42[1] + v43[10] * *(v42 - 1);
          *(double *)v78 = v44 + v43[1];
          v46 = v45 + v43[2];
          v47 = v87 + v43[3];
          v65 = *(double *)v78 - v43[1];
          *(double *)v73 = v65;
          *(double *)v66 = v46 - v43[2];
          *(double *)v74 = *(double *)v66;
          v67 = v47 - v43[3];
          v75 = v67;
          v48 = v67 * v43[17] - *(double *)v66 * v43[18];
          v49 = v65 * v43[18] - v67 * v43[16];
          v77 = *(double *)v66 * v43[16] - v65 * v43[17];
          v76 = v48 + v43[13];
          v50 = v49 + v43[14];
          v77 = v77 + v43[15];
          if ( v76 * v76 + v50 * v50 + v77 * v77 > 25.0 )
          {
            *(float *)&v69 = v76 * 0.5;
            v70 = v50 * 0.5 + 3.0;
            v71 = v77 * 0.5;
            sub_573430(v41, 15, 10, &v69);
            v16 = a2;
          }
        }
      }
    }
    ++v41;
    v42 += 3;
    ++v61;
    v59 += 4;
  }
  while ( v41 < 12 );
  v51 = (*(double *)(this + 1880) - 673.1600000000001) * 0.005;
  if ( v51 >= 0.0 )
  {
    if ( v51 > 1.0 )
      v51 = 1.0;
  }
  else
  {
    v51 = 0.0;
  }
  v16[157] = v51;
  v52 = (*(double *)(this + 3160) - 673.1600000000001) * 0.005;
  if ( v52 >= 0.0 )
  {
    if ( v52 > 1.0 )
      v52 = 1.0;
  }
  else
  {
    v52 = 0.0;
  }
  v16[231] = v52;
  v53 = (*(double *)(this + 4440) - 673.1600000000001) * 0.005;
  if ( v53 >= 0.0 )
  {
    if ( v53 > 1.0 )
      v53 = 1.0;
  }
  else
  {
    v53 = 0.0;
  }
  v16[305] = v53;
  v54 = (*(double *)(this + 5720) - 673.1600000000001) * 0.005;
  if ( v54 >= 0.0 )
  {
    if ( v54 <= 1.0 )
      v16[379] = v54;
    else
      v16[379] = 1.0;
  }
  else
  {
    v16[379] = 0.0;
  }
}
