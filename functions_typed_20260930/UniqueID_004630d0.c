bool __thiscall sub_4630D0(void *this, int a2)
{
  bool v3; // bl
  int v4; // edi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  v4 = VTableQueryWithStackBufferResult(*(_DWORD *)(*(_DWORD *)this + 16312));
  if ( !COMVTableCallVia0xc4(v4) )
  {
    v6 = 128;
    ByteAlignedMemoryCopyFromStruct(a2, &v6);
    v3 = v6 == 128;
  }
  VTableCallViaOffset0x7c(*(_DWORD *)(*(_DWORD *)this + 16312), v4);
  return v3;
}

