char __thiscall sub_462550(int *this, _BYTE *a2, int a3)
{
  int v4; // ecx
  _BYTE *v5; // esi
  int v6; // ecx
  int v7; // esi
  _DWORD *v8; // edi
  LPVOID *v9; // ebx
  char v10; // al
  int v11; // eax
  const char *v12; // edx
  int v13; // ebx
  const char *v14; // ecx
  _DWORD *v15; // esi
  int v16; // eax
  char v17; // bl
  _DWORD v19[12]; // [esp-38h] [ebp-50h] BYREF
  char v20; // [esp+13h] [ebp-5h]
  _BYTE *v21; // [esp+14h] [ebp-4h]

  v4 = *(_DWORD *)(*this + 16312);
  v20 = 0;
  v5 = (_BYTE *)VTableQueryWithStackBufferResult(v4);
  v21 = v5;
  sub_587DD0(v5 + 8, a2, 31);
  v5[39] = 0;
  v5[40] = 1;
  v6 = *(_DWORD *)(*this + 428);
  if ( v6 <= 0 )
  {
    v5[43] = dword_7D0FC4;
    a2[102] = dword_7D0FC4;
  }
  else
  {
    v5[43] = v6;
    a2[102] = *(_BYTE *)(*this + 428);
  }
  MemcpyLikeCopyWithWordByteSplitSizeStore(a2, 128);
  qmemcpy((void *)(*this + 52), a2, 0x80u);
  StringCopyToStructField(a3);
  qmemcpy(v19, &unk_7CD270, sizeof(v19));
  if ( VirtualFunctionDispatchWithStackFrames(
         v19[0],
         v19[1],
         v19[2],
         v19[3],
         v19[4],
         v19[5],
         v19[6],
         v19[7],
         v19[8],
         v19[9],
         v19[10],
         v19[11],
         v21,
         a3) )
  {
    v17 = v20;
  }
  else
  {
    if ( BitFlagTestAt0x6E(a2, 0) )
      *(_DWORD *)(*this + 16324) = 1;
    else
      *(_DWORD *)(*this + 16324) = 2;
    BufferFillWith0xFFFFFFFF(*this);
    v7 = *(_DWORD *)(*this + 16328);
    v8 = (_DWORD *)(*this + 16328);
    while ( v7 )
    {
      v9 = (LPVOID *)v7;
      v10 = *(_BYTE *)(v7 + 8);
      v7 = *(_DWORD *)(v7 + 4);
      if ( v10 )
        FreeWrapper_7bcf(*v9);
      FreeWrapper_7bcf(v9);
    }
    *v8 = 0;
    v8[1] = 0;
    v8[2] = 0;
    v8[3] = 0;
    if ( SessionStateCheck(this) != 1 )
    {
      v11 = OperatorNewNhMallocWrapper(128);
      v12 = (const char *)dword_7CE64C;
      v13 = v11;
      if ( !dword_7CE64C )
        v12 = byte_5EA438;
      v14 = &v12[strlen(v12)];
      if ( v14 > v12 )
      {
        while ( *v14 != 92 )
        {
          if ( --v14 <= v12 )
            goto LABEL_20;
        }
        ++v14;
      }
LABEL_20:
      sub_587DD0(v11, v14, 127);
      *(_BYTE *)(v13 + 127) = 0;
      v15 = (_DWORD *)(*this + 16328);
      v16 = OperatorNewNhMallocWrapper(12);
      if ( v16 )
      {
        *(_DWORD *)v16 = v13;
        *(_DWORD *)(v16 + 4) = 0;
        *(_BYTE *)(v16 + 8) = 1;
      }
      else
      {
        v16 = 0;
      }
      if ( *v15 )
      {
        *(_DWORD *)(v15[1] + 4) = v16;
      }
      else
      {
        *v15 = v16;
        v15[2] = v16;
      }
      v15[1] = v16;
      ++v15[3];
    }
    FileScanner((_BYTE *)(*this + 112468));
    v17 = 1;
  }
  VTableCallViaOffset0x7c(*(_DWORD *)(*this + 16312), v21);
  return v17;
}
