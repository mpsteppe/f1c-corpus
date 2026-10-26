int __cdecl sub_58C331(int a1)
{
  int v1; // edi

  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    CriticalSectionEnterWithLazyInit(a1);
    v1 = HandleCloseWithErrorReporting(a1);
    FileCriticalSectionLeave(a1);
    return v1;
  }
  else
  {
    *(_DWORD *)TLSOffsetGetter() = 9;
    *(_DWORD *)TLSOffsetGetter_afd8() = 0;
    return -1;
  }
}
