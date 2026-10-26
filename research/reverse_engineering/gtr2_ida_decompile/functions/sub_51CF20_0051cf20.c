char __stdcall sub_51CF20(int a1, int a2, float a3, int a4)
{
  double v4; // st7
  float *v5; // edx
  double v6; // st6
  double v7; // rt0
  double v8; // st6
  double v9; // st6
  double v10; // st6
  double v11; // st6
  float *v12; // ecx
  double v13; // st6
  float v15; // [esp+0h] [ebp-6Ch]
  float v16; // [esp+4h] [ebp-68h]
  float v17; // [esp+8h] [ebp-64h]
  float v18; // [esp+18h] [ebp-54h]
  float v19; // [esp+18h] [ebp-54h]
  float v20; // [esp+18h] [ebp-54h]
  float v21; // [esp+18h] [ebp-54h]
  float v22; // [esp+18h] [ebp-54h]
  float v23; // [esp+1Ch] [ebp-50h]
  float v24; // [esp+1Ch] [ebp-50h]
  float v25; // [esp+1Ch] [ebp-50h]
  float v26; // [esp+1Ch] [ebp-50h]
  float v27; // [esp+1Ch] [ebp-50h]
  float v28; // [esp+20h] [ebp-4Ch]
  float v29; // [esp+20h] [ebp-4Ch]
  float v30; // [esp+20h] [ebp-4Ch]
  float v31; // [esp+20h] [ebp-4Ch]
  float v32; // [esp+20h] [ebp-4Ch]
  float v33; // [esp+24h] [ebp-48h] BYREF
  float v34; // [esp+28h] [ebp-44h]
  float v35; // [esp+2Ch] [ebp-40h]
  float v36; // [esp+30h] [ebp-3Ch]
  float v37; // [esp+34h] [ebp-38h]
  float v38; // [esp+38h] [ebp-34h]
  float v39; // [esp+3Ch] [ebp-30h] BYREF
  float v40; // [esp+40h] [ebp-2Ch]
  float v41; // [esp+44h] [ebp-28h]
  float v42; // [esp+48h] [ebp-24h]
  float v43; // [esp+4Ch] [ebp-20h]
  float v44; // [esp+50h] [ebp-1Ch]
  float v45; // [esp+54h] [ebp-18h] BYREF
  float v46; // [esp+58h] [ebp-14h]
  float v47; // [esp+5Ch] [ebp-10h]
  float v48; // [esp+60h] [ebp-Ch]
  float v49; // [esp+64h] [ebp-8h]
  float v50; // [esp+68h] [ebp-4h]

  v4 = a3 + *(float *)(a1 + 32);
  v5 = *(float **)(a1 + 272);
  v6 = v4 * *(float *)(a1 + 36) + *(float *)(a1 + 4);
  v46 = v4 * *(float *)(a1 + 40) + *(float *)(a1 + 8);
  v7 = v6;
  v47 = v4 * *(float *)(a1 + 44) + *(float *)(a1 + 12);
  v8 = a3 + *(float *)(a2 + 32);
  v48 = v8 * *(float *)(a2 + 36) + *(float *)(a2 + 4);
  v49 = v8 * *(float *)(a2 + 40) + *(float *)(a2 + 8);
  v50 = v8 * *(float *)(a2 + 44) + *(float *)(a2 + 12);
  v9 = a3 + v5[8];
  v33 = v9 * v5[9] + v5[1];
  v34 = v9 * v5[10] + v5[2];
  v35 = v9 * v5[11] + v5[3];
  v10 = a3 + *(float *)(a1 + 32);
  v36 = v10 * *(float *)(a1 + 36) + *(float *)(a1 + 4);
  v37 = v10 * *(float *)(a1 + 40) + *(float *)(a1 + 8);
  v38 = v10 * *(float *)(a1 + 44) + *(float *)(a1 + 12);
  v11 = a3 + *(float *)(a2 + 32);
  v39 = v11 * *(float *)(a2 + 36) + *(float *)(a2 + 4);
  v40 = v11 * *(float *)(a2 + 40) + *(float *)(a2 + 8);
  v12 = *(float **)(a2 + 276);
  v41 = v11 * *(float *)(a2 + 44) + *(float *)(a2 + 12);
  v13 = a3 + v12[8];
  v42 = v13 * v12[9] + v12[1];
  v43 = v13 * v12[10] + v12[2];
  v44 = v13 * v12[11] + v12[3];
  v15 = v48 - v7;
  v16 = v49 - v46;
  v17 = v50 - v47;
  v18 = v15 * 10.0;
  v23 = v16 * 10.0;
  v28 = v17 * 10.0;
  v45 = v7 - v18;
  v46 = v46 - v23;
  v47 = v47 - v28;
  v48 = v18 + v48;
  v49 = v23 + v49;
  v50 = v28 + v50;
  v19 = v36 - v33;
  v24 = v37 - v34;
  v29 = v38 - v35;
  v20 = v19 * 10.0;
  v25 = v24 * 10.0;
  v30 = v29 * 10.0;
  v33 = v33 - v20;
  v34 = v34 - v25;
  v35 = v35 - v30;
  v36 = v20 + v36;
  v37 = v25 + v37;
  v38 = v30 + v38;
  v21 = v42 - v39;
  v26 = v43 - v40;
  v31 = v44 - v41;
  v22 = v21 * 10.0;
  v27 = v26 * 10.0;
  v32 = v31 * 10.0;
  v39 = v39 - v22;
  v40 = v40 - v27;
  v41 = v41 - v32;
  v42 = v22 + v42;
  v43 = v27 + v43;
  v44 = v32 + v44;
  sub_51CB50(&v45, &v33, a4);
  return sub_51CB50(&v45, &v39, a4 + 12);
}
