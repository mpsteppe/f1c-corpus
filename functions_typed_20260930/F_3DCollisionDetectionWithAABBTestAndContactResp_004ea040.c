void __thiscall sub_4EA040(float *this, int a2, int a3, int a4)
{
  int v5; // edx
  int v6; // eax
  float *v7; // eax
  double v8; // st7
  int v9; // eax
  double *v10; // ecx
  int v11; // eax
  int v12; // ebx
  float *v13; // eax
  double v14; // st7
  double v15; // st6
  double v16; // st5
  double v17; // st7
  double v18; // st6
  double v19; // st5
  double v20; // st7
  long double v21; // st7
  char *v22; // ebx
  int v23; // ecx
  long double v24; // st6
  double v25; // st7
  double v26; // st6
  double v27; // st6
  double v29; // st6
  unsigned __int8 v30; // c0
  unsigned __int8 v31; // c2
  double v32; // st7
  double v33; // st6
  long double v34; // st6
  double v35; // st6
  double v36; // st7
  double v37; // st6
  double v38; // st5
  double v39; // st7
  double v40; // st6
  double v41; // st5
  double v42; // st4
  long double v43; // st6
  double v44; // st5
  double v45; // st7
  double v46; // st6
  long double v47; // st5
  long double v48; // st5
  float *v49; // ebx
  double v50; // st4
  float v51; // [esp+Ch] [ebp-ECh]
  float v52; // [esp+Ch] [ebp-ECh]
  float v53; // [esp+10h] [ebp-E8h]
  float v54; // [esp+10h] [ebp-E8h]
  float v55; // [esp+14h] [ebp-E4h]
  float v56; // [esp+14h] [ebp-E4h]
  float v57; // [esp+14h] [ebp-E4h]
  float v58; // [esp+18h] [ebp-E0h]
  float v59; // [esp+18h] [ebp-E0h]
  float v60; // [esp+18h] [ebp-E0h]
  float v61; // [esp+1Ch] [ebp-DCh]
  float v62; // [esp+20h] [ebp-D8h]
  float v63; // [esp+24h] [ebp-D4h]
  float v64; // [esp+28h] [ebp-D0h] BYREF
  float v65; // [esp+2Ch] [ebp-CCh]
  float v66; // [esp+30h] [ebp-C8h]
  float v67; // [esp+34h] [ebp-C4h]
  float v68; // [esp+38h] [ebp-C0h]
  float v69; // [esp+3Ch] [ebp-BCh]
  float v70; // [esp+40h] [ebp-B8h] BYREF
  float v71; // [esp+44h] [ebp-B4h]
  float v72; // [esp+48h] [ebp-B0h]
  float v73; // [esp+4Ch] [ebp-ACh] BYREF
  float v74; // [esp+50h] [ebp-A8h]
  float v75; // [esp+54h] [ebp-A4h]
  float v76; // [esp+58h] [ebp-A0h]
  float v77; // [esp+5Ch] [ebp-9Ch] BYREF
  float v78; // [esp+60h] [ebp-98h]
  float v79; // [esp+64h] [ebp-94h]
  float v80; // [esp+68h] [ebp-90h]
  int v81; // [esp+6Ch] [ebp-8Ch]
  int v82; // [esp+70h] [ebp-88h]
  int v83; // [esp+74h] [ebp-84h]
  _DWORD v84[10]; // [esp+78h] [ebp-80h]
  double v85; // [esp+A0h] [ebp-58h] BYREF
  double v86; // [esp+A8h] [ebp-50h] BYREF
  double v87[3]; // [esp+B0h] [ebp-48h] BYREF
  double v88[3]; // [esp+C8h] [ebp-30h] BYREF
  double v89[3]; // [esp+E0h] [ebp-18h] BYREF

  v5 = *(_DWORD *)(a2 + 16);
  v6 = *(_DWORD *)(a2 + 20);
  v82 = *(_DWORD *)(a2 + 12);
  v83 = v5;
  v84[0] = v6;
  v7 = (float *)sub_4EA930(&v64);
  v61 = *v7;
  v63 = v7[2];
  v62 = v7[1];
  v8 = v63 * this[3378] + v62 * this[3375] + *v7 * this[3372];
  v68 = v63 * this[3379] + v62 * this[3376] + *v7 * this[3373];
  v69 = v63 * this[3380] + v62 * this[3377] + v61 * this[3374];
  v78 = this[465] + this[459];
  v79 = this[466] + this[460];
  v80 = this[467] + this[461];
  v74 = this[468] + this[459];
  v75 = this[469] + this[460];
  v76 = this[470] + this[461];
  if ( v8 >= v78 - *(float *)(a2 + 24)
    && v8 <= *(float *)(a2 + 24) + v74
    && v79 - *(float *)(a2 + 24) <= v68
    && *(float *)(a2 + 24) + v75 >= v68
    && v80 - *(float *)(a2 + 24) <= v69
    && *(float *)(a2 + 24) + v76 >= v69 )
  {
    v9 = 0;
    v64 = *(double *)(a4 + 4);
    v10 = (double *)(a4 + 28);
    v65 = *(double *)(a4 + 12);
    v66 = *(double *)(a4 + 20);
    do
      *(float *)&v84[++v9] = *v10++;
    while ( v9 < 9 );
    v58 = 3.4028235e38;
    v11 = LinkedListIndexedAccessor_c230(0);
    v12 = 0;
    v81 = PackedArrayTotalSize(v11);
    if ( v81 > 0 )
    {
      do
      {
        v13 = (float *)PackedArrayIndexLookup(v12);
        v14 = *v13;
        v15 = v13[1];
        v16 = v13[2];
        v67 = *(float *)&v84[3] * v16 + *(float *)&v84[2] * v15 + *(float *)&v84[1] * v14;
        v68 = *(float *)&v84[6] * v16 + *(float *)&v84[5] * v15 + *(float *)&v84[4] * v14;
        v68 = v68 + v65;
        v69 = *(float *)&v84[9] * v16 + *(float *)&v84[8] * v15 + *(float *)&v84[7] * v14 + v66;
        v17 = v67 + v64 - this[3381];
        v18 = v68 - this[3382];
        v19 = v69 - this[3383];
        v51 = v19 * this[3378] + v17 * this[3372] + v18 * this[3375];
        v53 = v19 * this[3379] + v17 * this[3373] + v18 * this[3376];
        v55 = v17 * this[3374] + v18 * this[3377] + v19 * this[3380];
        if ( v51 > (double)v78
          && v51 < (double)v74
          && v53 > (double)v79
          && v53 < (double)v75
          && v55 > (double)v80
          && v55 < (double)v76 )
        {
          v20 = v55 * v55 + v53 * v53 + v51 * v51;
          if ( v20 < v58 )
          {
            v58 = v20;
            v61 = v51;
            v62 = v53;
            v63 = v55;
          }
        }
        ++v12;
      }
      while ( v12 < v81 );
      if ( v58 != 3.4028235e38 )
      {
        v21 = sqrt(v58);
        v22 = ArithmeticComparison_a010();
        *(_DWORD *)v22 = -1;
        v23 = *(_DWORD *)(a2 + 28);
        *((_DWORD *)v22 + 4) = a2;
        *((_DWORD *)v22 + 3) = v23;
        v24 = this[3804] - v21;
        if ( v24 < 0.0 )
          v24 = 0.0;
        v67 = -v61;
        v52 = v67;
        v68 = -v62;
        v69 = -v63;
        v56 = v69;
        if ( v21 <= 0.0 )
        {
          v25 = v68;
        }
        else
        {
          v59 = v24 / v21;
          v52 = v59 * v67;
          v25 = v68 * v59;
          v56 = v69 * v59;
        }
        if ( v61 >= 0.0 )
          v26 = v74 - v61;
        else
          v26 = v61 - v78;
        v64 = v26;
        if ( v63 >= 0.0 )
          v27 = v76 - v63;
        else
          v27 = v63 - v80;
        if ( v64 >= v27 )
        {
          if ( v63 >= 0.0 )
            v27 = -v27;
          v64 = 0.0;
        }
        else
        {
          v29 = v64;
          if ( !(v30 | v31) )
            v29 = -v29;
          v64 = v29;
          v27 = 0.0;
        }
        v65 = v25;
        v66 = v56 + v27;
        v32 = (v64 + v52) * 0.1;
        v54 = v65 * 0.1;
        v33 = v66 * 0.1;
        v57 = v33;
        v34 = sqrt(v33 * v57 + v54 * v54 + v32 * v32);
        *((float *)v22 + 2) = v34;
        if ( v34 <= 0.0 )
        {
          *((_DWORD *)v22 + 11) = 0;
          *((_DWORD *)v22 + 12) = 1065353216;
          *((_DWORD *)v22 + 13) = 0;
        }
        else
        {
          *((float *)v22 + 11) = v57 * this[3374] + v54 * this[3373] + v32 * this[3372];
          *((float *)v22 + 12) = v57 * this[3377] + v54 * this[3376] + v32 * this[3375];
          *((float *)v22 + 13) = v57 * this[3380] + v54 * this[3379] + v32 * this[3378];
          v35 = 1.0 / *((float *)v22 + 2);
          *((float *)v22 + 11) = v35 * *((float *)v22 + 11);
          *((float *)v22 + 12) = v35 * *((float *)v22 + 12);
          *((float *)v22 + 13) = v35 * *((float *)v22 + 13);
        }
        v36 = v61 - v32;
        v37 = v62 - v54;
        v38 = v63 - v57;
        *((float *)v22 + 5) = v38 * this[3374] + v37 * this[3373] + v36 * this[3372];
        *((float *)v22 + 6) = v38 * this[3377] + v37 * this[3376] + v36 * this[3375];
        *((float *)v22 + 7) = v38 * this[3380] + v37 * this[3379] + v36 * this[3378];
        *((float *)v22 + 5) = *((float *)v22 + 5) + this[3381];
        *((float *)v22 + 6) = this[3382] + *((float *)v22 + 6);
        *((float *)v22 + 7) = this[3383] + *((float *)v22 + 7);
        VehicleGeometryProximityTest(v22 + 20, v22 + 44, &v73, &v77, &v70);
        v89[0] = *((float *)v22 + 5);
        v89[1] = *((float *)v22 + 6);
        v89[2] = *((float *)v22 + 7);
        v87[0] = *((float *)v22 + 11);
        v87[1] = *((float *)v22 + 12);
        v87[2] = *((float *)v22 + 13);
        VehicleProjectedPosition(v89, v87, &v85, &v86, v88);
        v73 = v73 - v85;
        v77 = v86 + v77;
        v60 = v72 - v88[2];
        v70 = v70 - v88[0];
        v71 = v71 - v88[1];
        v72 = v60;
        if ( v73 > 0.0 )
          v73 = 0.0;
        v39 = -(v73 / v77);
        v40 = v60 * v60;
        v41 = v71 * v71;
        v42 = v70 * v70;
        if ( v41 + v42 + v40 > 1.0 )
        {
          v43 = 1.0 / sqrt(v40 + v41 + v42);
          v70 = v70 * v43;
          v71 = v71 * v43;
          v72 = v43 * v60;
        }
        v68 = 0.2 * v39 * v71;
        v69 = 0.2 * v39 * v72;
        v44 = v39 * *((float *)v22 + 11);
        v65 = v39 * *((float *)v22 + 12);
        v66 = v39 * *((float *)v22 + 13);
        v45 = v44 - v70 * (0.2 * v39);
        v75 = v65 - v68;
        v46 = v66 - v69;
        v47 = sqrt(v46 * v46 + v75 * v75 + v45 * v45);
        *((float *)v22 + 1) = v47;
        if ( v47 <= 0.0 )
        {
          *((_DWORD *)v22 + 8) = 0;
          *((_DWORD *)v22 + 9) = 0;
          *((_DWORD *)v22 + 10) = 0;
        }
        else
        {
          v48 = 1.0 / v47;
          v49 = (float *)(v22 + 32);
          v64 = v48 * v45;
          v50 = v75;
          *v49 = v64;
          v65 = v50 * v48;
          v49[1] = v65;
          v66 = v48 * v46;
          v49[2] = v66;
        }
      }
    }
  }
}

