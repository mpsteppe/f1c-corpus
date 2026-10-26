_BYTE *__stdcall sub_6D31D0(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4)
{
  _DWORD *v4; // eax
  int v5; // ecx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // esi
  unsigned __int8 *v8; // ebx
  _BYTE *result; // eax
  int v10; // edx
  int v11; // esi
  int v12; // edx
  int v13; // edx
  _BYTE *v14; // eax
  char v15; // bl
  int v16; // edx
  int v17; // esi
  int v18; // ebx
  unsigned int v19; // [esp+Ch] [ebp-18h]
  int v20; // [esp+10h] [ebp-14h]
  int v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+18h] [ebp-Ch]
  int v23; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v24; // [esp+20h] [ebp-4h]
  int v25; // [esp+2Ch] [ebp+8h]
  int v26; // [esp+2Ch] [ebp+8h]
  unsigned int v27; // [esp+30h] [ebp+Ch]
  int v28; // [esp+34h] [ebp+10h]
  unsigned __int8 *v29; // [esp+38h] [ebp+14h]

  v4 = (_DWORD *)a1[114];
  v5 = a1[82];
  v23 = v4[4];
  v20 = v4[5];
  v21 = v4[6];
  v22 = v4[7];
  v6 = *(unsigned __int8 **)(*a2 + 4 * a3);
  v7 = *(unsigned __int8 **)(a2[1] + 4 * a3);
  v8 = *(unsigned __int8 **)(a2[2] + 4 * a3);
  result = *a4;
  v19 = a1[28];
  if ( v19 >> 1 )
  {
    v27 = v19 >> 1;
    do
    {
      v25 = *v7;
      v10 = *v8;
      v29 = v7 + 1;
      v24 = v8 + 1;
      v28 = *(_DWORD *)(v23 + 4 * v10);
      v11 = *(_DWORD *)(v21 + 4 * v10) + *(_DWORD *)(v22 + 4 * v25);
      v26 = *(_DWORD *)(v20 + 4 * v25);
      v12 = *v6;
      *result = *(_BYTE *)(v12 + v28 + v5);
      v11 >>= 16;
      result[1] = *(_BYTE *)(v12 + v11 + v5);
      result[2] = *(_BYTE *)(v26 + v12 + v5);
      v13 = v6[1];
      v14 = result + 3;
      *v14 = *(_BYTE *)(v13 + v28 + v5);
      v15 = *(_BYTE *)(v13 + v11 + v5);
      v7 = v29;
      v14[2] = *(_BYTE *)(v26 + v13 + v5);
      v14[1] = v15;
      v8 = v24;
      v6 += 2;
      result = v14 + 3;
      --v27;
    }
    while ( v27 );
  }
  if ( (v19 & 1) != 0 )
  {
    v16 = *v7;
    v17 = *v6;
    v18 = *v8;
    *result = *(_BYTE *)(v17 + *(_DWORD *)(v23 + 4 * v18) + v5);
    result[1] = *(_BYTE *)(v17 + ((*(_DWORD *)(v21 + 4 * v18) + *(_DWORD *)(v22 + 4 * v16)) >> 16) + v5);
    result[2] = *(_BYTE *)(v17 + *(_DWORD *)(v20 + 4 * v16) + v5);
  }
  return result;
}
