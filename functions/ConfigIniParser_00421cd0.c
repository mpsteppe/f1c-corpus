char __thiscall sub_421CD0(const CHAR **this, const CHAR *a2)
{
  unsigned int v3; // esi
  unsigned int v4; // kr04_4
  const CHAR *v5; // esi
  int v6; // edi
  int v8; // eax
  const char *v9; // ecx
  const char *v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // kr08_4
  const char *v13; // eax
  const char *v14; // ecx
  const char *v15; // eax
  unsigned int v16; // esi
  unsigned int v17; // kr0C_4
  const char *v18; // eax
  const char *v19; // ecx
  const char *v20; // eax
  unsigned int v21; // esi
  unsigned int v22; // kr10_4
  const char *v23; // eax
  int v24; // eax
  bool v25; // sf
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // [esp+0h] [ebp-1138h]
  int v31; // [esp+14h] [ebp-1124h] BYREF
  char v32; // [esp+1Bh] [ebp-111Dh]
  int v33; // [esp+1Ch] [ebp-111Ch]
  CHAR pszPath[256]; // [esp+20h] [ebp-1118h] BYREF
  CHAR NewFileName[256]; // [esp+120h] [ebp-1018h] BYREF
  _BYTE v36[384]; // [esp+220h] [ebp-F18h] BYREF
  int v37; // [esp+3A0h] [ebp-D98h]
  char v38; // [esp+3A4h] [ebp-D94h]
  int v39; // [esp+3ACh] [ebp-D8Ch]
  int v40; // [esp+3B0h] [ebp-D88h]
  int v41; // [esp+3B4h] [ebp-D84h]
  CHAR v42[384]; // [esp+3B8h] [ebp-D80h] BYREF
  CHAR PathName[1024]; // [esp+538h] [ebp-C00h] BYREF
  CHAR v44[1024]; // [esp+938h] [ebp-800h] BYREF
  CHAR v45[1024]; // [esp+D38h] [ebp-400h] BYREF

  memset(v42, 0, sizeof(v42));
  v37 = 0;
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v38 = 1;
  v32 = 0;
  sub_4230C0(pszPath);
  if ( (!strcmp(pszPath, aWindowsXp) || !strcmp(pszPath, aWindowsNt) || !strcmp(pszPath, aWindows2000))
    && !(unsigned __int8)WindowsAdminCheck(this) )
  {
    v32 = 1;
    if ( SHGetSpecialFolderPathA(0, pszPath, 5, 1) >= 0 )
    {
      StringFormatWithBufferOverflowCheck(NewFileName, "%s\\%s", pszPath, aF1Challenge990_0);
      if ( FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1 )
      {
        v3 = 0;
        v4 = strlen(NewFileName) + 1;
        if ( (int)(v4 - 1) > 0 )
        {
          do
          {
            if ( v3 >= 0x400 )
              break;
            if ( NewFileName[v3] == 92 )
            {
              sub_587DD0(PathName, NewFileName, v3);
              PathName[v3] = 0;
              CreateDirectoryAWrapper(PathName);
            }
            ++v3;
          }
          while ( (int)v3 < (int)(v4 - 1) );
        }
        CreateDirectoryAWrapper(NewFileName);
        StringCopyWithBufferRealloc(NewFileName);
        StringFormatWithBufferOverflowCheck(NewFileName, "%s\\%s%s", pszPath, aF1Challenge990_0, ExistingFileName);
        StringCopyWithBufferRealloc(NewFileName);
        CopyFileA(ExistingFileName, NewFileName, 1);
      }
      else
      {
        StringCopyWithBufferRealloc(NewFileName);
        StringFormatWithBufferOverflowCheck(NewFileName, "%s\\%s%s", pszPath, aF1Challenge990_0, ExistingFileName);
        StringCopyWithBufferRealloc(NewFileName);
      }
    }
  }
  v5 = a2;
  if ( !a2 )
  {
    v5 = *this;
    if ( !*this )
      v5 = &byte_5EA438;
  }
  v6 = sub_587DB0(v5, aRt);
  v33 = v6;
  if ( !v6 )
  {
    if ( !(unsigned __int8)sub_422BE0(v5) )
    {
      if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_10, 386) )
      {
        DebugLogWrite(&dword_8AD25C, aCouldNotCreate_0);
        return 0;
      }
      return 0;
    }
    v6 = sub_587DB0(v5, aRt);
    v33 = v6;
    if ( !v6 )
    {
      if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_10, 396) )
        DebugLogWrite(&dword_8AD25C, aSuccessfullyCr);
      return 0;
    }
  }
  while ( FileReadUntilNewline(v42, 256, v6) )
  {
    if ( !sub_5651B0(v36) )
    {
      if ( sub_587C20(v42, aComponents) )
      {
        while ( FileReadUntilNewline(v42, 256, v6) )
        {
          v8 = sub_5651B0(v36);
          v31 = v8;
          if ( v8 )
          {
            if ( v8 == 1 )
              break;
          }
          else if ( sub_5654A0(aSeasondir, pszPath) )
          {
            NameRegistrationDelegation(pszPath);
          }
          else if ( sub_5654A0(aSounddir, pszPath) )
          {
            StringCopyRealloc(pszPath);
          }
          else if ( sub_5654A0(aVehiclesound, pszPath) )
          {
            DoubleDelegateCall(pszPath);
          }
          else if ( sub_5654A0(aOptionsanim, pszPath) )
          {
            ChainedCall(pszPath);
          }
          else if ( sub_5654A0(aOptionsflags, pszPath) )
          {
            StringWritePathRegister(pszPath);
          }
          else if ( sub_5654A0(aOptionssounds, pszPath) )
          {
            DualFunctionCallChain(pszPath);
          }
          else if ( sub_5654A0(aOptionsdir, pszPath) )
          {
            ShortComputation_1990(pszPath);
          }
          else if ( sub_5654A0(aMoviedir, pszPath) )
          {
            sub_4219D0(pszPath);
          }
          else if ( sub_5654A0(aTracksdir, pszPath) )
          {
            DualFunctionDispatch(pszPath);
          }
          else if ( sub_5654A0(aVehiclesdir, pszPath) )
          {
            DualRegistrationCall(pszPath);
          }
          else if ( sub_5654A0(aDriversdir, pszPath) )
          {
            DualDispatchProcessPathRegister(pszPath);
          }
          else if ( sub_5654A0(aMusicdir, pszPath) )
          {
            ShortComputation_1a90(pszPath);
          }
          else if ( sub_5654A0(aReplaydir, pszPath) )
          {
            if ( v32 )
            {
              v9 = this[16];
              if ( !v9 )
                v9 = &byte_5EA438;
              v10 = this[42];
              if ( !v10 )
                v10 = &byte_5EA438;
              StringFormatWithBufferOverflowCheck(NewFileName, "%s%s", v10, v9);
              if ( FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1 )
              {
                v11 = 0;
                v12 = strlen(NewFileName) + 1;
                if ( (int)(v12 - 1) > 0 )
                {
                  do
                  {
                    if ( v11 >= 0x400 )
                      break;
                    if ( NewFileName[v11] == 92 )
                    {
                      sub_587DD0(PathName, NewFileName, v11);
                      PathName[v11] = 0;
                      CreateDirectoryAWrapper(PathName);
                    }
                    ++v11;
                  }
                  while ( (int)v11 < (int)(v12 - 1) );
                }
                CreateDirectoryAWrapper(NewFileName);
                v13 = this[16];
                if ( !v13 )
                  v13 = &byte_5EA438;
                FileEnumerationByExtension(v13, NewFileName);
                StringFormatWithBufferOverflowCheck(pszPath, "%s", NewFileName);
                v6 = v33;
              }
            }
            ShortComputation_19b0(pszPath);
          }
          else if ( sub_5654A0(aLogdir, pszPath) )
          {
            if ( v32 )
            {
              v14 = this[26];
              if ( !v14 )
                v14 = &byte_5EA438;
              v15 = this[42];
              if ( !v15 )
                v15 = &byte_5EA438;
              StringFormatWithBufferOverflowCheck(NewFileName, "%s%s", v15, v14);
              if ( FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1 )
              {
                v16 = 0;
                v17 = strlen(NewFileName) + 1;
                if ( (int)(v17 - 1) > 0 )
                {
                  do
                  {
                    if ( v16 >= 0x400 )
                      break;
                    if ( NewFileName[v16] == 92 )
                    {
                      sub_587DD0(v44, NewFileName, v16);
                      v44[v16] = 0;
                      CreateDirectoryAWrapper(v44);
                    }
                    ++v16;
                  }
                  while ( (int)v16 < (int)(v17 - 1) );
                }
                CreateDirectoryAWrapper(NewFileName);
                v18 = this[26];
                if ( !v18 )
                  v18 = &byte_5EA438;
                FileEnumerationByExtension(v18, NewFileName);
                StringFormatWithBufferOverflowCheck(pszPath, "%s", NewFileName);
                v6 = v33;
              }
            }
            DualCallWrapper(pszPath);
          }
          else if ( sub_5654A0(aSavedir, pszPath) )
          {
            if ( v32 )
            {
              v19 = this[28];
              if ( !v19 )
                v19 = &byte_5EA438;
              v20 = this[42];
              if ( !v20 )
                v20 = &byte_5EA438;
              StringFormatWithBufferOverflowCheck(NewFileName, "%s%s", v20, v19);
              if ( FileAttributeCheckWithErrorHandling(NewFileName, 0) == -1 )
              {
                v21 = 0;
                v22 = strlen(NewFileName) + 1;
                if ( (int)(v22 - 1) > 0 )
                {
                  do
                  {
                    if ( v21 >= 0x400 )
                      break;
                    if ( NewFileName[v21] == 92 )
                    {
                      sub_587DD0(v45, NewFileName, v21);
                      v45[v21] = 0;
                      CreateDirectoryAWrapper(v45);
                    }
                    ++v21;
                  }
                  while ( (int)v21 < (int)(v22 - 1) );
                }
                CreateDirectoryAWrapper(NewFileName);
                v23 = this[28];
                if ( !v23 )
                  v23 = &byte_5EA438;
                FileEnumerationByExtension(v23, NewFileName);
                StringFormatWithBufferOverflowCheck(pszPath, "%s", NewFileName);
                v6 = v33;
              }
            }
            sub_421A70(pszPath);
          }
          else if ( sub_5654A0(aCameraeditorre, pszPath) )
          {
            DualDelegationWrapper(pszPath);
          }
          else if ( sub_565760(aGridsize, &v31, 0, 0, 0) )
          {
            v24 = v31;
            v25 = v31 < 0;
            this[49] = (const CHAR *)v31;
            if ( v25 )
            {
              this[49] = 0;
            }
            else if ( v24 > 104 )
            {
              this[49] = (const CHAR *)104;
            }
          }
          else if ( sub_565760(aCpurating, &v31, 0, 0, 0) )
          {
            this[50] = (const CHAR *)v31;
          }
          else if ( sub_565760(aSystemram, &v31, 0, 0, 0) )
          {
            this[51] = (const CHAR *)v31;
          }
          else if ( sub_565760(aVideoram, &v31, 0, 0, 0) )
          {
            this[52] = (const CHAR *)v31;
          }
          else if ( sub_565760(aObjdetail, &v31, 0, 0, 0) )
          {
            this[54] = (const CHAR *)v31;
          }
          else if ( sub_565760(aTexdetail, &v31, 0, 0, 0) )
          {
            this[55] = (const CHAR *)v31;
          }
          else if ( sub_565520(aVideoguid, pszPath, 0) )
          {
            StringCopyWithBufferRealloc(pszPath);
          }
          else if ( sub_565760(aVideodriver, &v31, 0, 0, 0) )
          {
            this[46] = (const CHAR *)v31;
          }
          else if ( sub_565760(aVideomode, &v31, 0, 0, 0) )
          {
            this[47] = (const CHAR *)v31;
          }
          else if ( sub_565760(aVideorefresh, &v31, 0, 0, 0) )
          {
            this[48] = (const CHAR *)v31;
          }
          else if ( sub_565760(aWindowedmode, &v31, 0, 0, 0) )
          {
            *((_BYTE *)this + 212) = v31;
          }
          else if ( sub_565760(aRunbenchmarks, &v31, 0, 0, 0) )
          {
            *((_BYTE *)this + 213) = v31 != 0;
          }
          else if ( sub_565760(aFsaa, &v31, 0, 0, 0) )
          {
            this[56] = (const CHAR *)v31;
          }
          else if ( sub_565760(aVsync, &v31, 0, 0, 0) )
          {
            *((_BYTE *)this + 214) = v31 != 0;
          }
          else if ( sub_565760(aVbstrategy, &v31, 0, 0, 0) )
          {
            this[57] = (const CHAR *)v31;
          }
        }
      }
      else if ( sub_587C20(v42, aInstall) )
      {
        while ( FileReadUntilNewline(v42, 256, v6) )
        {
          v26 = sub_5651B0(v36);
          v31 = v26;
          if ( v26 )
          {
            if ( v26 == 1 )
              break;
          }
          else if ( sub_5654A0(aInstallfrom, pszPath) )
          {
            FunctionCallWrapper_1ab0(pszPath);
          }
          else if ( sub_5654A0(aInstallto, pszPath) )
          {
            PathRegistrationWrapper(pszPath);
          }
        }
      }
      else if ( sub_587C20(v42, aAutolaunch) )
      {
        while ( FileReadUntilNewline(v42, 256, v6) )
        {
          v27 = sub_5651B0(v36);
          v31 = v27;
          if ( v27 )
          {
            if ( v27 == 1 )
              break;
          }
          else if ( sub_5654A0(aMode, pszPath) )
          {
            v28 = QuickRace((int)pszPath);
            StructFieldSetter(&dword_5EA43C, v28);
          }
          else if ( sub_565760(aLaunchtime, &v31, 0, 0, 0) )
          {
            *(float *)&v30 = (float)v31;
            ShortComputation_4d30(&dword_5EA43C, v30);
          }
          else if ( sub_565760(aVcrcycle, &v31, 0, 0, 0) )
          {
            ResourceListCleanup(&dword_5EA43C, v31 != 0);
          }
          else if ( sub_5654A0(aVcrfile, pszPath) )
          {
            LinkedListNodeInsertion(&dword_5EA43C, (int)pszPath);
          }
          else if ( sub_5654A0(aIpaddress, pszPath) )
          {
            SingleFunctionCallWrapper_4ef0((int)pszPath);
          }
        }
      }
      else if ( sub_587C20(v42, aVersion) && FileReadUntilNewline(v42, 256, v6) )
      {
        do
        {
          v29 = sub_5651B0(v36);
          v31 = v29;
          if ( v29 )
          {
            if ( v29 == 1 )
              break;
          }
          else if ( sub_565520(aVersion_0, pszPath, 0) )
          {
            *((float *)this + 58) = sub_58850F(pszPath);
          }
        }
        while ( FileReadUntilNewline(v42, 256, v6) );
      }
    }
  }
  FileCloseWithLock(v6);
  if ( v32 )
    sub_422BE0(0);
  return 1;
}
