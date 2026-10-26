int __cdecl sub_595F11(int a1, int a2, int a3, DWORD dwMoveMethod)
{
  int v4; // edi

  if ( a1 < uNumber && (*(_BYTE *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4) & 1) != 0 )
  {
    CriticalSectionEnterWithLazyInit(a1);
    v4 = FilePointerSeekWithErrorHandling(a1, a2, a3, dwMoveMethod);
    FileCriticalSectionLeave(a1);
    return v4;
  }
  else
  {
    *(_DWORD *)TLSOffsetGetter() = 9;
    *(_DWORD *)TLSOffsetGetter_afd8() = 0;
    return -1;
  }
}

