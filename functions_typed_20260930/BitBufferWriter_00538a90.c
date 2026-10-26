int __fastcall sub_538A90(int a1, int a2, int a3, int a4)
{
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // ecx
  char v9; // bl
  int v10; // edi
  int v11; // ebx
  int v12; // ecx
  int v13; // eax
  int v14; // edi
  int v15; // ecx
  char v16; // bl
  int v17; // edi
  int v18; // ebx
  int v19; // ecx
  int v20; // eax
  int v21; // edi
  int v22; // ecx
  int v23; // edi
  char v24; // bl
  int v25; // ecx
  int v26; // ebx
  int i; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // edx
  int v31; // ecx
  int v32; // edx
  char v33; // bl
  int v34; // ecx
  int v35; // ebx
  int v37; // [esp+10h] [ebp-4h]

  v37 = a2;
  v5 = *(_DWORD *)(a1 + 5805);
  v6 = a2 - 257;
  if ( v5 <= 11 )
  {
    *(_WORD *)(a1 + 5803) |= v6 << v5;
    *(_DWORD *)(a1 + 5805) = v5 + 5;
  }
  else
  {
    v7 = v6 << v5;
    v8 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5803) |= v7;
    *(_BYTE *)(v8 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
    v9 = *(_BYTE *)(a1 + 5804);
    v10 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v10;
    *(_BYTE *)(v10 + *(_DWORD *)(a1 + 8)) = v9;
    v11 = *(_DWORD *)(a1 + 5805);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5805) = v11 - 11;
    *(_WORD *)(a1 + 5803) = (unsigned __int16)v6 >> (16 - v11);
  }
  v12 = *(_DWORD *)(a1 + 5805);
  v13 = a3 - 1;
  if ( v12 <= 11 )
  {
    *(_WORD *)(a1 + 5803) |= v13 << v12;
    *(_DWORD *)(a1 + 5805) = v12 + 5;
  }
  else
  {
    v14 = v13 << v12;
    v15 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5803) |= v14;
    *(_BYTE *)(v15 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
    v16 = *(_BYTE *)(a1 + 5804);
    v17 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v17;
    *(_BYTE *)(v17 + *(_DWORD *)(a1 + 8)) = v16;
    v18 = *(_DWORD *)(a1 + 5805);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5805) = v18 - 11;
    *(_WORD *)(a1 + 5803) = (unsigned __int16)v13 >> (16 - v18);
  }
  v19 = *(_DWORD *)(a1 + 5805);
  v20 = a4 - 4;
  if ( v19 <= 12 )
  {
    *(_WORD *)(a1 + 5803) |= v20 << v19;
    *(_DWORD *)(a1 + 5805) = v19 + 4;
  }
  else
  {
    v21 = v20 << v19;
    v22 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5803) |= v21;
    *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
    v23 = *(_DWORD *)(a1 + 8);
    v24 = *(_BYTE *)(a1 + 5804);
    v25 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v25;
    *(_BYTE *)(v25 + v23) = v24;
    ++*(_DWORD *)(a1 + 20);
    v26 = *(_DWORD *)(a1 + 5805);
    *(_DWORD *)(a1 + 5805) = v26 - 12;
    *(_WORD *)(a1 + 5803) = (unsigned __int16)v20 >> (16 - v26);
  }
  for ( i = 0; i < a4; ++i )
  {
    v28 = *(_DWORD *)(a1 + 5805);
    v29 = 0;
    if ( v28 <= 13 )
    {
      LOBYTE(v29) = byte_5B7DEC[i];
      *(_WORD *)(a1 + 5803) |= *(_WORD *)(a1 + 4 * v29 + 2676) << v28;
      *(_DWORD *)(a1 + 5805) = v28 + 3;
    }
    else
    {
      LOWORD(v29) = *(_WORD *)(a1 + 4 * (unsigned __int8)byte_5B7DEC[i] + 2676);
      v30 = v29 << v28;
      v31 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5803) |= v30;
      *(_BYTE *)(v31 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5803);
      v32 = *(_DWORD *)(a1 + 8);
      v33 = *(_BYTE *)(a1 + 5804);
      v34 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v34;
      *(_BYTE *)(v34 + v32) = v33;
      ++*(_DWORD *)(a1 + 20);
      v35 = *(_DWORD *)(a1 + 5805);
      a2 = v37;
      *(_DWORD *)(a1 + 5805) = v35 - 13;
      *(_WORD *)(a1 + 5803) = (unsigned __int16)v29 >> (16 - v35);
    }
  }
  CompressionBitstreamPacker(a2 - 1);
  return CompressionBitstreamPacker(a3 - 1);
}

