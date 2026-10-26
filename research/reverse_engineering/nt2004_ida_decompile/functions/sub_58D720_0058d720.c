int sub_58D720()
{
  int *v0; // eax
  __int16 *v1; // edx
  void *v2; // edi
  int result; // eax

  v0 = &dword_7FFA60;
  do
  {
    *(v0 - 8) = 0;
    *v0 = -1;
    v0[8] = -1;
    ++v0;
  }
  while ( (int)v0 < (int)&dword_7FFA80 );
  dword_7FFAA0 = 0;
  v1 = &word_7FFAA8;
  do
  {
    *((_BYTE *)v1 + 2) = 0;
    *v1 = 0;
    *((_DWORD *)v1 - 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    *((_BYTE *)v1 + 3) = -1;
    v2 = v1 + 6;
    v1 += 48;
    result = 0;
    memset(v2, 0, 0x50u);
  }
  while ( (int)v1 < (int)&word_8000A8 );
  dword_7FF9E8 = 0;
  word_7FF9E0 = 0;
  return result;
}
