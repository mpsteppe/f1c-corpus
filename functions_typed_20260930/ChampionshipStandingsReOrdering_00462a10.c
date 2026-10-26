int __thiscall sub_462A10(int *this)
{
  int *v1; // esi
  int v2; // edx
  int v3; // esi
  int v4; // edx
  int v5; // edi
  int v6; // ebx
  int v7; // ebp
  int *v8; // eax
  int *v9; // esi
  int v10; // eax
  bool v11; // cc
  int v12; // eax
  int i; // ecx
  int v14; // edx
  int *v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int v18; // eax
  int result; // eax
  int j; // esi
  LPVOID *v21; // edi
  char v22; // al
  int v23; // [esp+Ch] [ebp-20h]
  int v24; // [esp+10h] [ebp-1Ch]
  int v25; // [esp+14h] [ebp-18h]
  int v27; // [esp+1Ch] [ebp-10h]
  int v28; // [esp+1Ch] [ebp-10h]
  int v29; // [esp+20h] [ebp-Ch]
  int v30; // [esp+24h] [ebp-8h]
  int v31; // [esp+28h] [ebp-4h]

  v1 = this;
  v2 = *this;
  v27 = 0;
  v29 = 0;
  v31 = 0;
  v25 = 0;
  if ( *(int *)(*this + 15892) > 0 )
  {
    v3 = 0;
    v24 = 0;
    v23 = 15476;
    while ( 1 )
    {
      if ( FlagBitTest((char *)(v3 + v2 + 916), 2) )
        v5 = *(char *)(v3 + v4 + 1040);
      else
        v5 = -1;
      v6 = *(_DWORD *)(v23 + v4);
      if ( v5 < 0 )
        v7 = -1;
      else
        v7 = MEMORY[0x5F0730][4656 * v5];
      v8 = (int *)OperatorNewNhMallocWrapper(12);
      v9 = v8;
      if ( v8 )
      {
        *v8 = v5;
        v8[1] = v6;
        v8[2] = v7;
        v10 = OperatorNewNhMallocWrapper(12);
        if ( v10 )
        {
          *(_DWORD *)v10 = v9;
          *(_DWORD *)(v10 + 4) = 0;
          *(_BYTE *)(v10 + 8) = 1;
        }
        else
        {
          v10 = 0;
        }
        if ( v27 )
          *(_DWORD *)(v29 + 4) = v10;
        else
          v27 = v10;
        v29 = v10;
        ++v31;
      }
      v24 += 140;
      v2 = *this;
      v11 = ++v25 < *(_DWORD *)(*this + 15892);
      v23 += 4;
      if ( !v11 )
        break;
      v3 = v24;
    }
    v1 = this;
  }
  v12 = LinkedListMergeSort_47d0(v27);
  v28 = v12;
  if ( v12 )
  {
    for ( i = *(_DWORD *)(v12 + 4); i; i = *(_DWORD *)(i + 4) )
      ;
  }
  v14 = 0;
  v15 = MEMORY[0x5F0730];
  do
  {
    *v15 = ++v14;
    v15 += 4656;
  }
  while ( (int)v15 < (int)dword_7C9530 );
  v30 = v12;
  if ( v12 )
    v16 = *(int **)v12;
  else
    v16 = 0;
  v17 = 1;
  if ( v16 )
  {
    do
    {
      *(_DWORD *)(*v1 + 4 * v17 + 16342) = v16[1];
      v18 = *v16;
      if ( v18 >= 0 )
        MEMORY[0x5F0730][4656 * v18] = v17;
      ++v17;
      if ( !v30 )
        break;
      v30 = *(_DWORD *)(v30 + 4);
      if ( !v30 )
        break;
      v16 = *(int **)v30;
    }
    while ( *(_DWORD *)v30 );
  }
  result = *v1;
  *(_BYTE *)(*v1 + 16345) = v17 - 1;
  for ( j = v28; j; result = FreeWrapper_7bcf(v21) )
  {
    v21 = (LPVOID *)j;
    v22 = *(_BYTE *)(j + 8);
    j = *(_DWORD *)(j + 4);
    if ( v22 )
      FreeWrapper_7bcf(*v21);
  }
  return result;
}

