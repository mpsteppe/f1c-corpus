void __thiscall sub_4694C0(int this)
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
  HWND v14; // eax
  HWND v15; // eax
  HWND v16; // eax
  HWND v17; // eax
  HWND v18; // eax
  HWND v19; // eax
  HWND v20; // eax
  HWND v21; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v24; // eax
  const char *v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  int v28; // eax
  HWND v29; // eax
  int v30; // esi
  int v31; // edx
  CHAR *v32; // edi
  int v33; // ecx
  int v34; // eax
  CHAR *v35; // edi
  int v36; // eax
  int v37; // ecx
  __int16 v38; // dx
  int v39; // edx
  int v40; // eax
  CHAR *v41; // edi
  char v42; // cl
  CHAR *v43; // edi
  int v44; // eax
  int v45; // ecx
  char v46; // dl
  char v47; // dl
  CHAR *v48; // edi
  int v49; // ecx
  __int16 v50; // dx
  CHAR *v51; // edi
  int v52; // ecx
  char v53; // dl
  CHAR *v54; // edi
  __int16 v55; // cx
  int v56; // edx
  CHAR *v57; // edi
  int v58; // ecx
  char v59; // al
  int v60; // edx
  __int16 v61; // ax
  CHAR *v62; // edi
  HWND v63; // eax
  int v64; // edi
  HWND v65; // eax
  HWND v66; // edi
  const char *v67; // esi
  const char *v68; // eax
  bool v69; // zf
  const char *v70; // edx
  const char *v71; // esi
  const char *v72; // edi
  CHAR *v73; // eax
  LRESULT v74; // eax
  LRESULT v75; // eax
  bool v76; // cc
  int v77; // [esp-10h] [ebp-180h]
  int v78; // [esp-Ch] [ebp-17Ch]
  const CHAR *v79; // [esp-8h] [ebp-178h]
  LPARAM v80; // [esp-8h] [ebp-178h]
  int v81; // [esp-8h] [ebp-178h]
  int v82; // [esp-8h] [ebp-178h]
  float v83; // [esp+Ch] [ebp-164h]
  LPARAM v84; // [esp+Ch] [ebp-164h]
  const char **v85; // [esp+10h] [ebp-160h]
  float v86; // [esp+14h] [ebp-15Ch]
  char *v87; // [esp+14h] [ebp-15Ch]
  int v88; // [esp+18h] [ebp-158h] BYREF
  int v89; // [esp+1Ch] [ebp-154h] BYREF
  int v90; // [esp+20h] [ebp-150h]
  CHAR String[128]; // [esp+24h] [ebp-14Ch] BYREF
  CHAR lParam[80]; // [esp+A4h] [ebp-CCh] BYREF
  char Buffer[32]; // [esp+F4h] [ebp-7Ch] BYREF
  _BYTE v94[92]; // [esp+114h] [ebp-5Ch] BYREF

  v90 = this + 428;
  v83 = sub_57B7C0(this + 428);
  switch ( *(_DWORD *)(this + 420) )
  {
    case 1:
      DlgItem = GetDlgItem(hDlg, 1047);
      SetWindowTextA(DlgItem, ::String);
      v3 = GetDlgItem(hDlg, 1046);
      SetWindowTextA(v3, &byte_629120);
      v4 = GetDlgItem(hDlg, 1044);
      SetWindowTextA(v4, &byte_629120);
      v5 = GetDlgItem(hDlg, 1048);
      SetWindowTextA(v5, &byte_629120);
      v6 = GetDlgItem(hDlg, 1067);
      SetWindowTextA(v6, &byte_629120);
      v7 = GetDlgItem(hDlg, 1186);
      SetWindowTextA(v7, &byte_629120);
      v8 = GetDlgItem(hDlg, 1187);
      SetWindowTextA(v8, &byte_629120);
      v9 = GetDlgItem(hDlg, 1193);
      SetWindowTextA(v9, &byte_629120);
      v10 = GetDlgItem(hDlg, 1194);
      SetWindowTextA(v10, &byte_629120);
      v11 = GetDlgItem(hDlg, 1195);
      SetWindowTextA(v11, &byte_629120);
      v12 = GetDlgItem(hDlg, 1033);
      EnableWindow(v12, 0);
      break;
    case 2:
      v13 = GetDlgItem(hDlg, 1047);
      SetWindowTextA(v13, aLoading);
      v14 = GetDlgItem(hDlg, 1046);
      SetWindowTextA(v14, &byte_629120);
      v15 = GetDlgItem(hDlg, 1044);
      SetWindowTextA(v15, &byte_629120);
      v16 = GetDlgItem(hDlg, 1048);
      SetWindowTextA(v16, &byte_629120);
      v17 = GetDlgItem(hDlg, 1067);
      SetWindowTextA(v17, &byte_629120);
      sub_46C260(this);
      v18 = GetDlgItem(hDlg, 1193);
      SetWindowTextA(v18, &byte_629120);
      v19 = GetDlgItem(hDlg, 1194);
      SetWindowTextA(v19, &byte_629120);
      v20 = GetDlgItem(hDlg, 1195);
      SetWindowTextA(v20, &byte_629120);
      v21 = GetDlgItem(hDlg, 1033);
      EnableWindow(v21, 0);
      break;
    case 3:
    case 4:
    case 5:
    case 6:
      if ( v83 > 0.89999998 )
      {
        v22 = GetDlgItem(hDlg, 1033);
        EnableWindow(v22, 1);
        String[0] = 0;
        sub_462C80(v94);
        if ( sub_4641B0(dword_764D70, (int)v94, 0) )
          v79 = v94;
        else
          v79 = &byte_629120;
        v23 = GetDlgItem(hDlg, 1047);
        SetWindowTextA(v23, v79);
        sprintf(String, "%.3f", 1.001999974250793);
        v24 = GetDlgItem(hDlg, 1046);
        SetWindowTextA(v24, String);
        v80 = dword_764ED8;
        v25 = (const char *)sub_46C2E0(dword_764ED8);
        sprintf(String, "%s (%d kbps)", v25, v80);
        v26 = GetDlgItem(hDlg, 1044);
        SetWindowTextA(v26, String);
        if ( NumOfElements )
          sprintf(String, "%d fps", (unsigned int)(__int64)((double)*(int *)(this + 424) / v83));
        else
          strcpy(String, off_5FD8E4);
        v27 = GetDlgItem(hDlg, 1048);
        SetWindowTextA(v27, String);
        v81 = v94[70] - 1;
        *(_DWORD *)(this + 424) = 0;
        v28 = sub_463BC0(dword_764D70);
        sprintf(String, "%d / %d", v28 - 1, v81);
        v29 = GetDlgItem(hDlg, 1067);
        SetWindowTextA(v29, String);
        sub_46C260(this);
        v30 = dword_75CBB0;
        switch ( dword_75CBB0 )
        {
          case 1:
            strcpy(String, aPractice);
            break;
          case 2:
            strcpy(String, aPractice);
            break;
          case 3:
            strcpy(String, aPractice);
            break;
          case 4:
            strcpy(String, aPractice);
            break;
          case 5:
            strcpy(String, aQualifying);
            break;
          case 6:
            strcpy(String, aHappyHour);
            break;
          case 7:
            strcpy(String, aRace_0);
            break;
          default:
            strcpy(String, aTesting);
            break;
        }
        if ( v30 == 7 )
        {
          if ( (unsigned int)(dword_75CBB4 - 1) > 7 )
          {
            v60 = dword_600D34;
            v61 = word_600D38;
            v62 = &String[strlen(String)];
            *(_DWORD *)v62 = dword_600D30;
            *((_DWORD *)v62 + 1) = v60;
            *((_WORD *)v62 + 4) = v61;
          }
          else
          {
            switch ( dword_75CBB4 )
            {
              case 1:
                v31 = dword_600DA4;
                v32 = &String[strlen(String) + 1];
                v33 = dword_600DA0;
                *(_DWORD *)--v32 = dword_600D9C;
                v34 = dword_600DA8;
                *((_DWORD *)v32 + 1) = v33;
                LOWORD(v33) = word_600DAC;
                *((_DWORD *)v32 + 2) = v31;
                *((_DWORD *)v32 + 3) = v34;
                *((_WORD *)v32 + 8) = v33;
                break;
              case 2:
                v35 = &String[strlen(String) + 1];
                v36 = dword_600D90;
                v37 = dword_600D94;
                *(_DWORD *)--v35 = dword_600D8C;
                v38 = word_600D98;
                *((_DWORD *)v35 + 1) = v36;
                LOBYTE(v36) = byte_600D9A;
                *((_DWORD *)v35 + 2) = v37;
                *((_WORD *)v35 + 6) = v38;
                v35[14] = v36;
                break;
              case 3:
                v39 = dword_600D80;
                v40 = dword_600D84;
                v41 = &String[strlen(String)];
                *(_DWORD *)v41 = dword_600D7C;
                v42 = byte_600D88;
                *((_DWORD *)v41 + 1) = v39;
                *((_DWORD *)v41 + 2) = v40;
                v41[12] = v42;
                break;
              case 4:
                v43 = &String[strlen(String) + 1];
                v44 = dword_600D70;
                v45 = dword_600D74;
                *(_DWORD *)--v43 = dword_600D6C;
                v46 = byte_600D78;
                *((_DWORD *)v43 + 1) = v44;
                *((_DWORD *)v43 + 2) = v45;
                v43[12] = v46;
                break;
              case 5:
                v47 = byte_600D68;
                v48 = &String[strlen(String) + 1];
                v49 = dword_600D64;
                *(_DWORD *)--v48 = dword_600D60;
                *((_DWORD *)v48 + 1) = v49;
                v48[8] = v47;
                break;
              case 6:
                v50 = word_600D5C;
                v51 = &String[strlen(String) + 1];
                v52 = dword_600D58;
                *(_DWORD *)--v51 = dword_600D54;
                *((_DWORD *)v51 + 1) = v52;
                *((_WORD *)v51 + 4) = v50;
                break;
              case 7:
                v53 = byte_600D52;
                v54 = &String[strlen(String) + 1];
                v55 = word_600D50;
                *(_DWORD *)--v54 = dword_600D4C;
                *((_WORD *)v54 + 2) = v55;
                v54[6] = v53;
                break;
              case 8:
                v56 = dword_600D44;
                v57 = &String[strlen(String) + 1];
                v58 = dword_600D40;
                *(_DWORD *)--v57 = dword_600D3C;
                v59 = byte_600D48;
                *((_DWORD *)v57 + 1) = v58;
                *((_DWORD *)v57 + 2) = v56;
                v57[12] = v59;
                break;
            }
          }
        }
        v63 = GetDlgItem(hDlg, 1193);
        SetWindowTextA(v63, String);
        v86 = v83 + *(float *)(this + 580);
        *(float *)(this + 580) = v86;
        sub_4B2BD0(v86, (int)&v88, (int)&v89);
        v64 = v88 / 60;
        v88 %= 60;
        sprintf(String, "%d:%.02d:%.02d", v64, v88, (unsigned int)(__int64)*(float *)&v89);
        v65 = GetDlgItem(hDlg, 1194);
        SetWindowTextA(v65, String);
        v66 = GetDlgItem(hDlg, 1195);
        if ( *(float *)(this + 668) <= 0.0 )
        {
          if ( sub_41F230(dword_62A170, aNoVoteInProgre, Destination) )
          {
            strncpy(Destination, aNoVoteInProgre, 0x1FFu);
            byte_62A37B = 0;
          }
          SetWindowTextA(v66, Destination);
        }
        else
        {
          v67 = &byte_629120;
          if ( *(_DWORD *)(this + 684) == 1 )
          {
            v67 = aNextSession_0;
          }
          else if ( *(_DWORD *)(this + 684) == 2 )
          {
            v67 = aNextEvent;
          }
          v82 = *(_DWORD *)(this + 676);
          v78 = *(_DWORD *)(this + 884);
          v77 = *(_DWORD *)(this + 880);
          Buffer[0] = 0;
          sprintf(Buffer, "%d/%d (%d)", v77, v78, v82);
          lParam[0] = 0;
          sprintf(lParam, "%s - %s", v67, Buffer);
          SetWindowTextA(v66, lParam);
        }
        v68 = (const char *)&unk_6320F4;
        v85 = (const char **)(this + 16);
        v84 = 0;
        v87 = (char *)&unk_6320F4;
        do
        {
          v69 = *((_DWORD *)v68 - 2097) == -1;
          lParam[0] = 0;
          if ( !v69 )
            sprintf(lParam, "%s (id: %d)", v68, v84);
          v70 = *v85;
          v71 = *v85;
          if ( !*v85 )
            v71 = &byte_629120;
          if ( strcmp(lParam, v71) )
          {
            v72 = *v85;
            if ( !v70 )
              v72 = &byte_629120;
            if ( (int)strlen(v72) > 0 )
            {
              v73 = (CHAR *)*v85;
              if ( !v70 )
                v73 = &byte_629120;
              v74 = SendDlgItemMessageA(hDlg, 1033, 0x1A2u, 0xFFFFFFFF, (LPARAM)v73);
              SendDlgItemMessageA(hDlg, 1033, 0x182u, v74, 0);
              sub_578600(&byte_629120);
            }
            if ( strlen(lParam) )
            {
              sub_578600(lParam);
              v75 = SendDlgItemMessageA(hDlg, 1033, 0x180u, 0, (LPARAM)lParam);
              if ( v75 != -1 )
                SendDlgItemMessageA(hDlg, 1033, 0x19Au, v75, v84);
            }
          }
          v68 = v87 + 25304;
          v76 = (int)(v87 + 25304) < (int)&unk_75A974;
          ++v84;
          v85 += 2;
          v87 += 25304;
        }
        while ( v76 );
        sub_57B690(v90);
        nullsub_6(v94);
      }
      break;
    default:
      return;
  }
}
