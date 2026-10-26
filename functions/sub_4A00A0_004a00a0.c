int sub_4A00A0()
{
  int v0; // edi
  const char *v1; // eax
  int v2; // edx
  int v3; // eax
  int v4; // esi
  _BYTE v6[256]; // [esp+8h] [ebp-100h] BYREF

  v0 = 0;
  while ( ShowCursor(0) >= 0 )
    ;
  if ( dword_7D0410 == 4 && dword_7C56A4 == 7 && dword_7D032C == 1 )
  {
    v1 = (const char *)dword_5EC418;
    if ( !dword_5EC418 )
      v1 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v6, "%s%s", v1, aFiashortBik);
    v0 = FileLoadWithRetryLoop(v6, 1);
  }
  GuardedFunctionCallByState(dword_7CD25C);
  GlobalStateSetter(0);
  sub_42D210(&dword_7C569C, 0);
  GlobalFloatSetter(0);
  CameraViewportConfigBatch(&ppvOut);
  ShortComputation_d410((int)&dword_5EA510);
  v2 = dword_7C54F0[dword_7C54E4];
  dword_7C54DC = dword_7C54E4;
  dword_7C54E0 = v2;
  GameStateBranchDispatch(&dword_5EA510);
  VirtualDispatchConditionalAudio(&dword_5EA510);
  SafeDivisionWithZeroGuard((int)&flt_5EA4E8, 0.0);
  GuardedSubsystemRelease();
  ShortComputation_50c0();
  ShortComputation_bdf0(&dword_7CD204);
  sub_4B9FD0(&dword_8AB6E4);
  if ( ScoringGateCheck() )
  {
    FileLoadWithFlagPreserve((char **)&dword_7C73E8);
    SceneRenderUpdate(0);
    v3 = dword_7C54E8;
    v4 = *(_DWORD *)(dword_7C54E8 + 13024);
    if ( v4 )
    {
      if ( *(_BYTE *)(dword_7C54E8 + 13388) )
        UtilityFunction_4000(*(_DWORD *)(dword_7C54E8 + 13024));
      Camera(v4);
      v3 = dword_7C54E8;
    }
    if ( dword_7C56A4 != 7 || dword_7C56A8 != 2 && dword_7C56A8 != 3 && dword_7C56A8 != 4 )
    {
      VehicleClimbAdjust(0);
      v3 = dword_7C54E8;
    }
    CollisionWrapperWithLock(v3 + 12);
  }
  TelemetryDataDump(&dword_8AD238);
  return v0;
}
