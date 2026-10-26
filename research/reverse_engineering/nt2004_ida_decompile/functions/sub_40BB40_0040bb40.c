int __stdcall sub_40BB40(char *Buffer, int a2)
{
  const char *v2; // eax

  v2 = *(const char **)dword_62A0D0;
  if ( !*(_DWORD *)dword_62A0D0 )
    v2 = &byte_629120;
  return sub_405480(Buffer, a2 - 1, "%s%s", v2, aCamsCam);
}
