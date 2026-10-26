int __cdecl sub_58A02C(int a1)
{
  if ( BufferFlushWrite(a1) )
    return -1;
  if ( (*(_BYTE *)(a1 + 13) & 0x40) != 0 )
    return -(sub_592891(*(_DWORD *)(a1 + 16)) != 0);
  return 0;
}

