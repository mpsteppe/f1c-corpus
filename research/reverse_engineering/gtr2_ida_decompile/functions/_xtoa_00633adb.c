char __usercall xtoa@<al>(unsigned int a1@<eax>, char *a2@<ecx>, unsigned int a3, int a4)
{
  char *v4; // esi
  char v5; // dl
  unsigned int v6; // et2
  char v7; // dl
  char *v8; // ecx
  char result; // al

  if ( a4 )
  {
    *a2++ = 45;
    a1 = -a1;
  }
  v4 = a2;
  do
  {
    v6 = a1 % a3;
    a1 /= a3;
    v5 = v6;
    if ( v6 <= 9 )
      v7 = v5 + 48;
    else
      v7 = v5 + 87;
    *a2++ = v7;
  }
  while ( a1 );
  *a2 = 0;
  v8 = a2 - 1;
  do
  {
    result = *v8;
    *v8-- = *v4;
    *v4++ = result;
  }
  while ( v4 < v8 );
  return result;
}
