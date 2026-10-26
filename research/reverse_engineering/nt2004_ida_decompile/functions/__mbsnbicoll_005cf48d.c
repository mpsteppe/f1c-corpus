int __cdecl _mbsnbicoll(const unsigned __int8 *Str1, const unsigned __int8 *Str2, size_t MaxCount)
{
  int v4; // eax

  if ( !MaxCount )
    return 0;
  v4 = __crtCompareStringA(dword_8003A4, 1u, (PCNZCH)Str1, MaxCount, (PCNZCH)Str2, MaxCount, dword_800180);
  if ( v4 )
    return v4 - 2;
  else
    return 0x7FFFFFFF;
}
