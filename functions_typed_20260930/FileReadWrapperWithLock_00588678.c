int __cdecl sub_588678(int a1, int a2, int a3, int a4)
{
  int v4; // esi

  StreamBufferLockViaCriticalSection(a4);
  v4 = sub_5886A7(a1, a2, a3, a4);
  AddressRangeCriticalSectionLeave(a4);
  return v4;
}

