char __stdcall sub_6DCE40(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edx
  int v6; // ecx
  int *v7; // ebx
  __int16 *v8; // esi
  __int16 *v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  _BYTE *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  _BYTE *v18; // eax
  int v19; // edi
  _BYTE *v20; // eax
  int v21; // esi
  char *v22; // ecx
  int v23; // edx
  _BYTE *v24; // eax
  char v25; // dl
  int v26; // eax
  int v27; // edi
  int v28; // esi
  int v29; // edi
  int v30; // eax
  _BYTE *v31; // edx
  char v32; // bl
  int v33; // esi
  int v34; // edi
  char v35; // bl
  char v37; // [esp+Ch] [ebp-90h] BYREF
  _BYTE v38[96]; // [esp+2Ch] [ebp-70h] BYREF
  int *v39; // [esp+8Ch] [ebp-10h]
  _BYTE *v40; // [esp+90h] [ebp-Ch]
  int v41; // [esp+94h] [ebp-8h]
  int v42; // [esp+98h] [ebp-4h]
  int v43; // [esp+A4h] [ebp+8h]
  int v44; // [esp+A4h] [ebp+8h]
  int v45; // [esp+A4h] [ebp+8h]
  int v46; // [esp+A4h] [ebp+8h]
  int v47; // [esp+A8h] [ebp+Ch]
  int v48; // [esp+A8h] [ebp+Ch]
  int v49; // [esp+ACh] [ebp+10h]
  int v50; // [esp+ACh] [ebp+10h]

  v5 = *(_DWORD *)(a2 + 80);
  v6 = 8;
  v7 = (int *)v38;
  v8 = (__int16 *)(a3 + 96);
  v41 = *(_DWORD *)(a1 + 328) + 128;
  v42 = 8;
  v39 = (int *)v38;
  v9 = (__int16 *)(v5 + 96);
  do
  {
    if ( v6 != 4 )
    {
      if ( *(v8 - 40) || *(v8 - 32) || *(v8 - 24) || *(v8 - 8) || *v8 || v8[8] )
      {
        v11 = (*(v8 - 48) * *(v9 - 48)) << 14;
        v12 = 15137 * *(v8 - 32) * *(v9 - 32) - 6270 * *v9 * *v8;
        v13 = v12 + v11;
        v14 = (_BYTE *)(v11 - v12);
        v15 = v8[8];
        v40 = v14;
        v43 = v15 * v9[8];
        v49 = *(v8 - 24) * *(v9 - 24);
        v16 = *(v8 - 40) * *(v9 - 40);
        v47 = *(v8 - 8) * *(v9 - 8);
        v17 = 8697 * v16 + 11893 * v47 - 17799 * v49 - 1730 * v43;
        v7 = v39;
        v44 = 7373 * v49 + 20995 * v16 - 4926 * v47 - 4176 * v43;
        *(v39 - 8) = (v13 + v44 + 2048) >> 12;
        v18 = v40;
        v7[16] = (v13 - v44 + 2048) >> 12;
        v19 = (int)&v18[v17 + 2048];
        v20 = &v18[-v17];
        v6 = v42;
        *v7 = v19 >> 12;
        v10 = (int)(v20 + 2048) >> 12;
      }
      else
      {
        v10 = 4 * *(v8 - 48) * *(v9 - 48);
        *(v7 - 8) = v10;
        *v7 = v10;
        v7[16] = v10;
      }
      v7[8] = v10;
    }
    ++v7;
    ++v8;
    ++v9;
    --v6;
    v39 = v7;
    v42 = v6;
  }
  while ( v6 > 0 );
  v21 = 0;
  v22 = &v37;
  v42 = 0;
  do
  {
    v23 = *((_DWORD *)v22 + 1);
    v24 = (_BYTE *)(a5 + *(_DWORD *)(a4 + 4 * v21));
    v40 = v24;
    if ( v23
      || *((_DWORD *)v22 + 2)
      || *((_DWORD *)v22 + 3)
      || *((_DWORD *)v22 + 5)
      || *((_DWORD *)v22 + 6)
      || *((_DWORD *)v22 + 7) )
    {
      v26 = 15137 * *((_DWORD *)v22 + 2) - 6270 * *((_DWORD *)v22 + 6);
      v50 = *((_DWORD *)v22 + 3);
      v27 = *(_DWORD *)v22 << 14;
      v28 = v26 + v27;
      v29 = v27 - v26;
      v45 = *((_DWORD *)v22 + 7);
      v48 = *((_DWORD *)v22 + 5);
      v30 = 8697 * v23 + 11893 * v48 - 17799 * v50 - 1730 * v45;
      v46 = 7373 * v50 + 20995 * v23 - 4926 * v48 - 4176 * v45;
      v31 = v40;
      *v40 = *(_BYTE *)((((v28 + v46 + 0x40000) >> 19) & 0x3FF) + v41);
      v32 = *(_BYTE *)((((v28 - v46 + 0x40000) >> 19) & 0x3FF) + v41);
      v33 = v29 + v30 + 0x40000;
      v34 = v29 - v30;
      v24 = (_BYTE *)v41;
      v31[3] = v32;
      v35 = *(_BYTE *)(((v33 >> 19) & 0x3FF) + v41);
      v21 = v42;
      LOBYTE(v24) = v24[((v34 + 0x40000) >> 19) & 0x3FF];
      v31[1] = v35;
      v31[2] = (_BYTE)v24;
    }
    else
    {
      v25 = *(_BYTE *)((((*(_DWORD *)v22 + 16) >> 5) & 0x3FF) + v41);
      *v24 = v25;
      v24[1] = v25;
      v24[2] = v25;
      v24[3] = v25;
    }
    v22 += 32;
    v42 = ++v21;
  }
  while ( v21 < 4 );
  return (char)v24;
}
