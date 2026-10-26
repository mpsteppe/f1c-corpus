int __thiscall sub_5D64F0(int *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  float *v6; // ebx
  float *v7; // ebp
  float *v8; // esi
  int v9; // edi
  char *v10; // eax
  void *v11; // esi
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int result; // eax
  double v17; // st7
  int v18; // eax
  double v19; // st6
  double v20; // st5
  _DWORD *v21; // ecx
  int v22; // edx
  double v23; // st4
  int v24; // ecx
  double v25; // st3
  double v26; // st2
  float *v27; // ecx
  bool v28; // zf
  double v29; // st7
  int v30; // eax
  double v31; // st6
  double v32; // st5
  _DWORD *v33; // eax
  int v34; // esi
  int v35; // edx
  int v36; // eax
  double v37; // st4
  int v38; // ecx
  double v39; // st3
  double v40; // st2
  float *v41; // ecx
  float v42; // [esp+8h] [ebp-174h]
  float v43; // [esp+8h] [ebp-174h]
  float v44; // [esp+Ch] [ebp-170h]
  float v45; // [esp+Ch] [ebp-170h]
  float v46; // [esp+10h] [ebp-16Ch]
  float v47; // [esp+10h] [ebp-16Ch]
  float v48; // [esp+14h] [ebp-168h]
  float v49; // [esp+14h] [ebp-168h]
  float v50; // [esp+18h] [ebp-164h]
  float v51; // [esp+18h] [ebp-164h]
  float v52; // [esp+1Ch] [ebp-160h]
  float v53; // [esp+1Ch] [ebp-160h]
  int v54; // [esp+20h] [ebp-15Ch]
  int v55; // [esp+20h] [ebp-15Ch]
  int v56; // [esp+24h] [ebp-158h]
  float *v57; // [esp+28h] [ebp-154h]
  float v58; // [esp+28h] [ebp-154h]
  float v59; // [esp+28h] [ebp-154h]
  int v60; // [esp+2Ch] [ebp-150h]
  float v61; // [esp+2Ch] [ebp-150h]
  float v62; // [esp+2Ch] [ebp-150h]
  float v63; // [esp+30h] [ebp-14Ch]
  float v64; // [esp+30h] [ebp-14Ch]
  int v65; // [esp+34h] [ebp-148h]
  int v66; // [esp+38h] [ebp-144h]
  int v68; // [esp+40h] [ebp-13Ch]
  float v69; // [esp+40h] [ebp-13Ch]
  float v70; // [esp+44h] [ebp-138h]
  float v71; // [esp+48h] [ebp-134h]
  float v72; // [esp+4Ch] [ebp-130h]
  float v73; // [esp+50h] [ebp-12Ch]
  float v74; // [esp+54h] [ebp-128h]
  float v75; // [esp+58h] [ebp-124h]
  float v76; // [esp+58h] [ebp-124h]
  float v77; // [esp+60h] [ebp-11Ch]
  float v78; // [esp+60h] [ebp-11Ch]
  float v79; // [esp+64h] [ebp-118h]
  float v80; // [esp+64h] [ebp-118h]
  float v81; // [esp+6Ch] [ebp-110h]
  float v82; // [esp+6Ch] [ebp-110h]
  float v83; // [esp+78h] [ebp-104h]
  float v84; // [esp+78h] [ebp-104h]
  int v85; // [esp+7Ch] [ebp-100h]
  float v86; // [esp+80h] [ebp-FCh]
  float v87; // [esp+8Ch] [ebp-F0h]
  float v88; // [esp+8Ch] [ebp-F0h]
  float v89; // [esp+90h] [ebp-ECh]
  float v90; // [esp+98h] [ebp-E4h]
  float v91; // [esp+A4h] [ebp-D8h]
  float v92; // [esp+B0h] [ebp-CCh]
  float v93[16]; // [esp+BCh] [ebp-C0h] BYREF
  float v94[16]; // [esp+FCh] [ebp-80h] BYREF
  _BYTE v95[64]; // [esp+13Ch] [ebp-40h] BYREF

  qmemcpy(v93, (const void *)(a3 + 68), sizeof(v93));
  sub_5BE470(v93);
  v5 = (_DWORD *)this[1];
  v6 = (float *)v5[4];
  v7 = (float *)v5[5];
  qmemcpy(v94, v93, sizeof(v94));
  v8 = (float *)v5[6];
  v57 = v8;
  if ( this[3] )
  {
    v60 = 0;
    v68 = this[3];
    do
    {
      v9 = this[5] + v60;
      v10 = (char *)sub_42FBC0((char *)(*(_DWORD *)v9 + 132), v95, (float *)(*(_DWORD *)v9 + 68));
      v11 = sub_42FBC0(v10, v93, v94);
      v12 = v68;
      qmemcpy((void *)(v9 + 4), v11, 0x40u);
      v60 += 68;
      --v68;
    }
    while ( v12 != 1 );
    v8 = v57;
  }
  v13 = sub_5C2B80();
  v14 = *(_DWORD *)(v65 + 4);
  v15 = *(_DWORD *)(v14 + 24);
  result = *(_DWORD *)(v14 + 40);
  if ( v15 )
  {
    if ( result )
    {
      v56 = 0;
      v54 = result;
      do
      {
        v17 = 0.0;
        v18 = *this;
        v19 = 0.0;
        v20 = 0.0;
        v83 = 0.0;
        ++this;
        v61 = v6[1];
        v86 = v8[v56 + 3];
        v48 = *v7;
        v58 = *v6;
        v52 = v7[2];
        v63 = v6[2];
        v70 = v8[1];
        v50 = v7[1];
        v21 = (_DWORD *)(*(_DWORD *)(v13 + 12) + 8 * v18);
        v69 = *v8;
        v42 = 0.0;
        v44 = 0.0;
        v46 = 0.0;
        v72 = 0.0;
        v73 = 0.0;
        v74 = 0.0;
        v71 = v8[2];
        if ( v21[1] )
        {
          v85 = *(_DWORD *)(v65 + 20);
          v22 = *(_DWORD *)(v13 + 24) + 12 * *v21 + 4;
          v66 = v21[1];
          do
          {
            v23 = *(float *)v22;
            v24 = 68 * *(_DWORD *)(v22 + 4);
            v25 = v63 * *(float *)(v24 + v85 + 36) + v61 * *(float *)(v24 + v85 + 20);
            v26 = v58 * *(float *)(v24 + v85 + 4);
            v27 = (float *)(v85 + v24);
            v91 = v63 * v27[11] + v61 * v27[7] + v58 * v27[3] + v27[15];
            v79 = (v25 + v26 + v27[13]) * v23;
            v81 = v91 * v23;
            v17 = v17 + v79;
            v19 = v19 + (v63 * v27[10] + v61 * v27[6] + v58 * v27[2] + v27[14]) * v23;
            v20 = v20 + v81;
            v92 = v52 * v27[11] + v50 * v27[7] + v48 * v27[3];
            v89 = (v52 * v27[9] + v50 * v27[5] + v48 * v27[1]) * v23;
            v42 = v89 + v42;
            v44 = (v52 * v27[10] + v50 * v27[6] + v48 * v27[2]) * v23 + v44;
            v22 += 12;
            v28 = v66-- == 1;
            v46 = v92 * v23 + v46;
            v87 = v71 * v27[11] + v70 * v27[7] + v69 * v27[3] + v27[15];
            v75 = (v71 * v27[9] + v70 * v27[5] + v69 * v27[1] + v27[13]) * v23;
            v77 = v87 * v23;
            v72 = v75 + v72;
            v73 = (v71 * v27[10] + v70 * v27[6] + v69 * v27[2] + v27[14]) * v23 + v73;
            v74 = v77 + v74;
          }
          while ( !v28 );
          v83 = v20;
        }
        *v6 = v17;
        v6[2] = v83;
        v6[1] = v19;
        *v7 = v42;
        v7[2] = v46;
        v7[1] = v44;
        *v8 = v72;
        v8[3] = v86;
        v8[2] = v74;
        v8[1] = v73;
        v6 += 3;
        v7 += 3;
        v8 += 4;
        result = v54 - 1;
        v56 += 4;
        v54 = result;
      }
      while ( result );
    }
  }
  else if ( result )
  {
    v55 = result;
    do
    {
      v29 = 0.0;
      v30 = *this;
      v31 = 0.0;
      v32 = 0.0;
      v84 = 0.0;
      ++this;
      v59 = *v6;
      v62 = v6[1];
      v64 = v6[2];
      v49 = *v7;
      v51 = v7[1];
      v33 = (_DWORD *)(*(_DWORD *)(v13 + 12) + 8 * v30);
      v53 = v7[2];
      v43 = 0.0;
      v45 = 0.0;
      v47 = 0.0;
      if ( v33[1] )
      {
        v34 = *(_DWORD *)(v65 + 20);
        v35 = *(_DWORD *)(v13 + 24) + 12 * *v33 + 4;
        v36 = v33[1];
        do
        {
          v37 = *(float *)v35;
          v38 = 68 * *(_DWORD *)(v35 + 4);
          v39 = v64 * *(float *)(v38 + v34 + 36) + v62 * *(float *)(v38 + v34 + 20);
          v40 = v59 * *(float *)(v38 + v34 + 4);
          v41 = (float *)(v34 + v38);
          v88 = v64 * v41[11] + v62 * v41[7] + v59 * v41[3] + v41[15];
          v76 = (v39 + v40 + v41[13]) * v37;
          v78 = v88 * v37;
          v29 = v29 + v76;
          v31 = v31 + (v64 * v41[10] + v62 * v41[6] + v59 * v41[2] + v41[14]) * v37;
          v32 = v32 + v78;
          v90 = v53 * v41[11] + v51 * v41[7] + v49 * v41[3];
          v80 = (v53 * v41[9] + v51 * v41[5] + v49 * v41[1]) * v37;
          v82 = v90 * v37;
          v43 = v80 + v43;
          v45 = (v53 * v41[10] + v51 * v41[6] + v49 * v41[2]) * v37 + v45;
          v35 += 12;
          --v36;
          v47 = v82 + v47;
        }
        while ( v36 );
        v84 = v32;
      }
      *v6 = v29;
      v6[2] = v84;
      v6[1] = v31;
      v7[2] = v47;
      *v7 = v43;
      v7[1] = v45;
      v6 += 3;
      v7 += 3;
      result = v55 - 1;
      v55 = result;
    }
    while ( result );
  }
  return result;
}
