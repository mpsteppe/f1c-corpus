int __cdecl sub_589898(int a1, _DWORD *a2)
{
  int v3; // edi

  StreamBufferLockViaCriticalSection(a2);
  if ( --a2[1] < 0 )
  {
    v3 = sub_58CF35(a1, a2);
  }
  else
  {
    v3 = (unsigned __int8)a1;
    *(_BYTE *)(*a2)++ = a1;
  }
  AddressRangeCriticalSectionLeave(a2);
  return v3;
}

