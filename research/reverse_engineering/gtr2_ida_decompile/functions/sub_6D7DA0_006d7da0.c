unsigned __int8 **__stdcall sub_6D7DA0(int *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  unsigned __int8 **result; // eax
  int v7; // ecx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // ebx
  unsigned __int8 *v13; // edi
  unsigned __int8 *v14; // ecx
  int v15; // eax
  int v16; // edx
  _BYTE *v17; // esi
  int v18; // esi
  int v19; // edx
  int v20; // ebx
  bool v21; // zf
  bool v22; // cc
  int v23; // [esp+Ch] [ebp-20h]
  int v24; // [esp+10h] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-18h]
  int v26; // [esp+18h] [ebp-14h]
  int v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+20h] [ebp-Ch]
  unsigned __int8 *v29; // [esp+24h] [ebp-8h]
  int v30; // [esp+28h] [ebp-4h]
  unsigned __int8 **v31; // [esp+34h] [ebp+8h]
  _BYTE *v32; // [esp+38h] [ebp+Ch]
  _BYTE *v33; // [esp+38h] [ebp+Ch]
  int v34; // [esp+3Ch] [ebp+10h]
  int v35; // [esp+3Ch] [ebp+10h]

  v4 = 8 * *(_DWORD *)(a2 + 28);
  sub_6D75E0(v4, a2, a3 - 4, a1[61] + 2, a1[7]);
  v5 = a1[48];
  v30 = (128 - v5) << 9;
  result = (unsigned __int8 **)(v5 << 6);
  v7 = 0;
  v31 = result;
  v26 = 0;
  v23 = *(_DWORD *)(a2 + 12);
  if ( v23 > 0 )
  {
    result = (unsigned __int8 **)(a3 + 4);
    v24 = v4 - 2;
    v25 = a3 + 4;
    do
    {
      v8 = *(result - 2);
      v32 = *(_BYTE **)(a4 + 4 * v7);
      v9 = *(result - 1);
      v10 = *result;
      v11 = *v9;
      v34 = v11 + *v10 + *v8;
      v12 = v9[1] + v10[1];
      v13 = v8 + 1;
      v14 = v9 + 1;
      v29 = v10 + 1;
      v15 = v12 + *v13;
      *v32 = (unsigned int)((_DWORD)v31 * (v15 + 2 * v34 - v11) + v30 * v11 + 0x8000) >> 16;
      v16 = v34;
      v17 = v32 + 1;
      v33 = v32 + 1;
      v28 = v34;
      v35 = v15;
      if ( v24 )
      {
        v27 = v24;
        do
        {
          v18 = *v14;
          v19 = *++v14;
          v20 = v19 + v29[1];
          ++v13;
          ++v29;
          v15 = v20 + *v13;
          *v33 = (unsigned int)((_DWORD)v31 * (v35 + v15 + v28 - v18) + v30 * v18 + 0x8000) >> 16;
          v16 = v35;
          v17 = v33 + 1;
          v21 = v27 == 1;
          ++v33;
          v28 = v35;
          v35 = v15;
          --v27;
        }
        while ( !v21 );
      }
      *v17 = ((_DWORD)v31 * (v16 + 2 * v15 - *v14) + v30 * (unsigned int)*v14 + 0x8000) >> 16;
      v7 = v26 + 1;
      result = (unsigned __int8 **)(v25 + 4);
      v22 = ++v26 < v23;
      v25 += 4;
    }
    while ( v22 );
  }
  return result;
}
