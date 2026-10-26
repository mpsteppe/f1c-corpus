int *sub_45E390()
{
  int v0; // eax

  v0 = 0;
  dword_764DB4 = 0;
  dword_764DB8 = 0;
  dword_764DBC = 0;
  dword_764DC0 = 0;
  do
  {
    *((_BYTE *)&dword_764DB4 + v0) = byte_5D6440[v0] ^ 0x3E;
    ++v0;
  }
  while ( v0 < 6 );
  return &dword_764DB4;
}
