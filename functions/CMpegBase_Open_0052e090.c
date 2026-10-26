int __thiscall sub_52E090(int this, unsigned int a2, int a3)
{
  int v5; // eax
  int v6; // ecx

  if ( *(_BYTE *)(this + 9452) )
    DeferredDeactivation();
  *(_BYTE *)(this + 9452) = 1;
  *(_DWORD *)(this + 9380) = 0;
  *(_DWORD *)(this + 9456) = a2;
  if ( ArithmeticComparison_de40((void *)this, a2) )
  {
    off_5DA714(aAudioAssert);
    off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1698, aCmpegbaseOpenG);
    off_5DA718();
    return -1;
  }
  else
  {
    sub_52DA10(this);
    AudioNetworkBufferTimingCalc(this);
    LapPerformanceStateReset(this);
    v5 = F_64BitIntegerDivision(
           a3 + *(_DWORD *)(this + 9428),
           *(_DWORD *)(this + 9440),
           *(_DWORD *)(this + 9428) * (*(_DWORD *)(this + 9436) + *(_DWORD *)(this + 9440) * *(_DWORD *)(this + 9432)));
    v6 = v5 * *(_DWORD *)(this + 9356);
    *(_DWORD *)(this + 9376) = v5;
    *(_DWORD *)(this + 9392) = v6;
    return 0;
  }
}
