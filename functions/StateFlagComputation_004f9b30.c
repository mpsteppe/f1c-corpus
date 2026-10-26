int __stdcall sub_4F9B30(char a1)
{
  int v1; // eax
  int result; // eax

  v1 = 2 - sub_4F9B20();
  if ( a1 || byte_7CE254 )
    v1 |= 4u;
  result = CallWrapper_c060(v1);
  if ( result == -2 )
    byte_8AFE72 = 1;
  return result;
}
