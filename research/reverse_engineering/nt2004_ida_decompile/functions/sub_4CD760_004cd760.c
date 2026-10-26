int __thiscall sub_4CD760(char *this, char *Destination, int a3)
{
  if ( !Destination || a3 < 1 )
    return -1;
  sub_4CD5B0(this, Destination, a3 - strlen(aChampionshipBc));
  strcat(Destination, "Championship.bch");
  return 0;
}
