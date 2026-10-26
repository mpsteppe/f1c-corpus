// f1c  0x00596c20  size=92
char __cdecl sub_596C20(unsigned int a1, char *a2, unsigned int a3, int a4)
{
  char *v4; // ecx
  unsigned int v5; // esi
  char *v6; // edi
  int v7; // ebx
  bool v8; // cc
  char v9; // bl
  char *v10; // ecx
  char result; // al

  v4 = a2;
  if ( a4 )
  {
    *a2 = 45;
    v4 = a2 + 1;
    v5 = -a1;
  }
  else
  {
    v5 = a1;
  }
  v6 = v4;
  do
  {
    v7 = v5 % a3;
    v8 = v5 % a3 <= 9;
    v5 /= a3;
    if ( v8 )
      v9 = v7 + 48;
    else
      v9 = v7 + 87;
    *v4++ = v9;
  }
  while ( v5 );
  *v4 = 0;
  v10 = v4 - 1;
  do
  {
    result = *v10;
    *v10 = *v6;
    *v6 = result;
    --v10;
    ++v6;
  }
  while ( v6 < v10 );
  return result;
}
