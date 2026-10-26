char __cdecl sub_559F0F(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // ecx
  int v5; // eax
  unsigned __int8 **v6; // edx
  unsigned __int8 *v7; // edi
  int v8; // esi
  int v9; // ecx
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // edi
  _BYTE *v12; // ecx
  _BYTE *v13; // esi
  int v14; // ebx
  int v15; // edx
  int v16; // edi
  int v17; // edx
  int v18; // edx
  _BYTE *v19; // ecx
  int v20; // edx
  int v21; // edx
  _BYTE *v22; // esi
  int v23; // ebx
  int v24; // edx
  int v25; // edi
  int v26; // edx
  int v27; // ecx
  int v29; // [esp+Ch] [ebp-20h]
  int v30; // [esp+10h] [ebp-1Ch]
  int v31; // [esp+14h] [ebp-18h]
  int v32; // [esp+18h] [ebp-14h]
  unsigned __int8 *v33; // [esp+1Ch] [ebp-10h]
  unsigned __int8 *v34; // [esp+20h] [ebp-Ch]
  int v35; // [esp+24h] [ebp-8h]
  int v36; // [esp+28h] [ebp-4h]
  int v37; // [esp+28h] [ebp-4h]
  unsigned __int8 *v38; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v39; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v40; // [esp+3Ch] [ebp+10h]
  unsigned __int8 *v41; // [esp+3Ch] [ebp+10h]
  int v42; // [esp+40h] [ebp+14h]
  int v43; // [esp+40h] [ebp+14h]

  v4 = (_DWORD *)a1[103];
  v5 = a1[71];
  v32 = v4[4];
  v29 = v4[5];
  v30 = v4[6];
  v31 = v4[7];
  v6 = (unsigned __int8 **)(*a2 + 8 * a3);
  v7 = *v6;
  v8 = 4 * a3;
  v40 = v6[1];
  v9 = a2[2];
  v10 = *(unsigned __int8 **)(v8 + a2[1]);
  v38 = v7;
  v11 = *(unsigned __int8 **)(v8 + v9);
  v12 = *(_BYTE **)a4;
  v13 = *(_BYTE **)(a4 + 4);
  if ( a1[23] >> 1 )
  {
    v35 = a1[23] >> 1;
    do
    {
      v14 = *v10;
      v34 = v10 + 1;
      v15 = 4 * *v11;
      v33 = v11 + 1;
      v42 = *(_DWORD *)(v15 + v32);
      v16 = *(_DWORD *)(v15 + v30) + *(_DWORD *)(4 * v14 + v31);
      v36 = *(_DWORD *)(4 * v14 + v29);
      v17 = *v38;
      *v12 = *(_BYTE *)(v17 + v42 + v5);
      v16 >>= 16;
      v39 = v38 + 1;
      v12[1] = *(_BYTE *)(v17 + v16 + v5);
      v12[2] = *(_BYTE *)(v36 + v17 + v5);
      v18 = *v39;
      v19 = v12 + 3;
      *v19 = *(_BYTE *)(v18 + v42 + v5);
      v19[1] = *(_BYTE *)(v18 + v16 + v5);
      v19[2] = *(_BYTE *)(v36 + v18 + v5);
      v20 = *v40;
      v38 = v39 + 1;
      *v13 = *(_BYTE *)(v20 + v42 + v5);
      v13[1] = *(_BYTE *)(v20 + v16 + v5);
      v13[2] = *(_BYTE *)(v36 + v20 + v5);
      v12 = v19 + 3;
      v41 = v40 + 1;
      v21 = *v41;
      v22 = v13 + 3;
      v40 = v41 + 1;
      *v22 = *(_BYTE *)(v21 + v42 + v5);
      v22[1] = *(_BYTE *)(v21 + v16 + v5);
      v22[2] = *(_BYTE *)(v36 + v21 + v5);
      v11 = v33;
      v10 = v34;
      v13 = v22 + 3;
      --v35;
    }
    while ( v35 );
  }
  if ( (a1[23] & 1) != 0 )
  {
    v23 = *v10;
    v24 = 4 * *v11;
    v43 = *(_DWORD *)(v24 + v32);
    v25 = *(_DWORD *)(v24 + v30) + *(_DWORD *)(4 * v23 + v31);
    v37 = *(_DWORD *)(4 * v23 + v29);
    v26 = *v38;
    *v12 = *(_BYTE *)(v26 + v43 + v5);
    v25 >>= 16;
    v12[1] = *(_BYTE *)(v26 + v25 + v5);
    v12[2] = *(_BYTE *)(v37 + v26 + v5);
    v27 = *v40;
    *v13 = *(_BYTE *)(v27 + v43 + v5);
    v13[1] = *(_BYTE *)(v27 + v25 + v5);
    LOBYTE(v5) = *(_BYTE *)(v37 + v27 + v5);
    v13[2] = v5;
  }
  return v5;
}
