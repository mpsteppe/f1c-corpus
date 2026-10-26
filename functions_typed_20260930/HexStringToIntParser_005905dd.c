int __cdecl sub_5905DD(char *a1)
{
  int result; // eax
  char v3; // cl

  for ( result = 0; ; result = v3 + 16 * (result + 268435453) )
  {
    v3 = *a1++;
    if ( !v3 )
      break;
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

