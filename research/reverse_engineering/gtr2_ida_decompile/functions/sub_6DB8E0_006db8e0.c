unsigned __int16 *__stdcall sub_6DB8E0(int a1, int a2, __int16 *a3, int a4, int a5)
{
  __int16 *v5; // edx
  __int16 *v6; // ecx
  int v7; // edi
  int *v8; // eax
  int v9; // esi
  int v10; // esi
  unsigned __int16 v11; // di
  char *v12; // ebx
  int v13; // edx
  unsigned __int16 v14; // si
  unsigned __int16 v15; // di
  int v16; // esi
  int v17; // edi
  int v18; // edx
  int v19; // ebx
  int v20; // esi
  int v21; // edi
  int v22; // ebx
  int v23; // edi
  int v24; // edx
  bool v25; // zf
  int v26; // esi
  unsigned __int16 *result; // eax
  _BYTE *v28; // ecx
  char v29; // dl
  unsigned __int16 v30; // bx
  int v31; // esi
  unsigned __int16 v32; // bx
  unsigned __int16 v33; // dx
  int v34; // edx
  int v35; // ebx
  int v36; // ebx
  int v37; // edx
  int v38; // ebx
  int v39; // esi
  int v40; // edx
  int v41; // ebx
  int v42; // edx
  int v43; // ebx
  int v44; // esi
  _BYTE v45[256]; // [esp+Ch] [ebp-124h] BYREF
  int v46; // [esp+10Ch] [ebp-24h]
  int v47; // [esp+110h] [ebp-20h]
  int v48; // [esp+114h] [ebp-1Ch]
  char *v49; // [esp+118h] [ebp-18h]
  int v50; // [esp+11Ch] [ebp-14h]
  int v51; // [esp+120h] [ebp-10h]
  __int16 *v52; // [esp+124h] [ebp-Ch]
  int v53; // [esp+128h] [ebp-8h]
  int v54; // [esp+12Ch] [ebp-4h]
  __int16 v55; // [esp+138h] [ebp+8h]
  int v56; // [esp+138h] [ebp+8h]
  int v57; // [esp+138h] [ebp+8h]
  __int16 v58; // [esp+13Ch] [ebp+Ch]
  int v59; // [esp+13Ch] [ebp+Ch]
  int v60; // [esp+13Ch] [ebp+Ch]
  __int16 v61; // [esp+13Ch] [ebp+Ch]
  __int16 v62; // [esp+140h] [ebp+10h]
  char *v63; // [esp+140h] [ebp+10h]
  int v64; // [esp+140h] [ebp+10h]
  int v65; // [esp+140h] [ebp+10h]
  int v66; // [esp+140h] [ebp+10h]
  int v67; // [esp+140h] [ebp+10h]

  v5 = a3;
  v6 = *(__int16 **)(a2 + 80);
  v7 = *(_DWORD *)(a1 + 328) + 128;
  v48 = v7;
  v52 = a3;
  v8 = (int *)v45;
  v51 = 8;
  do
  {
    LOWORD(v54) = v5[56];
    v62 = v5[48];
    LOWORD(v53) = v5[40];
    v55 = v5[32];
    v58 = v5[24];
    v9 = (unsigned __int16)v5[16];
    v46 = (unsigned __int16)v5[8];
    v50 = (unsigned __int16)v9;
    if ( (unsigned __int16)v54 | (unsigned __int16)(v62 | v53 | v55 | v58 | v9 | v46) )
    {
      LOWORD(v5) = *v6 * *v5;
      LOWORD(v9) = v50 * v6[16];
      v56 = (unsigned __int16)(v55 * v6[32]);
      v11 = v62 * v6[48];
      v63 = (char *)v5 + v56;
      v12 = (char *)v5 - v56;
      v47 = (int)v5 + v56 + v11 + v9;
      v13 = ((362 * ((__int16)v9 - (__int16)v11)) >> 8) - (v11 + v9);
      v50 = (int)&v63[-v11 - v9];
      v49 = &v12[v13];
      LOWORD(v12) = (_WORD)v12 - v13;
      LOWORD(v13) = v46 * v6[8];
      v59 = (unsigned __int16)(v58 * v6[24]);
      v14 = v53 * v6[40];
      v15 = v54 * v6[56];
      LOWORD(v56) = (_WORD)v12;
      LOWORD(v63) = v14 + v59;
      LOWORD(v12) = v14 - v59;
      v53 = v15 + v13;
      v60 = v14 + v59 + v53;
      v16 = (__int16)(v13 - v15);
      v17 = (473 * ((__int16)v12 + v16)) >> 8;
      v54 = v17 + ((-669 * (__int16)v12) >> 8) - v60;
      v18 = ((362 * ((__int16)v53 - (__int16)v63)) >> 8) - v54;
      v64 = v18 + ((277 * v16) >> 8) - v17;
      v19 = (__int16)v47 + (__int16)v60;
      v20 = (__int16)v54;
      v8[56] = (__int16)v47 - (__int16)v60;
      v21 = (__int16)v49;
      *v8 = v19;
      v22 = v20 + v21;
      v8[48] = v21 - v20;
      v23 = (__int16)v56 + (__int16)v18;
      v8[40] = (__int16)v56 - (__int16)v18;
      v24 = (__int16)v50;
      v8[16] = v23;
      v8[32] = (__int16)v64 + v24;
      v7 = v48;
      v8[24] = v24 - (__int16)v64;
      v5 = v52;
      v8[8] = v22;
    }
    else
    {
      v10 = *v6 * *v5;
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
    v25 = v51 == 1;
    v52 = v5;
    --v51;
  }
  while ( !v25 );
  v26 = 0;
  result = (unsigned __int16 *)v45;
  v52 = 0;
  do
  {
    v28 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v26));
    if ( *((_DWORD *)result + 1)
       | *((_DWORD *)result + 2)
       | *((_DWORD *)result + 3)
       | *((_DWORD *)result + 4)
       | *((_DWORD *)result + 5)
       | *((_DWORD *)result + 7)
       | *((_DWORD *)result + 6) )
    {
      v30 = result[8];
      v31 = *result + v30;
      v65 = *result - v30;
      v32 = result[12];
      v33 = result[4];
      v57 = v32 + v33;
      v34 = ((362 * ((__int16)v33 - (__int16)v32)) >> 8) - v57;
      v47 = v31 + v57;
      v50 = v31 - v57;
      v35 = v34 + v65;
      LOWORD(v57) = v65 - v34;
      LOWORD(v31) = result[6];
      LOWORD(v34) = result[10];
      v49 = (char *)v35;
      v36 = (unsigned __int16)v31 + (unsigned __int16)v34;
      v37 = (unsigned __int16)v34 - (unsigned __int16)v31;
      LOWORD(v31) = result[14];
      v48 = v37;
      LOWORD(v37) = result[2];
      v66 = v36;
      v38 = (unsigned __int16)v37 + (unsigned __int16)v31;
      LOWORD(v37) = v37 - v31;
      v53 = v38;
      v61 = v66 + v38;
      v51 = (473 * ((__int16)v48 + (__int16)v37)) >> 8;
      v54 = v51 + ((-669 * (__int16)v48) >> 8) - (v66 + v38);
      v39 = ((362 * ((__int16)v38 - (__int16)v66)) >> 8) - v54;
      v67 = v39 + ((277 * (__int16)v37) >> 8) - v51;
      v40 = (__int16)v47;
      *v28 = *(_BYTE *)(((((__int16)v47 + v61) >> 5) & 0x3FF) + v7);
      v41 = (__int16)v54;
      v28[7] = *(_BYTE *)((((v40 - v61) >> 5) & 0x3FF) + v7);
      v42 = (__int16)v49;
      v28[1] = *(_BYTE *)(((((__int16)v49 + v41) >> 5) & 0x3FF) + v7);
      v28[6] = *(_BYTE *)((((v42 - v41) >> 5) & 0x3FF) + v7);
      v43 = (__int16)v57 + (__int16)v39;
      LOBYTE(v42) = *(_BYTE *)(((((__int16)v57 - (__int16)v39) >> 5) & 0x3FF) + v7);
      v44 = (__int16)v50;
      LOBYTE(v43) = *(_BYTE *)(((v43 >> 5) & 0x3FF) + v7);
      v28[5] = v42;
      v28[2] = v43;
      LOBYTE(v43) = *(_BYTE *)(((((__int16)v67 + v44) >> 5) & 0x3FF) + v7);
      v29 = *(_BYTE *)((((v44 - (__int16)v67) >> 5) & 0x3FF) + v7);
      v26 = (int)v52;
      v28[4] = v43;
    }
    else
    {
      v29 = *(_BYTE *)(((*(int *)result >> 5) & 0x3FF) + v7);
      *v28 = v29;
      v28[1] = v29;
      v28[2] = v29;
      v28[4] = v29;
      v28[5] = v29;
      v28[6] = v29;
      v28[7] = v29;
    }
    result += 16;
    ++v26;
    v28[3] = v29;
    v52 = (__int16 *)v26;
  }
  while ( v26 < 8 );
  return result;
}
