int __thiscall sub_5D4820(int this, int a2)
{
  int result; // eax
  double v3; // st7
  int v4; // ecx
  double v5; // st7
  int v6; // esi
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  float *v10; // esi
  double v11; // st7
  double v12; // st7
  double v13; // st6
  float v14; // edx
  float v15; // ecx
  int v16; // eax
  float v17; // edx
  float v18; // eax
  float v19; // edx
  float *v20; // eax
  float v21; // edx
  float v22; // ecx
  float v23; // edx
  int *v24; // eax
  float v25; // edx
  int v26; // ecx
  int v27; // edx
  float *v28; // eax
  float *v29; // eax
  float *v30; // eax
  double v31; // st7
  double v32; // st6
  double v33; // st5
  float v34; // edx
  double v35; // st4
  float v36; // ecx
  float v37; // edx
  double v38; // st3
  float *v39; // eax
  float *v40; // eax
  double v41; // st7
  double v42; // st7
  double v43; // st6
  bool v44; // zf
  float v45; // [esp+0h] [ebp-F0h]
  float v46; // [esp+4h] [ebp-ECh] BYREF
  float v47; // [esp+8h] [ebp-E8h]
  float v48; // [esp+Ch] [ebp-E4h]
  float v49; // [esp+10h] [ebp-E0h]
  int v50; // [esp+14h] [ebp-DCh]
  int v51; // [esp+18h] [ebp-D8h]
  int v52; // [esp+1Ch] [ebp-D4h] BYREF
  float v53; // [esp+20h] [ebp-D0h]
  float v54; // [esp+24h] [ebp-CCh]
  float v55; // [esp+28h] [ebp-C8h]
  int v56; // [esp+2Ch] [ebp-C4h]
  float v57; // [esp+34h] [ebp-BCh]
  float v58; // [esp+38h] [ebp-B8h]
  float v59; // [esp+40h] [ebp-B0h]
  float v60; // [esp+44h] [ebp-ACh]
  float v61[4]; // [esp+48h] [ebp-A8h] BYREF
  float v62[6]; // [esp+58h] [ebp-98h] BYREF
  float v63; // [esp+70h] [ebp-80h]
  float v64; // [esp+74h] [ebp-7Ch]
  float v65; // [esp+80h] [ebp-70h]
  float v66; // [esp+8Ch] [ebp-64h]
  float v67[4]; // [esp+90h] [ebp-60h] BYREF
  float v68[4]; // [esp+A0h] [ebp-50h] BYREF
  float v69[4]; // [esp+B0h] [ebp-40h] BYREF
  float v70[4]; // [esp+C0h] [ebp-30h] BYREF
  float v71[4]; // [esp+D0h] [ebp-20h] BYREF
  float v72[4]; // [esp+E0h] [ebp-10h] BYREF

  result = this;
  v3 = *(float *)(this + 44);
  v4 = *(_DWORD *)(this + 68);
  v5 = v3 - *(float *)(result + 40);
  v50 = result;
  v45 = v5 * *(float *)(result + 36) + *(float *)(result + 40);
  if ( v4 > 0 )
  {
    v51 = 0;
    v56 = v4;
    do
    {
      v6 = *(_DWORD *)(a2 + 444);
      v7 = 0;
      if ( v6 > 0 )
      {
        v8 = *(_DWORD *)(result + 76) + v51;
        v9 = *(_DWORD *)(a2 + 452);
        while ( *(_DWORD *)(*(_DWORD *)v9 + 400) != *(_DWORD *)(v8 + 4) )
        {
          ++v7;
          v9 += 4;
          if ( v7 >= v6 )
            goto LABEL_12;
        }
        v10 = *(float **)(*(_DWORD *)(a2 + 452) + 4 * v7);
        if ( v10 )
        {
          v11 = v45 * *(float *)(v8 + 24);
          v59 = v45 * *(float *)(v8 + 28);
          v60 = v45 * *(float *)(v8 + 32);
          v12 = v11 + v10[57];
          v13 = v59 + v10[58];
          v65 = v60 + v10[59];
          v10[59] = v65;
          v10[57] = v12;
          v10[58] = v13;
          v14 = v10[49];
          v15 = v10[51];
          v47 = v10[50];
          v16 = *(int *)(v8 + 8);
          v46 = v14;
          v17 = v10[52];
          v52 = v16;
          v18 = *(float *)(v8 + 20);
          v49 = v17;
          v19 = *(float *)(v8 + 16);
          v55 = v18;
          v54 = v19;
          v48 = v15;
          v53 = *(float *)(v8 + 12);
          if ( v18 * v49 + v19 * v15 + v53 * v47 + *(float *)&v52 * v46 < 0.0 )
          {
            v63 = -v48;
            v48 = v63;
            v64 = -v49;
            v49 = v64;
            v46 = -v46;
            v47 = -v47;
          }
          v20 = sub_5D43F0(&v46, v67);
          v21 = v20[1];
          v46 = *v20;
          v22 = v20[2];
          v47 = v21;
          v23 = v20[3];
          v48 = v22;
          v49 = v23;
          v24 = (int *)sub_5D43F0((float *)&v52, v69);
          v25 = *((float *)v24 + 1);
          v52 = *v24;
          v26 = v24[2];
          v53 = v25;
          v27 = v24[3];
          v54 = *(float *)&v26;
          v55 = *(float *)&v27;
          v28 = sub_5D4490(v68, &v46, (float *)&v52, v45);
          v29 = sub_5D4360(v28, v71);
          v30 = sub_5D1DF0(v29);
          v31 = v10[52];
          v32 = v10[51];
          v33 = v10[50];
          v34 = v30[1];
          v35 = v10[49];
          v62[0] = *v30;
          v36 = v30[2];
          v62[1] = v34;
          v37 = v30[3];
          v62[2] = v36;
          v62[3] = v37;
          v38 = 1.0 / (v35 * v35 + v33 * v33 + v32 * v32 + v31 * v31);
          v61[0] = -(v38 * v10[49]);
          v61[1] = -(v38 * v10[50]);
          v61[2] = -(v38 * v10[51]);
          v61[3] = v38 * v10[52];
          v39 = sub_5D1CD0(v70, v61, v62);
          v40 = sub_5D1CD0(v72, v10 + 53, v39);
          v10[53] = *v40;
          v10[54] = v40[1];
          v10[55] = v40[2];
          v10[56] = v40[3];
          v41 = v45 * *(float *)(v8 + 36);
          v57 = v45 * *(float *)(v8 + 40);
          v58 = v45 * *(float *)(v8 + 44);
          v42 = v41 + v10[60];
          v43 = v57 + v10[61];
          v66 = v58 + v10[62];
          v10[62] = v66;
          v10[60] = v42;
          v10[61] = v43;
        }
LABEL_12:
        result = v50;
      }
      v44 = v56 == 1;
      v51 += 48;
      --v56;
    }
    while ( !v44 );
  }
  return result;
}
