int __fastcall sub_562B50(const char *a1, const char *a2, const char *a3, int a4, int a5, int a6, int a7)
{
  int v8; // esi
  void *v9; // edi

  v8 = MallocWrapperForNhMalloc(1464);
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 4) = Malloc0x18ByteStructWithInnerBuffer(sub_5640F0);
  *(_DWORD *)(v8 + 148) = AllocateIntArrayViaFactory(4, sub_5645A0, IndirectDwordCompare, sub_564630);
  *(_DWORD *)(v8 + 108) = a4;
  v9 = (void *)MallocWrapperForNhMalloc(28 * a4);
  *(_DWORD *)(v8 + 8) = v9;
  memset(v9, 0, 4 * ((unsigned int)(28 * a4) >> 2));
  strcpy((char *)(v8 + 12), a1);
  strcpy((char *)(v8 + 44), a3);
  strcpy((char *)(v8 + 76), a2);
  *(_DWORD *)(v8 + 120) = a5;
  *(_DWORD *)(v8 + 124) = a7;
  *(_DWORD *)(v8 + 128) = byte_5EA438;
  *(_DWORD *)(v8 + 152) = 0;
  NetworkStartup();
  return v8;
}

