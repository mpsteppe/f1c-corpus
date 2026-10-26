__int16 __cdecl sub_59BDE9(unsigned int a1)
{
  __int16 v1; // di

  StreamBufferLockViaCriticalSection(a1);
  v1 = sub_59BE0C(a1);
  AddressRangeCriticalSectionLeave(a1);
  return v1;
}

