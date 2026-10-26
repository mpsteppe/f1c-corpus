int sub_5887B1(int a1, int a2, ...)
{
  int v2; // edi
  int v3; // ebx
  va_list va; // [esp+18h] [ebp+Ch] BYREF

  va_start(va, a2);
  StreamBufferLockViaCriticalSection(a1);
  v2 = sub_58E41B(a1);
  v3 = sub_58D04D(a1, a2, va);
  ClearStructFieldsIfFlagSet(v2, a1);
  AddressRangeCriticalSectionLeave(a1);
  return v3;
}
