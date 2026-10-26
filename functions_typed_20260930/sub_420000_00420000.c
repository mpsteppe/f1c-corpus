int sub_420000()
{
  int v0; // edi
  int v1; // eax
  int v2; // esi

  v0 = -1;
  v1 = dword_8AC490 + 396 * dword_8AC48C;
  if ( v1 )
  {
    v2 = v1 + 260;
    if ( sub_566810(v1 + 260, aAlbertPark) )
      return 338;
    if ( sub_566810(v2, aInterlagos) )
      return 339;
    if ( sub_566810(v2, aImola) )
      return 340;
    if ( sub_566810(v2, aMonaco_0) )
      return 341;
    if ( sub_566810(v2, aBarcelona) )
      return 342;
    if ( sub_566810(v2, aMontreal) )
      return 343;
    if ( sub_566810(v2, aMagnyCours) )
      return 344;
    if ( sub_566810(v2, aSilverstone) )
      return 345;
    if ( sub_566810(v2, aA1Ring) )
      return 346;
    if ( sub_566810(v2, aHockenheim) )
      return 347;
    if ( sub_566810(v2, aHungaroring) )
      return 348;
    if ( sub_566810(v2, aSpaFrancorcham) )
      return 349;
    if ( sub_566810(v2, aMonza) )
      return 350;
    if ( sub_566810(v2, aNurburgring) )
      return 354;
    if ( sub_566810(v2, aSepang) )
      return 351;
    if ( sub_566810(v2, aSuzuka) )
      return 352;
    if ( sub_566810(v2, aIndianapolis) )
      return 353;
  }
  return v0;
}

