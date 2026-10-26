int __cdecl sub_58A163(int a1, int a2, int a3)
{
  int v3; // edi
  int v4; // ebx

  StreamBufferLockViaCriticalSection(a1);
  v3 = sub_58E41B(a1);
  v4 = sub_58D04D(a1, a2, a3);
  ClearStructFieldsIfFlagSet(v3, a1);
  AddressRangeCriticalSectionLeave(a1);
  return v4;
}

