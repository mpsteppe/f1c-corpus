int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  float v4; // edi
  HMODULE LibraryA; // eax
  char *v6; // eax
  HANDLE CurrentProcess; // eax
  CHAR LCData[8]; // [esp+0h] [ebp-108h] BYREF
  CHAR LibFileName[256]; // [esp+8h] [ebp-100h] BYREF

  dword_B64140 = 1065353216;
  dword_B64144 = (int)"aa12  ab12_";
  byte_B6413D = 0;
  dword_B640C4 = 3;
  ::hInstance = hInstance;
  GetLocaleInfoA(0x400u, 1u, LCData, 5);
  dword_B6F1AC = hInstance;
  sprintf(LibFileName, "UIRes%s.dll", LCData);
  LibraryA = LoadLibraryA(LibFileName);
  dword_B6F1AC = hInstance;
  if ( LibraryA )
    dword_B6F1AC = LibraryA;
  if ( !strcmp("0407", _strupr(LCData))
    || !strcmp("0807", _strupr(LCData))
    || !strcmp("0C07", _strupr(LCData))
    || !strcmp("1007", _strupr(LCData))
    || (v6 = _strupr(LCData), byte_B6F1BE = 0, !strcmp("1407", v6)) )
  {
    byte_B6F1BE = 1;
  }
  sub_41AE00();
  sub_41C040((const CHAR **)&unk_91CA68, 0);
  sub_561320(byte_FAE910, lpCmdLine, lpCmdLine);
  sub_4EA8A0(&unk_B6F134, lpCmdLine);
  sub_501EE0(&byte_B6F530, lpCmdLine);
  sub_475280(&dword_B6CBA8, lpCmdLine);
  CurrentProcess = GetCurrentProcess();
  SetProcessAffinityMask(CurrentProcess, 1u);
  if ( !sub_4305F0() && !sub_4308E0() )
  {
LABEL_11:
    if ( !sbdt::Game::Init() )
    {
      while ( !sub_4309C0(&dword_B640C0, 1) )
      {
        if ( sub_430B40(&dword_B640C0, v4) )
        {
          sub_430D50();
          if ( !sub_4308E0() )
            goto LABEL_11;
          break;
        }
      }
    }
  }
  sbdt::Game::Exit((sbdt::Game *)&dword_B640C0);
  return 0;
}
