_BYTE *__cdecl sub_51C6E1(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // edi
  int v7; // ecx
  _BYTE *result; // eax
  int v9; // edx
  _DWORD *v10; // esi
  unsigned __int8 *v11; // ecx
  _BYTE **v12; // eax
  int v13; // ebx
  int v14; // esi
  int v15; // esi
  int v16; // edi
  int v17; // [esp+8h] [ebp-28h]
  int v18; // [esp+Ch] [ebp-24h]
  int v19; // [esp+10h] [ebp-20h]
  int v20; // [esp+14h] [ebp-1Ch]
  int v21; // [esp+18h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-14h]
  int v23; // [esp+20h] [ebp-10h]
  int v24; // [esp+24h] [ebp-Ch]
  int v25; // [esp+24h] [ebp-Ch]
  int v26; // [esp+28h] [ebp-8h]
  int v27; // [esp+2Ch] [ebp-4h]
  int v28; // [esp+2Ch] [ebp-4h]
  int v29; // [esp+38h] [ebp+8h]
  int v30; // [esp+48h] [ebp+18h]
  int v31; // [esp+48h] [ebp+18h]

  v5 = (_DWORD *)a1[104];
  v6 = a1[23];
  v29 = a1[71];
  v21 = v5[2];
  v18 = v5[3];
  v7 = v5[4];
  v20 = v5[5];
  result = (_BYTE *)(a5 - 1);
  v17 = v6;
  v19 = v7;
  if ( a5 - 1 >= 0 )
  {
    v9 = 4 * a3;
    v10 = a2;
    v26 = a5;
    do
    {
      v30 = *(_DWORD *)(v9 + *v10);
      v11 = *(unsigned __int8 **)(v9 + v10[1]);
      v27 = *(_DWORD *)(v9 + v10[2]);
      v24 = *(_DWORD *)(v9 + v10[3]);
      v12 = a4++;
      result = *v12;
      v9 += 4;
      if ( v6 )
      {
        v13 = v30 - (_DWORD)v11;
        v14 = v27 - (_DWORD)v11;
        v23 = v30 - (_DWORD)v11;
        v22 = v27 - (_DWORD)v11;
        v25 = v24 - (_DWORD)v11;
        v28 = v6;
        while ( 1 )
        {
          v31 = v11[v13];
          v15 = 4 * v11[v14];
          v16 = 4 * *v11;
          *result = *(_BYTE *)(v29 - *(_DWORD *)(v15 + v21) - v31 + 255);
          result += 4;
          *(result - 3) = *(_BYTE *)(v29 - ((*(_DWORD *)(v15 + v19) + *(_DWORD *)(v16 + v20)) >> 16) - v31 + 255);
          *(result - 2) = *(_BYTE *)(v29 - *(_DWORD *)(v16 + v18) - v31 + 255);
          *(result - 1) = (v11++)[v25];
          if ( !--v28 )
            break;
          v13 = v23;
          v14 = v22;
        }
        v6 = v17;
        v10 = a2;
      }
      --v26;
    }
    while ( v26 );
  }
  return result;
}
