int *__thiscall sub_6C5028(_DWORD *this, int a2, int a3, unsigned int *a4, int a5, int a6)
{
  _DWORD *v6; // esi
  int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // eax
  int *result; // eax
  int v11; // edi
  _DWORD *v12; // edx
  int v13; // eax
  unsigned int v14; // eax
  int v15; // edi
  int v16; // edx
  _DWORD *v17; // edx
  unsigned int v19; // edx
  unsigned int v20; // edi
  int v21; // edi
  _DWORD *v22; // ecx
  int v23; // ebx
  _DWORD *v24; // ecx
  unsigned int v25; // ebx
  int v26; // esi
  int v27; // ecx
  int *v28; // edx
  int v29; // edi
  char *v30; // ebx
  _DWORD *v31; // edi
  int v32; // ecx
  unsigned int v33; // edx
  char *v34; // edi
  _DWORD *v35; // esi
  char v36; // cl
  _DWORD v37[4]; // [esp+4h] [ebp-20h] BYREF
  unsigned int v38; // [esp+14h] [ebp-10h]
  _DWORD *v39; // [esp+18h] [ebp-Ch]
  unsigned int v40; // [esp+1Ch] [ebp-8h]
  char *v41; // [esp+20h] [ebp-4h]
  unsigned int v42; // [esp+2Ch] [ebp+8h]
  int v43; // [esp+38h] [ebp+14h]
  _DWORD *v44; // [esp+38h] [ebp+14h]
  int v45; // [esp+3Ch] [ebp+18h]
  int v46; // [esp+3Ch] [ebp+18h]
  unsigned int v47; // [esp+3Ch] [ebp+18h]

  v6 = (_DWORD *)a3;
  v7 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(a3 + 16));
  v8 = *(_DWORD *)(v7 + 72);
  v9 = *(_DWORD *)(v7 + 84);
  v38 = v8;
  v40 = v9;
  if ( v9 == -1 )
    return 0;
  v41 = 0;
  if ( *(_DWORD *)(a3 + 4) )
  {
    v11 = this[5];
    v12 = *(_DWORD **)(a3 + 8);
    while ( 1 )
    {
      v13 = *(_DWORD *)(v11 + 4 * *v12);
      if ( this[34] == *(_DWORD *)(v13 + 4) )
      {
        v14 = *(_DWORD *)(v13 + 80);
        if ( v14 > v38 && v14 < v40 )
          return 0;
      }
      ++v41;
      ++v12;
      if ( (unsigned int)v41 >= *(_DWORD *)(a3 + 4) )
      {
        v9 = v40;
        break;
      }
    }
  }
  result = *(int **)(this[6] + 4 * v9);
  v15 = *result;
  if ( a2 != *result )
    return 0;
  v16 = *(_DWORD *)(a3 + 12);
  v41 = 0;
  if ( v16 )
  {
    v39 = *(_DWORD **)(a3 + 16);
    do
    {
      v17 = *(_DWORD **)(this[5] + 4 * *v39);
      if ( v17[21] != v40 || v17[22] != v40 )
        return 0;
      if ( !(*(_DWORD *)(a3 + 12) == 1 ? v17[23] == a6 * (a2 & 0xFFFFF) : v17[23] == a6) )
        return 0;
      ++v41;
      ++v39;
    }
    while ( (unsigned int)v41 < *(_DWORD *)(a3 + 12) );
  }
  v19 = v15 & 0xFFFFF;
  v42 = v15 & 0xFFFFF;
  if ( result[3] != (v15 & 0xFFFFF) )
    return 0;
  v20 = result[1];
  if ( v20 > a5 * v19 )
    return 0;
  v41 = 0;
  if ( v20 )
  {
    v21 = this[5];
    v43 = this[34];
    v22 = (_DWORD *)result[2];
    v45 = v21;
    do
    {
      v23 = *(_DWORD *)(v45 + 4 * *v22);
      if ( v43 == *(_DWORD *)(v23 + 4) && *(_DWORD *)(v23 + 72) > v38 )
        return 0;
      ++v41;
      v20 = result[1];
      ++v22;
    }
    while ( (unsigned int)v41 < v20 );
  }
  v41 = 0;
  if ( v20 )
  {
    v46 = **(_DWORD **)(a3 + 16);
    v24 = (_DWORD *)result[2];
    do
    {
      if ( *v24 == v46 )
        break;
      ++v41;
      ++v24;
    }
    while ( (unsigned int)v41 < v20 );
  }
  if ( v41 == (char *)v20 )
    return 0;
  if ( (unsigned int)v41 >= v19 )
  {
    v25 = 0;
    if ( v19 )
    {
      v26 = 4 * v19;
      do
      {
        v27 = result[2];
        v28 = (int *)(v27 + 4 * v25);
        v29 = *v28;
        *v28 = *(_DWORD *)(v26 + v27);
        *(_DWORD *)(v26 + result[2]) = v29;
        ++v25;
        v26 += 4;
      }
      while ( v25 < v42 );
      v19 = v42;
      v6 = (_DWORD *)a3;
    }
  }
  if ( v6[3] > 1u )
  {
    v30 = (char *)v6[2];
    v41 = &v30[4 * v6[1]];
    if ( v30 < v41 )
    {
      while ( 1 )
      {
        if ( v19 )
        {
          v39 = (_DWORD *)v6[4];
          v31 = v30;
          v32 = result[2] - (_DWORD)v30;
          v38 = v19;
          do
          {
            v47 = 0;
            v44 = v39;
            while ( *v44 != *(_DWORD *)((char *)v31 + v32) )
            {
              ++v47;
              v19 = v42;
              ++v44;
              if ( v47 >= v42 )
                goto LABEL_48;
            }
            v37[v47] = *v31;
            v19 = v42;
LABEL_48:
            ++v31;
            --v38;
          }
          while ( v38 );
        }
        v33 = 4 * v19;
        qmemcpy(v30, v37, 4 * (v33 >> 2));
        v35 = &v37[v33 >> 2];
        v34 = &v30[4 * (v33 >> 2)];
        v36 = v33;
        v19 = v42;
        qmemcpy(v34, v35, v36 & 3);
        v30 += 4 * v42;
        if ( v30 >= v41 )
          break;
        v6 = (_DWORD *)a3;
      }
    }
  }
  if ( a4 )
    *a4 = v40;
  return result;
}
