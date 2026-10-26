unsigned __int8 *__stdcall sub_6D2150(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // ecx
  unsigned __int8 *result; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // ecx
  unsigned __int8 **v12; // esi
  int v13; // edi
  _BYTE *v14; // ecx
  int v15; // esi
  int v16; // edi
  int v17; // edi
  int v18; // esi
  int v19; // ebx
  int v20; // edi
  unsigned __int8 **v21; // [esp+4h] [ebp-24h]
  int v22; // [esp+8h] [ebp-20h]
  int v23; // [esp+Ch] [ebp-1Ch]
  int v24; // [esp+10h] [ebp-18h]
  unsigned __int8 *v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int v28; // [esp+20h] [ebp-8h]
  int v29; // [esp+24h] [ebp-4h]
  int v30; // [esp+30h] [ebp+8h]
  int v31; // [esp+30h] [ebp+8h]
  int v32; // [esp+34h] [ebp+Ch]
  int v33; // [esp+38h] [ebp+10h]

  v5 = (_DWORD *)a1[115];
  v29 = a1[28];
  v6 = a1[82];
  v26 = v5[2];
  v22 = v5[3];
  v7 = v5[4];
  result = (unsigned __int8 *)v5[5];
  v23 = v6;
  v24 = v7;
  v25 = result;
  if ( a5 - 1 >= 0 )
  {
    v9 = a2[1];
    v10 = *a2 - v9;
    v11 = a2[2] - v9;
    v12 = (unsigned __int8 **)(v9 + 4 * a3);
    v33 = v10;
    v32 = v11;
    while ( 1 )
    {
      v13 = *(int *)((char *)v12 + v10);
      result = *v12;
      v30 = *(int *)((char *)v12 + v11);
      v14 = *a4++;
      v21 = ++v12;
      if ( v29 )
      {
        v15 = v13 - (_DWORD)result;
        v16 = v30 - (_DWORD)result;
        v27 = v15;
        v28 = v30 - (_DWORD)result;
        v31 = v29;
        while ( 1 )
        {
          v17 = result[v16];
          v18 = result[v15];
          *v14 = *(_BYTE *)(v18 + *(_DWORD *)(v26 + 4 * v17) + v6);
          v19 = *(_DWORD *)(v24 + 4 * v17) + *(_DWORD *)&v25[4 * *result];
          v6 = v23;
          v20 = *result;
          v14[1] = *(_BYTE *)(v18 + (v19 >> 16) + v23);
          v14[2] = *(_BYTE *)(v18 + *(_DWORD *)(v22 + 4 * v20) + v23);
          v14 += 3;
          ++result;
          if ( !--v31 )
            break;
          v15 = v27;
          v16 = v28;
        }
        v12 = v21;
      }
      if ( !--a5 )
        break;
      v11 = v32;
      v10 = v33;
    }
  }
  return result;
}
