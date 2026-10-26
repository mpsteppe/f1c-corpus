int __cdecl mbtowc(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes)
{
  UINT *v3; // eax

  v3 = (UINT *)_getptd()[25];
  if ( v3 != off_91290C )
    v3 = (UINT *)__updatetlocinfo();
  return __mbtowc_mt(v3, DstCh, (unsigned __int8 *)SrcCh, SrcSizeInBytes);
}
