__int16 __cdecl sub_52B206(_WORD *a1, _WORD *a2, _WORD *a3, int a4, int a5, int a6)
{
  __int16 v6; // bx
  __int16 v7; // dx
  __int16 v8; // ax
  __int16 v9; // bx
  __int16 v10; // bx
  __int16 v11; // ax
  __int16 v12; // bx
  __int16 v13; // cx
  __int16 v14; // ax
  __int16 v15; // bx
  __int16 v16; // dx
  __int16 v17; // bx
  __int16 v18; // cx
  __int16 v19; // ax
  int v20; // ecx
  __int16 v21; // dx
  int v22; // ebx
  __int16 v23; // dx
  __int16 v24; // dx
  _BYTE *v25; // edi
  __int16 v26; // bx
  __int16 v27; // dx
  __int16 v28; // ax
  __int16 v29; // bx
  __int16 v30; // bx
  __int16 v31; // ax
  __int16 v32; // bx
  __int16 v33; // cx
  __int16 v34; // ax
  __int16 v35; // bx
  __int16 v36; // dx
  __int16 v37; // bx
  __int16 v38; // cx
  __int16 v39; // ax
  int v40; // ecx
  __int16 v41; // dx
  int v42; // ebx
  __int16 v43; // dx
  __int16 result; // ax
  _WORD *v47; // [esp+14h] [ebp-24h]
  _WORD *v48; // [esp+14h] [ebp-24h]
  int v49; // [esp+18h] [ebp-20h]
  __int16 v50; // [esp+1Ch] [ebp-1Ch]
  __int16 v51; // [esp+1Ch] [ebp-1Ch]
  __int16 v52; // [esp+20h] [ebp-18h]
  __int16 v53; // [esp+20h] [ebp-18h]
  __int16 v54; // [esp+20h] [ebp-18h]
  __int16 v55; // [esp+20h] [ebp-18h]
  __int16 v56; // [esp+20h] [ebp-18h]
  __int16 v57; // [esp+24h] [ebp-14h]
  __int16 v58; // [esp+24h] [ebp-14h]
  __int16 v59; // [esp+28h] [ebp-10h]
  __int16 v60; // [esp+28h] [ebp-10h]
  __int16 v61; // [esp+2Ch] [ebp-Ch]
  __int16 v62; // [esp+2Ch] [ebp-Ch]
  __int16 v63; // [esp+30h] [ebp-8h]
  __int16 v64; // [esp+30h] [ebp-8h]
  __int16 v65; // [esp+30h] [ebp-8h]
  __int16 v66; // [esp+30h] [ebp-8h]
  __int16 v67; // [esp+34h] [ebp-4h]

  v47 = a2;
  v50 = 8;
  do
  {
    v6 = a3[32] * a1[32];
    v7 = a3[48] * a1[48];
    v52 = *a3 * *a1;
    v8 = v6 + v52;
    v53 = v52 - v6;
    v9 = a3[16] * a1[16];
    v57 = v7 + v9 + v8;
    v59 = v8 - (v7 + v9);
    v10 = ((362 * (__int16)(v9 - v7)) >> 8) - (v7 + v9);
    v11 = v10 + v53;
    v54 = v53 - v10;
    v61 = v11;
    v12 = a3[56] * a1[56];
    v13 = a3[24] * a1[24];
    v63 = a3[8] * a1[8];
    v14 = v12 + v63;
    v64 = v63 - v12;
    v15 = a3[40] * a1[40];
    v16 = v13 + v15;
    v17 = v15 - v13;
    v18 = v14;
    v19 = v16 + v14;
    v20 = (__int16)(v18 - v16);
    v21 = v17;
    v22 = (473 * (__int16)(v64 + v17)) >> 8;
    v23 = v22 + ((-669 * v21) >> 8) - v19;
    *v47 = v57 + v19;
    v47[56] = v57 - v19;
    v47[8] = v61 + v23;
    v47[48] = v61 - v23;
    v24 = ((362 * v20) >> 8) - v23;
    v47[16] = v54 + v24;
    v47[40] = v54 - v24;
    LOWORD(v20) = v24 + ((277 * v64) >> 8) - v22;
    v47[32] = v59 + v20;
    v47[24] = v59 - v20;
    ++a1;
    ++a3;
    ++v47;
    --v50;
  }
  while ( v50 );
  v49 = 0;
  v51 = 8;
  v48 = a2;
  do
  {
    v25 = (_BYTE *)(a5 + *(_DWORD *)(v49 + a4));
    v49 += 4;
    v26 = v48[4];
    v27 = v48[6];
    v28 = v26 + *v48;
    v55 = *v48 - v26;
    v29 = v48[2];
    v58 = v27 + v29 + v28;
    v60 = v28 - (v27 + v29);
    v30 = ((362 * (__int16)(v29 - v27)) >> 8) - (v27 + v29);
    v31 = v30 + v55;
    v56 = v55 - v30;
    v62 = v31;
    v32 = v48[7];
    v33 = v48[3];
    v65 = v48[1];
    v34 = v32 + v65;
    v66 = v65 - v32;
    v35 = v48[5];
    v36 = v33 + v35;
    v37 = v35 - v33;
    v38 = v34;
    v39 = v36 + v34;
    v40 = (__int16)(v38 - v36);
    v41 = v37;
    v42 = (473 * (__int16)(v66 + v37)) >> 8;
    v43 = v42 + ((-669 * v41) >> 8) - v39;
    LOWORD(v40) = ((362 * v40) >> 8) - v43;
    v67 = v40 + ((277 * v66) >> 8) - v42;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((__int16)(v58 - v39) >> 5) & 0x3FF));
    *v25 = *(_BYTE *)(a6 + (((__int16)(v58 + v39) >> 5) & 0x3FF));
    v25[7] = v42;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((__int16)(v62 - v43) >> 5) & 0x3FF));
    v25[1] = *(_BYTE *)(a6 + (((__int16)(v62 + v43) >> 5) & 0x3FF));
    v25[6] = v42;
    LOBYTE(v42) = *(_BYTE *)(a6 + (((__int16)(v56 - v40) >> 5) & 0x3FF));
    v25[2] = *(_BYTE *)(a6 + (((__int16)(v56 + v40) >> 5) & 0x3FF));
    v25[5] = v42;
    LOBYTE(v39) = *(_BYTE *)(a6 + (((__int16)(v60 - v67) >> 5) & 0x3FF));
    v25[4] = *(_BYTE *)(a6 + (((__int16)(v60 + v67) >> 5) & 0x3FF));
    v25[3] = v39;
    v48 += 8;
    result = --v51;
  }
  while ( v51 );
  return result;
}
