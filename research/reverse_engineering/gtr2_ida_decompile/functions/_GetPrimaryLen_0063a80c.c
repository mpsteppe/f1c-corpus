int __fastcall GetPrimaryLen(int a1, char *a2)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; ++result )
  {
    v3 = *a2++;
    if ( (v3 < 65 || v3 > 90) && (v3 < 97 || v3 > 122) )
      break;
  }
  return result;
}
