void __thiscall sub_515C20(float *this, int a2, int a3, int a4)
{
  int v5; // edx
  int v6; // eax
  float *v7; // ebp
  float *v8; // eax
  double v9; // st7
  int v10; // eax
  double *v11; // ecx
  int v12; // eax
  int v13; // edi
  float *v14; // eax
  double v15; // st7
  double v16; // st6
  double v17; // st5
  double v18; // st7
  double v19; // st6
  double v20; // st5
  double v21; // st7
  long double v22; // st7
  char *v23; // edi
  int v24; // ecx
  long double v25; // st6
  double v26; // st7
  double v27; // st6
  double v28; // st6
  double v30; // st6
  unsigned __int8 v31; // c0
  unsigned __int8 v32; // c2
  float *v33; // ebx
  double v34; // st7
  double v35; // st6
  long double v36; // st6
  double v37; // st6
  double v38; // st7
  double v39; // st6
  double v40; // st5
  int v41; // ecx
  int v42; // eax
  double v43; // st7
  double v44; // st6
  double v45; // st5
  double v46; // st4
  long double v47; // st6
  double v48; // st5
  double v49; // st7
  double v50; // st6
  long double v51; // st5
  long double v52; // st5
  float *v53; // edi
  double v54; // st4
  float v55; // [esp+10h] [ebp-ECh]
  float v56; // [esp+10h] [ebp-ECh]
  float v57; // [esp+14h] [ebp-E8h]
  float v58; // [esp+14h] [ebp-E8h]
  float v59; // [esp+18h] [ebp-E4h]
  float v60; // [esp+18h] [ebp-E4h]
  float v61; // [esp+18h] [ebp-E4h]
  float v62; // [esp+1Ch] [ebp-E0h]
  float v63; // [esp+1Ch] [ebp-E0h]
  float v64; // [esp+1Ch] [ebp-E0h]
  float v65; // [esp+20h] [ebp-DCh]
  float v66; // [esp+24h] [ebp-D8h]
  float v67; // [esp+28h] [ebp-D4h]
  float v68; // [esp+2Ch] [ebp-D0h] BYREF
  float v69; // [esp+30h] [ebp-CCh]
  float v70; // [esp+34h] [ebp-C8h]
  float v71; // [esp+38h] [ebp-C4h]
  float v72; // [esp+3Ch] [ebp-C0h]
  float v73; // [esp+40h] [ebp-BCh]
  float v74; // [esp+44h] [ebp-B8h] BYREF
  float v75; // [esp+48h] [ebp-B4h]
  float v76; // [esp+4Ch] [ebp-B0h]
  float v77; // [esp+50h] [ebp-ACh] BYREF
  float v78; // [esp+54h] [ebp-A8h]
  float v79; // [esp+58h] [ebp-A4h]
  float v80; // [esp+5Ch] [ebp-A0h]
  float v81; // [esp+60h] [ebp-9Ch] BYREF
  float v82; // [esp+64h] [ebp-98h]
  float v83; // [esp+68h] [ebp-94h]
  float v84; // [esp+6Ch] [ebp-90h]
  int v85; // [esp+70h] [ebp-8Ch]
  int v86; // [esp+74h] [ebp-88h]
  int v87; // [esp+78h] [ebp-84h]
  _DWORD v88[10]; // [esp+7Ch] [ebp-80h]
  double v89; // [esp+A4h] [ebp-58h] BYREF
  double v90; // [esp+ACh] [ebp-50h] BYREF
  double v91[3]; // [esp+B4h] [ebp-48h] BYREF
  double v92[3]; // [esp+CCh] [ebp-30h] BYREF
  double v93[3]; // [esp+E4h] [ebp-18h] BYREF

  v5 = *(_DWORD *)(a2 + 20);
  v6 = *(_DWORD *)(a2 + 24);
  v86 = *(_DWORD *)(a2 + 16);
  v87 = v5;
  v7 = this + 4380;
  v88[0] = v6;
  v8 = (float *)sub_516530(&v68);
  v65 = *v8;
  v67 = v8[2];
  v66 = v8[1];
  v9 = v67 * this[4377] + v66 * this[4374] + *v8 * this[4371];
  v72 = v67 * this[4378] + v66 * this[4375] + *v8 * this[4372];
  v73 = v67 * this[4379] + v66 * this[4376] + v65 * this[4373];
  v82 = this[476] + this[470];
  v83 = this[477] + this[471];
  v84 = this[478] + this[472];
  v78 = this[479] + this[470];
  v79 = this[480] + this[471];
  v80 = this[481] + this[472];
  if ( v9 >= v82 - *(float *)(a2 + 28)
    && v9 <= *(float *)(a2 + 28) + v78
    && v83 - *(float *)(a2 + 28) <= v72
    && *(float *)(a2 + 28) + v79 >= v72
    && v84 - *(float *)(a2 + 28) <= v73
    && *(float *)(a2 + 28) + v80 >= v73 )
  {
    v10 = 0;
    v68 = *(double *)(a4 + 4);
    v11 = (double *)(a4 + 28);
    v69 = *(double *)(a4 + 12);
    v70 = *(double *)(a4 + 20);
    do
      *(float *)&v88[++v10] = *v11++;
    while ( v10 < 9 );
    v62 = 3.4028235e38;
    v12 = sub_59EFF0(0);
    v13 = 0;
    v85 = sub_59CB20(v12);
    if ( v85 > 0 )
    {
      do
      {
        v14 = (float *)sub_59CB40(v13);
        v15 = *v14;
        v16 = v14[1];
        v17 = v14[2];
        v71 = *(float *)&v88[3] * v17 + *(float *)&v88[2] * v16 + *(float *)&v88[1] * v15;
        v72 = *(float *)&v88[6] * v17 + *(float *)&v88[5] * v16 + *(float *)&v88[4] * v15;
        v72 = v72 + v69;
        v73 = *(float *)&v88[9] * v17 + *(float *)&v88[8] * v16 + *(float *)&v88[7] * v15 + v70;
        v18 = v71 + v68 - *v7;
        v19 = v72 - v7[1];
        v20 = v73 - v7[2];
        v55 = v20 * this[4377] + v18 * this[4371] + v19 * this[4374];
        v57 = v20 * this[4378] + v18 * this[4372] + v19 * this[4375];
        v59 = v18 * this[4373] + v19 * this[4376] + v20 * this[4379];
        if ( v55 > (double)v82
          && v55 < (double)v78
          && v57 > (double)v83
          && v57 < (double)v79
          && v59 > (double)v84
          && v59 < (double)v80 )
        {
          v21 = v59 * v59 + v57 * v57 + v55 * v55;
          if ( v21 < v62 )
          {
            v62 = v21;
            v65 = v55;
            v66 = v57;
            v67 = v59;
          }
        }
        ++v13;
      }
      while ( v13 < v85 );
      if ( v62 != 3.4028235e38 )
      {
        v22 = sqrt(v62);
        v23 = (char *)sub_515BF0();
        *(_DWORD *)v23 = -1;
        v24 = *(_DWORD *)(a2 + 32);
        *((_DWORD *)v23 + 4) = a2;
        *((_DWORD *)v23 + 3) = v24;
        v25 = this[4806] - v22;
        if ( v25 < 0.0 )
          v25 = 0.0;
        v71 = -v65;
        v56 = v71;
        v72 = -v66;
        v73 = -v67;
        v60 = v73;
        if ( v22 <= 0.0 )
        {
          v26 = v72;
        }
        else
        {
          v63 = v25 / v22;
          v56 = v63 * v71;
          v26 = v72 * v63;
          v60 = v73 * v63;
        }
        if ( v65 >= 0.0 )
          v27 = v78 - v65;
        else
          v27 = v65 - v82;
        v68 = v27;
        if ( v67 >= 0.0 )
          v28 = v80 - v67;
        else
          v28 = v67 - v84;
        if ( v68 >= v28 )
        {
          if ( v67 >= 0.0 )
            v28 = -v28;
          v68 = 0.0;
        }
        else
        {
          v30 = v68;
          if ( !(v31 | v32) )
            v30 = -v30;
          v68 = v30;
          v28 = 0.0;
        }
        v33 = (float *)(v23 + 60);
        v69 = v26;
        v70 = v60 + v28;
        v34 = (v68 + v56) * 0.1;
        v58 = v69 * 0.1;
        v35 = v70 * 0.1;
        v61 = v35;
        v36 = sqrt(v35 * v61 + v58 * v58 + v34 * v34);
        *((float *)v23 + 2) = v36;
        if ( v36 <= 0.0 )
        {
          *v33 = 0.0;
          *((_DWORD *)v23 + 16) = 1065353216;
          *((_DWORD *)v23 + 17) = 0;
        }
        else
        {
          *v33 = v61 * this[4373] + v58 * this[4372] + v34 * this[4371];
          *((float *)v23 + 16) = v61 * this[4376] + v58 * this[4375] + v34 * this[4374];
          *((float *)v23 + 17) = v61 * this[4379] + v58 * this[4378] + v34 * this[4377];
          v37 = 1.0 / *((float *)v23 + 2);
          *v33 = v37 * *v33;
          *((float *)v23 + 16) = v37 * *((float *)v23 + 16);
          *((float *)v23 + 17) = v37 * *((float *)v23 + 17);
        }
        v38 = v65 - v34;
        v39 = v66 - v58;
        v40 = v67 - v61;
        *((float *)v23 + 6) = v40 * this[4373] + v39 * this[4372] + v38 * this[4371];
        *((float *)v23 + 7) = v40 * this[4376] + v39 * this[4375] + v38 * this[4374];
        *((float *)v23 + 8) = v40 * this[4379] + v39 * this[4378] + v38 * this[4377];
        *((float *)v23 + 6) = *((float *)v23 + 6) + *v7;
        *((float *)v23 + 7) = v7[1] + *((float *)v23 + 7);
        *((float *)v23 + 8) = v7[2] + *((float *)v23 + 8);
        v41 = *((_DWORD *)v23 + 7);
        *((_DWORD *)v23 + 9) = *((_DWORD *)v23 + 6);
        v42 = *((_DWORD *)v23 + 8);
        *((_DWORD *)v23 + 10) = v41;
        *((_DWORD *)v23 + 11) = v42;
        sub_519A30(v23 + 36, v23 + 60, &v77, &v81, &v74);
        v93[0] = *((float *)v23 + 9);
        v93[1] = *((float *)v23 + 10);
        v93[2] = *((float *)v23 + 11);
        v91[0] = *v33;
        v91[1] = *((float *)v23 + 16);
        v91[2] = *((float *)v23 + 17);
        sub_57C270(v93, v91, &v89, &v90, v92);
        v77 = v77 - v89;
        v81 = v90 + v81;
        v64 = v76 - v92[2];
        v74 = v74 - v92[0];
        v75 = v75 - v92[1];
        v76 = v64;
        if ( v77 > 0.0 )
          v77 = 0.0;
        v43 = -(v77 / v81);
        v44 = v64 * v64;
        v45 = v75 * v75;
        v46 = v74 * v74;
        if ( v45 + v46 + v44 > 1.0 )
        {
          v47 = 1.0 / sqrt(v44 + v45 + v46);
          v74 = v74 * v47;
          v75 = v75 * v47;
          v76 = v47 * v64;
        }
        v72 = 0.2 * v43 * v75;
        v73 = 0.2 * v43 * v76;
        v48 = v43 * *v33;
        v69 = v43 * *((float *)v23 + 16);
        v70 = v43 * *((float *)v23 + 17);
        v49 = v48 - v74 * (0.2 * v43);
        v79 = v69 - v72;
        v50 = v70 - v73;
        v51 = sqrt(v50 * v50 + v79 * v79 + v49 * v49);
        *((float *)v23 + 1) = v51;
        if ( v51 <= 0.0 )
        {
          *((_DWORD *)v23 + 12) = 0;
          *((_DWORD *)v23 + 13) = 0;
          *((_DWORD *)v23 + 14) = 0;
        }
        else
        {
          v52 = 1.0 / v51;
          v53 = (float *)(v23 + 48);
          v68 = v52 * v49;
          v54 = v79;
          *v53 = v68;
          v69 = v54 * v52;
          v53[1] = v69;
          v70 = v52 * v50;
          v53[2] = v70;
        }
      }
    }
  }
}
