void __thiscall sub_482440(int this)
{
  HWND DlgItem; // eax
  HWND v3; // eax
  HWND v4; // eax
  HWND v5; // eax
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  HWND v12; // eax
  HWND v13; // eax
  char *v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  int v17; // eax
  HWND v18; // eax
  int v19; // ecx
  char *v20; // edi
  char *v22; // edi
  char *v24; // edi
  char *v26; // edi
  char *v28; // edi
  char *v30; // edi
  char *v32; // edi
  char *v34; // edi
  char *v36; // edi
  HWND v38; // eax
  const char *v39; // eax
  HWND v40; // eax
  int v41; // esi
  HWND v42; // eax
  HWND v43; // esi
  const char *v44; // edi
  CHAR *v45; // eax
  const char **v46; // ebx
  bool v47; // zf
  const char *v48; // edi
  const char *v49; // esi
  const char *v50; // eax
  const CHAR *v51; // eax
  LRESULT v52; // eax
  LRESULT v53; // eax
  bool v54; // cc
  int v55; // [esp-Ch] [ebp-1F4h]
  int v56; // [esp-8h] [ebp-1F0h]
  char *v57; // [esp-4h] [ebp-1ECh]
  int v58; // [esp-4h] [ebp-1ECh]
  const CHAR *v59; // [esp+4h] [ebp-1E4h]
  LPARAM v60; // [esp+4h] [ebp-1E4h]
  int v61; // [esp+4h] [ebp-1E4h]
  char *v62; // [esp+4h] [ebp-1E4h]
  char *v63; // [esp+8h] [ebp-1E0h]
  float lParam; // [esp+10h] [ebp-1D8h]
  LPARAM lParama; // [esp+10h] [ebp-1D8h]
  float v66; // [esp+14h] [ebp-1D4h]
  int *v67; // [esp+14h] [ebp-1D4h]
  int v68[2]; // [esp+18h] [ebp-1D0h] BYREF
  int v69; // [esp+20h] [ebp-1C8h] BYREF
  CHAR Buffer[7]; // [esp+24h] [ebp-1C4h] BYREF
  char v71; // [esp+2Bh] [ebp-1BDh] BYREF
  CHAR String[120]; // [esp+2Ch] [ebp-1BCh] BYREF
  CHAR v74[80]; // [esp+A8h] [ebp-140h] BYREF
  char v75[32]; // [esp+F8h] [ebp-F0h] BYREF
  _BYTE v76[8]; // [esp+118h] [ebp-D0h] BYREF
  _BYTE v77[180]; // [esp+120h] [ebp-C8h] BYREF
  int v78; // [esp+1DCh] [ebp-Ch]
  int v79; // [esp+1E4h] [ebp-4h]

  *(_DWORD *)Buffer = this + 880;
  *(float *)v68 = sub_617F80(this + 880);
  switch ( *(_DWORD *)(this + 868) )
  {
    case 1:
      sub_41D840(&byte_91CC38, "Starting server...");
      off_16C95B0();
      break;
    case 2:
    case 3:
      v63 = sub_41D840(&byte_91CC38, "Loading...");
      DlgItem = GetDlgItem(hDlg, 1047);
      SetWindowTextA(DlgItem, v63);
      v3 = GetDlgItem(hDlg, 1046);
      SetWindowTextA(v3, WindowName);
      v4 = GetDlgItem(hDlg, 1044);
      SetWindowTextA(v4, WindowName);
      v5 = GetDlgItem(hDlg, 1048);
      SetWindowTextA(v5, WindowName);
      v6 = GetDlgItem(hDlg, 1067);
      SetWindowTextA(v6, WindowName);
      sub_481840();
      v7 = GetDlgItem(hDlg, 1193);
      SetWindowTextA(v7, WindowName);
      v8 = GetDlgItem(hDlg, 1194);
      SetWindowTextA(v8, WindowName);
      v9 = GetDlgItem(hDlg, 1195);
      SetWindowTextA(v9, WindowName);
      v10 = GetDlgItem(hDlg, 1033);
      EnableWindow(v10, 0);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      if ( *(float *)v68 > 0.89999998 )
      {
        v11 = GetDlgItem(hDlg, 1033);
        EnableWindow(v11, 1);
        String[0] = 0;
        sub_4744E0(v77);
        v79 = 0;
        if ( sub_4747D0(&dword_B6CBA8, (int)v77, 0) )
          v59 = v77;
        else
          v59 = WindowName;
        v12 = GetDlgItem(hDlg, 1047);
        SetWindowTextA(v12, v59);
        sprintf(String, "%.3f", 1.0);
        v13 = GetDlgItem(hDlg, 1046);
        SetWindowTextA(v13, String);
        v60 = ::lParam;
        v14 = sub_4818C0(::lParam);
        sprintf(String, "%s (%d kbps)", v14, v60);
        v15 = GetDlgItem(hDlg, 1044);
        SetWindowTextA(v15, String);
        if ( dword_757C10 )
          sprintf(String, "%d fps", (unsigned int)(unsigned __int64)((double)*(int *)(this + 872) / *(float *)v68));
        else
          *(_DWORD *)String = &loc_412F4E;
        v16 = GetDlgItem(hDlg, 1048);
        SetWindowTextA(v16, String);
        v61 = v77[106] - 1;
        *(_DWORD *)(this + 872) = 0;
        v17 = sub_4736B0(&dword_B6CBA8);
        sprintf(String, "%d / %d", v17 - 1, v61);
        v18 = GetDlgItem(hDlg, 1067);
        SetWindowTextA(v18, String);
        sub_481840();
        switch ( *(_DWORD *)dword_B640C8 )
        {
          case 1:
            strcpy(String, "Practice 1");
            break;
          case 2:
            strcpy(String, "Practice 2");
            break;
          case 3:
            strcpy(String, "Qualifying 1");
            break;
          case 4:
            strcpy(String, "Qualifying 2");
            break;
          case 5:
            strcpy(String, "Warmup");
            break;
          case 6:
            v19 = 1701011794;
            String[4] = 0;
            goto LABEL_19;
          default:
            v19 = 1953719636;
            *(_DWORD *)&String[4] = (char *)&loc_676E66 + 3;
LABEL_19:
            *(_DWORD *)String = v19;
            break;
        }
        if ( *(_DWORD *)dword_B640C8 == 6 )
        {
          switch ( dword_B64134 )
          {
            case 1:
              v20 = &v71;
              while ( *++v20 )
                ;
              strcpy(v20, " - Reconnaissance");
              break;
            case 2:
              v22 = &v71;
              while ( *++v22 )
                ;
              strcpy(v22, " - Walkthrough");
              break;
            case 3:
              v24 = &v71;
              while ( *++v24 )
                ;
              strcpy(v24, " - Formation");
              break;
            case 4:
              v26 = &v71;
              while ( *++v26 )
                ;
              strcpy(v26, " - Countdown");
              break;
            case 5:
              v28 = &v71;
              while ( *++v28 )
                ;
              strcpy(v28, " - Green");
              break;
            case 6:
              v30 = &v71;
              while ( *++v30 )
                ;
              strcpy(v30, " - Yellow");
              break;
            case 7:
              v32 = &v71;
              while ( *++v32 )
                ;
              strcpy(v32, " - Red");
              break;
            case 8:
              v34 = &v71;
              while ( *++v34 )
                ;
              strcpy(v34, " - Checkered");
              break;
            default:
              v36 = &v71;
              while ( *++v36 )
                ;
              strcpy(v36, " - Before");
              break;
          }
        }
        v62 = sub_41D840(off_16C998C[0], String);
        v38 = GetDlgItem(hDlg, 1193);
        SetWindowTextA(v38, v62);
        v39 = (const char *)sub_50A790(&byte_B6F530, -1, 0);
        v57 = sub_41D840(&byte_91CC38, v39);
        v40 = GetDlgItem(hDlg, 1069);
        SetWindowTextA(v40, v57);
        v66 = lParam + *(float *)(this + 1040);
        *(float *)(this + 1040) = v66;
        sub_4E42B0(v66, (int)v68, (int)&v69);
        v41 = v68[0] / 60;
        v68[0] %= 60;
        sprintf(Buffer, "%d:%.02d:%.02d", v41, v68[0], (unsigned int)(unsigned __int64)*(float *)&v69);
        v42 = GetDlgItem(hDlg, 1194);
        SetWindowTextA(v42, Buffer);
        v43 = GetDlgItem(hDlg, 1195);
        if ( sub_47F780((float *)(this + 1056)) )
        {
          v44 = WindowName;
          if ( *(_DWORD *)(this + 1152) == 1 )
          {
            v44 = "Next Session";
          }
          else if ( *(_DWORD *)(this + 1152) == 2 )
          {
            v44 = "Next Event";
          }
          v58 = *(_DWORD *)(this + 1144);
          v56 = *(_DWORD *)(this + 1580);
          v55 = *(_DWORD *)(this + 1576);
          v75[0] = 0;
          sprintf(v75, "%d/%d (%d)", v55, v56, v58);
          v74[0] = 0;
          sprintf(v74, "%s - %s", v44, v75);
          v45 = v74;
        }
        else
        {
          v45 = sub_41D840(&byte_91CC38, "No vote in progress");
        }
        SetWindowTextA(v43, v45);
        v46 = (const char **)(this + 16);
        lParama = 0;
        v67 = &dword_9259BC;
        do
        {
          v47 = *(v67 - 1742) == -1;
          v74[0] = 0;
          if ( !v47 )
            sprintf(v74, "%s (id: %d)", (const char *)&v67[27 * *v67 - 33], lParama);
          v48 = *v46;
          v49 = *v46;
          if ( !*v46 )
            v49 = WindowName;
          if ( strcmp(v74, v49) )
          {
            v50 = *v46;
            if ( !v48 )
              v50 = WindowName;
            if ( (int)strlen(v50) > 0 )
            {
              v51 = *v46;
              if ( !v48 )
                v51 = WindowName;
              v52 = SendDlgItemMessageA(hDlg, 1033, 0x1A2u, 0xFFFFFFFF, (LPARAM)v51);
              SendDlgItemMessageA(hDlg, 1033, 0x182u, v52, 0);
              sub_615860(WindowName);
            }
            if ( strlen(v74) )
            {
              sub_615860(v74);
              v53 = SendDlgItemMessageA(hDlg, 1033, 0x180u, 0, (LPARAM)v74);
              if ( v53 != -1 )
                SendDlgItemMessageA(hDlg, 1033, 0x19Au, v53, lParama);
            }
          }
          v46 += 2;
          v54 = (int)(v67 + 5654) < (int)&unk_B63D7C;
          ++lParama;
          v67 += 5654;
        }
        while ( v54 );
        sub_617E70(v68[1]);
        v78 = -1;
        nullsub_7(v76);
      }
      break;
    default:
      return;
  }
}
