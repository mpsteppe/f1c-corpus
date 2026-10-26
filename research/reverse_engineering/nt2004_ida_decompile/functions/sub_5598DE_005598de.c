unsigned int *__cdecl sub_5598DE(_DWORD *a1, _DWORD *a2, int a3, int *a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // esi
  unsigned int v7; // edi
  int v8; // ecx
  unsigned int *result; // eax
  unsigned int v10; // ebx
  int v11; // eax
  unsigned int *v12; // edx
  unsigned int *v13; // edi
  unsigned int *v14; // ecx
  int *v15; // eax
  int v16; // edi
  _BYTE *v17; // edi
  int v18; // ecx
  int v19; // ecx
  int v20; // edx
  bool v21; // zf
  _DWORD *v22; // ebx
  int v23; // edx
  unsigned int **v24; // eax
  unsigned __int8 *v25; // ecx
  int v26; // edx
  int v27; // edx
  int v28; // ebx
  unsigned int v29; // [esp+Ch] [ebp-34h]
  int v30; // [esp+Ch] [ebp-34h]
  int v31; // [esp+10h] [ebp-30h]
  int v32; // [esp+10h] [ebp-30h]
  int v33; // [esp+14h] [ebp-2Ch]
  int v34; // [esp+18h] [ebp-28h]
  int v35; // [esp+1Ch] [ebp-24h]
  unsigned int *v36; // [esp+20h] [ebp-20h]
  int v37; // [esp+24h] [ebp-1Ch]
  int v38; // [esp+28h] [ebp-18h]
  unsigned int v39; // [esp+28h] [ebp-18h]
  unsigned int v40; // [esp+2Ch] [ebp-14h]
  int v41; // [esp+2Ch] [ebp-14h]
  unsigned int v42; // [esp+30h] [ebp-10h]
  unsigned int *v43; // [esp+38h] [ebp-8h]
  int v44; // [esp+38h] [ebp-8h]
  int v45; // [esp+38h] [ebp-8h]
  int v46; // [esp+38h] [ebp-8h]
  unsigned int *v47; // [esp+3Ch] [ebp-4h]
  int v48; // [esp+3Ch] [ebp-4h]
  int v49; // [esp+3Ch] [ebp-4h]
  int v50; // [esp+3Ch] [ebp-4h]
  unsigned int *v51; // [esp+48h] [ebp+8h]
  int v52; // [esp+48h] [ebp+8h]
  unsigned __int8 *v53; // [esp+48h] [ebp+8h]

  v5 = (_DWORD *)a1[104];
  v6 = a1[71];
  v7 = a1[23];
  v37 = v5[2];
  v34 = v5[3];
  v8 = v5[4];
  result = (unsigned int *)v5[5];
  v10 = v7 & 0xFFFFFFF8;
  v42 = v7;
  v29 = v7 & 0xFFFFFFF8;
  v35 = v8;
  v36 = result;
  if ( byte_61765C )
  {
    if ( a5 - 1 >= 0 )
    {
      v31 = 3 * v10;
      v11 = 4 * a3;
      v38 = a5;
      while ( 1 )
      {
        v12 = *(unsigned int **)(v11 + *a2);
        v13 = *(unsigned int **)(v11 + a2[1]);
        v14 = *(unsigned int **)(v11 + a2[2]);
        v33 = v11 + 4;
        v15 = a4++;
        v51 = v13;
        v16 = *v15;
        v47 = v12;
        v43 = v14;
        result = sub_5597A2(v10, v12, v51, v14, *v15);
        v17 = (_BYTE *)(v31 + v16);
        if ( v10 < v42 )
        {
          v48 = (char *)v47 - (char *)v51;
          v18 = (char *)v43 - (char *)v51;
          result = (unsigned int *)((char *)v51 + v10);
          v44 = (char *)v43 - (char *)v51;
          v40 = v42 - v10;
          while ( 1 )
          {
            v19 = 4 * *((unsigned __int8 *)result + v18);
            v52 = *((unsigned __int8 *)result + v48);
            v20 = *(unsigned __int8 *)result;
            *v17 = *(_BYTE *)(v52 + *(_DWORD *)(v19 + v37) + v6);
            v17 += 3;
            *(v17 - 2) = *(_BYTE *)(v52 + ((int)(*(_DWORD *)(v19 + v35) + v36[v20]) >> 16) + v6);
            result = (unsigned int *)((char *)result + 1);
            v21 = v40-- == 1;
            *(v17 - 1) = *(_BYTE *)(v52 + *(_DWORD *)(4 * v20 + v34) + v6);
            if ( v21 )
              break;
            v18 = v44;
          }
          v10 = v29;
        }
        if ( !--v38 )
          break;
        v11 = v33;
      }
    }
    _m_empty();
  }
  else
  {
    result = (unsigned int *)(a5 - 1);
    if ( a5 - 1 >= 0 )
    {
      v22 = a2;
      v23 = 4 * a3;
      v41 = a5;
      do
      {
        v49 = *(_DWORD *)(v23 + *v22);
        v53 = *(unsigned __int8 **)(v23 + v22[1]);
        v45 = *(_DWORD *)(v23 + v22[2]);
        v24 = (unsigned int **)a4++;
        result = *v24;
        v23 += 4;
        v32 = v23;
        if ( v7 )
        {
          v25 = v53;
          v50 = v49 - (_DWORD)v53;
          v26 = v45 - (_DWORD)v53;
          v46 = v45 - (_DWORD)v53;
          v39 = v7;
          while ( 1 )
          {
            v27 = v25[v26];
            v28 = v25[v50];
            v30 = *v25;
            *(_BYTE *)result = *(_BYTE *)(v28 + *(_DWORD *)(4 * v27 + v37) + v6);
            result = (unsigned int *)((char *)result + 3);
            *((_BYTE *)result - 2) = *(_BYTE *)(v28 + ((int)(*(_DWORD *)(4 * v27 + v35) + v36[v30]) >> 16) + v6);
            ++v25;
            v21 = v39-- == 1;
            *((_BYTE *)result - 1) = *(_BYTE *)(v28 + *(_DWORD *)(4 * v30 + v34) + v6);
            if ( v21 )
              break;
            v26 = v46;
          }
          v23 = v32;
          v22 = a2;
          v7 = v42;
        }
        --v41;
      }
      while ( v41 );
    }
  }
  return result;
}
