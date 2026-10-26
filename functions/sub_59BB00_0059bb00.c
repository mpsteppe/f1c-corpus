int __cdecl sub_59BB00(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // edi
  int v6; // ecx
  int v7; // eax
  int v8; // [esp+8h] [ebp-4h]

  v8 = 0;
  if ( a3 != 4 && (a4 < 2 || a3 && a3 != 64) )
    return -1;
  v5 = a4 & 0xFFFFFFFE;
  StreamBufferLockViaCriticalSection(a1);
  BufferFlushWrite((_DWORD *)a1);
  sub_58C411(a1);
  *(_WORD *)(a1 + 12) &= 0xC2F3u;
  v6 = *(_DWORD *)(a1 + 12);
  if ( (a3 & 4) != 0 )
  {
    *(_DWORD *)(a1 + 12) = v6 | 4;
    v7 = a1 + 20;
    v5 = 2;
LABEL_13:
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 24) = v5;
    *(_DWORD *)(a1 + 8) = v7;
    *(_DWORD *)a1 = v7;
    goto LABEL_14;
  }
  v7 = a2;
  if ( a2 )
  {
    BYTE1(v6) |= 5u;
    *(_DWORD *)(a1 + 12) = v6;
    goto LABEL_13;
  }
  v7 = MallocWrapperForNhMalloc(v5);
  if ( v7 )
  {
    *(_WORD *)(a1 + 12) |= 0x408u;
    goto LABEL_13;
  }
  ++dword_8D3EC8;
  v8 = -1;
LABEL_14:
  AddressRangeCriticalSectionLeave(a1);
  return v8;
}
