_BYTE *__stdcall sub_6DBD20(int a1, int a2, __int16 *a3, int a4, int a5)
{
  __int16 *v5; // ebx
  __int16 *v6; // edi
  int v7; // edx
  int *v8; // eax
  unsigned __int16 v9; // cx
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  int v13; // esi
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // ecx
  int v21; // ecx
  int v22; // edx
  int v23; // edx
  int v24; // esi
  int v25; // ebx
  int v26; // ecx
  int v27; // edx
  int v28; // esi
  int v29; // edi
  int v30; // ebx
  int v31; // edi
  int v32; // esi
  int v33; // edi
  int v34; // esi
  int v35; // edx
  int v36; // esi
  bool v37; // zf
  int v38; // edi
  _DWORD *v39; // ecx
  _BYTE *result; // eax
  char v41; // bl
  int v42; // edx
  int v43; // esi
  int v44; // edi
  int v45; // edx
  int v46; // ebx
  int v47; // edi
  int v48; // esi
  int v49; // edi
  int v50; // edx
  int v51; // esi
  int v52; // esi
  int v53; // esi
  _BYTE v54[256]; // [esp+Ch] [ebp-134h] BYREF
  int v55; // [esp+10Ch] [ebp-34h]
  int v56; // [esp+110h] [ebp-30h]
  int v57; // [esp+114h] [ebp-2Ch]
  int v58; // [esp+118h] [ebp-28h]
  int v59; // [esp+11Ch] [ebp-24h]
  int v60; // [esp+120h] [ebp-20h]
  int v61; // [esp+124h] [ebp-1Ch]
  int v62; // [esp+128h] [ebp-18h]
  int v63; // [esp+12Ch] [ebp-14h]
  int v64; // [esp+130h] [ebp-10h]
  int v65; // [esp+134h] [ebp-Ch]
  int v66; // [esp+138h] [ebp-8h]
  int v67; // [esp+13Ch] [ebp-4h]
  int v68; // [esp+148h] [ebp+8h]
  int v69; // [esp+148h] [ebp+8h]
  int v70; // [esp+148h] [ebp+8h]
  __int16 *v71; // [esp+14Ch] [ebp+Ch]
  int v72; // [esp+14Ch] [ebp+Ch]
  int v73; // [esp+14Ch] [ebp+Ch]
  int v74; // [esp+14Ch] [ebp+Ch]
  int v75; // [esp+150h] [ebp+10h]
  int v76; // [esp+150h] [ebp+10h]
  int v77; // [esp+150h] [ebp+10h]
  int v78; // [esp+150h] [ebp+10h]
  int v79; // [esp+150h] [ebp+10h]

  v5 = a3;
  v6 = *(__int16 **)(a2 + 80);
  v7 = *(_DWORD *)(a1 + 328) + 128;
  v57 = v7;
  v67 = (int)a3;
  v71 = v6;
  v8 = (int *)v54;
  v63 = 8;
  do
  {
    v9 = v5[8];
    v60 = v9;
    if ( v9 || v5[16] || v5[24] || v5[32] || v5[40] || v5[48] || v5[56] )
    {
      v11 = v5[16] * v6[16];
      v12 = v5[48] * v6[48];
      v68 = 4433 * (v12 + v11);
      v13 = v68 - 15137 * v12;
      v75 = v68 + 6270 * v11;
      v14 = *v6 * *v5;
      v15 = v5[32];
      v64 = v13;
      v16 = v15 * v6[32];
      v17 = (v16 + v14) << 13;
      v55 = v17 + v75;
      v18 = (v14 - v16) << 13;
      v56 = v17 - v75;
      v19 = v18 + v64;
      v20 = v6[56];
      v58 = v18 - v64;
      v21 = v5[56] * v20;
      v22 = v6[40];
      v59 = v19;
      v23 = v5[40] * v22;
      v24 = v5[24] * v6[24];
      v76 = (__int16)v60 * v6[8];
      v62 = v23 + v76;
      v61 = 9633 * (v21 + v24 + v23 + v76);
      v69 = -7373 * (v21 + v76);
      v66 = -20995 * (v23 + v24);
      v65 = v61 - 16069 * (v21 + v24);
      v25 = v61 - 3196 * (v23 + v76);
      v26 = v65 + v69 + 2446 * v21;
      v27 = v66 + v25 + 16819 * v23;
      v28 = v66 + v65 + 25172 * v24;
      v29 = v55;
      v77 = v69 + v25 + 12299 * v76;
      *v8 = (v55 + v77 + 1024) >> 11;
      v8[56] = (v29 - v77 + 1024) >> 11;
      v30 = v59 + v28 + 1024;
      v31 = v59 - v28;
      v32 = v58;
      v8[48] = (v31 + 1024) >> 11;
      v33 = v32 + v27 + 1024;
      v34 = v32 - v27;
      v35 = v56;
      v8[40] = (v34 + 1024) >> 11;
      v36 = v35 + v26 + 1024;
      v8[8] = v30 >> 11;
      v5 = (__int16 *)v67;
      v8[16] = v33 >> 11;
      v6 = v71;
      v8[32] = (v35 - v26 + 1024) >> 11;
      v7 = v57;
      v8[24] = v36 >> 11;
    }
    else
    {
      v10 = 4 * *v6 * *v5;
      *v8 = v10;
      v8[8] = v10;
      v8[16] = v10;
      v8[24] = v10;
      v8[32] = v10;
      v8[40] = v10;
      v8[48] = v10;
      v8[56] = v10;
    }
    ++v5;
    ++v6;
    ++v8;
    v37 = v63 == 1;
    v67 = (int)v5;
    v71 = v6;
    --v63;
  }
  while ( !v37 );
  v38 = 0;
  v39 = v54;
  v60 = 0;
  do
  {
    result = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v38));
    v63 = v39[1];
    if ( v63 || v39[2] || v39[3] || v39[4] || v39[5] || v39[6] || v39[7] )
    {
      v42 = v39[2];
      v43 = v39[6];
      v44 = 4433 * (v43 + v42);
      v78 = v44 + 6270 * v42;
      v45 = v39[4];
      v46 = v44 - 15137 * v43;
      v47 = (v45 + *v39) << 13;
      v72 = (*v39 - v45) << 13;
      v48 = v47 + v78;
      v49 = v47 - v78;
      v59 = v46 + v72;
      v50 = v72 - v46;
      v73 = v39[5];
      v64 = v39[3];
      v58 = v50;
      v67 = v39[7];
      v61 = 9633 * (v64 + v67 + v73 + v63);
      v70 = -7373 * (v63 + v67);
      v66 = -20995 * (v64 + v73);
      v65 = v61 - 16069 * (v64 + v67);
      v62 = v61 - 3196 * (v73 + v63);
      v67 = v65 + v70 + 2446 * v67;
      v74 = v66 + v62 + 16819 * v73;
      v64 = v66 + v65 + 25172 * v64;
      v79 = v70 + v62 + 12299 * v63;
      v7 = v57;
      *result = *(_BYTE *)((((v48 + v79 + 0x20000) >> 18) & 0x3FF) + v57);
      LOBYTE(v46) = *(_BYTE *)((((v48 - v79 + 0x20000) >> 18) & 0x3FF) + v7);
      v51 = v59;
      result[7] = v46;
      result[1] = *(_BYTE *)((((v51 + v64 + 0x20000) >> 18) & 0x3FF) + v7);
      LOBYTE(v46) = *(_BYTE *)((((v51 - v64 + 0x20000) >> 18) & 0x3FF) + v7);
      v52 = v58;
      result[6] = v46;
      result[2] = *(_BYTE *)((((v52 + v74 + 0x20000) >> 18) & 0x3FF) + v7);
      LOBYTE(v46) = *(_BYTE *)((((v52 - v74 + 0x20000) >> 18) & 0x3FF) + v7);
      v53 = v67;
      result[5] = v46;
      result[3] = *(_BYTE *)((((v49 + v53 + 0x20000) >> 18) & 0x3FF) + v7);
      v41 = *(_BYTE *)((((v49 - v53 + 0x20000) >> 18) & 0x3FF) + v7);
      v38 = v60;
    }
    else
    {
      v41 = *(_BYTE *)((((*v39 + 16) >> 5) & 0x3FF) + v7);
      *result = v41;
      result[1] = v41;
      result[2] = v41;
      result[3] = v41;
      result[5] = v41;
      result[6] = v41;
      result[7] = v41;
    }
    v39 += 8;
    ++v38;
    result[4] = v41;
    v60 = v38;
  }
  while ( v38 < 8 );
  return result;
}
