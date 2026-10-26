int __stdcall sub_4D0F40(char *Buffer, int a2)
{
  const char *v2; // eax

  v2 = *(const char **)dword_91CAB0;
  if ( !*(_DWORD *)dword_91CAB0 )
    v2 = WindowName;
  return sub_41D810(Buffer, a2 - 1, "%s%s", v2, "ListAssets.GTR");
}
