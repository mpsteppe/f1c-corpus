int __thiscall sub_4943E0(_DWORD *this)
{
  const CHAR *v3; // eax
  char *v4; // eax
  const CHAR *v5; // [esp-Ch] [ebp-168h]
  struct _STARTUPINFOA StartupInfo; // [esp+8h] [ebp-154h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+4Ch] [ebp-110h] BYREF
  char Buffer[256]; // [esp+5Ch] [ebp-100h] BYREF

  switch ( this[69] )
  {
    case 1:
      v4 = sub_41D840(&byte_91CC38, "Please Wait...");
      sub_4EB900(&unk_B6F134, v4);
      sprintf(Buffer, (const char *const)(dword_B6CBB0 + 1335));
      ShellExecuteA(0, "open", Buffer, 0, 0, 5);
      sub_4DF020(this[12]);
      return 0;
    case 2:
      if ( CINet::UpdateExecuteNow((CINet *)dword_B6CBB0) )
        return 0;
      CINet::DownloadUpdate((CINet *)dword_B6CBB0, 0, sub_4942A0);
      sub_4CD6D0("SIM_WHATS_NEW");
      return 0;
    case 3:
      StartupInfo.cb = 68;
      memset(&StartupInfo.lpReserved, 0, 12);
      StartupInfo.dwFlags = 32;
      StartupInfo.cbReserved2 = 0;
      StartupInfo.lpReserved2 = 0;
      v5 = CINet::PathToExecute((CINet *)dword_B6CBB0);
      v3 = CINet::UpdateToExecute((CINet *)dword_B6CBB0);
      CreateProcessA(v3, (LPSTR)CommandLine, 0, 0, 0, 0x4000020u, 0, v5, &StartupInfo, &ProcessInformation);
      goto LABEL_5;
    case 4:
LABEL_5:
      dword_75B17C = -1;
      return 0;
    default:
      return 0;
  }
}
