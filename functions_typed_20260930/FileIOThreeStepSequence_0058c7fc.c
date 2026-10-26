__int64 __cdecl sub_58C7FC(unsigned int a1)
{
  __int64 v1; // kr00_8

  StreamBufferLockViaCriticalSection(a1);
  v1 = sub_58C824(a1);
  AddressRangeCriticalSectionLeave(a1);
  return v1;
}

