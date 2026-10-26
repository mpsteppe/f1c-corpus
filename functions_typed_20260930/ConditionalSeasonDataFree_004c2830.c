char __thiscall sub_4C2830(void *this, int a2)
{
  int v2; // eax

  v2 = LinkedListDereference(this);
  if ( v2 )
    LOBYTE(v2) = RaceStandingsRankingsComputation(v2);
  return v2;
}

