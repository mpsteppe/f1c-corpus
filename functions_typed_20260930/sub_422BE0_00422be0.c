char __thiscall sub_422BE0(const CHAR **this, LPCSTR lpFileName)
{
  const CHAR *v2; // esi
  int v4; // eax
  int v5; // esi
  int v7; // eax
  double v8; // st7

  v2 = lpFileName;
  if ( !lpFileName )
  {
    v2 = *this;
    if ( !*this )
      v2 = &byte_5EA438;
  }
  ToggleFileReadOnlyAttributeViaWin32API(v2, 128);
  v4 = sub_587DB0(v2, aWt);
  v5 = v4;
  if ( !v4 )
    return 0;
  StringFormatWithNestedIO(v4, aComponents_0);
  StringFormatWithNestedIO(v5, aSeasondirS);
  StringFormatWithNestedIO(v5, aSounddirS);
  StringFormatWithNestedIO(v5, aVehiclesoundS);
  StringFormatWithNestedIO(v5, aOptionsanimS);
  StringFormatWithNestedIO(v5, aOptionsflagsS);
  StringFormatWithNestedIO(v5, aOptionssoundsS);
  StringFormatWithNestedIO(v5, aOptionsdirS);
  StringFormatWithNestedIO(v5, aReplaydirS);
  StringFormatWithNestedIO(v5, aMoviedirS);
  StringFormatWithNestedIO(v5, aTracksdirS);
  StringFormatWithNestedIO(v5, aVehiclesdirS);
  StringFormatWithNestedIO(v5, aDriversdirS);
  StringFormatWithNestedIO(v5, aLogdirS);
  StringFormatWithNestedIO(v5, aSavedirS);
  StringFormatWithNestedIO(v5, aMusicdirS);
  StringFormatWithNestedIO(v5, aCameraeditorre_0);
  ShortComputation_3060(this);
  StringFormatWithNestedIO(v5, aGridsizeD);
  StringFormatWithNestedIO(v5, aCpuratingD);
  StringFormatWithNestedIO(v5, aSystemramD);
  StringFormatWithNestedIO(v5, aVideoramD);
  StringFormatWithNestedIO(v5, aObjdetailD);
  StringFormatWithNestedIO(v5, aTexdetailD);
  StringFormatWithNestedIO(v5, aVideoguidS);
  StringFormatWithNestedIO(v5, aVideodriverD);
  StringFormatWithNestedIO(v5, aVideomodeD);
  StringFormatWithNestedIO(v5, aVideorefreshD);
  StringFormatWithNestedIO(v5, aWindowedmodeD);
  StringFormatWithNestedIO(v5, aRunbenchmarksD);
  StringFormatWithNestedIO(v5, aFsaaD);
  StringFormatWithNestedIO(v5, aVsyncD);
  StringFormatWithNestedIO(v5, aVbstrategyD);
  StringFormatWithNestedIO(v5, aInstall_0);
  StringFormatWithNestedIO(v5, aInstallfromS);
  StringFormatWithNestedIO(v5, aInstalltoS);
  StringFormatWithNestedIO(v5, aAutolaunch_0);
  v7 = FieldAccessorAt0x20(&dword_5EA43C);
  ArrayIndexedPointerGetter(v7);
  StringFormatWithNestedIO(v5, aModeS);
  v8 = sub_404D20(&dword_5EA43C);
  CRTFtol(v8);
  StringFormatWithNestedIO(v5, aLaunchtimeD);
  StringFormatWithNestedIO(v5, aVersion_1);
  StringFormatWithNestedIO(v5, aVersionF);
  FileCloseWithLock(v5);
  return 1;
}

