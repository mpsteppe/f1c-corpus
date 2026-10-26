char __stdcall sub_6DD150(int a1, int a2, __int16 *a3, _DWORD *a4, int a5)
{
  __int16 *v5; // ecx
  int v7; // edi
  int *v8; // edx
  int v9; // esi
  int v10; // edi
  int v11; // ebx
  int v12; // esi
  __int16 *v13; // eax
  __int16 *v14; // ecx
  int *v15; // edx
  int v16; // esi
  int v17; // edi
  int v18; // ebx
  int v19; // esi
  __int16 *v20; // eax
  __int16 *v21; // ecx
  int *v22; // edx
  int v23; // esi
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  __int16 *v27; // eax
  __int16 *v28; // ecx
  int *v29; // edx
  int v30; // esi
  int v31; // edi
  int v32; // ebx
  int v33; // esi
  _BYTE *v34; // edx
  char v35; // al
  int v36; // esi
  int v37; // esi
  int v38; // edi
  int v39; // ebx
  _BYTE *v40; // edx
  char result; // al
  int v42; // esi
  int v43; // [esp+Ch] [ebp-44h] BYREF
  int v44; // [esp+10h] [ebp-40h]
  int v45; // [esp+18h] [ebp-38h]
  int v46; // [esp+20h] [ebp-30h]
  int v47; // [esp+28h] [ebp-28h]
  int v48; // [esp+2Ch] [ebp-24h]
  int v49; // [esp+30h] [ebp-20h]
  int v50; // [esp+38h] [ebp-18h]
  int v51; // [esp+40h] [ebp-10h]
  int v52; // [esp+48h] [ebp-8h]
  int v53; // [esp+4Ch] [ebp-4h]
  int v54; // [esp+58h] [ebp+8h]
  int v55; // [esp+58h] [ebp+8h]
  int v56; // [esp+58h] [ebp+8h]
  int v57; // [esp+58h] [ebp+8h]
  int v58; // [esp+60h] [ebp+10h]

  v5 = *(__int16 **)(a2 + 80);
  v53 = *(_DWORD *)(a1 + 328) + 128;
  v7 = 6;
  v8 = &v43;
  v58 = 6;
  do
  {
    if ( v7 != 4 && v7 != 2 && v7 )
    {
      if ( a3[8] || a3[24] || a3[40] || a3[56] )
      {
        v54 = (*v5 * *a3) << 15;
        v10 = 29692 * a3[8] * v5[8] + 6967 * a3[40] * v5[40] - 10426 * a3[24] * v5[24] - 5906 * a3[56] * v5[56];
        v11 = v10 + v54 + 4096;
        v12 = v54 - v10;
        v7 = v58;
        *v8 = v11 >> 13;
        v9 = (v12 + 4096) >> 13;
      }
      else
      {
        v9 = 4 * *v5 * *a3;
        *v8 = v9;
      }
      v8[8] = v9;
    }
    v13 = a3 + 1;
    v14 = v5 + 1;
    v15 = v8 + 1;
    if ( v7 != 5 && v7 != 3 && v7 != 1 )
    {
      if ( v13[8] || v13[24] || v13[40] || v13[56] )
      {
        v55 = (*v14 * *v13) << 15;
        v17 = 29692 * v13[8] * v14[8] + 6967 * v13[40] * v14[40] - 10426 * v13[24] * v14[24] - 5906 * v13[56] * v14[56];
        v18 = v17 + v55 + 4096;
        v19 = v55 - v17;
        v7 = v58;
        *v15 = v18 >> 13;
        v16 = (v19 + 4096) >> 13;
      }
      else
      {
        v16 = 4 * *v14 * *v13;
        *v15 = v16;
      }
      v15[8] = v16;
    }
    v20 = v13 + 1;
    v21 = v14 + 1;
    v22 = v15 + 1;
    if ( v7 != 6 && v7 != 4 && v7 != 2 )
    {
      if ( v20[8] || v20[24] || v20[40] || v20[56] )
      {
        v56 = (*v21 * *v20) << 15;
        v24 = 29692 * v20[8] * v21[8] + 6967 * v20[40] * v21[40] - 10426 * v20[24] * v21[24] - 5906 * v20[56] * v21[56];
        v25 = v24 + v56 + 4096;
        v26 = v56 - v24;
        v7 = v58;
        *v22 = v25 >> 13;
        v23 = (v26 + 4096) >> 13;
      }
      else
      {
        v23 = 4 * *v21 * *v20;
        *v22 = v23;
      }
      v22[8] = v23;
    }
    v27 = v20 + 1;
    v28 = v21 + 1;
    v29 = v22 + 1;
    if ( v7 != 7 && v7 != 5 && v7 != 3 )
    {
      if ( v27[8] || v27[24] || v27[40] || v27[56] )
      {
        v57 = (*v28 * *v27) << 15;
        v31 = 29692 * v27[8] * v28[8] + 6967 * v27[40] * v28[40] - 10426 * v27[24] * v28[24] - 5906 * v27[56] * v28[56];
        v32 = v31 + v57 + 4096;
        v33 = v57 - v31;
        v7 = v58;
        *v29 = v32 >> 13;
        v30 = (v33 + 4096) >> 13;
      }
      else
      {
        v30 = 4 * *v28 * *v27;
        *v29 = v30;
      }
      v29[8] = v30;
    }
    v7 -= 4;
    a3 = v27 + 1;
    v5 = v28 + 1;
    v8 = v29 + 1;
    v58 = v7;
  }
  while ( v7 + 2 > 0 );
  v34 = (_BYTE *)(a5 + *a4);
  if ( v44 || v45 || v46 || v47 )
  {
    v36 = 6967 * v46 + 29692 * v44 - 10426 * v45 - 5906 * v47;
    v35 = *(_BYTE *)(((((v43 << 15) - v36 + 0x80000) >> 20) & 0x3FF) + v53);
    *v34 = *(_BYTE *)((((v36 + (v43 << 15) + 0x80000) >> 20) & 0x3FF) + v53);
  }
  else
  {
    v35 = *(_BYTE *)((((v43 + 16) >> 5) & 0x3FF) + v53);
    *v34 = v35;
  }
  v37 = v52;
  v38 = v51;
  v39 = v50;
  v34[1] = v35;
  v40 = (_BYTE *)(a5 + a4[1]);
  if ( v49 || v39 || v38 || v37 )
  {
    v42 = 6967 * v38 + 29692 * v49 - 5906 * v37 - 10426 * v39;
    result = *(_BYTE *)(((((v48 << 15) - v42 + 0x80000) >> 20) & 0x3FF) + v53);
    *v40 = *(_BYTE *)((((v42 + (v48 << 15) + 0x80000) >> 20) & 0x3FF) + v53);
    v40[1] = result;
  }
  else
  {
    result = *(_BYTE *)((((v48 + 16) >> 5) & 0x3FF) + v53);
    *v40 = result;
    v40[1] = result;
  }
  return result;
}
