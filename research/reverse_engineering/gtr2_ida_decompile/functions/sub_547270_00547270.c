int __cdecl sub_547270(int a1)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // ebp
  char ArgList[280]; // [esp+20h] [ebp-118h] BYREF

  v2 = v1;
  v1[3] = 1065353216;
  v1[4] = 1065353216;
  v1[5] = 1065353216;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  ArgList[12] = 0;
  v1[16] = 0;
  v1[21] = 0;
  v1[17] = 1065353216;
  v1[12] = 1092616192;
  v1[13] = 1077936128;
  v1[14] = 1077936128;
  v1[15] = 1077936128;
  v1[19] = 1048576000;
  v1[20] = 1098907648;
  if ( sub_6137E0(a1) )
  {
    if ( !strcmp(ArgList, "DUST") )
    {
      v2[1] = 0;
    }
    else if ( !strcmp(ArgList, "WHITESMOKE") )
    {
      v2[1] = 1;
    }
    else if ( !strcmp(ArgList, "TIRESMOKE") )
    {
      v2[1] = 2;
    }
    else if ( !strcmp(ArgList, "BLACKSMOKE") )
    {
      v2[1] = 3;
    }
    else if ( !strcmp(ArgList, "FLAMES") )
    {
      v2[1] = 4;
    }
    else if ( !strcmp(ArgList, "EXHAUST") )
    {
      v2[1] = 5;
    }
    else if ( !strcmp(ArgList, "SKID") )
    {
      v2[1] = 7;
    }
    else if ( !strcmp(ArgList, "SOFTSKID") )
    {
      v2[1] = 8;
    }
    else if ( !strcmp(ArgList, "SPRAY") )
    {
      v2[1] = 6;
    }
    else if ( !strcmp(ArgList, "SPRAY2") )
    {
      v2[1] = 20;
    }
    else if ( !strcmp(ArgList, "WETSKID") )
    {
      v2[1] = 9;
    }
    else if ( !strcmp(ArgList, "GROOVE") )
    {
      v2[1] = 10;
    }
    else if ( !strcmp(ArgList, "WETGROOVE") )
    {
      v2[1] = 11;
    }
    else if ( !strcmp(ArgList, "DSRACELINE") )
    {
      v2[1] = 12;
    }
    else if ( !strcmp(ArgList, "PARTICLE") )
    {
      v2[1] = 13;
    }
    else if ( !strcmp(ArgList, "SPARK") )
    {
      v2[1] = 14;
    }
    else if ( !strcmp(ArgList, "RAIN") )
    {
      v2[1] = 15;
    }
    else if ( !strcmp(ArgList, "WALLSKID") )
    {
      v2[1] = 16;
    }
    else if ( !strcmp(ArgList, "SHARDSMOKE") )
    {
      v2[1] = 17;
    }
    else if ( !strcmp(ArgList, "SHARDS1") )
    {
      v2[1] = 18;
    }
    else if ( !strcmp(ArgList, "SHARDS2") )
    {
      v2[1] = 19;
    }
    else if ( (unsigned __int8)sub_5612D0(
                                 (int)byte_FAE910,
                                 1,
                                 "\\Dev\\Src\\Copperhead\\App\\Source\\specialfx.cpp",
                                 643) )
    {
      sub_561210((int)byte_FAE910, "Unrecognized reaction \"%s\"", (char)ArgList);
    }
  }
  return off_16C970C();
}
