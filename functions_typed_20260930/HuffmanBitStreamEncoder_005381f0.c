_WORD *__fastcall sub_5381F0(int a1, int a2, int a3, int a4)
{
  int v5; // eax
  unsigned int v7; // edx
  unsigned int v8; // ecx
  int v9; // edi
  bool v10; // zf
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  char v15; // bl
  int v16; // edx
  int v17; // edx
  int v18; // edx
  int v19; // ebx
  int v20; // ecx
  int v21; // ebx
  char v22; // al
  int v23; // ecx
  int v24; // ebx
  _WORD *result; // eax
  int v26; // [esp+18h] [ebp+8h]

  v5 = 0;
  if ( *(int *)(a1 + 122) <= 0 )
  {
    v8 = a3 + 5;
LABEL_7:
    v7 = v8;
    goto LABEL_8;
  }
  if ( *(_BYTE *)(a1 + 28) == 2 )
    BufferChecksumValidator(a1);
  sub_5383D0(a1, a1 + 2830);
  sub_5383D0(a1, a1 + 2842);
  v5 = PerformanceSectorTimeAccumulator(a1);
  v7 = (unsigned int)(*(_DWORD *)(a1 + 5787) + 10) >> 3;
  v8 = (unsigned int)(*(_DWORD *)(a1 + 5791) + 10) >> 3;
  if ( v8 <= v7 )
    goto LABEL_7;
LABEL_8:
  if ( a3 + 4 <= v7 && a2 )
  {
    v9 = a4;
    BitstreamWriteBits(a1, a3, a4);
  }
  else
  {
    v9 = a4;
    v10 = v8 == v7;
    v11 = *(_DWORD *)(a1 + 5805);
    if ( v10 )
    {
      v12 = a4 + 2;
      if ( v11 <= 13 )
      {
        *(_WORD *)(a1 + 5803) |= v12 << v11;
        *(_DWORD *)(a1 + 5805) = v11 + 3;
      }
      else
      {
        v13 = v12 << v11;
        v14 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5803) |= v13;
        *(_BYTE *)(v14 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5803);
        v15 = *(_BYTE *)(a1 + 5804);
        v16 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v16;
        *(_BYTE *)(v16 + *(_DWORD *)(a1 + 8)) = v15;
        v17 = *(_DWORD *)(a1 + 5805);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5805) = v17 - 13;
        *(_WORD *)(a1 + 5803) = (unsigned __int16)v12 >> (16 - v17);
      }
      HuffmanBitStreamDecoder(&unk_5B8280);
    }
    else
    {
      v18 = a4 + 4;
      if ( v11 <= 13 )
      {
        *(_WORD *)(a1 + 5803) |= v18 << v11;
        *(_DWORD *)(a1 + 5805) = v11 + 3;
      }
      else
      {
        v26 = v5;
        v19 = v18 << v11;
        v20 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5803) |= v19;
        *(_BYTE *)(v20 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5803);
        v21 = *(_DWORD *)(a1 + 8);
        v22 = *(_BYTE *)(a1 + 5804);
        v23 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v23;
        *(_BYTE *)(v23 + v21) = v22;
        v24 = *(_DWORD *)(a1 + 5805);
        ++*(_DWORD *)(a1 + 20);
        v5 = v26;
        *(_DWORD *)(a1 + 5805) = v24 - 13;
        *(_WORD *)(a1 + 5803) = (unsigned __int16)v18 >> (16 - v24);
      }
      BitBufferWriter(*(_DWORD *)(a1 + 2846) + 1, v5 + 1);
      HuffmanBitStreamDecoder(a1 + 2430);
    }
  }
  result = ScorecardZero(a1);
  if ( v9 )
    return (_WORD *)UnicodeBufferFlusher();
  return result;
}

