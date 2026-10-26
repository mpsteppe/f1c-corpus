int __thiscall sub_5D0AA0(void *this, int a2, int a3, int a4, float a5)
{
  int v5; // eax
  double v6; // st7
  double v7; // st6
  int v8; // ecx
  double v9; // st5
  int v10; // edx
  double v11; // st4
  int v12; // eax
  double v13; // st3
  int v14; // ecx
  int result; // eax
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int v20; // edx
  int v21; // esi
  int *v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  bool v26; // cc
  int v27; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  int v32; // edx
  int v33; // eax
  float *v34; // eax
  double v35; // st7
  double v36; // st6
  int v37; // edx
  int v38; // ecx
  int v39; // edx
  int v40; // ecx
  int v41; // edx
  int v42; // ecx
  int v43; // edx
  int v44[4]; // [esp+4h] [ebp-38h] BYREF
  float v45; // [esp+14h] [ebp-28h]
  int v46; // [esp+18h] [ebp-24h]
  int v47; // [esp+1Ch] [ebp-20h]
  int v48; // [esp+20h] [ebp-1Ch]
  int v49; // [esp+24h] [ebp-18h]
  int v50; // [esp+28h] [ebp-14h]
  int v51; // [esp+2Ch] [ebp-10h]
  int v52; // [esp+30h] [ebp-Ch]
  int v53; // [esp+34h] [ebp-8h]
  int v54; // [esp+38h] [ebp-4h]

  v5 = sub_5BFD60((_DWORD *)a4, (int)this);
  if ( v5 )
  {
    v21 = *(_DWORD *)v5;
    if ( *(int *)(*(_DWORD *)v5 + 48) <= 0 )
    {
      v23 = *(_DWORD *)(v21 + 128);
      v24 = *(_DWORD *)(v21 + 132);
      v25 = *(_DWORD *)(v21 + 136);
    }
    else
    {
      v22 = sub_4058B0(*(_DWORD *)v5 + 48, v44, a5);
      v23 = *v22;
      v24 = v22[1];
      v25 = v22[2];
    }
    v49 = v23;
    v51 = v25;
    v26 = *(_DWORD *)(v21 + 16) <= 0;
    v50 = v24;
    if ( v26 )
    {
      v31 = *(_DWORD *)(v21 + 116);
      v32 = *(_DWORD *)(v21 + 120);
      v45 = *(float *)(v21 + 112);
      v33 = *(_DWORD *)(v21 + 124);
      v46 = v31;
      v47 = v32;
      v48 = v33;
    }
    else
    {
      v27 = sub_5D09B0(v21 + 16, (int)v44, a5);
      v28 = *(_DWORD *)(v27 + 4);
      v45 = *(float *)v27;
      v29 = *(_DWORD *)(v27 + 8);
      v46 = v28;
      v30 = *(_DWORD *)(v27 + 12);
      v47 = v29;
      v48 = v30;
    }
    if ( *(int *)(v21 + 80) <= 0 )
    {
      v35 = *(float *)(v21 + 140);
      v36 = *(float *)(v21 + 144);
      v54 = *(_DWORD *)(v21 + 148);
    }
    else
    {
      v34 = (float *)sub_4058B0(v21 + 80, v44, a5);
      v35 = *v34;
      v36 = v34[1];
      v54 = *((_DWORD *)v34 + 2);
    }
    result = a2;
    v37 = v46;
    *(float *)a2 = v45;
    v38 = v47;
    *(_DWORD *)(a2 + 4) = v37;
    v39 = v48;
    *(_DWORD *)(a2 + 8) = v38;
    v40 = v49;
    *(_DWORD *)(a2 + 12) = v39;
    v41 = v50;
    *(_DWORD *)(a2 + 16) = v40;
    v42 = v51;
    *(_DWORD *)(a2 + 20) = v41;
    v43 = v54;
    *(_DWORD *)(a2 + 24) = v42;
    *(float *)(a2 + 28) = v35;
    *(float *)(a2 + 32) = v36;
    *(_DWORD *)(a2 + 36) = v43;
  }
  else
  {
    v6 = *(float *)(a4 + 228);
    v7 = *(float *)(a4 + 232);
    v8 = *(_DWORD *)(a4 + 224);
    v9 = *(float *)(a4 + 212);
    v10 = *(_DWORD *)(a4 + 240);
    v11 = *(float *)(a4 + 216);
    v51 = *(_DWORD *)(a4 + 236);
    v12 = *(_DWORD *)(a4 + 244);
    v13 = *(float *)(a4 + 220);
    v48 = v8;
    v14 = *(_DWORD *)(a4 + 248);
    v53 = v12;
    result = a2;
    *(float *)a2 = v9;
    v52 = v10;
    v16 = v48;
    *(float *)(a2 + 4) = v11;
    *(_DWORD *)(a2 + 12) = v16;
    v17 = v52;
    *(float *)(a2 + 8) = v13;
    v54 = v14;
    v18 = v51;
    *(float *)(a2 + 16) = v6;
    *(_DWORD *)(a2 + 24) = v18;
    v19 = v53;
    *(float *)(a2 + 20) = v7;
    *(_DWORD *)(a2 + 28) = v17;
    v20 = v54;
    *(_DWORD *)(a2 + 32) = v19;
    *(_DWORD *)(a2 + 36) = v20;
  }
  return result;
}
