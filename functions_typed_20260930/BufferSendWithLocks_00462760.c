char __thiscall sub_462760(void *this, int a2)
{
  int v3; // edi

  v3 = VTableQueryWithStackBufferResult(*(_DWORD *)(*(_DWORD *)this + 16312));
  COMVTableCallVia0xc4(v3);
  MemcpyLikeCopyWithWordByteSplitSizeStore(a2, 128);
  VirtualDispatchWrapper_a8c0(v3);
  VTableCallViaOffset0x7c(*(_DWORD *)(*(_DWORD *)this + 16312), v3);
  return 1;
}

