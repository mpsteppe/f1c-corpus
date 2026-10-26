int __cdecl mbtowc(wchar_t *DstCh, const char *SrcCh, size_t SrcSizeInBytes)
{
  int v3; // ebx
  size_t SrcSizeInBytesa; // [esp+1Ch] [ebp+10h]

  InterlockedIncrement(&dword_80151C);
  v3 = 0;
  if ( dword_801518 )
  {
    InterlockedDecrement(&dword_80151C);
    _lock(19);
    v3 = 1;
  }
  SrcSizeInBytesa = _mbtowc_lk(DstCh, SrcCh, SrcSizeInBytes);
  if ( v3 )
    _unlock(19);
  else
    InterlockedDecrement(&dword_80151C);
  return SrcSizeInBytesa;
}
