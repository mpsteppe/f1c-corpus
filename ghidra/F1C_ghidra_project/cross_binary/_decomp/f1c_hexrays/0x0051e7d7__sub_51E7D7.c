// f1c  0x0051e7d7  size=255
_DWORD *__cdecl sub_51E7D7(int a1, int a2, _BYTE **a3, int a4)
{
  _DWORD *result; // eax
  int *v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // ecx
  int v8; // edx
  int v9; // esi
  unsigned __int8 *v10; // ecx
  bool v11; // zf
  int v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+8h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-28h]
  int v15; // [esp+10h] [ebp-24h]
  int v16; // [esp+14h] [ebp-20h]
  int v17; // [esp+18h] [ebp-1Ch]
  int v18; // [esp+1Ch] [ebp-18h]
  int v19; // [esp+24h] [ebp-10h]
  int v20; // [esp+28h] [ebp-Ch]
  _BYTE **v21; // [esp+2Ch] [ebp-8h]
  _BYTE *v22; // [esp+30h] [ebp-4h]
  int v23; // [esp+3Ch] [ebp+8h]
  char v24; // [esp+48h] [ebp+14h]
  char v25; // [esp+48h] [ebp+14h]

  result = *(_DWORD **)(a1 + 420);
  v5 = (int *)result[6];
  v16 = *v5;
  v13 = v5[2];
  v18 = *(_DWORD *)(a1 + 92);
  v15 = v5[1];
  if ( a4 > 0 )
  {
    v6 = a2 - (_DWORD)a3;
    v21 = a3;
    v19 = a4;
    while ( 1 )
    {
      v7 = *(_BYTE **)((char *)v21 + v6);
      v23 = 0;
      v12 = result[12];
      v22 = *v21;
      v8 = (v12 << 6) + result[14];
      v9 = (v12 << 6) + result[13];
      v17 = v8;
      v14 = (v12 << 6) + result[15];
      if ( v18 )
      {
        v20 = v18;
        while ( 1 )
        {
          v24 = *(_BYTE *)(*v7 + *(_DWORD *)(v9 + 4 * v23) + v16);
          v10 = v7 + 1;
          v25 = *(_BYTE *)(*v10++ + *(_DWORD *)(v8 + 4 * v23) + v15) + v24;
          *v22 = *(_BYTE *)(*v10 + *(_DWORD *)(v14 + 4 * v23) + v13) + v25;
          v7 = v10 + 1;
          ++v22;
          v11 = v20-- == 1;
          v23 = ((_BYTE)v23 + 1) & 0xF;
          if ( v11 )
            break;
          v8 = v17;
        }
      }
      ++v21;
      v11 = v19-- == 1;
      result[12] = ((_BYTE)v12 + 1) & 0xF;
      if ( v11 )
        break;
      v6 = a2 - (_DWORD)a3;
    }
  }
  return result;
}
