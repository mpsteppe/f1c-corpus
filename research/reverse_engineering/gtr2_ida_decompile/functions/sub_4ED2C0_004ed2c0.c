int __stdcall sub_4ED2C0(HWND hWnd, UINT a2, int a3, unsigned int a4)
{
  int result; // eax
  int i; // esi
  int v6; // [esp-4h] [ebp-8h]

  if ( a2 > 0x14 )
  {
    if ( a2 > 0x204 )
    {
      switch ( a2 )
      {
        case 0x205u:
          sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 2, 0);
          return 0;
        case 0x207u:
          sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 1, 1);
          return 0;
        case 0x208u:
          sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 1, 0);
          return 0;
        case 0x20Au:
          if ( a3 <= 0 )
            v6 = -1;
          else
            v6 = 1;
          sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 3, v6);
          return 0;
        default:
          return DefWindowProcA(hWnd, a2, a3, a4);
      }
    }
    if ( a2 == 516 )
    {
      sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 2, 1);
    }
    else
    {
      if ( a2 <= 0x200 )
      {
        switch ( a2 )
        {
          case 0x200u:
            sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), -1, 0);
            return 0;
          case 0x20u:
            sub_45DDA0(dword_B6A328, dword_B6A3D4);
            return 1;
          case 0x112u:
            if ( (a3 & 0xFFF0) != 0xF100 && (a3 & 0xFFF0) != 0xF140 && (a3 & 0xFFF0) != 0xF170 )
              return DefWindowProcA(hWnd, 0x112u, a3, a4);
            return 0;
        }
        return DefWindowProcA(hWnd, a2, a3, a4);
      }
      if ( a2 == 513 )
      {
        sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 0, 1);
      }
      else
      {
        if ( a2 != 514 )
          return DefWindowProcA(hWnd, a2, a3, a4);
        sub_45EE90(dword_B6A328, (unsigned __int16)a4, HIWORD(a4), 0, 0);
      }
    }
    return 0;
  }
  if ( a2 == 20 )
    return 1;
  switch ( a2 )
  {
    case 2u:
      ShowWindow(hWnd, 0);
      PostQuitMessage(0);
      return 0;
    case 3u:
    case 5u:
      sub_4ED2A0();
      return 0;
    case 6u:
      if ( sub_473630(&dword_B6CBA8) )
        goto LABEL_24;
      if ( (_WORD)a3 )
      {
        if ( !byte_B6F1BC )
        {
          byte_B6F1BC = 1;
          *(_BYTE *)(dword_FB27A4 + 4813) = 0;
          SetForegroundWindow(dword_B6F1B8);
          ShowWindow(dword_B6F1B8, 9);
          if ( dword_B640C0 == 5 )
          {
            if ( !(unsigned __int8)sub_4735A0() && dword_BE1204 != 2 && byte_B6F1C0 )
            {
              byte_B6F1C0 = 0;
              sub_4304C0();
              sub_540140(&unk_BE1D30);
            }
            for ( i = 0; i < dword_757C10; ++i )
              sub_4FB7D0(*(&dword_91E088 + i) + 14824);
          }
        }
      }
      else if ( byte_B6F1BC )
      {
        byte_B6F1BC = 0;
        *(_BYTE *)(dword_FB27A4 + 4813) = 1;
        if ( !dword_FB1CF8 )
          ShowWindow(dword_B6F1B8, 6);
        if ( dword_B640C0 == 5 && !(unsigned __int8)sub_4735A0() && dword_BE1204 != 2 && !byte_B6413C )
        {
          byte_B6F1C0 = 1;
          sub_4304C0();
          sub_540130(&unk_BE1D30);
          return 1;
        }
      }
LABEL_24:
      result = 1;
      break;
    case 7u:
      result = 1;
      byte_75B2B9 = 1;
      return result;
    case 8u:
      result = 1;
      byte_75B2B9 = 0;
      return result;
    case 0x10u:
      if ( dword_B640C0 != 7 )
        return 0;
      sub_4ED060();
      return 0;
    default:
      return DefWindowProcA(hWnd, a2, a3, a4);
  }
  return result;
}
