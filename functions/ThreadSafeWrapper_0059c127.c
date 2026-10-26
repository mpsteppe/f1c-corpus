int __cdecl sub_59C127(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // esi

  StreamBufferLockViaCriticalSection(a1);
  v4 = FileSeekWithModeFlagValidation(a1, a2, a3, a4);
  AddressRangeCriticalSectionLeave(a1);
  return v4;
}
