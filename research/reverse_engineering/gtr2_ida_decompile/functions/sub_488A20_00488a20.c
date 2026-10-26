char __thiscall sub_488A20(float *this)
{
  DWORD v2; // eax
  int *v3; // eax
  int v4; // eax
  int v5; // eax
  HWND DlgItem; // eax
  const char *v7; // ecx
  const char *v8; // eax
  const char *v9; // eax
  char *v10; // eax
  const CHAR *v11; // ecx
  char *v12; // eax
  char *v13; // eax
  char *v14; // ecx
  char *v15; // eax
  char *v16; // eax
  char *v17; // ecx
  char *v18; // eax
  char *v19; // eax
  char *v20; // eax
  char v21; // bl
  const char *v22; // ecx
  const char *v23; // eax
  char *v24; // esi
  LRESULT v25; // ebx
  signed int v26; // edi
  int v27; // esi
  int v28; // eax
  const CHAR ***v29; // eax
  bool v30; // zf
  const CHAR **v31; // eax
  const CHAR *v32; // eax
  char *v33; // eax
  const char *v34; // eax
  const char *v35; // ecx
  const char *v36; // eax
  const char *v37; // ecx
  const char *v38; // eax
  int v39; // eax
  int v40; // eax
  CHAR v41; // cl
  int v42; // eax
  CHAR v43; // cl
  char *v44; // edi
  const CHAR ***v46; // eax
  const CHAR **v47; // eax
  const CHAR ***v48; // eax
  const CHAR *v49; // eax
  const char *v50; // eax
  const char *v51; // edx
  unsigned int v52; // eax
  char v54; // [esp+0h] [ebp-8D2h]
  _BYTE v55[28]; // [esp+Ah] [ebp-8C8h] BYREF
  char *v56; // [esp+26h] [ebp-8ACh]
  char *v57; // [esp+2Ah] [ebp-8A8h]
  const char *v58; // [esp+3Ah] [ebp-898h]
  const char *v59; // [esp+3Eh] [ebp-894h]
  CHAR *v60; // [esp+42h] [ebp-890h]
  LPARAM *v61; // [esp+46h] [ebp-88Ch]
  char *v62; // [esp+4Eh] [ebp-884h]
  char *v63; // [esp+52h] [ebp-880h]
  int *v64; // [esp+56h] [ebp-87Ch]
  unsigned int v65; // [esp+5Ah] [ebp-878h]
  char *v66; // [esp+5Eh] [ebp-874h]
  char *v67; // [esp+62h] [ebp-870h]
  char v69; // [esp+7Ah] [ebp-858h] BYREF
  const char *v70; // [esp+86h] [ebp-84Ch]
  CHAR *v71; // [esp+8Ah] [ebp-848h]
  LPCSTR v72; // [esp+8Eh] [ebp-844h]
  char v73[14]; // [esp+9Ah] [ebp-838h] BYREF
  char v74; // [esp+A8h] [ebp-82Ah]
  bool v75; // [esp+A9h] [ebp-829h] BYREF
  float *v76; // [esp+AAh] [ebp-828h]
  unsigned int v77; // [esp+AEh] [ebp-824h]
  _BYTE v78[100]; // [esp+B2h] [ebp-820h] BYREF
  float v79; // [esp+116h] [ebp-7BCh]
  _BYTE v80[61]; // [esp+11Ah] [ebp-7B8h] BYREF
  __int16 v81; // [esp+157h] [ebp-77Bh]
  char v82; // [esp+159h] [ebp-779h]
  CHAR Filename[508]; // [esp+15Eh] [ebp-774h] BYREF
  __int16 v85; // [esp+35Ah] [ebp-578h]
  char v86; // [esp+35Ch] [ebp-576h]
  LPARAM v87[63]; // [esp+3B2h] [ebp-520h] BYREF
  __int16 v88; // [esp+4AEh] [ebp-424h]
  char v89; // [esp+4B0h] [ebp-422h]
  char v90; // [esp+55Dh] [ebp-375h] BYREF
  CHAR ApplicationName[172]; // [esp+55Eh] [ebp-374h] BYREF
  _BYTE v92[88]; // [esp+60Ah] [ebp-2C8h] BYREF
  _BYTE v93[8]; // [esp+662h] [ebp-270h] BYREF
  _BYTE v94[436]; // [esp+66Ah] [ebp-268h] BYREF
  int v95; // [esp+826h] [ebp-ACh]
  char v96; // [esp+87Eh] [ebp-54h]
  char v97; // [esp+882h] [ebp-50h]
  int v98; // [esp+8CEh] [ebp-4h]

  ++*((_DWORD *)this + 218);
  v76 = this;
  v74 = 1;
  if ( hMutex && ((v2 = WaitForSingleObject(hMutex, dwMilliseconds)) == 0 || v2 == 128) )
    v3 = (int *)&unk_759EA8;
  else
    v3 = 0;
  v4 = *v3;
  if ( v4 == 3 || v4 == 4 )
  {
    v5 = *((_DWORD *)this + 217);
    if ( !v5 || v5 == 5 )
      *((_DWORD *)this + 217) = 8;
  }
  if ( hMutex )
    ReleaseMutex(hMutex);
  sub_482440((int)this);
  sub_47FAA0(this, 0);
  switch ( *((_DWORD *)this + 217) )
  {
    case 1:
      v72 = "<< Back";
      *((_DWORD *)this + 217) = 2;
      DlgItem = GetDlgItem(hWnd, 1034);
      SetWindowTextA(DlgItem, v72);
      sub_4744E0(v78);
      memset(v87, 0, sizeof(v87));
      v7 = (const char *)dword_759EC0;
      v88 = 0;
      v89 = 0;
      v98 = 0;
      v8 = (const char *)dword_759EC0;
      if ( !dword_759EC0 )
        v8 = WindowName;
      v77 = strlen(v8);
      if ( v77 )
      {
        if ( !dword_759EC0 )
          v7 = WindowName;
      }
      else
      {
        v7 = *(const char **)dword_759ED8;
        if ( !*(_DWORD *)dword_759ED8 )
          v7 = WindowName;
      }
      strcpy((char *)v87, v7);
      sub_478D00(byte_B6FEA8, (unsigned __int8 *)&byte_759E78);
      sub_478D00(byte_B6FEC0, (unsigned __int8 *)&byte_B6CE97);
      sub_478D00(byte_B6FED8, (unsigned __int8 *)&byte_B6CE98);
      sub_478D00(byte_B6FEF0, (unsigned __int8 *)&byte_B6CE99);
      sub_478D00(byte_B6FF08, (unsigned __int8 *)&byte_B6CE9A);
      v75 = *(_DWORD *)dword_759E98 != 0;
      sub_478D00(byte_B7352C, (unsigned __int8 *)&v75);
      sub_630FE0(v78, v87, 31);
      v78[31] = 0;
      sub_477E20();
      sub_4734F0(v78, 0, 1);
      if ( CINet::IsSubscriptionServer((CINet *)dword_B6CBB0) )
        sub_4734F0(v78, 3, 1);
      v80[13] = byte_759E9C;
      v79 = (float)dword_B72A24;
      *(_DWORD *)&v80[16] = *(_DWORD *)dword_759E7C;
      *(_DWORD *)&v80[44] = *(_DWORD *)dword_759E94;
      *(_DWORD *)&v80[20] = *(_DWORD *)dword_759E80;
      *(_DWORD *)&v80[28] = *(_DWORD *)dword_759E88;
      *(_DWORD *)&v80[24] = *(_DWORD *)dword_759E84;
      *(_DWORD *)&v80[32] = *(_DWORD *)dword_759E8C;
      *(_DWORD *)&v80[40] = *(_DWORD *)dword_B6CE9C;
      *(_DWORD *)&v80[36] = *(_DWORD *)dword_759E90;
      *(_DWORD *)&v80[52] = dword_759E50;
      *(_DWORD *)&Filename[4] = *(_DWORD *)dword_759E74;
      byte_B6CBC3 = 0;
      if ( dword_B6CE84 )
      {
        if ( dword_B6CE84 == 1 )
          v72 = "SEMIPRO_SERVER.txt";
        else
          v72 = "SIM_SERVER.txt";
      }
      else
      {
        v72 = "ARCADE_SERVER.txt";
      }
      sub_615860(v72);
      if ( byte_B6CEA0 )
      {
        v9 = (const char *)lpData;
        if ( !lpData )
          v9 = WindowName;
        v77 = strlen(v9);
        if ( v77 )
        {
          v10 = (char *)dword_759ED0;
          if ( !dword_759ED0 )
            v10 = (char *)WindowName;
          CINet::SetServerName((CINet *)dword_B6CBB0, v10);
          CINet::SetDifficulty((CINet *)dword_B6CBB0, dword_B6CE88[0]);
          CINet::SetDedicated((CINet *)dword_B6CBB0, 1);
          CINet::SetConnectionClosedCallback((CINet *)dword_B6CBB0, sub_487190);
          CINet::SetLobbyTimeout((CINet *)dword_B6CBB0, (unsigned __int16)word_B733E4);
          v11 = (const CHAR *)lpData;
          if ( !lpData )
            v11 = WindowName;
          v12 = *(char **)dword_759EE0;
          if ( !*(_DWORD *)dword_759EE0 )
            v12 = (char *)WindowName;
          v67 = (char *)v11;
          v66 = v12;
          v13 = (char *)sub_486C40();
          switch ( CINet::Login((CINet *)dword_B6CBB0, v13, v66, v67, 1, 0, 1, 0, 0, (char *)WindowName) )
          {
            case 0:
              byte_B6CBC3 = 1;
              break;
            case 1:
              v64 = 0;
              v63 = byte_B6CD60;
              v62 = "Could not connect to the server!  Cannot Broadcast to Lobby.";
              goto LABEL_144;
            case 2:
              v64 = 0;
              v63 = byte_B6CD60;
              v62 = "Version check failed!  Cannot Broadcast to Lobby.";
              goto LABEL_144;
            case 5:
LABEL_61:
              v61 = 0;
              v60 = byte_B6CD60;
              v59 = "Login Failed: Invalid CD-Key. Cannot Broadcast to Lobby.";
              goto LABEL_144;
            case 7:
              v64 = 0;
              v63 = byte_B6CD60;
              v62 = "Login Failed: General Error!  Cannot Broadcast to Lobby.";
              goto LABEL_144;
            case 8:
              v14 = (char *)lpData;
              if ( !lpData )
                v14 = (char *)WindowName;
              v15 = *(char **)dword_759EE0;
              if ( !*(_DWORD *)dword_759EE0 )
                v15 = (char *)WindowName;
              v63 = v14;
              v62 = v15;
              v16 = (char *)sub_486C40();
              switch ( CINet::Register((CINet *)dword_B6CBB0, v16, v62, v63, (char *)WindowName) )
              {
                case 0:
                  CINet::SetLobbyTimeout((CINet *)dword_B6CBB0, (unsigned __int16)word_B733E4);
                  v17 = (char *)lpData;
                  if ( !lpData )
                    v17 = (char *)WindowName;
                  v18 = *(char **)dword_759EE0;
                  if ( !*(_DWORD *)dword_759EE0 )
                    v18 = (char *)WindowName;
                  v57 = v17;
                  v56 = v18;
                  v19 = (char *)sub_486C40();
                  if ( !CINet::Login((CINet *)dword_B6CBB0, v19, v56, v57, 1, 0, 1, 0, 0, (char *)WindowName) )
                    byte_B6CBC3 = 1;
                  break;
                case 1:
                  v61 = 0;
                  v60 = byte_B6CD60;
                  v59 = "Registration Failed: Could not connect to the server ! Cannot Broadcast to Lobby";
                  goto LABEL_144;
                case 2:
                  v61 = 0;
                  v60 = byte_B6CD60;
                  v59 = "Registration Failed: Version check failed ! Cannot Broadcast to Lobby";
                  goto LABEL_144;
                case 3:
                  v61 = 0;
                  v60 = byte_B6CD60;
                  v59 = "Login Failed. Incorrect Password ! Cannot Broadcast to Lobby";
                  goto LABEL_144;
                case 5:
                  goto LABEL_61;
                case 6:
                  v61 = 0;
                  v60 = byte_B6CD60;
                  v59 = "Registration Failed ! Cannot Broadcast to Lobby";
                  goto LABEL_144;
                case 0xA:
                  v61 = 0;
                  v60 = byte_B6CD60;
                  v59 = "Could not find server !  Cannot Broadcast to Lobby.";
                  goto LABEL_144;
                default:
                  goto LABEL_65;
              }
              break;
            case 9:
              v64 = 0;
              v63 = byte_B6CD60;
              v62 = "Login Failed: CD-Key already online. Cannot Broadcast to Lobby.";
              goto LABEL_144;
            case 0xA:
              v64 = 0;
              v63 = byte_B6CD60;
              v62 = "Could not find server!  Cannot Broadcast to Lobby.";
              goto LABEL_144;
            default:
              break;
          }
        }
        else
        {
          v72 = 0;
          v71 = byte_B6CD60;
          v70 = "No CD Key Supplied. Cannot Broadcast to Lobby";
LABEL_144:
          v20 = sub_41D840(off_16C99D0, v62);
          MessageBoxA(0, v20, v63, (UINT)v64);
        }
      }
LABEL_65:
      while ( CINet::PopulatingRooms((CINet *)dword_B6CBB0) )
        ;
      v64 = &dword_B6CE60;
      v63 = (char *)sub_473A80(0);
      v62 = &v69;
      if ( (unsigned __int8)sub_47BC30() )
      {
        v21 = 0;
        if ( byte_B6CBC3 )
        {
          memset(&Filename[16], 0, 255);
          v22 = (const char *)dword_759EC0;
          v23 = (const char *)dword_759EC0;
          if ( !dword_759EC0 )
            v23 = WindowName;
          if ( strlen(v23) )
          {
            if ( !dword_759EC0 )
              v22 = WindowName;
          }
          else
          {
            v22 = *(const char **)dword_759ED8;
            if ( !*(_DWORD *)dword_759ED8 )
              v22 = WindowName;
          }
          strcpy(&Filename[16], v22);
          if ( CINet::RoomExists((CINet *)dword_B6CBB0, &Filename[16]) )
          {
            v33 = sub_41D840(
                    &byte_91CC38,
                    "A room with the same name already exists in the lobby. Cannot Broadcast to Lobby.");
            MessageBoxA(0, v33, byte_B6CD60, 0);
            CINet::Logout((CINet *)dword_B6CBB0);
          }
          else
          {
            v24 = v67;
            sub_409FB0(v67);
            v25 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0);
            v26 = 0;
            if ( v25 > 0 )
            {
              do
              {
                if ( SendDlgItemMessageA(hWnd, 1003, 0x189u, v26, (LPARAM)&v87[46]) != -1 )
                {
                  v61 = &v87[46];
                  v27 = sub_53B760(&unk_BE1CFD);
                  if ( v27 )
                  {
                    v67 = (char *)operator new(8u);
                    v97 = 1;
                    if ( v67 )
                    {
                      v60 = (CHAR *)(v27 + 260);
                      v28 = sub_409B50();
                    }
                    else
                    {
                      v28 = 0;
                    }
                    v96 = 0;
                    sub_5FDFB0(v28, 1);
                  }
                }
                ++v26;
              }
              while ( v26 < v25 );
              v24 = (char *)v65;
            }
            v29 = *(const CHAR ****)v24;
            v30 = *(_DWORD *)v24 == 0;
            *((_DWORD *)v24 + 2) = *(_DWORD *)v24;
            if ( v30 )
              v31 = 0;
            else
              v31 = *v29;
            v32 = *v31;
            if ( !v32 )
              v32 = WindowName;
            sub_615860(v32);
            v21 = 1;
          }
        }
        sub_4744D0(v93);
        v96 = 2;
        sub_630FE0(v94, "[Server]", 31);
        v59 = v93;
        v94[31] = 0;
        sub_4736F0();
        sub_4839A0(v64);
        if ( byte_B6CEA1 )
        {
          v34 = dword_759EF0;
          if ( !dword_759EF0 )
            v34 = WindowName;
          dword_B6CBC4 = j__atol(v34);
        }
        else
        {
          dword_B6CBC4 = 0;
        }
        memset(&Filename[256], 0, 0xFCu);
        v35 = (const char *)dword_759EC0;
        v85 = 0;
        v86 = 0;
        v36 = (const char *)dword_759EC0;
        if ( !dword_759EC0 )
          v36 = WindowName;
        v65 = strlen(v36);
        if ( v65 )
        {
          if ( !dword_759EC0 )
            v35 = WindowName;
        }
        else
        {
          v35 = *(const char **)dword_759ED8;
          if ( !*(_DWORD *)dword_759ED8 )
            v35 = WindowName;
        }
        strcpy(&Filename[256], v35);
        if ( byte_B6CEA2 )
        {
          v37 = *(const char **)dword_91CAB0;
          if ( !*(_DWORD *)dword_91CAB0 )
            v37 = WindowName;
          v38 = dword_759EF8;
          if ( !dword_759EF8 )
            v38 = WindowName;
          v58 = v37;
          v39 = j__atol(v38);
          sprintf((char *const)&v87[43], " %d %s%c%s", v39, &Filename[256], 255, v58);
          memset(Filename, 0, 255);
          GetModuleFileNameA(0, Filename, 0xFFu);
          v40 = strlen(Filename);
          if ( Filename[v40] != 92 )
          {
            do
            {
              if ( v40 <= 0 )
                break;
              Filename[v40] = 0;
              v41 = Filename[--v40];
            }
            while ( v41 != 92 );
          }
          v42 = 0;
          do
          {
            v43 = Filename[v42];
            ApplicationName[v42++] = v43;
          }
          while ( v43 );
          v44 = &v90;
          while ( *++v44 )
            ;
          strcpy(v44, "GTR2_Reporter.exe");
          StartupInfo.cb = 68;
          StartupInfo.lpReserved = 0;
          StartupInfo.lpDesktop = 0;
          StartupInfo.lpTitle = "GTR2_Reporter";
          StartupInfo.dwFlags = 1;
          StartupInfo.wShowWindow = 5;
          StartupInfo.cbReserved2 = 0;
          StartupInfo.lpReserved2 = 0;
          CreateProcessA(
            ApplicationName,
            (LPSTR)&v87[43],
            0,
            0,
            0,
            0x4000020u,
            0,
            Filename,
            &StartupInfo,
            (LPPROCESS_INFORMATION)&ProcessInformation);
          byte_B6CEA3 = 1;
        }
        if ( v21 )
        {
          v46 = (const CHAR ***)v64[2];
          if ( v46 && (v47 = *v46) != 0
            || (v48 = (const CHAR ***)*v64, v30 = *v64 == 0, v64[2] = *v64, !v30) && (v47 = *v48) != 0 )
          {
            v49 = *v47;
            if ( !v49 )
              v49 = WindowName;
            sub_538860(&unk_BE1CFD, v49, v59, v60, v61);
            sub_53A160(0);
          }
          memset(v80, 0, sizeof(v80));
          v81 = 0;
          v82 = 0;
          sub_53A410(&unk_BE1CFD, v80, 63);
          LOBYTE(v63) = CINet::IsSubscriptionServer((CINet *)dword_B6CBB0);
          v50 = (const char *)dword_759EC8;
          if ( !dword_759EC8 )
            v50 = WindowName;
          v51 = v50 + 1;
          v52 = (unsigned int)&v50[strlen(v50) + 1];
          v64 = (int *)(v52 - (_DWORD)v51);
          CINet::CreateRoom(
            (CINet *)dword_B6CBB0,
            (bool)v63,
            &Filename[252],
            v80,
            *(_DWORD *)dword_759E90,
            *(_DWORD *)dword_B6CE9C,
            byte_759E9C,
            v73,
            *(_DWORD *)dword_759E4C + 1,
            v52 != (_DWORD)v51,
            dword_B6CE60,
            dword_B73294,
            dword_B706CC,
            dword_B73000,
            dword_B72EBC,
            dword_B70588,
            dword_B6FE20,
            dword_B73348,
            1,
            0,
            0);
        }
        LOBYTE(v95) = 0;
        nullsub_7(v92);
      }
      else
      {
        *((_DWORD *)this + 217) = 8;
      }
      v95 = -1;
      nullsub_7(v55);
      break;
    case 2:
      v72 = (LPCSTR)1;
      goto LABEL_135;
    case 3:
      v72 = 0;
LABEL_135:
      if ( (unsigned __int8)sub_484A00() )
      {
        sub_4EA880(1);
        this[288] = 0.0;
        *((_DWORD *)this + 217) = 5;
      }
      else
      {
        *((_DWORD *)this + 217) = 8;
      }
      break;
    case 4:
      sub_47F960();
      this[288] = 0.0;
      *((_DWORD *)this + 217) = 5;
      break;
    case 5:
      sub_4888D0((int)(this + 264), (int)this);
      sub_430B40(&dword_B640C0, COERCE_FLOAT(8));
      sub_482360(this);
      break;
    case 8:
      if ( dword_B640C0 != 2 )
        sub_430D50();
      SendMessageA(dword_B6CE68, 0x10u, 0, 0);
      v74 = 0;
      break;
    default:
      return v54;
  }
  return v54;
}
