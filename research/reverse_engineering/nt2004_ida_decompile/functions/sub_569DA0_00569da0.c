char *__thiscall sub_569DA0(char *Destination, char *Source, char *a3, char a4, int a5)
{
  char *v6; // eax
  int v7; // edi

  strncpy(Destination, Source, 9u);
  v6 = Destination;
  v7 = 4;
  do
  {
    *v6 |= v6[&a4 - Destination];
    ++v6;
    --v7;
  }
  while ( v7 );
  return strncpy(Destination + 16, a3, 4u);
}
