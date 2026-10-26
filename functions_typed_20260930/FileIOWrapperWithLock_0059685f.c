int __cdecl sub_59685F(int a1, unsigned int a2)
{
  int v2; // esi

  StreamBufferLockViaCriticalSection(a2);
  v2 = sub_596888(a1, a2);
  AddressRangeCriticalSectionLeave(a2);
  return v2;
}

