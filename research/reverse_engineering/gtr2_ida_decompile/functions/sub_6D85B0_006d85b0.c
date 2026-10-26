int __stdcall sub_6D85B0(int a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  int result; // eax
  int v6; // edx
  int v7; // ebx
  _DWORD *v8; // ecx
  unsigned __int8 *v9; // edx
  _BYTE *v10; // edi
  int v11; // esi
  int v12; // ecx
  int v13; // esi
  int v14; // edx
  _DWORD *v15; // [esp+4h] [ebp-20h]
  int v16; // [esp+8h] [ebp-1Ch]
  int v17; // [esp+Ch] [ebp-18h]
  int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  int v21; // [esp+1Ch] [ebp-8h]
  int v22; // [esp+20h] [ebp-4h]
  unsigned __int8 *v23; // [esp+2Ch] [ebp+8h]
  int v24; // [esp+34h] [ebp+10h]
  int v25; // [esp+34h] [ebp+10h]
  int v26; // [esp+38h] [ebp+14h]
  int v27; // [esp+3Ch] [ebp+18h]
  int v28; // [esp+3Ch] [ebp+18h]

  result = *(_DWORD *)(*(_DWORD *)(a1 + 360) + 8);
  v19 = *(_DWORD *)(a1 + 28);
  if ( a5 - 1 >= 0 )
  {
    v6 = a3[1];
    v21 = *a3 - v6;
    v7 = a3[2] - v6;
    v8 = (_DWORD *)(v6 + 4 * a4);
    v22 = v7;
    v20 = a3[3] - v6;
    v26 = a5;
    while ( 1 )
    {
      v9 = *a2;
      v24 = *(_DWORD *)((char *)v8 + v7);
      ++a2;
      v10 = *(_BYTE **)((char *)v8 + v21);
      v11 = *v8;
      v27 = *(_DWORD *)((char *)v8++ + v20);
      v23 = v9;
      v15 = v8;
      if ( v19 )
      {
        v18 = v27 - (_DWORD)v10;
        v17 = v11 - (_DWORD)v10;
        v16 = v24 - (_DWORD)v10;
        v25 = v19;
        while ( 1 )
        {
          v12 = 255 - *v9;
          v13 = 255 - v9[1];
          v28 = 255 - v9[2];
          v10[v18] = v23[3];
          v23 += 4;
          v14 = *(_DWORD *)(result + 4 * v28 + 5120);
          *v10 = (unsigned int)(*(_DWORD *)(result + 4 * v12)
                              + *(_DWORD *)(result + 4 * v13 + 1024)
                              + *(_DWORD *)(result + 4 * v28 + 2048)) >> 16;
          v10[v17] = (unsigned int)(*(_DWORD *)(result + 4 * v12 + 3072) + *(_DWORD *)(result + 4 * v13 + 4096) + v14) >> 16;
          (v10++)[v16] = (unsigned int)(*(_DWORD *)(result + 4 * v12 + 5120)
                                      + *(_DWORD *)(result + 4 * v13 + 6144)
                                      + *(_DWORD *)(result + 4 * v28 + 7168)) >> 16;
          if ( !--v25 )
            break;
          v9 = v23;
        }
        v8 = v15;
      }
      if ( !--v26 )
        break;
      v7 = v22;
    }
  }
  return result;
}
