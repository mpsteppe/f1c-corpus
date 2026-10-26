_BYTE *__cdecl sub_52804A(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // ecx
  int v6; // edx
  unsigned __int16 *v7; // esi
  int *v8; // edi
  _WORD *v9; // ecx
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // bx
  __int16 v12; // ax
  unsigned __int16 v13; // bx
  bool v14; // zf
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // esi
  int v20; // eax
  int v21; // edi
  int v22; // edx
  int v23; // edi
  int v24; // ebx
  int v25; // esi
  int v26; // esi
  int v27; // eax
  char *v28; // ecx
  int v29; // ebx
  _BYTE *result; // eax
  char v31; // bl
  int v32; // esi
  int v33; // edx
  int v34; // edi
  int v35; // edx
  int v36; // esi
  int v37; // ebx
  int v38; // esi
  int v39; // edx
  int v40; // ebx
  int v41; // edi
  int v42; // edi
  char v43; // [esp+Ch] [ebp-98h] BYREF
  _BYTE v44[96]; // [esp+2Ch] [ebp-78h] BYREF
  int v45; // [esp+8Ch] [ebp-18h]
  unsigned __int16 *v46; // [esp+90h] [ebp-14h]
  int *v47; // [esp+94h] [ebp-10h]
  int v48; // [esp+98h] [ebp-Ch]
  int v49; // [esp+9Ch] [ebp-8h]
  int v50; // [esp+A0h] [ebp-4h]
  int v51; // [esp+ACh] [ebp+8h]
  int v52; // [esp+ACh] [ebp+8h]
  __int16 v53; // [esp+B0h] [ebp+Ch]
  __int16 v54; // [esp+B0h] [ebp+Ch]
  int v55; // [esp+B0h] [ebp+Ch]
  unsigned __int16 v56; // [esp+B4h] [ebp+10h]
  __int16 v57; // [esp+B4h] [ebp+10h]
  int v58; // [esp+B4h] [ebp+10h]
  int v59; // [esp+B4h] [ebp+10h]

  v5 = *(_DWORD *)(a2 + 80);
  v6 = *(_DWORD *)(a1 + 284) + 128;
  v7 = (unsigned __int16 *)(a3 + 96);
  v8 = (int *)v44;
  v48 = v6;
  v51 = 8;
  v47 = (int *)v44;
  v46 = (unsigned __int16 *)(a3 + 96);
  v9 = (_WORD *)(v5 + 96);
  do
  {
    if ( v51 != 4 )
    {
      v56 = v7[8];
      v10 = *v7;
      v53 = *(v7 - 8);
      LOWORD(v50) = *(v7 - 24);
      v11 = *(v7 - 40);
      v45 = v10;
      v49 = v11;
      v12 = v53 | v50 | v11 | v10;
      v13 = *(v7 - 32);
      v14 = (v13 | (unsigned __int16)(v56 | v12)) == 0;
      v15 = (__int16)*(v9 - 48);
      if ( v14 )
      {
        v16 = 4 * (__int16)*(v7 - 48) * v15;
        *(v8 - 8) = v16;
        *v8 = v16;
        v8[16] = v16;
      }
      else
      {
        v17 = 15137 * (__int16)(v13 * *(v9 - 32)) - 6270 * (__int16)(v45 * *v9);
        v18 = ((__int16)*(v7 - 48) * v15) << 14;
        v19 = v17 + v18;
        v20 = v18 - v17;
        LOWORD(v17) = v56 * v9[8];
        v57 = v50 * *(v9 - 24);
        v54 = v53 * *(v9 - 8);
        v49 = (__int16)v49 * (__int16)*(v9 - 40);
        v21 = v57;
        v50 = (__int16)v49;
        v58 = (__int16)v17;
        v22 = 8697 * (__int16)v49 + 11893 * v54 - 1730 * (__int16)v17 - 17799 * v21;
        v23 = 20995 * (__int16)v49 + 7373 * v21 - 4926 * v54 - 4176 * v58;
        v24 = v19 + v23 + 2048;
        v25 = v19 - v23;
        v8 = v47;
        *(v47 - 8) = v24 >> 12;
        v8[16] = (v25 + 2048) >> 12;
        v26 = v20 + v22 + 2048;
        v27 = v20 - v22;
        v6 = v48;
        *v8 = v26 >> 12;
        v7 = v46;
        v16 = (v27 + 2048) >> 12;
      }
      v8[8] = v16;
    }
    ++v7;
    ++v8;
    ++v9;
    --v51;
    v46 = v7;
    v47 = v8;
  }
  while ( v51 > 0 );
  v52 = 0;
  v28 = &v43;
  do
  {
    v29 = *((_DWORD *)v28 + 5);
    result = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v52));
    if ( *((_DWORD *)v28 + 2)
       | *((_DWORD *)v28 + 6)
       | *((_DWORD *)v28 + 7)
       | v29
       | *((_DWORD *)v28 + 3)
       | *((_DWORD *)v28 + 1) )
    {
      v32 = 15137 * *((__int16 *)v28 + 4) - 6270 * *((__int16 *)v28 + 12);
      v33 = *(_DWORD *)v28 << 14;
      v34 = v32 + v33;
      v35 = v33 - v32;
      v50 = *((__int16 *)v28 + 2);
      v59 = *((__int16 *)v28 + 14);
      v55 = (__int16)v29;
      v36 = 8697 * v50 + 11893 * (__int16)v29 - 1730 * v59;
      v49 = v35;
      v37 = *((__int16 *)v28 + 6);
      v38 = v36 - 17799 * v37;
      v39 = 20995 * v50 + 7373 * v37 - 4926 * v55 - 4176 * v59;
      v40 = (v34 + v39 + 0x40000) >> 19;
      v41 = v34 - v39;
      v6 = v48;
      *result = *(_BYTE *)((v40 & 0x3FF) + v48);
      LOBYTE(v40) = *(_BYTE *)((((v41 + 0x40000) >> 19) & 0x3FF) + v6);
      v42 = v49;
      result[3] = v40;
      result[1] = *(_BYTE *)((((v42 + v38 + 0x40000) >> 19) & 0x3FF) + v6);
      v31 = *(_BYTE *)((((v42 - v38 + 0x40000) >> 19) & 0x3FF) + v6);
    }
    else
    {
      v31 = *(_BYTE *)((((*(_DWORD *)v28 + 16) >> 5) & 0x3FF) + v6);
      *result = v31;
      result[1] = v31;
      result[3] = v31;
    }
    v28 += 32;
    ++v52;
    result[2] = v31;
  }
  while ( v52 < 4 );
  return result;
}

