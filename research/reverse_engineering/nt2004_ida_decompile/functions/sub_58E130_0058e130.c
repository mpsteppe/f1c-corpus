_WORD *sub_58E130()
{
  int *v0; // eax
  _WORD *result; // eax

  dword_7E484C = 0;
  dword_7E4850 = 0;
  dword_7E4848 = -1;
  v0 = &dword_7E49D8;
  do
  {
    *(v0 - 1) = 0;
    *v0 = 0;
    *((_BYTE *)v0 + 4) = 0;
    *((_BYTE *)v0 + 5) = 0;
    *((_BYTE *)v0 + 7) = 0;
    v0 += 23;
  }
  while ( (int)v0 < (int)&dword_7E4CB8 );
  result = &unk_7E4856;
  do
  {
    *(result - 1) = -1;
    *result = -1;
    result[1] = 0;
    result[2] = 0;
    result += 4;
  }
  while ( (int)result < (int)((_WORD *)&dword_7E49D4 + 1) );
  return result;
}
