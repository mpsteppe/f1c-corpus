// Function: FUN_004f8b50 @ 004f8b50
// Strings:  [VFXGetTracking, VFXSetVideoMode, VFXZeroSet, VFXClose, VFXOpen, VFXDrive.dll]


undefined4 FUN_004f8b50(void)

{
  DAT_008afc78 = LoadLibraryA(s_VFXDrive_dll_005d6d50);
  if (DAT_008afc78 == (HMODULE)0x0) {
    return 1;
  }
  DAT_008afc7c = GetProcAddress(DAT_008afc78,s_VFXOpen_005d6d48);
  DAT_008afc80 = GetProcAddress(DAT_008afc78,s_VFXClose_005d6d3c);
  DAT_008afc84 = GetProcAddress(DAT_008afc78,s_VFXZeroSet_005d6d30);
  DAT_008afc88 = GetProcAddress(DAT_008afc78,s_VFXSetVideoMode_005d6d20);
  DAT_008afc8c = GetProcAddress(DAT_008afc78,s_VFXGetTracking_005d6d10);
  if ((((DAT_008afc8c != (FARPROC)0x0) && (DAT_008afc7c != (FARPROC)0x0)) &&
      (DAT_008afc80 != (FARPROC)0x0)) &&
     ((DAT_008afc84 != (FARPROC)0x0 && (DAT_008afc88 != (FARPROC)0x0)))) {
    (*DAT_008afc7c)();
    return 0;
  }
  return 4;
}


