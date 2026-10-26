char __thiscall sub_4B7A90(int this, int *a2, int a3, float a4)
{
  double v5; // st7
  int v6; // ebp
  int v7; // ebx
  float *v8; // edi
  double v9; // st7
  int i; // edi
  int v11; // eax
  int v12; // eax
  float v14; // [esp+4h] [ebp-1B4h]
  _DWORD v15[108]; // [esp+8h] [ebp-1B0h] BYREF

  if ( !*(_BYTE *)(this + 3960) )
  {
    if ( a3 )
      VehicleInstanceListBuilder((int **)this, a3);
    v5 = PerformanceCounterDiffWithScaling(this + 3372);
    v14 = v5;
    if ( v5 > 0.025 && fabs(a4 - *(float *)(this + 3448)) > 0.001 )
    {
      TimerResetUsingQueryPerformanceCounter(this + 3372);
      v6 = dword_5C329C;
      v7 = 0;
      if ( dword_5C329C > 0 )
      {
        v8 = (float *)(this + 3452);
        do
        {
          v9 = v14 + *v8;
          *v8 = v9;
          if ( v9 > *(float *)(this + 3964) )
          {
            *v8 = 0.0;
            SetupCarLightingAndRender(v15);
            PitStallProximityCheck((_DWORD *)this, (int)v15, SLODWORD(a4));
          }
          ++v7;
          ++v8;
        }
        while ( v7 < v6 );
      }
      for ( i = *(_DWORD *)(this + 3368); i < 104; i += 12 )
        sub_4B6190((_DWORD *)this, i);
      *(_DWORD *)(this + 3368) = (*(_DWORD *)(this + 3368) + 1) % 12;
    }
    *(float *)(this + 3448) = a4;
    if ( *a2 > 0 )
    {
      SessionDataCopy(a2);
      while ( AdvanceRingBuffer(a2, v15) )
      {
        switch ( v15[0] >> 29 )
        {
          case 1:
            v11 = (v15[0] >> 18) & 0x3F;
            if ( v11 && v11 != 7 )
              goto LABEL_19;
            break;
          case 2:
          case 3:
          case 4:
          case 6:
LABEL_19:
            PitStallProximityCheck((_DWORD *)this, (int)v15, SLODWORD(a4));
            break;
          default:
            break;
        }
      }
      v12 = *(_DWORD *)(this + 2480) + 176 * *(_DWORD *)(this + 2488);
      if ( v12 && *(float *)(this + 3964) + *(float *)(v12 + 108) <= a4 )
        PitstopActionSet((_DWORD *)this, a4);
    }
  }
  return 0;
}

