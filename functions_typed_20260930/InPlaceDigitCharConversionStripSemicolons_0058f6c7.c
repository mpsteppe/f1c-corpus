char __cdecl sub_58F6C7(char *a1)
{
  char *v1; // ecx
  char result; // al
  char *v3; // eax

  v1 = a1;
  for ( result = *a1; *v1; result = *v1 )
  {
    if ( result < 48 || result > 57 )
    {
      if ( result == 59 )
      {
        v3 = v1;
        do
        {
          *v3 = v3[1];
          ++v3;
        }
        while ( *v3 );
        continue;
      }
    }
    else
    {
      *v1 = result - 48;
    }
    ++v1;
  }
  return result;
}

