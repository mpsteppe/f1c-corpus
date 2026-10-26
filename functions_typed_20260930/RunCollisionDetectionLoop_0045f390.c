char __thiscall sub_45F390(_DWORD *this)
{
  double v2; // st7
  double v3; // st7
  float v5; // [esp+Ch] [ebp-60h]
  float v6; // [esp+10h] [ebp-5Ch]
  float v7; // [esp+14h] [ebp-58h] BYREF
  char *v8; // [esp+18h] [ebp-54h] BYREF
  _BYTE v9[4]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v10[76]; // [esp+20h] [ebp-4Ch] BYREF

  if ( this[4081] != 3 )
    return 0;
  StructZeroInit_8ba0(v10);
  QPCTimerInitialization(1);
  TimerResetUsingQueryPerformanceCounter(v10);
  v2 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  while ( 1 )
  {
    if ( v2 <= 0.0 )
    {
      AnimationTimingUpdateWithParamSet(this[4078]);
      v5 = 4.0;
    }
    if ( (unsigned __int8)AnimationValueFetchWithTiming(&v7, &v8, v9) )
      break;
    v3 = HighResolutionTimerDelta(v10);
    v6 = v6 + v3;
    v2 = v5 - v3;
    v5 = v2;
    if ( v6 >= 60.0 )
    {
      EmptyStub_0170(v10);
      return 0;
    }
  }
  sub_4F9FC0(v7);
  TimerConversionWithSin(v7);
  MultiplayerVehiclePlacement(&dword_7C569C, *v8);
  ArrayInitializationLoop(this + 26864, 0);
  EmptyStub_0170(v10);
  return 1;
}

