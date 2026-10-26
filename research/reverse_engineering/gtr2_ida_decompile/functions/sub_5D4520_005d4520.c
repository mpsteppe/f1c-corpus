void __thiscall sub_5D4520(int this, int a2, int a3, float *a4, float *a5, float *a6)
{
  int v6; // edx
  int v7; // edi
  int v8; // esi
  int *i; // eax
  int v10; // ebx
  int v11; // esi
  int v12; // eax
  int v13; // edx
  float *v14; // esi
  double v15; // st7
  int v16; // edi
  double v17; // st6
  float v18; // ecx
  float v19; // eax
  int v20; // edx
  float v21; // ecx
  float v22; // edx
  float v23; // ecx
  float v24; // eax
  float *v25; // eax
  float v26; // edx
  float v27; // ecx
  float v28; // edx
  int *v29; // eax
  int v30; // edx
  int v31; // ecx
  int v32; // edx
  float *v33; // eax
  float *v34; // eax
  int *v35; // eax
  double v36; // st7
  double v37; // st6
  double v38; // st5
  int v39; // edx
  double v40; // st4
  int v41; // ecx
  int v42; // edx
  double v43; // st3
  float *v44; // eax
  float *v45; // eax
  double v46; // st7
  double v47; // st6
  float v48; // [esp+4h] [ebp-44h]
  float v49; // [esp+8h] [ebp-40h] BYREF
  float v50; // [esp+Ch] [ebp-3Ch]
  float v51; // [esp+10h] [ebp-38h]
  float v52; // [esp+14h] [ebp-34h]
  int v53; // [esp+18h] [ebp-30h] BYREF
  float v54; // [esp+1Ch] [ebp-2Ch]
  float v55; // [esp+20h] [ebp-28h]
  float v56; // [esp+24h] [ebp-24h]
  float v57[2]; // [esp+28h] [ebp-20h] BYREF
  float v58; // [esp+30h] [ebp-18h]
  float v59; // [esp+34h] [ebp-14h]
  float v60[4]; // [esp+38h] [ebp-10h] BYREF
  int v61; // [esp+50h] [ebp+8h]

  v6 = *(_DWORD *)(this + 68);
  v7 = 0;
  v48 = (*(float *)(this + 44) - *(float *)(this + 40)) * *(float *)(this + 36) + *(float *)(this + 40);
  if ( v6 > 0 )
  {
    v8 = *(_DWORD *)(a3 + 400);
    v61 = *(_DWORD *)(this + 76);
    for ( i = (int *)(v61 + 4); ; i += 12 )
    {
      v10 = *i;
      if ( v8 == *i )
        break;
      if ( ++v7 >= v6 )
        return;
    }
    v11 = *(_DWORD *)(a2 + 444);
    v12 = 0;
    if ( v11 <= 0 )
    {
LABEL_10:
      v14 = 0;
    }
    else
    {
      v13 = *(_DWORD *)(a2 + 452);
      while ( *(_DWORD *)(*(_DWORD *)v13 + 400) != v10 )
      {
        ++v12;
        v13 += 4;
        if ( v12 >= v11 )
          goto LABEL_10;
      }
      v14 = *(float **)(*(_DWORD *)(a2 + 452) + 4 * v12);
    }
    v15 = v48 * *(float *)(48 * v7 + v61 + 24);
    v16 = 48 * v7 + v61 + 8;
    v17 = v48 * *(float *)(v16 + 20);
    v51 = v48 * *(float *)(v16 + 24);
    *a4 = v15 + *a4;
    a4[1] = v17 + a4[1];
    a4[2] = v51 + a4[2];
    v18 = v14[49];
    v19 = v14[51];
    v50 = v14[50];
    v20 = *(int *)v16;
    v49 = v18;
    v21 = v14[52];
    v53 = v20;
    v22 = *(float *)(v16 + 12);
    v52 = v21;
    v23 = *(float *)(v16 + 8);
    v56 = v22;
    v51 = v19;
    v24 = *(float *)(v16 + 4);
    v55 = v23;
    v54 = v24;
    if ( v22 * v52 + v23 * v51 + v24 * v50 + *(float *)&v53 * v49 < 0.0 )
    {
      v58 = -v51;
      v51 = v58;
      v59 = -v52;
      v52 = v59;
      v49 = -v49;
      v50 = -v50;
    }
    v25 = sub_5D43F0(&v49, v57);
    v26 = v25[1];
    v49 = *v25;
    v27 = v25[2];
    v50 = v26;
    v28 = v25[3];
    v51 = v27;
    v52 = v28;
    v29 = (int *)sub_5D43F0((float *)&v53, v57);
    v30 = v29[1];
    v53 = *v29;
    v31 = v29[2];
    v54 = *(float *)&v30;
    v32 = v29[3];
    v55 = *(float *)&v31;
    v56 = *(float *)&v32;
    v33 = sub_5D4490(v60, &v49, (float *)&v53, v48);
    v34 = sub_5D4360(v33, v57);
    v35 = (int *)sub_5D1DF0(v34);
    v36 = v14[52];
    v37 = v14[51];
    v38 = v14[50];
    v39 = v35[1];
    v40 = v14[49];
    v53 = *v35;
    v41 = v35[2];
    v54 = *(float *)&v39;
    v42 = v35[3];
    v55 = *(float *)&v41;
    v56 = *(float *)&v42;
    v43 = 1.0 / (v40 * v40 + v38 * v38 + v37 * v37 + v36 * v36);
    v49 = -(v43 * v14[49]);
    v50 = -(v43 * v14[50]);
    v51 = -(v43 * v14[51]);
    v52 = v43 * v14[52];
    v44 = sub_5D1CD0(v60, &v49, (float *)&v53);
    v45 = sub_5D1CD0(v57, a5, v44);
    *a5 = *v45;
    a5[1] = v45[1];
    a5[2] = v45[2];
    a5[3] = v45[3];
    v46 = v48 * *(float *)(v16 + 28);
    v47 = v48 * *(float *)(v16 + 32);
    v51 = v48 * *(float *)(v16 + 36);
    *a6 = v46 + *a6;
    a6[1] = v47 + a6[1];
    a6[2] = v51 + a6[2];
  }
}
