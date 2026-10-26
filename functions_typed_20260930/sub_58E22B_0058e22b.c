int __cdecl sub_58E22B(int a1, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite)
{
  int v3; // edi

  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    CriticalSectionEnterWithLazyInit(a1);
    v3 = sub_58E290(a1, lpBuffer, nNumberOfBytesToWrite);
    FileCriticalSectionLeave(a1);
    return v3;
  }
  else
  {
    *(_DWORD *)TLSOffsetGetter() = 9;
    *(_DWORD *)TLSOffsetGetter_afd8() = 0;
    return -1;
  }
}

