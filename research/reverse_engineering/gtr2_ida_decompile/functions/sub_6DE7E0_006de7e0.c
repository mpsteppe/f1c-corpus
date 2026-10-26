_WORD *__stdcall sub_6DE7E0(int a1)
{
  _WORD *v1; // eax
  __int16 v2; // cx
  __int16 v3; // bx
  __int16 v4; // di
  __int16 v5; // dx
  __int16 v6; // di
  __int16 v7; // cx
  __int16 v8; // si
  __int16 v9; // cx
  __int16 v10; // cx
  __int16 v11; // dx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // ecx
  __int16 v18; // bx
  __int16 v19; // di
  _WORD *result; // eax
  __int16 v21; // cx
  __int16 v22; // bx
  __int16 v23; // di
  __int16 v24; // dx
  __int16 v25; // di
  __int16 v26; // cx
  __int16 v27; // si
  __int16 v28; // cx
  __int16 v29; // cx
  __int16 v30; // dx
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // esi
  int v35; // edx
  int v36; // ecx
  __int16 v37; // bx
  __int16 v38; // di
  int v39; // [esp+Ch] [ebp-18h]
  __int16 v40; // [esp+10h] [ebp-14h]
  __int16 v41; // [esp+10h] [ebp-14h]
  __int16 v42; // [esp+14h] [ebp-10h]
  __int16 v43; // [esp+14h] [ebp-10h]
  __int16 v44; // [esp+18h] [ebp-Ch]
  __int16 v45; // [esp+18h] [ebp-Ch]
  __int16 v46; // [esp+1Ch] [ebp-8h]
  __int16 v47; // [esp+1Ch] [ebp-8h]
  __int16 v48; // [esp+20h] [ebp-4h]
  __int16 v49; // [esp+20h] [ebp-4h]
  int v50; // [esp+2Ch] [ebp+8h]

  v1 = (_WORD *)(a1 + 4);
  v39 = 8;
  do
  {
    v2 = v1[5];
    v3 = v1[4];
    v4 = *(v1 - 2);
    v5 = v4 + v2;
    v6 = v4 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v3;
    v40 = v7 - v3;
    v48 = *v1 + v1[3];
    v46 = *v1 - v1[3];
    v9 = v1[1];
    v44 = v9 + v1[2];
    v42 = v9 - v1[2];
    v10 = v44 + v5;
    v11 = v5 - v44;
    *(v1 - 2) = v10 + v8 + v48;
    v1[2] = v10 - (v8 + v48);
    v12 = (181 * (v11 + (__int16)(v8 - v48))) >> 8;
    v1[4] = v11 - v12;
    *v1 = v12 + v11;
    v13 = (__int16)(v40 + v6);
    v14 = (98 * ((__int16)(v46 + v42) - v13)) >> 8;
    v15 = v14 + ((139 * (__int16)(v46 + v42)) >> 8);
    v16 = v14 + ((334 * v13) >> 8);
    v17 = (181 * (__int16)(v40 + v46)) >> 8;
    v18 = v17 + v6;
    v19 = v6 - v17;
    v1[3] = v19 + v15;
    *(v1 - 1) = v18 + v16;
    v1[1] = v19 - v15;
    v1[5] = v18 - v16;
    v1 += 8;
    --v39;
  }
  while ( v39 );
  result = (_WORD *)(a1 + 32);
  v50 = 8;
  do
  {
    v21 = result[40];
    v22 = result[32];
    v23 = *(result - 16);
    v24 = v23 + v21;
    v25 = v23 - v21;
    v26 = *(result - 8);
    v27 = v26 + v22;
    v41 = v26 - v22;
    v49 = *result + result[24];
    v47 = *result - result[24];
    v28 = result[8];
    v45 = v28 + result[16];
    v43 = v28 - result[16];
    v29 = v45 + v24;
    v30 = v24 - v45;
    *(result - 16) = v29 + v27 + v49;
    result[16] = v29 - (v27 + v49);
    v31 = (181 * (v30 + (__int16)(v27 - v49))) >> 8;
    result[32] = v30 - v31;
    *result = v31 + v30;
    v32 = (__int16)(v41 + v25);
    v33 = (98 * ((__int16)(v43 + v47) - v32)) >> 8;
    v34 = v33 + ((139 * (__int16)(v43 + v47)) >> 8);
    v35 = v33 + ((334 * v32) >> 8);
    v36 = (181 * (__int16)(v41 + v47)) >> 8;
    v37 = v36 + v25;
    v38 = v25 - v36;
    result[24] = v38 + v34;
    *(result - 8) = v37 + v35;
    result[8] = v38 - v34;
    result[40] = v37 - v35;
    ++result;
    --v50;
  }
  while ( v50 );
  return result;
}
