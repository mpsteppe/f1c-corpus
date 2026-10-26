__int16 __cdecl sub_59BBAF(int a1, unsigned int a2)
{
  __int16 v2; // si

  StreamBufferLockViaCriticalSection(a2);
  v2 = sub_59BBD9(a1, a2);
  AddressRangeCriticalSectionLeave(a2);
  return v2;
}

