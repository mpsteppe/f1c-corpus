int __stdcall sub_49C310(char *lpSrcStr, int a2)
{
  const CHAR *v2; // esi
  int v3; // eax

  v2 = strcpy(lpSrcStr, asc_5CCE54);
  if ( !*(_DWORD *)(dword_7C54E0 + 16484) )
  {
    v3 = *(_DWORD *)(dword_7C54E0 + 16592);
    if ( v3 )
    {
      StringFormatWithBufferOverflowCheck(v2, "%s:", (const char *)(v3 + 18168));
      sub_589901(v2);
    }
  }
  return 0;
}
