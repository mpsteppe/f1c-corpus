int __stdcall sub_6DC210(__int16 *a1, __int16 *a2, int *a3, int a4, int a5, int a6)
{
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  int v14; // edx
  int v15; // ebx
  int v16; // edx
  int v17; // esi
  int v18; // ecx
  int v19; // ebx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // esi
  int v26; // edi
  int *v27; // edi
  int v28; // ecx
  int v29; // ebx
  int v30; // eax
  int v31; // ebx
  int v32; // edx
  int v33; // ebx
  int v34; // edx
  int v35; // eax
  int v36; // edx
  int v37; // esi
  int v38; // ecx
  int v39; // ebx
  int v40; // eax
  int v41; // ecx
  int v42; // eax
  int v43; // edx
  int v44; // esi
  int result; // eax
  int *v48; // [esp+14h] [ebp-3Ch]
  int *v49; // [esp+14h] [ebp-3Ch]
  int v50; // [esp+18h] [ebp-38h]
  int v51; // [esp+18h] [ebp-38h]
  int v52; // [esp+1Ch] [ebp-34h]
  int v53; // [esp+1Ch] [ebp-34h]
  int v54; // [esp+1Ch] [ebp-34h]
  int v55; // [esp+1Ch] [ebp-34h]
  int v56; // [esp+1Ch] [ebp-34h]
  int v57; // [esp+20h] [ebp-30h]
  int v58; // [esp+20h] [ebp-30h]
  int v59; // [esp+20h] [ebp-30h]
  int v60; // [esp+20h] [ebp-30h]
  int v61; // [esp+24h] [ebp-2Ch]
  int v62; // [esp+24h] [ebp-2Ch]
  int v63; // [esp+28h] [ebp-28h]
  int v64; // [esp+28h] [ebp-28h]
  int v65; // [esp+2Ch] [ebp-24h]
  int v66; // [esp+2Ch] [ebp-24h]
  int v67; // [esp+30h] [ebp-20h]
  int v68; // [esp+30h] [ebp-20h]
  int v69; // [esp+34h] [ebp-1Ch]
  int v70; // [esp+34h] [ebp-1Ch]
  int v71; // [esp+34h] [ebp-1Ch]
  int v72; // [esp+38h] [ebp-18h]
  int v73; // [esp+40h] [ebp-10h]
  int v74; // [esp+4Ch] [ebp-4h]

  v48 = a3;
  v50 = 8;
  do
  {
    v6 = a2[48] * a1[48];
    v7 = a2[16] * a1[16];
    v8 = 6270 * v7;
    v9 = 4433 * (v6 + v7);
    v52 = v9 - 15137 * v6;
    v57 = v9 + v8;
    v10 = *a2 * *a1;
    v11 = a2[32] * a1[32];
    v12 = (v10 + v11) << 13;
    v13 = (v10 - v11) << 13;
    v61 = v57 + v12;
    v63 = v52 + v13;
    v65 = v12 - v57;
    v67 = v13 - v52;
    v69 = a2[56] * a1[56];
    v53 = a2[24] * a1[24];
    v58 = a2[8] * a1[8];
    v14 = a2[40] * a1[40];
    v15 = v58 + v14;
    v16 = -20995 * (v53 + v14);
    v17 = 9633 * (v15 + v53 + v69);
    v18 = v17 - 16069 * (v53 + v69);
    v19 = v17 - 3196 * v15;
    v20 = v18 - 7373 * (v58 + v69);
    v21 = v16 + v18;
    v22 = 2446 * v69 + v20;
    v23 = 16819 * a2[40] * a1[40] + v19 + v16;
    v24 = 25172 * v53 + v21;
    v25 = 12299 * v58 + v19 - 7373 * (v58 + v69);
    v48[32] = (v65 - v22 + 1024) >> 11;
    v48[24] = (v65 + v22 + 1024) >> 11;
    v48[40] = (v67 - v23 + 1024) >> 11;
    v48[48] = (v63 - v24 + 1024) >> 11;
    v48[16] = (v67 + v23 + 1024) >> 11;
    v48[8] = (v63 + v24 + 1024) >> 11;
    v48[56] = (v61 - v25 + 1024) >> 11;
    *v48 = (v25 + v61 + 1024) >> 11;
    ++a1;
    ++v48;
    ++a2;
    --v50;
  }
  while ( v50 );
  v51 = 8;
  v74 = 0;
  v49 = a3;
  do
  {
    v26 = *(_DWORD *)(v74 + a4);
    v74 += 4;
    v27 = (int *)(a5 + v26);
    v28 = v49[6];
    v29 = v49[2];
    v30 = 6270 * v29;
    v31 = 4433 * (v28 + v29);
    v54 = v31 - 15137 * v28;
    v59 = v31 + v30;
    v32 = v49[4];
    v33 = (*v49 + v32) << 13;
    v34 = (*v49 - v32) << 13;
    v62 = v59 + v33;
    v64 = v54 + v34;
    v66 = v33 - v59;
    v68 = v34 - v54;
    v70 = v49[7];
    v55 = v49[3];
    v35 = v49[5];
    v60 = v49[1];
    v73 = 16819 * v35;
    v36 = -20995 * (v55 + v35);
    v37 = 9633 * (v60 + v35 + v55 + v70);
    v38 = v37 - 16069 * (v55 + v70);
    v39 = v37 - 3196 * (v60 + v35);
    v40 = v38 - 7373 * (v60 + v70);
    v41 = v36 + v38;
    v42 = 2446 * v70 + v40;
    v43 = v73 + v39 + v36;
    v44 = 12299 * v60 + v39 - 7373 * (v60 + v70);
    v71 = v42;
    v72 = v43;
    v56 = 25172 * v55 + v41;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((v42 + v66 + 0x20000) >> 18) & 0x3FF));
    LOBYTE(v43) = *(_BYTE *)(a6 + (((v62 - v44 + 0x20000) >> 18) & 0x3FF));
    v42 <<= 8;
    v43 <<= 8;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((v72 + v68 + 0x20000) >> 18) & 0x3FF));
    LOBYTE(v43) = *(_BYTE *)(a6 + (((v64 - v56 + 0x20000) >> 18) & 0x3FF));
    v42 <<= 8;
    v43 <<= 8;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((v56 + v64 + 0x20000) >> 18) & 0x3FF));
    LOBYTE(v43) = *(_BYTE *)(a6 + (((v68 - v72 + 0x20000) >> 18) & 0x3FF));
    v42 <<= 8;
    v43 <<= 8;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((v44 + v62 + 0x20000) >> 18) & 0x3FF));
    LOBYTE(v43) = *(_BYTE *)(a6 + (((v66 - v71 + 0x20000) >> 18) & 0x3FF));
    *v27 = v42;
    v27[1] = v43;
    v49 += 8;
    result = --v51;
  }
  while ( v51 );
  return result;
}
