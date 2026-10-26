BOOL __stdcall sub_44EDD0(int a1, int a2)
{
  int v2; // eax

  if ( (*(_BYTE *)(a1 + 28) & 1) != 0 )
  {
    v2 = dword_7CD07C;
    dword_7CC9CC[dword_7CD07C] = *(_DWORD *)(a1 + 24);
    dword_7CD07C = v2 + 1;
  }
  return (unsigned int)dword_7CD07C < 8;
}
