int __cdecl sub_589FCC(_DWORD *a1)
{
  int v2; // edi

  StreamBufferLockViaCriticalSection(a1);
  if ( --a1[1] < 0 )
    v2 = sub_58C255(a1);
  else
    v2 = *(unsigned __int8 *)(*a1)++;
  AddressRangeCriticalSectionLeave(a1);
  return v2;
}

