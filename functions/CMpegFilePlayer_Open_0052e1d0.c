int __thiscall sub_52E1D0(int this, unsigned int a2, int a3)
{
  int v4; // eax
  int v6; // eax
  int v7; // ecx

  if ( *(_BYTE *)(this + 9452) )
    DeferredDeactivation();
  v4 = this + 9523;
  *(_BYTE *)(this + 9452) = 1;
  LOBYTE(v4) = (this + 51) & 0xC0;
  *(_DWORD *)(this + 9380) = v4;
  if ( a2 )
  {
    if ( ArithmeticComparison_de40((void *)this, _byteswap_ulong(a2)) )
    {
      off_5DA714(aAudioAssert);
      off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1736, aCmpegfileplaye_0);
LABEL_8:
      off_5DA718();
      return -1;
    }
  }
  else if ( (*(int (__thiscall **)(int))(*(_DWORD *)this + 12))(this) )
  {
    off_5DA714(aAudioAssert);
    off_5DA714("%s(%d) : %s\n", aDDevAudiodevSh, 1744, aCmpegfileplaye_1);
    goto LABEL_8;
  }
  sub_52DA10(this);
  AudioNetworkBufferTimingCalc(this);
  LapPerformanceStateReset(this);
  v6 = F_64BitIntegerDivision(
         a3 + *(_DWORD *)(this + 9428),
         *(_DWORD *)(this + 9440),
         *(_DWORD *)(this + 9428) * (*(_DWORD *)(this + 9436) + *(_DWORD *)(this + 9440) * *(_DWORD *)(this + 9432)));
  *(_DWORD *)(this + 9392) = v6 * *(_DWORD *)(this + 9356);
  v7 = *(_DWORD *)(this + 11572);
  *(_DWORD *)(this + 9376) = v6;
  (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v7 + 12))(v7, *(_DWORD *)(this + 11576), 0);
  *(_BYTE *)(this + 11580) = 1;
  return 0;
}
