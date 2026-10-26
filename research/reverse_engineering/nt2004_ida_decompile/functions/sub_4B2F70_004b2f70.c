char sub_4B2F70()
{
  unsigned int v0; // eax
  bool v1; // zf
  char result; // al

  if ( dword_75CBB0 != 7 )
    return 0;
  v0 = sub_4FA870(0);
  if ( v0 >= 0x30 )
    return 0;
  v1 = dword_631104[6326 * v0] == 1;
  result = 1;
  if ( !v1 )
    return 0;
  return result;
}
