// f1c  0x0053c590  size=29
char *__stdcall sub_53C590(int a1, char *a2)
{
  char *result; // eax
  char v3; // cl

  result = a2;
  if ( a2 )
  {
    do
    {
      v3 = *result;
      result[byte_8B6AC8 - a2] = *result;
      ++result;
    }
    while ( v3 );
  }
  return result;
}
