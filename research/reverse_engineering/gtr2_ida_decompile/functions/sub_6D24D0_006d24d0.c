unsigned __int8 *__stdcall sub_6D24D0(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // ecx
  int v7; // edx
  unsigned __int8 *result; // eax
  int v9; // eax
  int v10; // edi
  int v11; // ebx
  int v12; // ecx
  unsigned __int8 **v13; // edx
  int v14; // esi
  int v15; // edi
  _BYTE *v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // esi
  int v20; // edi
  unsigned __int8 **v21; // [esp+4h] [ebp-2Ch]
  int v22; // [esp+8h] [ebp-28h]
  int v23; // [esp+Ch] [ebp-24h]
  int v24; // [esp+10h] [ebp-20h]
  unsigned __int8 *v25; // [esp+14h] [ebp-1Ch]
  int v26; // [esp+18h] [ebp-18h]
  int v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+20h] [ebp-10h]
  int v29; // [esp+24h] [ebp-Ch]
  int v30; // [esp+28h] [ebp-8h]
  int v31; // [esp+2Ch] [ebp-4h]
  int v32; // [esp+38h] [ebp+8h]
  int v33; // [esp+3Ch] [ebp+Ch]
  int v34; // [esp+40h] [ebp+10h]
  int v35; // [esp+48h] [ebp+18h]
  int v36; // [esp+48h] [ebp+18h]

  v5 = (_DWORD *)a1[115];
  v29 = a1[28];
  v32 = a1[82];
  v6 = v5[3];
  v26 = v5[2];
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
    v12 = a2[3] - v9;
    v13 = (unsigned __int8 **)(v9 + 4 * a3);
    v34 = v10;
    v31 = v11;
    v30 = v12;
    v33 = a5;
    while ( 1 )
    {
      v14 = *(int *)((char *)v13 + v10);
      v15 = *(int *)((char *)v13 + v11);
      result = *v13;
      v35 = *(int *)((char *)v13 + v12);
      v16 = *a4++;
      v21 = ++v13;
      if ( v29 )
      {
        v17 = v14 - (_DWORD)result;
        v18 = v15 - (_DWORD)result;
        v28 = v14 - (_DWORD)result;
        v27 = v18;
        v22 = v35 - (_DWORD)result;
        v36 = v29;
        while ( 1 )
        {
          v19 = result[v17];
          v20 = result[v18];
          *v16 = *(_BYTE *)(v32 - *(_DWORD *)(v26 + 4 * v20) - v19 + 255);
          v16[1] = *(_BYTE *)(v32 - ((*(_DWORD *)(v24 + 4 * v20) + *(_DWORD *)&v25[4 * *result]) >> 16) - v19 + 255);
          v16 += 4;
          *(v16 - 2) = *(_BYTE *)(v32 - *(_DWORD *)(v23 + 4 * *result) - v19 + 255);
          *(v16 - 1) = (result++)[v22];
          if ( !--v36 )
            break;
          v17 = v28;
          v18 = v27;
        }
        v13 = v21;
      }
      if ( !--v33 )
        break;
      v10 = v34;
      v11 = v31;
      v12 = v30;
    }
  }
  return result;
}
