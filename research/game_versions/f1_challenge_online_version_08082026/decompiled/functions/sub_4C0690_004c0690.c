char __thiscall sub_4C0690(int *this, _DWORD *a2, int a3)
{
  int v4; // edi
  int *v5; // ebx

  if ( *a2 )
  {
    if ( a3 )
    {
      sub_566CF0(a3);
      sub_566CF0(&word_5C30B4);
    }
    sub_566C30(a2, aNameS);
    sub_566C30(a2, aVehfileS);
    sub_566C30(a2, aRcdfileS);
    v4 = 0;
    v5 = this + 6;
    do
    {
      if ( *v5 < 0 )
        break;
      sub_566C30(a2, aFinishposition_0);
      sub_566C30(a2, aFinishpoints22);
      ++v4;
      ++v5;
    }
    while ( v4 < 48 );
    sub_566C30(a2, aSeasonpointsD);
    sub_566C30(a2, aPointsposition_0);
    sub_566C30(a2, aPolestakenD);
    sub_566C30(a2, aOriginalgridpo_0);
    sub_566C30(a2, aCurrentgridpos_0);
    sub_566C30(a2, aControltypeD);
    sub_566C30(a2, aActiveD);
    sub_566C30(a2, &word_5C30B4);
  }
  return 0;
}
