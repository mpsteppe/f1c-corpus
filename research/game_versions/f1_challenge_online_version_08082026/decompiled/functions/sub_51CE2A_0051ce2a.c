_BYTE *__cdecl sub_51CE2A(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4)
{
  _DWORD *v4; // eax
  int v5; // ecx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // edx
  unsigned __int8 *v8; // esi
  _BYTE *result; // eax
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // edx
  unsigned __int8 *v14; // edi
  int v15; // edx
  _BYTE *v16; // eax
  int v17; // edi
  int v18; // ebx
  int v19; // esi
  int v20; // [esp+Ch] [ebp-18h]
  int v21; // [esp+10h] [ebp-14h]
  int v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+18h] [ebp-Ch]
  unsigned __int8 *v24; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *v25; // [esp+20h] [ebp-4h]
  int v26; // [esp+30h] [ebp+Ch]
  int v27; // [esp+34h] [ebp+10h]
  int v28; // [esp+34h] [ebp+10h]
  int v29; // [esp+34h] [ebp+10h]
  int v30; // [esp+38h] [ebp+14h]

  v4 = (_DWORD *)a1[103];
  v5 = a1[71];
  v20 = v4[4];
  v21 = v4[5];
  v23 = v4[7];
  v22 = v4[6];
  v6 = *(unsigned __int8 **)(4 * a3 + *a2);
  v7 = *(unsigned __int8 **)(4 * a3 + a2[1]);
  v8 = *(unsigned __int8 **)(4 * a3 + a2[2]);
  result = *a4;
  if ( a1[23] >> 1 )
  {
    v30 = a1[23] >> 1;
    do
    {
      v10 = *v7;
      v25 = v7 + 1;
      v11 = 4 * *v8;
      v24 = v8 + 1;
      v26 = *(_DWORD *)(v11 + v20);
      v12 = *(_DWORD *)(v11 + v22) + *(_DWORD *)(4 * v10 + v23);
      v27 = *(_DWORD *)(4 * v10 + v21);
      v13 = *v6;
      *result = *(_BYTE *)(v13 + v26 + v5);
      v12 >>= 16;
      result[1] = *(_BYTE *)(v13 + v12 + v5);
      result[2] = *(_BYTE *)(v27 + v13 + v5);
      v14 = v6 + 1;
      v15 = *v14;
      v16 = result + 3;
      *v16 = *(_BYTE *)(v15 + v26 + v5);
      LOBYTE(v10) = *(_BYTE *)(v15 + v12 + v5);
      v8 = v24;
      v16[1] = v10;
      v16[2] = *(_BYTE *)(v27 + v15 + v5);
      v7 = v25;
      v6 = v14 + 1;
      result = v16 + 3;
      --v30;
    }
    while ( v30 );
  }
  if ( (a1[23] & 1) != 0 )
  {
    v17 = *v6;
    v28 = 4 * *v7;
    v18 = 4 * *v8;
    v19 = *(_DWORD *)(v18 + v22) + *(_DWORD *)(v28 + v23);
    v29 = *(_DWORD *)(v28 + v21);
    *result = *(_BYTE *)(v17 + *(_DWORD *)(v18 + v20) + v5);
    result[1] = *(_BYTE *)(v17 + (v19 >> 16) + v5);
    result[2] = *(_BYTE *)(v29 + v17 + v5);
  }
  return result;
}
