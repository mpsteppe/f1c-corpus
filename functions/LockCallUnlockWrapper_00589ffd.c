int __cdecl sub_589FFD(int a1)
{
  int v2; // edi

  if ( !a1 )
    return sub_58A0BF(0);
  StreamBufferLockViaCriticalSection(a1);
  v2 = MemoryBlockValidationCheck(a1);
  AddressRangeCriticalSectionLeave(a1);
  return v2;
}
