int __thiscall sub_552D70(int this)
{
  unsigned int *v2; // ebp
  _DWORD *v3; // eax
  int v4; // edi
  int v5; // ecx
  unsigned int v6; // edx
  unsigned int *v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // edi
  unsigned int *v11; // ecx
  int v12; // eax
  unsigned int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  _DWORD *v22; // edi
  int v23; // eax
  int v24; // ecx
  int v25; // ecx
  unsigned int v26; // eax
  int v28; // [esp+10h] [ebp-10h]
  unsigned int *v29; // [esp+14h] [ebp-Ch]
  int v30; // [esp+18h] [ebp-8h]
  _BYTE *v31; // [esp+18h] [ebp-8h]
  int v32; // [esp+1Ch] [ebp-4h]
  int v33; // [esp+1Ch] [ebp-4h]

  v2 = (unsigned int *)ThunkWithArgReorder(*(void **)(this + 100), *(_DWORD *)(*(_DWORD *)(this + 100) + 24), 0);
  v3 = *(_DWORD **)(this + 100);
  v32 = v3[8];
  v4 = (int)v3[10] >> 2;
  v5 = v3[7] + v4 * (v32 - 2);
  v6 = v2[v5 - 1];
  v7 = &v2[v5 - 2];
  *(_DWORD *)(this + 40) = v6;
  *(_DWORD *)(this + 44) = *v7;
  *(_DWORD *)(this + 48) = *(v7 - 1);
  v29 = v2;
  v8 = 1;
  do
  {
    v30 = *(unsigned int *)((char *)&v2[v8] + v3[10]);
    v9 = *(_DWORD *)(this + 40);
    ++v8;
  }
  while ( v30 != v9 );
  *(_DWORD *)(this + 52) = v8 - 1;
  v10 = v4;
  v11 = &v2[v10 + 1];
  *(_DWORD *)(this + 60) = v3[7] / (v8 - 1);
  v12 = 1;
  do
  {
    v13 = *v11;
    ++v12;
    v11 = (unsigned int *)((char *)v11 + v10 * 4);
  }
  while ( v13 != v9 );
  v14 = v12 - 1;
  v15 = v32 / (v12 - 1);
  *(_DWORD *)(this + 56) = v14;
  v28 = 0;
  v16 = v15 * *(_DWORD *)(this + 60);
  *(_DWORD *)(this + 64) = v15;
  v33 = v16;
  *(_DWORD *)(this + 68) = v16 + 32;
  if ( v16 > 0 )
  {
    v31 = (_BYTE *)(this + 109);
    do
    {
      v17 = *(_DWORD *)(this + 60);
      v18 = *(_DWORD *)(this + 48);
      v19 = v28 / v17 * *(_DWORD *)(this + 56);
      v20 = v28 % v17 * *(_DWORD *)(this + 52) + 1;
      v21 = v19 + 1;
      v22 = (unsigned int *)((char *)&v2[v20] + v21 * *(_DWORD *)(*(_DWORD *)(this + 100) + 40));
      v23 = 0;
      if ( *v22 == v18 )
      {
LABEL_11:
        LOBYTE(v23) = v23 + 1;
      }
      else
      {
        while ( ++v23 < *(_DWORD *)(this + 52) )
        {
          if ( v22[v23] == v18 )
          {
            v2 = v29;
            goto LABEL_11;
          }
        }
        v2 = v29;
      }
      *(v31 - 1) = v23 - 1;
      *v31 = *(_BYTE *)(this + 56) - 1;
      *(_WORD *)(v31 - 5) = v20;
      *(_WORD *)(v31 - 3) = v21;
      ++v28;
      v31 += 8;
    }
    while ( v28 < v33 );
  }
  v24 = *(_DWORD *)(this + 100);
  if ( *(_DWORD *)(v24 + 28) * *(_DWORD *)(v24 + 32) > 0 )
  {
    v25 = *(_DWORD *)(v24 + 28) * *(_DWORD *)(v24 + 32);
    do
    {
      v26 = *v2;
      if ( *v2 == *(_DWORD *)(this + 48) || v26 == *(_DWORD *)(this + 40) || v26 == *(_DWORD *)(this + 44) )
      {
        *v2 = 15790320;
        *(_DWORD *)(*(_DWORD *)(this + 100) + 24) |= 0x800u;
      }
      else
      {
        *v2 = v26 | 0xFF000000;
      }
      ++v2;
      --v25;
    }
    while ( v25 );
  }
  *(_DWORD *)(this + 44) = 15790320;
  return ArgumentReorderWrapper_3230(*(void **)(this + 100), *(_DWORD *)(*(_DWORD *)(this + 100) + 24), 0);
}
