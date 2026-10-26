LRESULT __thiscall sub_46A4A0(CHAR ****this, int a2)
{
  LRESULT result; // eax
  CHAR *v3; // eax
  CHAR *v4; // eax
  LPARAM v5; // edi
  HWND v6; // eax
  HWND v7; // eax
  HWND v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  HWND v11; // eax
  int v12; // ebp
  int v13; // edi
  LRESULT v14; // eax
  CHAR ***v15; // eax
  bool v16; // zf
  CHAR **i; // eax
  CHAR *v18; // eax
  CHAR ***v19; // eax
  CHAR ***v20; // eax
  LRESULT v21; // ebp
  signed int j; // edi
  LRESULT v23; // eax
  HWND DlgItem; // eax
  HWND v25; // eax
  HWND v26; // eax
  HWND v27; // eax
  HWND v28; // eax
  HWND v29; // eax
  HWND v30; // eax
  HWND v31; // eax
  HWND v32; // eax
  int wParam; // [esp+Ch] [ebp-178h]
  CHAR String[8]; // [esp+14h] [ebp-170h] BYREF
  int v36; // [esp+1Ch] [ebp-168h]
  CHAR Buffer[16]; // [esp+24h] [ebp-160h] BYREF
  char lParam[80]; // [esp+34h] [ebp-150h] BYREF
  LPARAM v39[64]; // [esp+84h] [ebp-100h] BYREF

  if ( a2 == 3 )
  {
    DlgItem = GetDlgItem(hDlg, 1047);
    SetWindowTextA(DlgItem, &byte_629120);
    v25 = GetDlgItem(hDlg, 1046);
    SetWindowTextA(v25, &byte_629120);
    v26 = GetDlgItem(hDlg, 1048);
    SetWindowTextA(v26, &byte_629120);
    v27 = GetDlgItem(hDlg, 1067);
    SetWindowTextA(v27, &byte_629120);
    v28 = GetDlgItem(hDlg, 1186);
    SetWindowTextA(v28, &byte_629120);
    v29 = GetDlgItem(hDlg, 1187);
    SetWindowTextA(v29, &byte_629120);
    v30 = GetDlgItem(hDlg, 1193);
    SetWindowTextA(v30, &byte_629120);
    v31 = GetDlgItem(hDlg, 1194);
    SetWindowTextA(v31, &byte_629120);
    v32 = GetDlgItem(hDlg, 1195);
    SetWindowTextA(v32, &byte_629120);
    return SendDlgItemMessageA(hDlg, 1033, 0x184u, 0, 0);
  }
  else if ( a2 == 4 )
  {
    SendDlgItemMessageA(hWnd, 1000, 0x184u, 0, 0);
    SendDlgItemMessageA(hWnd, 1000, 0x184u, 0, 0);
    v8 = GetDlgItem(hWnd, 1040);
    SetWindowTextA(v8, &byte_629120);
    v9 = GetDlgItem(hWnd, 1045);
    SetWindowTextA(v9, &byte_629120);
    v10 = GetDlgItem(hWnd, 1041);
    SetWindowTextA(v10, &byte_629120);
    v11 = GetDlgItem(hWnd, 1046);
    SetWindowTextA(v11, &byte_629120);
    v12 = dword_7D6B50;
    v13 = 0;
    for ( wParam = 0; v13 < v12; ++v13 )
    {
      sub_4E8D80(v13);
      lParam[0] = 0;
      sub_4E8F40(lParam, 79);
      v14 = SendDlgItemMessageA(hWnd, 1000, 0x180u, 0, (LPARAM)lParam);
      if ( SendDlgItemMessageA(hWnd, 1000, 0x198u, v14, (LPARAM)String) != -1 && wParam <= v36 - *(_DWORD *)String )
        wParam = v36 - *(_DWORD *)String;
    }
    v15 = *this;
    v16 = *this == 0;
    this[2] = *this;
    if ( !v16 )
    {
      for ( i = *v15; i; i = *v20 )
      {
        v18 = *i;
        if ( !v18 )
          v18 = &byte_629120;
        sub_4E8C80(v18);
        lParam[0] = 0;
        if ( !sub_4E8F40(lParam, 79) )
          SendDlgItemMessageA(hWnd, 1003, 0x180u, 0, (LPARAM)lParam);
        v19 = this[2];
        if ( !v19 )
          break;
        v20 = (CHAR ***)v19[1];
        this[2] = v20;
        if ( !v20 )
          break;
      }
    }
    v21 = SendDlgItemMessageA(hWnd, 1003, 0x18Bu, 0, 0);
    for ( j = 0; j < v21; ++j )
    {
      SendDlgItemMessageA(hWnd, 1003, 0x189u, j, (LPARAM)v39);
      v23 = SendDlgItemMessageA(hWnd, 1000, 0x1A2u, 0xFFFFFFFF, (LPARAM)v39);
      if ( v23 != -1 )
        SendDlgItemMessageA(hWnd, 1000, 0x182u, v23, 0);
    }
    if ( wParam > 0 )
    {
      SendDlgItemMessageA(hWnd, 1000, 0x194u, wParam, 0);
      SendDlgItemMessageA(hWnd, 1003, 0x194u, wParam, 0);
    }
    SendDlgItemMessageA(hWnd, 1042, 0x14Bu, 0, 0);
    SendDlgItemMessageA(hWnd, 1042, 0x143u, 0, (LPARAM)a56kModem);
    SendDlgItemMessageA(hWnd, 1042, 0x143u, 0, (LPARAM)aIsdn);
    SendDlgItemMessageA(hWnd, 1042, 0x143u, 0, (LPARAM)aCableDsl128Kbi);
    SendDlgItemMessageA(hWnd, 1042, 0x143u, 0, (LPARAM)aCableDsl256Kbi);
    SendDlgItemMessageA(hWnd, 1042, 0x143u, 0, (LPARAM)off_600E2C);
    SendDlgItemMessageA(hWnd, 1042, 0x143u, 0, (LPARAM)aCustom);
    SendDlgItemMessageA(hWnd, 1042, 0x14Eu, dword_7652C4, 0);
    sub_46B970();
    return sub_46BA40();
  }
  else
  {
    result = a2 - 5;
    if ( a2 == 5 )
    {
      v3 = (CHAR *)::lParam;
      if ( !::lParam )
        v3 = &byte_629120;
      SendDlgItemMessageA(dword_7652C0, 1024, 0xCu, 0, (LPARAM)v3);
      v4 = (CHAR *)dword_764ED0;
      if ( !dword_764ED0 )
        v4 = &byte_629120;
      SendDlgItemMessageA(dword_7652C0, 1025, 0xCu, 0, (LPARAM)v4);
      SendDlgItemMessageA(dword_7652C0, 1024, 0xC5u, 0x17u, 0);
      SendDlgItemMessageA(dword_7652C0, 1025, 0xC5u, 0xFu, 0);
      SendDlgItemMessageA(dword_7652C0, 1028, 0x14Bu, 0, 0);
      SendDlgItemMessageA(dword_7652C0, 1028, 0x143u, 0, (LPARAM)&off_5FB7E4);
      SendDlgItemMessageA(dword_7652C0, 1028, 0x143u, 0, (LPARAM)aBlackOnly);
      SendDlgItemMessageA(dword_7652C0, 1028, 0x143u, 0, (LPARAM)aOn);
      SendDlgItemMessageA(dword_7652C0, 1028, 0x14Eu, ::wParam, 0);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x14Bu, 0, 0);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)&off_5FB7E4);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)aNormal_0);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)a2x);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)a3x);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)a4x);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)a5x);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)a6x);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x143u, 0, (LPARAM)a7x);
      SendDlgItemMessageA(dword_7652C0, 1029, 0x14Eu, dword_600764, 0);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x14Bu, 0, 0);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)&off_5FB7E4);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)aNormal_0);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)a2x);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)a3x);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)a4x);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)a5x);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)a6x);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x143u, 0, (LPARAM)a7x);
      SendDlgItemMessageA(dword_7652C0, 1030, 0x14Eu, dword_600768, 0);
      SendDlgItemMessageA(dword_7652C0, 1031, 0x14Bu, 0, 0);
      SendDlgItemMessageA(dword_7652C0, 1031, 0x143u, 0, (LPARAM)&off_5FB7E4);
      SendDlgItemMessageA(dword_7652C0, 1031, 0x143u, 0, (LPARAM)aNormal_0);
      SendDlgItemMessageA(dword_7652C0, 1031, 0x143u, 0, (LPARAM)aTimeScaled);
      SendDlgItemMessageA(dword_7652C0, 1031, 0x14Eu, dword_60076C, 0);
      SendDlgItemMessageA(dword_7652C0, 1032, 0x14Bu, 0, 0);
      SendDlgItemMessageA(dword_7652C0, 1032, 0x143u, 0, (LPARAM)aChanging);
      SendDlgItemMessageA(dword_7652C0, 1032, 0x143u, 0, (LPARAM)aClear);
      SendDlgItemMessageA(dword_7652C0, 1032, 0x143u, 0, (LPARAM)aCloudy);
      SendDlgItemMessageA(dword_7652C0, 1032, 0x14Eu, dword_600770, 0);
      SendDlgItemMessageA(dword_7652C0, 1006, 0xF1u, (unsigned __int8)byte_600774, 0);
      SendDlgItemMessageA(dword_7652C0, 1007, 0xF1u, (unsigned __int8)byte_600775, 0);
      SendDlgItemMessageA(dword_7652C0, 1008, 0xF1u, (unsigned __int8)byte_600776, 0);
      SendDlgItemMessageA(dword_7652C0, 1009, 0xF1u, (unsigned __int8)byte_600777, 0);
      SendDlgItemMessageA(dword_7652C0, 1010, 0xF1u, (unsigned __int8)byte_600778, 0);
      SendDlgItemMessageA(dword_7652C0, 1011, 0xF1u, (unsigned __int8)byte_7652D0, 0);
      SendDlgItemMessageA(dword_7652C0, 1012, 0xF1u, (unsigned __int8)byte_600779, 0);
      SendDlgItemMessageA(dword_7652C0, 1013, 0xF1u, (unsigned __int8)byte_60077A, 0);
      SendDlgItemMessageA(dword_7652C0, 1014, 0xF1u, (unsigned __int8)byte_60077B, 0);
      SendDlgItemMessageA(dword_7652C0, 1015, 0xF1u, (unsigned __int8)byte_60077C, 0);
      SendDlgItemMessageA(dword_7652C0, 1016, 0xF1u, (unsigned __int8)byte_60077D, 0);
      SendDlgItemMessageA(dword_7652C0, 1017, 0xF1u, (unsigned __int8)byte_7652D1, 0);
      SendDlgItemMessageA(dword_7652C0, 1198, 0x406u, 1u, (LPARAM)&unk_640003);
      v5 = (__int64)(flt_600780 * 100.0 + 0.5);
      SendDlgItemMessageA(dword_7652C0, 1198, 0x405u, 1u, v5);
      sprintf(String, "%d%%", v5);
      v6 = GetDlgItem(dword_7652C0, 1037);
      SetWindowTextA(v6, String);
      SendDlgItemMessageA(dword_7652C0, 1199, 0x406u, 1u, (LPARAM)&unk_640000);
      SendDlgItemMessageA(dword_7652C0, 1199, 0x405u, 1u, dword_600784);
      sprintf(Buffer, "%d%%", dword_600784);
      v7 = GetDlgItem(dword_7652C0, 1038);
      return SetWindowTextA(v7, Buffer);
    }
  }
  return result;
}
