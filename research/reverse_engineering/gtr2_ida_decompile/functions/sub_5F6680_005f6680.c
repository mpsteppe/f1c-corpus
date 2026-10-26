int __stdcall sub_5F6680(char *String1)
{
  if ( !_stricmp(String1, "S000") )
  {
    strcpy(String1, "L0SCREENT0");
    return 0;
  }
  else if ( !_stricmp(String1, "N000") )
  {
    strcpy(String1, "L0NOLIGHTING");
    return 0;
  }
  else if ( !_stricmp(String1, "N001") )
  {
    strcpy(String1, "L1USEVERTEXONLY");
    return 0;
  }
  else
  {
    if ( !sub_5F6650("N002", String1, "L2USEVERTEXPIXEL")
      && !sub_5F6650("N004", String1, "L0NONDIRECTIONALT0")
      && !sub_5F6650("R000", String1, "L0NOLIGHTING")
      && !sub_5F6650("R001", String1, "L0SPECULART0")
      && !sub_5F6650("R002", String1, "L0CMAPT0")
      && !sub_5F6650("R003", String1, "L0BUMPT0")
      && !sub_5F6650("N005", String1, "L0SHADOWDRAW")
      && !sub_5F6650("N006", String1, "L0SHADOWDRAWTEX")
      && !sub_5F6650("N007", String1, "L0SHADOWPROJECT")
      && !sub_5F6650("N008", String1, "L0SHADOWPROJECTTEX")
      && !sub_5F6650("N010", String1, "L1SHADOWDRAW")
      && !sub_5F6650("N011", String1, "L1SHADOWDRAWTEX")
      && !sub_5F6650("N012", String1, "L1SHADOWPROJECT")
      && !sub_5F6650("N013", String1, "L1SHADOWPROJECTTEX")
      && !sub_5F6650("N020", String1, "L1NOLIGHTINGT0")
      && !sub_5F6650("P000", String1, "L1DIFFUSET0")
      && !sub_5F6650("P001", String1, "L1DIFFUSET0T1")
      && !sub_5F6650("P002", String1, "L1DIFFUSET0XT1")
      && !sub_5F6650("P003", String1, "L1DIFFUSET0T1T2")
      && !sub_5F6650("P004", String1, "L1DIFFUSET0T1XT2")
      && !sub_5F6650("P005", String1, "L1DIFFUSET0XT1T2")
      && !sub_5F6650("P006", String1, "L1DIFFUSET0XT1XT2")
      && !sub_5F6650("P007", String1, "L1DIFFUSET0T1T2T3")
      && !sub_5F6650("P008", String1, "L1DIFFUSET0T1XT2T3")
      && !sub_5F6650("P009", String1, "L1DIFFUSET0XT1T2T3")
      && !sub_5F6650("P010", String1, "L1DIFFUSET0XT1XT2T3")
      && !sub_5F6650("P011", String1, "L1DIFFUSET0T1T2XT3")
      && !sub_5F6650("P012", String1, "L1DIFFUSET0T1XT2XT3")
      && !sub_5F6650("P013", String1, "L1DIFFUSET0XT1T2XT3")
      && !sub_5F6650("P014", String1, "L1DIFFUSET0XT1XT2XT3")
      && !sub_5F6650("P100", String1, "L1SPECULART0")
      && !sub_5F6650("P101", String1, "L1SPECULART0T1")
      && !sub_5F6650("P102", String1, "L1SPECULART0XT1")
      && !sub_5F6650("P110", String1, "L1SPECULARMAPT0")
      && !sub_5F6650("P115", String1, "L1SPECIALROADT0")
      && !sub_5F6650("P120", String1, "L1CMAPT0")
      && !sub_5F6650("P121", String1, "L1CMAPT0T1")
      && !sub_5F6650("P122", String1, "L1CMAPT0XT1")
      && !sub_5F6650("P123", String1, "L1CMAPADDALPHAREFLECTT0")
      && !sub_5F6650("P124", String1, "L1CMAPLERPALPHAREFLECTT0")
      && !sub_5F6650("P130", String1, "L1BUMPT0")
      && !sub_5F6650("P131", String1, "L1BUMPT0T1")
      && !sub_5F6650("P132", String1, "L1BUMPT0XT1")
      && !sub_5F6650("P140", String1, "L1BUMPCMAPT0")
      && !sub_5F6650("P150", String1, "L1CMAPSPECT0")
      && !sub_5F6650("P151", String1, "L1CMAPSPECMAPT0")
      && !sub_5F6650("P152", String1, "L1CMAPSPECADDT0") )
    {
      sub_5F6650("P161", String1, "L1BUMPSPECMAPT0");
    }
    return 0;
  }
}
