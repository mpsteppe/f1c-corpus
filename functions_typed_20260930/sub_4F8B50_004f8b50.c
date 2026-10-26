int sub_4F8B50()
{
  HMODULE LibraryA; // eax

  LibraryA = LoadLibraryA(LibFileName);
  hLibModule = LibraryA;
  if ( !LibraryA )
    return 1;
  VFXOpen = GetProcAddress(LibraryA, ProcName);
  VFXClose = (int)GetProcAddress(hLibModule, aVfxclose);
  VFXZeroSet = (int)GetProcAddress(hLibModule, aVfxzeroset);
  VFXSetVideoMode = (int)GetProcAddress(hLibModule, aVfxsetvideomod);
  VFXGetTracking = (int)GetProcAddress(hLibModule, aVfxgettracking);
  if ( !VFXGetTracking || !VFXOpen || !VFXClose || !VFXZeroSet || !VFXSetVideoMode )
    return 4;
  VFXOpen();
  return 0;
}

