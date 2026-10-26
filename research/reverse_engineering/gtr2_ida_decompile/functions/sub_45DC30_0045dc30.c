BOOL __stdcall sub_45DC30(int a1, int a2)
{
  int v2; // eax

  if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
  {
    v2 = dword_B69660;
    dword_B69640[dword_B69660] = *(_DWORD *)(a1 + 24);
    dword_B69660 = v2 + 1;
  }
  return (unsigned int)dword_B69660 < 8;
}
