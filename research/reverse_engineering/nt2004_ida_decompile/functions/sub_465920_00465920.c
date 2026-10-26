DWORD __thiscall sub_465920(DWORD *this)
{
  DWORD result; // eax
  CHAR *v2; // eax
  __int16 v3; // bx
  const char *v4; // edx
  CHAR *v5; // edi
  int v6; // ecx
  int v7; // eax
  unsigned int v8; // ecx
  const char *v9; // edx
  CHAR *v10; // edi
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  char v14; // [esp+0h] [ebp-8D8h]
  _PROCESS_INFORMATION ProcessInformation; // [esp+4h] [ebp-8D4h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+14h] [ebp-8C4h] BYREF
  CHAR CommandLine[1152]; // [esp+58h] [ebp-880h] BYREF
  CHAR Filename[1024]; // [esp+4D8h] [ebp-400h] BYREF

  result = *this;
  if ( *(_BYTE *)(*this + 153) )
  {
    *(_BYTE *)(result + 153) = 0;
    memset(Filename, 0, sizeof(Filename));
    result = GetModuleFileNameA(0, Filename, 0x400u);
    if ( result )
    {
      if ( result < 0x400 )
      {
        sprintf(CommandLine, "%s +dedicated", Filename);
        v2 = sub_4658F0(dword_764D70);
        v3 = *(_WORD *)word_5FD024;
        v4 = v2;
        if ( v2 && strlen(v2) )
        {
          v5 = &CommandLine[strlen(CommandLine) + 1];
          v6 = dword_60065C;
          *(_DWORD *)--v5 = dword_600658;
          v7 = dword_600660;
          *((_DWORD *)v5 + 1) = v6;
          LOBYTE(v6) = byte_600664;
          *((_DWORD *)v5 + 2) = v7;
          v5[12] = v6;
          v8 = strlen(v4) + 1;
          qmemcpy(&CommandLine[strlen(CommandLine)], v4, v8);
          *(_WORD *)&CommandLine[strlen(CommandLine)] = v3;
        }
        v9 = (const char *)sub_465260(dword_764D70, 0);
        if ( v9 && strlen(v9) )
        {
          v10 = &CommandLine[strlen(CommandLine) + 1];
          v11 = dword_60064C;
          *(_DWORD *)--v10 = dword_600648;
          v12 = dword_600650;
          *((_DWORD *)v10 + 1) = v11;
          LOBYTE(v11) = byte_600654;
          *((_DWORD *)v10 + 2) = v12;
          v10[12] = v11;
          v13 = strlen(v9) + 1;
          qmemcpy(&CommandLine[strlen(CommandLine)], v9, v13);
          *(_WORD *)&CommandLine[strlen(CommandLine)] = v3;
        }
        memset(&StartupInfo, 0, sizeof(StartupInfo));
        StartupInfo.cb = 68;
        return CreateProcessA(0, CommandLine, 0, 0, 0, 0x20u, 0, 0, &StartupInfo, &ProcessInformation);
      }
      else if ( dword_75CBA8 != 5 )
      {
        result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 8438);
        if ( (_BYTE)result )
          return sub_500FE0((int)&unk_7D7920, aBufferNotLarge, v14);
      }
    }
    else if ( dword_75CBA8 != 5 )
    {
      result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 8434);
      if ( (_BYTE)result )
        return sub_500FE0((int)&unk_7D7920, aCouldnTAscerta, v14);
    }
  }
  return result;
}
