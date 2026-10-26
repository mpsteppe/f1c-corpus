char __userpurge sub_6D3320@<al>(int a1@<eax>, _DWORD *a2@<edx>, _DWORD *a3@<ecx>, int a4)
{
  _DWORD *v5; // ecx
  int v6; // edi
  int v8; // eax
  int v9; // ecx
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  _BYTE *v12; // ecx
  _BYTE *v13; // esi
  int v14; // edx
  int v15; // edi
  int v16; // edx
  int v17; // edx
  _BYTE *v18; // ecx
  int v19; // edx
  int v20; // edx
  _BYTE *v21; // esi
  int v22; // edx
  int v23; // edi
  int v24; // edx
  int v25; // ecx
  unsigned int v27; // [esp+Ch] [ebp-2Ch]
  int v28; // [esp+10h] [ebp-28h]
  int v29; // [esp+14h] [ebp-24h]
  int v30; // [esp+18h] [ebp-20h]
  int v31; // [esp+1Ch] [ebp-1Ch]
  unsigned __int8 *v32; // [esp+20h] [ebp-18h]
  unsigned int v33; // [esp+28h] [ebp-10h]
  unsigned __int8 *v34; // [esp+2Ch] [ebp-Ch]
  unsigned __int8 *v35; // [esp+30h] [ebp-8h]
  int v36; // [esp+34h] [ebp-4h]
  int v37; // [esp+34h] [ebp-4h]
  int v38; // [esp+34h] [ebp-4h]
  int v39; // [esp+34h] [ebp-4h]
  int v40; // [esp+40h] [ebp+8h]
  int v41; // [esp+40h] [ebp+8h]

  v5 = (_DWORD *)a2[114];
  v31 = v5[4];
  v28 = v5[5];
  v6 = v5[6];
  v30 = v5[7];
  v8 = a2[82];
  v9 = *a3 + 8 * a1;
  v29 = v6;
  v34 = *(unsigned __int8 **)(v9 + 4);
  v35 = *(unsigned __int8 **)v9;
  v10 = *(unsigned __int8 **)(a3[1] + 4 * a1);
  v11 = *(unsigned __int8 **)(a3[2] + 4 * a1);
  v12 = *(_BYTE **)a4;
  v13 = *(_BYTE **)(a4 + 4);
  v27 = a2[28];
  if ( v27 >> 1 )
  {
    v33 = v27 >> 1;
    do
    {
      v36 = *v10;
      v14 = *v11;
      v32 = v10 + 1;
      v40 = *(_DWORD *)(v31 + 4 * v14);
      v15 = *(_DWORD *)(v29 + 4 * v14) + *(_DWORD *)(v30 + 4 * v36);
      v37 = *(_DWORD *)(v28 + 4 * v36);
      v16 = *v35;
      v15 >>= 16;
      *v12 = *(_BYTE *)(v16 + v40 + v8);
      v12[1] = *(_BYTE *)(v16 + v15 + v8);
      v12[2] = *(_BYTE *)(v37 + v16 + v8);
      v17 = v35[1];
      v18 = v12 + 3;
      v35 += 2;
      *v18 = *(_BYTE *)(v17 + v40 + v8);
      v18[1] = *(_BYTE *)(v17 + v15 + v8);
      v18[2] = *(_BYTE *)(v37 + v17 + v8);
      v19 = *v34;
      v12 = v18 + 3;
      *v13 = *(_BYTE *)(v19 + v40 + v8);
      v13[1] = *(_BYTE *)(v19 + v15 + v8);
      v13[2] = *(_BYTE *)(v37 + v19 + v8);
      v20 = v34[1];
      v21 = v13 + 3;
      v34 += 2;
      *v21 = *(_BYTE *)(v20 + v40 + v8);
      v21[1] = *(_BYTE *)(v20 + v15 + v8);
      v10 = v32;
      ++v11;
      v21[2] = *(_BYTE *)(v37 + v20 + v8);
      v13 = v21 + 3;
      --v33;
    }
    while ( v33 );
  }
  if ( (v27 & 1) != 0 )
  {
    v22 = *v11;
    v41 = *(_DWORD *)(v31 + 4 * v22);
    v38 = *v10;
    v23 = *(_DWORD *)(v29 + 4 * v22) + *(_DWORD *)(v30 + 4 * v38);
    v39 = *(_DWORD *)(v28 + 4 * v38);
    v24 = *v35;
    *v12 = *(_BYTE *)(v24 + v41 + v8);
    v23 >>= 16;
    v12[1] = *(_BYTE *)(v24 + v23 + v8);
    v12[2] = *(_BYTE *)(v39 + v24 + v8);
    v25 = *v34;
    *v13 = *(_BYTE *)(v25 + v41 + v8);
    LOBYTE(v24) = *(_BYTE *)(v25 + v23 + v8);
    LOBYTE(v8) = *(_BYTE *)(v39 + v25 + v8);
    v13[1] = v24;
    v13[2] = v8;
  }
  return v8;
}
