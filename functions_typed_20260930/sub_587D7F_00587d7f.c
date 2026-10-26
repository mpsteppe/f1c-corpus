int __cdecl sub_587D7F(const CHAR *a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi
  int v5; // edi

  result = sub_58C5AC();
  v4 = result;
  if ( result )
  {
    v5 = sub_58C43C(a1, a2, a3, result);
    AddressRangeCriticalSectionLeave(v4);
    return v5;
  }
  return result;
}

