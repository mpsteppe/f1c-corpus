int __cdecl _fclose_lk(int a1)
{
  int v1; // edi

  v1 = -1;
  if ( (*(_BYTE *)(a1 + 12) & 0x83) != 0 )
  {
    v1 = _flush(a1);
    _freebuf(a1);
    if ( _close(*(_DWORD *)(a1 + 16)) >= 0 )
    {
      if ( *(_DWORD *)(a1 + 28) )
      {
        sub_5C1B88(*(LPVOID *)(a1 + 28));
        *(_DWORD *)(a1 + 28) = 0;
      }
    }
    else
    {
      v1 = -1;
    }
  }
  *(_DWORD *)(a1 + 12) = 0;
  return v1;
}
