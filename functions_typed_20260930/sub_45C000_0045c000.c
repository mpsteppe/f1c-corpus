char sub_45C000()
{
  int v0; // eax

  LOBYTE(v0) = byte_7CD26C;
  if ( byte_7CD26C )
  {
    v0 = CloseHandle(dword_7CD264);
    if ( v0 )
      dword_7CD264 = 0;
  }
  return v0;
}

