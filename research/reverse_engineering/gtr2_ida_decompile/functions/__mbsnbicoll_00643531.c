int __cdecl _mbsnbicoll(const unsigned __int8 *Str1, const unsigned __int8 *Str2, size_t MaxCount)
{
  _DWORD *v3; // eax
  int v5; // eax

  v3 = (_DWORD *)_getptd()[24];
  if ( v3 != dword_FBB260 )
    v3 = (_DWORD *)sub_640F4B();
  if ( !MaxCount )
    return 0;
  v5 = __crtCompareStringA(v3[3], 1, Str1, MaxCount, Str2, MaxCount, v3[1]);
  if ( v5 )
    return v5 - 2;
  else
    return 0x7FFFFFFF;
}
