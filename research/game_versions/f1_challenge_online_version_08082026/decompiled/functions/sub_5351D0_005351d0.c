char *__fastcall sub_5351D0(int a1, char *a2, int a3)
{
  char *v3; // esi
  int v6; // edi
  char v7; // al

  v3 = a2;
  if ( !a2 )
    return 0;
  v6 = a3;
  if ( a3 <= 0 )
    return 0;
  do
  {
    if ( --v6 <= 0 )
      break;
    if ( sub_534F90(a1, (int)v3, 1) != 1 )
      break;
    v7 = *v3++;
  }
  while ( v7 != 10 );
  *v3 = 0;
  if ( a2 == v3 && v6 > 0 )
    return 0;
  else
    return a2;
}
