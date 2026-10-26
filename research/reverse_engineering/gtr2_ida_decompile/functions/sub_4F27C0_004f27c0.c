int __thiscall sub_4F27C0(float *this, int a2)
{
  int v3; // ecx
  int v4; // eax
  double v5; // st7
  double v6; // st6
  int v7; // eax
  _DWORD *v8; // edx
  double v9; // st7
  double v10; // st6
  float *v11; // eax
  double v12; // st7
  int v13; // edx
  int v14; // ebp
  int v15; // ecx
  float *v16; // eax
  double v17; // st7
  double v18; // st7
  double v19; // st6
  double v20; // st7
  double v21; // st7
  double v22; // st6
  double v23; // st5
  double v24; // st5
  double v25; // st4
  double v26; // st5
  bool v27; // cc
  int v28; // ecx
  float *v29; // eax
  double v30; // st7
  double v31; // st7
  double v32; // st6
  double v33; // st7
  double v34; // st6
  double v35; // st7
  double v36; // st6
  long double v37; // st5
  long double v38; // st7
  double v39; // st6
  float v40; // eax
  int result; // eax
  float v42; // edx
  float v43; // [esp+0h] [ebp-ECh]
  float v44; // [esp+14h] [ebp-D8h]
  float v45; // [esp+14h] [ebp-D8h]
  float v46; // [esp+14h] [ebp-D8h]
  float v47; // [esp+18h] [ebp-D4h]
  float v48; // [esp+18h] [ebp-D4h]
  float v49; // [esp+18h] [ebp-D4h]
  float v50; // [esp+1Ch] [ebp-D0h]
  float v51; // [esp+1Ch] [ebp-D0h]
  float v52; // [esp+20h] [ebp-CCh]
  float v53; // [esp+20h] [ebp-CCh]
  float v54; // [esp+20h] [ebp-CCh]
  float v55; // [esp+24h] [ebp-C8h]
  float v56; // [esp+24h] [ebp-C8h]
  float v57; // [esp+28h] [ebp-C4h]
  float v58; // [esp+28h] [ebp-C4h]
  int v59; // [esp+2Ch] [ebp-C0h]
  float v60; // [esp+2Ch] [ebp-C0h]
  float v61; // [esp+30h] [ebp-BCh]
  float v62; // [esp+30h] [ebp-BCh]
  float v63; // [esp+30h] [ebp-BCh]
  float v64; // [esp+34h] [ebp-B8h]
  float v65; // [esp+34h] [ebp-B8h]
  int v66; // [esp+38h] [ebp-B4h]
  float v67; // [esp+38h] [ebp-B4h]
  float v68; // [esp+3Ch] [ebp-B0h]
  float v69; // [esp+40h] [ebp-ACh]
  float v70; // [esp+44h] [ebp-A8h]
  float v71; // [esp+44h] [ebp-A8h]
  float v72; // [esp+4Ch] [ebp-A0h]
  float v73; // [esp+50h] [ebp-9Ch]
  float v74; // [esp+50h] [ebp-9Ch]
  float v75; // [esp+54h] [ebp-98h]
  float v76; // [esp+58h] [ebp-94h]
  float v77; // [esp+58h] [ebp-94h]
  float v78; // [esp+5Ch] [ebp-90h]
  float v79; // [esp+5Ch] [ebp-90h]
  int v80; // [esp+60h] [ebp-8Ch] BYREF
  float v81; // [esp+64h] [ebp-88h]
  float v82; // [esp+68h] [ebp-84h]
  float v83; // [esp+74h] [ebp-78h]
  float v84; // [esp+78h] [ebp-74h]
  int v85[3]; // [esp+7Ch] [ebp-70h] BYREF
  int v86[3]; // [esp+88h] [ebp-64h] BYREF
  int v87[3]; // [esp+94h] [ebp-58h] BYREF
  int v88[3]; // [esp+A0h] [ebp-4Ch] BYREF
  float v89[16]; // [esp+ACh] [ebp-40h] BYREF

  v3 = *((_DWORD *)this + 3);
  v4 = *(_DWORD *)(*(_DWORD *)(v3 + 232) + 4);
  v5 = *(float *)(v4 + 116);
  v6 = *(float *)(v4 + 120);
  v7 = *(_DWORD *)(v4 + 124);
  *(float *)v85 = v5;
  v85[2] = v7;
  *(float *)&v85[1] = v6;
  v8 = *(_DWORD **)(v3 + 232);
  v9 = *(float *)(*v8 + 116);
  v10 = *(float *)(*v8 + 120);
  v82 = *(float *)(*v8 + 124);
  v11 = (float *)v8[1];
  v76 = v11[30];
  v47 = v11[29] - v9;
  v78 = v11[31];
  v87[0] = (int)this[4];
  v50 = v76 - v10;
  v87[2] = (int)this[6];
  v88[0] = 0;
  v88[1] = 1065353216;
  v88[2] = 0;
  v12 = v78 - v82;
  v55 = 1.0 / sqrt(v47 * v47 + v12 * v12 + v50 * v50);
  *(float *)&v66 = v12 * v55;
  v86[2] = v66;
  v13 = *((_DWORD *)this + 5);
  *(float *)v86 = v47 * v55;
  v87[1] = v13;
  *(float *)&v86[1] = v50 * v55;
  v14 = *(_DWORD *)(v3 + 228) - 3;
  v57 = 1.0 / (double)v14;
  v59 = 0;
  v56 = 0.0;
  if ( v14 > 0 )
  {
    v84 = v57 * 0.2;
    do
    {
      sub_5A988B((int)&v80, (int)v85, (int)v86, (int)v87, (int)v88, v56);
      v43 = v84 + v56;
      v61 = *(float *)&v80;
      v64 = v81;
      v67 = v82;
      sub_5A988B((int)&v80, (int)v85, (int)v86, (int)v87, (int)v88, v43);
      v15 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 3) + 232) + 4 * v59 + 4);
      v16 = *(float **)(v15 + 388);
      v17 = v16[25];
      v16 += 17;
      v18 = (v17 + *v16) * 0.0 + v16[4];
      v19 = (v16[9] + v16[1]) * 0.0 + v16[5];
      v52 = (v16[10] + v16[2]) * 0.0 + v16[6];
      v44 = 1.0 / sqrt(v18 * v18 + v52 * v52 + v19 * v19);
      v48 = v18 * v44;
      v51 = v19 * v44;
      v53 = v52 * v44;
      v20 = *(float *)&v80 - v61;
      v72 = v81 - v64;
      v73 = v82 - v67;
      v45 = 1.0 / sqrt(v20 * v20 + v73 * v73 + v72 * v72);
      v21 = v20 * v45;
      v22 = v72 * v45;
      v23 = v73 * v45;
      v74 = v23;
      v89[2] = v74;
      v24 = v23 * v51 - v22 * v53;
      v25 = v53 * v21 - v74 * v48;
      v70 = v22 * v48 - v51 * v21;
      v46 = 1.0 / sqrt(v24 * v24 + v70 * v70 + v25 * v25);
      v68 = v24 * v46;
      v69 = v25 * v46;
      v26 = v70 * v46;
      v71 = v26;
      v75 = v26 * v22 - v69 * v74;
      v77 = v74 * v68 - v71 * v21;
      v79 = v69 * v21 - v22 * v68;
      v89[0] = v21;
      v89[1] = v22;
      v89[5] = v77;
      v89[4] = v75;
      v89[6] = v79;
      v83 = -v71;
      v89[8] = -v68;
      v89[10] = v83;
      v89[9] = -v69;
      v89[13] = v64;
      v89[12] = v61;
      v56 = v56 + v57;
      v27 = v59 + 1 < v14;
      v89[14] = v67;
      qmemcpy((void *)(v15 + 68), v89, 0x40u);
      ++v59;
    }
    while ( v27 );
  }
  v28 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 3) + 232) + 4 * *(_DWORD *)(*((_DWORD *)this + 3) + 228) - 8);
  v29 = *(float **)(v28 + 388);
  v30 = v29[25];
  v29 += 17;
  v31 = (v30 + *v29) * 0.0 + v29[4];
  v32 = (v29[9] + v29[1]) * 0.0 + v29[5];
  v54 = (v29[10] + v29[2]) * 0.0 + v29[6];
  v60 = 1.0 / sqrt(v31 * v31 + v54 * v54 + v32 * v32);
  v49 = v31 * v60;
  v33 = v54 * v60;
  v34 = v32 * v60 * 0.0;
  v58 = v34;
  v62 = v34 - v33;
  v35 = v33 * 0.0 - v49 * 0.0;
  v36 = v49 - v58;
  v37 = 1.0 / sqrt(v62 * v62 + v36 * v36 + v35 * v35);
  v63 = v62 * v37;
  v65 = v35 * v37;
  v38 = v37 * v36;
  v39 = v65 * 0.0;
  v83 = v39 - v63;
  v89[6] = v83;
  v40 = this[4];
  v89[4] = v38 - v39;
  v89[12] = v40;
  result = *((_DWORD *)this + 6);
  v89[5] = v63 * 0.0 - v38 * 0.0;
  v89[0] = 0.0;
  v89[1] = 1.0;
  v89[2] = 0.0;
  v83 = -v38;
  v89[10] = v83;
  v42 = this[5];
  v89[8] = -v63;
  v89[13] = v42;
  v89[9] = -v65;
  LODWORD(v89[14]) = result;
  qmemcpy((void *)(v28 + 68), v89, 0x40u);
  return result;
}
