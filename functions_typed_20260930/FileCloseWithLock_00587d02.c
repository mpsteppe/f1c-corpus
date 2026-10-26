int __cdecl sub_587D02(int a1)
{
  int v1; // edi

  v1 = -1;
  if ( (*(_BYTE *)(a1 + 12) & 0x40) != 0 )
  {
    *(_DWORD *)(a1 + 12) = 0;
  }
  else
  {
    StreamBufferLockViaCriticalSection(a1);
    v1 = MSVCCRTFileClose(a1);
    AddressRangeCriticalSectionLeave(a1);
  }
  return v1;
}

