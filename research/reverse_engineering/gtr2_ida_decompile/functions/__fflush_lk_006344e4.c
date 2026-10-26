int __cdecl _fflush_lk(int a1)
{
  if ( _flush((_DWORD *)a1) )
    return -1;
  if ( (*(_BYTE *)(a1 + 13) & 0x40) != 0 )
    return -(_commit(*(_DWORD *)(a1 + 16)) != 0);
  return 0;
}
