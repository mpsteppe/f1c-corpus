// f1c  0x0058bccf  size=90
char __cdecl sub_58BCCF(char *a1)
{
  char *v1; // esi
  int v2; // eax
  char result; // al
  char *v4; // esi
  char v5; // cl

  v1 = a1;
  if ( sub_58B465(*a1) != 101 )
  {
    do
    {
      ++v1;
      if ( cbMultiByte <= 1 )
        v2 = off_5E69C8[0][*v1] & 4;
      else
        v2 = sub_58C674(*v1, 4);
    }
    while ( v2 );
  }
  result = *v1;
  *v1 = byte_5E6BD8;
  v4 = v1 + 1;
  do
  {
    v5 = *v4;
    *v4 = result;
    result = v5;
  }
  while ( *v4++ );
  return result;
}
