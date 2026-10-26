// f1c  0x00590616  size=33
int __cdecl sub_590616(char *a1)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; ++result )
  {
    v3 = *a1++;
    if ( (v3 < 65 || v3 > 90) && (v3 < 97 || v3 > 122) )
      break;
  }
  return result;
}
