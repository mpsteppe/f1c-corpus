int __userpurge sub_6D9DD5@<eax>(int a1@<eax>, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int i; // edi
  int v18; // ecx
  int v19; // edx
  unsigned __int16 v20; // si
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  int v24; // eax

  v4 = *(_DWORD *)(a1 + 5812);
  v5 = a4;
  if ( v4 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= (a2 - 257) << v4;
    *(_DWORD *)(a1 + 5812) = v4 + 5;
  }
  else
  {
    v6 = (a2 - 257) << v4;
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v6;
    *(_BYTE *)(v7 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
    v8 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    v5 = a4;
    *(_DWORD *)(a1 + 5812) = v8 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(a2 - 257) >> (16 - v8);
  }
  v9 = *(_DWORD *)(a1 + 5812);
  if ( v9 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= (a3 - 1) << v9;
    *(_DWORD *)(a1 + 5812) = v9 + 5;
  }
  else
  {
    v10 = (a3 - 1) << v9;
    v11 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v10;
    *(_BYTE *)(v11 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
    v12 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v12 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(a3 - 1) >> (16 - v12);
  }
  v13 = *(_DWORD *)(a1 + 5812);
  if ( v13 <= 12 )
  {
    *(_WORD *)(a1 + 5808) |= (v5 - 4) << v13;
    *(_DWORD *)(a1 + 5812) = v13 + 4;
  }
  else
  {
    v14 = (v5 - 4) << v13;
    v15 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v14;
    *(_BYTE *)(v15 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
    v16 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v16 - 12;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(v5 - 4) >> (16 - v16);
  }
  for ( i = 0; i < v5; ++i )
  {
    v18 = *(_DWORD *)(a1 + 5812);
    v19 = (unsigned __int8)byte_748104[i];
    if ( v18 <= 13 )
    {
      *(_WORD *)(a1 + 5808) |= *(_WORD *)(a1 + 4 * v19 + 2678) << v18;
      *(_DWORD *)(a1 + 5812) = v18 + 3;
    }
    else
    {
      v20 = *(_WORD *)(a1 + 4 * v19 + 2678);
      v21 = v20 << v18;
      v22 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) |= v21;
      *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
      *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5809);
      v23 = *(_DWORD *)(a1 + 5812);
      ++*(_DWORD *)(a1 + 20);
      v5 = a4;
      *(_DWORD *)(a1 + 5812) = v23 - 13;
      *(_WORD *)(a1 + 5808) = v20 >> (16 - v23);
    }
  }
  v24 = sub_6D9938(a1, a2 - 1, a1 + 140);
  return sub_6D9938(v24, a3 - 1, v24 + 2432);
}
