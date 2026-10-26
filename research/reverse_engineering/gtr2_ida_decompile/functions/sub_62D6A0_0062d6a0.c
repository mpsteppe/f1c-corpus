int __userpurge sub_62D6A0@<eax>(int a1@<eax>, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // ebx
  int v7; // edx
  int v8; // ecx
  char v9; // bl
  int v10; // edx
  int v11; // edx
  int v12; // ecx
  unsigned __int16 v13; // si
  int v14; // edx
  int v15; // ecx
  char v16; // bl
  int v17; // edx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  char v22; // bl
  int v23; // edx
  int v24; // edx
  int v25; // edi
  int v26; // ecx
  int v27; // edx
  unsigned __int16 v28; // si
  int v29; // edx
  int v30; // ecx
  char v31; // bl
  int v32; // edx
  int v33; // edx
  int v34; // eax
  int v36; // [esp+1Ch] [ebp+Ch]
  int v37; // [esp+1Ch] [ebp+Ch]

  v4 = *(_DWORD *)(a1 + 5805);
  v5 = a3;
  if ( v4 <= 11 )
  {
    *(_WORD *)(a1 + 5803) |= (a2 - 257) << v4;
    *(_DWORD *)(a1 + 5805) = v4 + 5;
  }
  else
  {
    v7 = (a2 - 257) << v4;
    v8 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5803) |= v7;
    *(_BYTE *)(v8 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
    v9 = *(_BYTE *)(a1 + 5804);
    v10 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v10;
    *(_BYTE *)(v10 + *(_DWORD *)(a1 + 8)) = v9;
    v11 = *(_DWORD *)(a1 + 5805);
    v5 = a3;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5805) = v11 - 11;
    *(_WORD *)(a1 + 5803) = (unsigned __int16)(a2 - 257) >> (16 - v11);
  }
  v12 = *(_DWORD *)(a1 + 5805);
  if ( v12 <= 11 )
  {
    *(_WORD *)(a1 + 5803) |= (v5 - 1) << v12;
    *(_DWORD *)(a1 + 5805) = v12 + 5;
  }
  else
  {
    v13 = v5 - 1;
    v14 = (v5 - 1) << v12;
    v15 = *(_DWORD *)(a1 + 20);
    v36 = v5;
    *(_WORD *)(a1 + 5803) |= v14;
    *(_BYTE *)(v15 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
    v16 = *(_BYTE *)(a1 + 5804);
    v17 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v17;
    *(_BYTE *)(v17 + *(_DWORD *)(a1 + 8)) = v16;
    v18 = *(_DWORD *)(a1 + 5805);
    v5 = v36;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5805) = v18 - 11;
    *(_WORD *)(a1 + 5803) = v13 >> (16 - v18);
  }
  v19 = *(_DWORD *)(a1 + 5805);
  if ( v19 <= 12 )
  {
    *(_WORD *)(a1 + 5803) |= (a4 - 4) << v19;
    *(_DWORD *)(a1 + 5805) = v19 + 4;
  }
  else
  {
    v20 = (a4 - 4) << v19;
    v21 = *(_DWORD *)(a1 + 20);
    v37 = v5;
    *(_WORD *)(a1 + 5803) |= v20;
    *(_BYTE *)(v21 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
    v22 = *(_BYTE *)(a1 + 5804);
    v23 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v23;
    *(_BYTE *)(v23 + *(_DWORD *)(a1 + 8)) = v22;
    v24 = *(_DWORD *)(a1 + 5805);
    v5 = v37;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5805) = v24 - 12;
    *(_WORD *)(a1 + 5803) = (unsigned __int16)(a4 - 4) >> (16 - v24);
  }
  v25 = 0;
  if ( a4 > 0 )
  {
    do
    {
      v26 = *(_DWORD *)(a1 + 5805);
      v27 = (unsigned __int8)byte_72F444[v25];
      if ( v26 <= 13 )
      {
        *(_WORD *)(a1 + 5803) |= *(_WORD *)(a1 + 4 * v27 + 2676) << v26;
        *(_DWORD *)(a1 + 5805) = v26 + 3;
      }
      else
      {
        v28 = *(_WORD *)(a1 + 4 * v27 + 2676);
        v29 = v28 << v26;
        v30 = *(_DWORD *)(a1 + 20);
        *(_WORD *)(a1 + 5803) |= v29;
        *(_BYTE *)(v30 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
        v31 = *(_BYTE *)(a1 + 5804);
        v32 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v32;
        *(_BYTE *)(v32 + *(_DWORD *)(a1 + 8)) = v31;
        v33 = *(_DWORD *)(a1 + 5805);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5805) = v33 - 13;
        *(_WORD *)(a1 + 5803) = v28 >> (16 - v33);
      }
      ++v25;
    }
    while ( v25 < a4 );
    v5 = a3;
  }
  v34 = sub_62D190(a1, a1 + 138, a2 - 1);
  return sub_62D190(v34, v34 + 2430, v5 - 1);
}
