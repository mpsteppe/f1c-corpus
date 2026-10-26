__int16 *__stdcall sub_6DEA30(int a1)
{
  __int16 *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // edi
  int v13; // ecx
  int v14; // ecx
  __int16 v15; // bx
  int v16; // ecx
  __int16 *result; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // edx
  int v22; // ecx
  int v23; // esi
  int v24; // edi
  int v25; // esi
  int v26; // ecx
  int v27; // edi
  int v28; // edi
  int v29; // ecx
  int v30; // ecx
  int v31; // ebx
  int v32; // ecx
  int v33; // [esp+Ch] [ebp-1Ch]
  int v34; // [esp+10h] [ebp-18h]
  int v35; // [esp+10h] [ebp-18h]
  int v36; // [esp+14h] [ebp-14h]
  int v37; // [esp+14h] [ebp-14h]
  int v38; // [esp+18h] [ebp-10h]
  int v39; // [esp+18h] [ebp-10h]
  int v40; // [esp+18h] [ebp-10h]
  int v41; // [esp+18h] [ebp-10h]
  int v42; // [esp+18h] [ebp-10h]
  int v43; // [esp+1Ch] [ebp-Ch]
  int v44; // [esp+1Ch] [ebp-Ch]
  int v45; // [esp+1Ch] [ebp-Ch]
  int v46; // [esp+1Ch] [ebp-Ch]
  int v47; // [esp+20h] [ebp-8h]
  int v48; // [esp+20h] [ebp-8h]
  int v49; // [esp+24h] [ebp-4h]
  int v50; // [esp+24h] [ebp-4h]
  int v51; // [esp+24h] [ebp-4h]
  int v52; // [esp+24h] [ebp-4h]
  int v53; // [esp+24h] [ebp-4h]
  int v54; // [esp+30h] [ebp+8h]

  v1 = (__int16 *)(a1 + 4);
  v33 = 8;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v3 + v2;
    v5 = v3 - v2;
    v6 = v1[4];
    v38 = v4;
    v7 = *(v1 - 1);
    v8 = v7 + v6;
    v9 = v7 - v6;
    v10 = v1[3];
    v36 = v8;
    v11 = *v1;
    v43 = v10 + v11;
    v12 = v11 - v10;
    v13 = v1[1];
    v49 = v13 + v1[2];
    v47 = v13 - v1[2];
    v14 = v38;
    LOWORD(v38) = v38 + v49;
    v34 = v14 - v49;
    LOWORD(v49) = v36 + v43;
    v15 = v36 + v43;
    v44 = v36 - v43;
    *(v1 - 2) = 4 * (v38 + v15);
    v1[2] = 4 * (v38 - v49);
    v16 = 4433 * (v34 + v44);
    *v1 = (6270 * v34 + v16 + 1024) >> 11;
    v1[4] = (v16 - 15137 * v44 + 1024) >> 11;
    v39 = 9633 * (v9 + v47 + v12 + v5) - 16069 * (v9 + v47);
    v50 = 9633 * (v9 + v47 + v12 + v5) - 3196 * (v12 + v5);
    v1[5] = (v39 + 2446 * v47 - 7373 * (v5 + v47) + 1024) >> 11;
    v1[3] = (v50 + 16819 * v12 - 20995 * (v12 + v9) + 1024) >> 11;
    v1[1] = (v39 + 25172 * v9 - 20995 * (v12 + v9) + 1024) >> 11;
    *(v1 - 1) = (v50 + 12299 * v5 - 7373 * (v5 + v47) + 1024) >> 11;
    v1 += 8;
    --v33;
  }
  while ( v33 );
  result = (__int16 *)(a1 + 32);
  v54 = 8;
  do
  {
    v18 = result[40];
    v19 = *(result - 16);
    v20 = v19 + v18;
    v21 = v19 - v18;
    v22 = result[32];
    v40 = v20;
    v23 = *(result - 8);
    v24 = v23 + v22;
    v25 = v23 - v22;
    v26 = result[24];
    v37 = v24;
    v27 = *result;
    v45 = v26 + v27;
    v28 = v27 - v26;
    v29 = result[8];
    v51 = v29 + result[16];
    v48 = v29 - result[16];
    v30 = v40;
    v41 = v40 + v51;
    v35 = v30 - v51;
    v52 = v37 + v45;
    v31 = v37 + v45;
    v46 = v37 - v45;
    *(result - 16) = (v31 + v41 + 2) >> 2;
    result[16] = (v41 - v52 + 2) >> 2;
    v32 = 4433 * (v35 + v46);
    *result = (6270 * v35 + v32 + 0x4000) >> 15;
    result[32] = (v32 - 15137 * v46 + 0x4000) >> 15;
    v42 = 9633 * (v25 + v48 + v28 + v21) - 16069 * (v25 + v48);
    v53 = 9633 * (v25 + v48 + v28 + v21) - 3196 * (v28 + v21);
    result[40] = (v42 + 2446 * v48 - 7373 * (v21 + v48) + 0x4000) >> 15;
    result[24] = (v53 + 16819 * v28 - 20995 * (v28 + v25) + 0x4000) >> 15;
    result[8] = (v42 + 25172 * v25 - 20995 * (v28 + v25) + 0x4000) >> 15;
    *(result - 8) = (v53 + 12299 * v21 - 7373 * (v21 + v48) + 0x4000) >> 15;
    ++result;
    --v54;
  }
  while ( v54 );
  return result;
}
