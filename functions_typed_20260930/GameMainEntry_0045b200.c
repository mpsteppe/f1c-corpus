int __stdcall sub_45B200(HINSTANCE a1, int a2, int a3, int a4)
{
  dword_7C56B0 = 1065571320;
  dword_7C56B4 = (int)aIlya1011;
  byte_7C56AD = 0;
  dword_7C56A0 = 3;
  hinst = a1;
  sub_423070(a3);
  ConfigIniParser((const CHAR **)dword_5EC3D0, 0);
  sub_4D7A00(a3);
  sub_4A0D50(a3);
  sub_4B17F0(a3);
  NetCommParseCommandLine(a3);
  if ( !Game_Enter((char *)&dword_7C569C) && !Game_Setup(&dword_7C569C) )
  {
LABEL_3:
    if ( !Game_Init(&dword_7C569C) )
    {
      while ( !Game_Restart(&dword_7C569C) )
      {
        if ( GamePostMainLoop(&dword_7C569C) )
        {
          Game_Post(&dword_7C569C);
          if ( !Game_Setup(&dword_7C569C) )
            goto LABEL_3;
          break;
        }
      }
    }
  }
  GameExit(&dword_7C569C);
  return 0;
}

