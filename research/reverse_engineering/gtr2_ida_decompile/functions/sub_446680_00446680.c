int __thiscall sub_446680(int this)
{
  int result; // eax
  int v3; // ecx
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  double *v7; // eax
  double v8; // st7
  double *v9; // ecx
  int v10; // ebp
  double v11; // st6
  int v12; // ebx
  double v13; // st6
  double *v14; // eax
  int v15; // ecx
  double v16; // st7
  double *v17; // ecx
  double v18; // st6
  double v19; // st6
  int v20; // ecx
  int v21; // eax
  double v22; // st7
  double *v23; // ecx
  double *v24; // eax
  double v25; // st6
  double v26; // st6
  int v27; // ecx
  int v28; // eax
  double v29; // st7
  double *v30; // eax
  double v31; // st6
  double *v32; // ecx
  double v33; // st6
  double v34; // rtt
  int v35; // edi
  int v36; // edx
  char *v37; // ebx
  int v38; // ecx
  int v39; // eax
  double v40; // st7
  double v41; // st6
  double *v42; // ecx
  double v43; // st6
  double v44; // rt1
  unsigned int v45; // [esp+14h] [ebp-24h]
  int v46; // [esp+18h] [ebp-20h]
  double *v47; // [esp+1Ch] [ebp-1Ch]
  double v48; // [esp+30h] [ebp-8h]
  double v49; // [esp+30h] [ebp-8h]
  double v50; // [esp+30h] [ebp-8h]
  double v51; // [esp+30h] [ebp-8h]
  double v52; // [esp+30h] [ebp-8h]
  double v53; // [esp+30h] [ebp-8h]
  double v54; // [esp+30h] [ebp-8h]
  double v55; // [esp+30h] [ebp-8h]
  double v56; // [esp+30h] [ebp-8h]
  double v57; // [esp+30h] [ebp-8h]

  sub_439B70((double *)this);
  sub_61E0A0(this + 6244);
  result = *(_DWORD *)(this + 6244);
  v3 = 0;
  v47 = (double *)result;
  if ( result >= 4 )
  {
    v4 = 0;
    v5 = 0;
    v45 = ((unsigned int)(result - 4) >> 2) + 1;
    v46 = 4 * v45;
    do
    {
      v6 = *(_DWORD *)(this + 6376);
      v7 = (double *)(v5 + *(_DWORD *)(this + 6248));
      v8 = *(double *)(v6 + v4) - v7[39];
      v9 = (double *)(v4 + v6);
      v10 = v4 + 144;
      v11 = v9[1] - v7[40];
      v12 = v5 + 1752;
      v48 = v9[2] - v7[41];
      v7[39] = v8 + v7[39];
      v7[40] = v11 + v7[40];
      v7[41] = v48 + v7[41];
      v13 = v9[4] - v7[43];
      v49 = v9[5] - v7[44];
      v7[42] = v9[3] - v7[42] + v7[42];
      v7[43] = v13 + v7[43];
      v7[44] = v49 + v7[44];
      v14 = (double *)(v5 + *(_DWORD *)(this + 6248) + 584);
      v15 = *(_DWORD *)(this + 6376);
      v16 = *(double *)(v4 + v15 + 48);
      v17 = (double *)(v4 + v15 + 48);
      v18 = v17[1] - *(double *)(v5 + *(_DWORD *)(this + 6248) + 904);
      v50 = v17[2] - *(double *)(v5 + *(_DWORD *)(this + 6248) + 912);
      v14[39] = v16 - *(double *)(v5 + *(_DWORD *)(this + 6248) + 896) + v14[39];
      v14[40] = v18 + v14[40];
      v14[41] = v50 + v14[41];
      v19 = v17[4] - v14[43];
      v51 = v17[5] - v14[44];
      v14[42] = v17[3] - v14[42] + v14[42];
      v14[43] = v19 + v14[43];
      v14[44] = v51 + v14[44];
      v20 = *(_DWORD *)(this + 6376);
      v21 = *(_DWORD *)(this + 6248);
      v22 = *(double *)(v20 + v4 + 144 - 48) - *(double *)(v5 + 1752 + v21 - 272);
      v23 = (double *)(v20 + v4 + 144 - 48);
      v24 = (double *)(v5 + 1752 + v21 - 584);
      v25 = v23[1] - v24[40];
      v52 = v23[2] - v24[41];
      v5 += 2336;
      v4 += 192;
      v24[39] = v22 + v24[39];
      v24[40] = v25 + v24[40];
      v24[41] = v52 + v24[41];
      v26 = v23[4] - v24[43];
      v53 = v23[5] - v24[44];
      v24[42] = v23[3] - v24[42] + v24[42];
      v24[43] = v26 + v24[43];
      v24[44] = v53 + v24[44];
      v27 = *(_DWORD *)(this + 6376);
      v28 = *(_DWORD *)(this + 6248);
      v29 = *(double *)(v27 + v10) - *(double *)(v28 + v12 + 312);
      v30 = (double *)(v12 + v28);
      v31 = *(double *)(v27 + v10 + 8);
      v32 = (double *)(v10 + v27);
      v33 = v31 - v30[40];
      v54 = v32[2] - v30[41];
      v30[39] = v29 + v30[39];
      v30[40] = v33 + v30[40];
      v30[41] = v54 + v30[41];
      v55 = v32[5] - v30[44];
      v34 = v32[4] - v30[43];
      v30[42] = v32[3] - v30[42] + v30[42];
      v30[43] = v34 + v30[43];
      v30[44] = v55 + v30[44];
      --v45;
    }
    while ( v45 );
    v3 = v46;
    result = (int)v47;
  }
  if ( v3 < result )
  {
    v35 = 48 * v3;
    v36 = 584 * v3;
    v37 = (char *)(result - v3);
    do
    {
      v38 = *(_DWORD *)(this + 6376);
      v39 = *(_DWORD *)(this + 6248);
      v40 = *(double *)(v38 + v35) - *(double *)(v39 + v36 + 312);
      result = v36 + v39;
      v41 = *(double *)(v38 + v35 + 8);
      v42 = (double *)(v35 + v38);
      v43 = v41 - *(double *)(result + 320);
      v36 += 584;
      v35 += 48;
      --v37;
      v56 = v42[2] - *(double *)(result + 328);
      *(double *)(result + 312) = v40 + *(double *)(result + 312);
      *(double *)(result + 320) = v43 + *(double *)(result + 320);
      *(double *)(result + 328) = v56 + *(double *)(result + 328);
      v57 = v42[5] - *(double *)(result + 352);
      v44 = v42[4] - *(double *)(result + 344);
      *(double *)(result + 336) = v42[3] - *(double *)(result + 336) + *(double *)(result + 336);
      *(double *)(result + 344) = v44 + *(double *)(result + 344);
      *(double *)(result + 352) = v57 + *(double *)(result + 352);
    }
    while ( v37 );
  }
  return result;
}
