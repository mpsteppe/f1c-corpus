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
  sub_58BA36(v2, 128);
  v4 = sub_587DB0(v2, aWt);
  v5 = v4;
  if ( !v4 )
    return 0;
  sub_5887B1(v4, aComponents_0);
  sub_5887B1(v5, aSeasondirS);
  sub_5887B1(v5, aSounddirS);
  sub_5887B1(v5, aVehiclesoundS);
  sub_5887B1(v5, aOptionsanimS);
  sub_5887B1(v5, aOptionsflagsS);
  sub_5887B1(v5, aOptionssoundsS);
  sub_5887B1(v5, aOptionsdirS);
  sub_5887B1(v5, aReplaydirS);
  sub_5887B1(v5, aMoviedirS);
  sub_5887B1(v5, aTracksdirS);
  sub_5887B1(v5, aVehiclesdirS);
  sub_5887B1(v5, aDriversdirS);
  sub_5887B1(v5, aLogdirS);
  sub_5887B1(v5, aSavedirS);
  sub_5887B1(v5, aMusicdirS);
  sub_5887B1(v5, aCameraeditorre_0);
  sub_423060(this);
  sub_5887B1(v5, aGridsizeD);
  sub_5887B1(v5, aCpuratingD);
  sub_5887B1(v5, aSystemramD);
  sub_5887B1(v5, aVideoramD);
  sub_5887B1(v5, aObjdetailD);
  sub_5887B1(v5, aTexdetailD);
  sub_5887B1(v5, aVideoguidS);
  sub_5887B1(v5, aVideodriverD);
  sub_5887B1(v5, aVideomodeD);
  sub_5887B1(v5, aVideorefreshD);
  sub_5887B1(v5, aWindowedmodeD);
  sub_5887B1(v5, aRunbenchmarksD);
  sub_5887B1(v5, aFsaaD);
  sub_5887B1(v5, aVsyncD);
  sub_5887B1(v5, aVbstrategyD);
  sub_5887B1(v5, aInstall_0);
  sub_5887B1(v5, aInstallfromS);
  sub_5887B1(v5, aInstalltoS);
  sub_5887B1(v5, aAutolaunch_0);
  v7 = sub_404D10(&dword_5EA43C);
  sub_404D00(v7);
  sub_5887B1(v5, aModeS);
  v8 = sub_404D20(&dword_5EA43C);
  sub_587BDC(v8);
  sub_5887B1(v5, aLaunchtimeD);
  sub_5887B1(v5, aVersion_1);
  sub_5887B1(v5, aVersionF);
  sub_587D02(v5);
  return 1;
}
