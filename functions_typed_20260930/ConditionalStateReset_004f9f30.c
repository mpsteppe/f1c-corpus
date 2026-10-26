char sub_4F9F30()
{
  int v0; // eax

  v0 = StructFieldGetter(&dword_8B78A0);
  if ( v0 )
  {
    LOBYTE(v0) = byte_8AFE71;
    if ( byte_8AFE71 )
    {
      byte_8AFE71 = 0;
      LOBYTE(v0) = VTableDispatchGetter(&dword_8B78A0);
    }
  }
  return v0;
}

