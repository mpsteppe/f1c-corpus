_DWORD *__stdcall sub_6D2270(_DWORD *a1, _DWORD *a2, int a3, int *a4, int a5)
{
  _DWORD *result; // eax
  int v6; // ebx
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // esi
  _BYTE *v10; // esi
  int v11; // edx
  unsigned __int8 *v12; // eax
  int v13; // edi
  int v14; // ecx
  int v15; // [esp+Ch] [ebp-24h]
  int v16; // [esp+10h] [ebp-20h]
  int v17; // [esp+14h] [ebp-1Ch]
  int v18; // [esp+18h] [ebp-18h]
  int v19; // [esp+1Ch] [ebp-14h]
  int v20; // [esp+20h] [ebp-10h]
  int v21; // [esp+24h] [ebp-Ch]
  int v22; // [esp+24h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-8h]
  unsigned int v24; // [esp+2Ch] [ebp-4h]
  int v25; // [esp+38h] [ebp+8h]
  unsigned int v26; // [esp+38h] [ebp+8h]
  _DWORD *v27; // [esp+40h] [ebp+10h]
  int v28; // [esp+48h] [ebp+18h]
  int v29; // [esp+48h] [ebp+18h]

  result = (_DWORD *)a1[115];
  v6 = a1[82];
  v19 = result[2];
  v17 = result[4];
  v24 = a1[28];
  v15 = result[3];
  v7 = v24 & 0xFFFFFFF8;
  v16 = v6;
  v18 = result[5];
  if ( a5 - 1 >= 0 )
  {
    v20 = 3 * v7;
    result = (_DWORD *)(4 * a3);
    v23 = a5;
    do
    {
      v25 = *(_DWORD *)((char *)result + *a2);
      v8 = *(_DWORD *)((char *)result + a2[1]);
      v28 = *(_DWORD *)((char *)result + a2[2]);
      v9 = *a4;
      ++result;
      v21 = v8;
      v27 = result;
      ++a4;
      if ( v7 )
      {
        sub_6DD650(v7, v25, v8, v28, v9);
        v8 = v21;
        result = v27;
      }
      v10 = (_BYTE *)(v20 + v9);
      if ( v7 < v24 )
      {
        v22 = v25 - v8;
        v11 = v28 - v8;
        v12 = (unsigned __int8 *)(v8 + v7);
        v29 = v28 - v8;
        v26 = v24 - v7;
        while ( 1 )
        {
          v13 = v12[v11];
          v14 = v12[v22];
          *v10 = *(_BYTE *)(v14 + *(_DWORD *)(v19 + 4 * v13) + v6);
          v6 = v16;
          v10[1] = *(_BYTE *)(v14 + ((*(_DWORD *)(v17 + 4 * v13) + *(_DWORD *)(v18 + 4 * *v12)) >> 16) + v16);
          v10[2] = *(_BYTE *)(v14 + *(_DWORD *)(v15 + 4 * *v12) + v16);
          v10 += 3;
          ++v12;
          if ( !--v26 )
            break;
          v11 = v29;
        }
        v7 = v24 & 0xFFFFFFF8;
        result = v27;
      }
      --v23;
    }
    while ( v23 );
  }
  _m_empty();
  return result;
}
