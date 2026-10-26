char __thiscall sub_500F90(_DWORD *this, int a2, char *a3, int a4)
{
  char v6; // si

  if ( *this < a2 )
    return 0;
  do
  {
    v6 = (_BYTE)a3 + 1;
    a3 = strstr(a3 + 1, word_5FB9F4);
  }
  while ( a3 );
  sub_500FE0((int)this, a1212s5d, v6);
  return 1;
}
