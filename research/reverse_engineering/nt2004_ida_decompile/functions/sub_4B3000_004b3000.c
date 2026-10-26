char sub_4B3000()
{
  unsigned int v0; // eax
  int v1; // edx
  char result; // al

  if ( dword_75CBB0 != 7 )
    return 0;
  v0 = sub_4FA870(0);
  if ( v0 >= 0x30 )
    return 0;
  v1 = dword_6310D8[6326 * v0];
  result = 1;
  if ( v1 < dword_7D74B8 - 1 )
    return 0;
  return result;
}
