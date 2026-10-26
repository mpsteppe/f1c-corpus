int __cdecl sub_587F64(int a1, int a2, int a3)
{
  int v3; // esi

  StreamBufferLockViaCriticalSection(a1);
  v3 = FileTellSeekPositionQuery(a1, a2, a3);
  AddressRangeCriticalSectionLeave(a1);
  return v3;
}
