int __cdecl sub_58ACE6(int a1)
{
  int v1; // edi

  StreamBufferLockViaCriticalSection(a1);
  v1 = sub_58AD08(a1);
  AddressRangeCriticalSectionLeave(a1);
  return v1;
}

