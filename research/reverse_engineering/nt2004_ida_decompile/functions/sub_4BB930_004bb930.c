int sub_4BB930()
{
  HWND v0; // eax
  HMODULE ModuleHandleA; // eax
  HWND v3; // eax
  HWND DesktopWindow; // eax
  int pvParam; // [esp+0h] [ebp-140h] BYREF
  DWORD NumberOfFreeClusters; // [esp+4h] [ebp-13Ch] BYREF
  ULARGE_INTEGER TotalNumberOfFreeBytes; // [esp+8h] [ebp-138h] BYREF
  ULARGE_INTEGER TotalNumberOfBytes; // [esp+10h] [ebp-130h] BYREF
  ULARGE_INTEGER FreeBytesAvailableToCaller; // [esp+18h] [ebp-128h] BYREF
  _MEMORYSTATUS Buffer; // [esp+20h] [ebp-120h] BYREF
  CHAR Text[256]; // [esp+40h] [ebp-100h] BYREF

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_10, 460) )
    sub_500FE0((int)&unk_7D7920, aEnteredOsmanEn, pvParam);
  hObject = CreateMutexA(0, 1, Name);
  if ( !hObject || GetLastError() == 183 )
  {
    byte_76621D = 1;
    DesktopWindow = GetDesktopWindow();
    MessageBoxA(DesktopWindow, ::Text, aError, 0);
    return 1;
  }
  Buffer.dwLength = 32;
  GlobalMemoryStatus(&Buffer);
  if ( Buffer.dwAvailPageFile < 0x9600000 )
  {
    sprintf(Text, aSystemResource, 150);
    v0 = GetDesktopWindow();
    MessageBoxA(v0, Text, aLowSystemResou, 0);
  }
  ModuleHandleA = GetModuleHandleA(ModuleName);
  if ( GetProcAddress(ModuleHandleA, ProcName) )
  {
    if ( !GetDiskFreeSpaceExA(0, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes)
      || TotalNumberOfFreeBytes.QuadPart >= 0x10000000 )
    {
      goto LABEL_10;
    }
LABEL_15:
    sprintf(Text, "You must have %d MB disk space free to run this application.", 256);
    v3 = GetDesktopWindow();
    MessageBoxA(v3, Text, aNotEnoughDiskS, 0);
    return 1;
  }
  TotalNumberOfBytes.LowPart = 0;
  FreeBytesAvailableToCaller.LowPart = 0;
  NumberOfFreeClusters = 0;
  TotalNumberOfFreeBytes.LowPart = 0;
  if ( GetDiskFreeSpaceA(
         0,
         &TotalNumberOfBytes.LowPart,
         &FreeBytesAvailableToCaller.LowPart,
         &NumberOfFreeClusters,
         &TotalNumberOfFreeBytes.LowPart)
    && TotalNumberOfBytes.LowPart * FreeBytesAvailableToCaller.LowPart * NumberOfFreeClusters < 0x10000000 )
  {
    goto LABEL_15;
  }
LABEL_10:
  pvParam = 0;
  SystemParametersInfoA(0x10u, 0, &pvParam, 0);
  if ( pvParam == 1 )
  {
    SystemParametersInfoA(0x11u, 0, 0, 2u);
    byte_76621E = 1;
  }
  return 0;
}
