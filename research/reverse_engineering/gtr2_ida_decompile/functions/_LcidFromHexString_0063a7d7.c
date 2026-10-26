int __fastcall LcidFromHexString(int a1, char *a2)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; result = v3 + 16 * (result + 268435453) )
  {
    v3 = *a2;
    if ( !*a2 )
      break;
    ++a2;
    if ( v3 < 97 || v3 > 102 )
    {
      if ( v3 >= 65 && v3 <= 70 )
        v3 -= 7;
    }
    else
    {
      v3 -= 39;
    }
  }
  return result;
}
