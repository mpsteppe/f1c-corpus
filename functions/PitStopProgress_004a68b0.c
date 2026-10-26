char __thiscall sub_4A68B0(int this, float a2)
{
  int v3; // eax
  _DWORD *v4; // ecx
  int v5; // edx
  double v6; // st7
  float v8; // [esp+0h] [ebp-4h]
  float v9; // [esp+0h] [ebp-4h]
  float v10; // [esp+8h] [ebp+4h]

  if ( a2 < (double)*(float *)(this + 420) )
  {
    if ( *(_BYTE *)(this + 428) && *(float *)(this + 420) - 2.0 <= a2 )
    {
      *(_BYTE *)(this + 428) = 0;
      ShortComputation_d410((int)&dword_5EA510);
    }
    if ( *(_DWORD *)(this + 448) && a2 > (double)*(float *)(this + 436) )
    {
      v6 = (a2 - *(float *)(this + 436)) * 12.0 + *(float *)(this + 432);
      v8 = v6;
      if ( v6 > *(float *)(this + 440) )
        v8 = *(float *)(this + 440);
      SpeedValueSetterWithGlobalMirror(LODWORD(v8));
    }
    v3 = *(_DWORD *)(this + 452);
    if ( v3 )
    {
      if ( a2 <= (double)*(float *)(this + 468) )
      {
        if ( *(float *)(this + 464) + 0.80000001 >= a2 )
        {
          if ( *(float *)(this + 464) + 0.2 >= a2 )
            v9 = 0.0;
          else
            v9 = (a2 - *(float *)(this + 464) - 0.2) * 0.16;
        }
        else
        {
          v9 = 0.096000001;
        }
        if ( *(float *)(this + 464) + 2.0 >= a2 )
        {
          if ( *(float *)(this + 464) + 1.4 >= a2 )
            v10 = 0.0;
          else
            v10 = (a2 - *(float *)(this + 464) - 1.4) * 0.16;
        }
        else
        {
          v10 = 0.096000001;
        }
        LOBYTE(v3) = WheelForceParameterSet(v9, v9, v10, v10);
      }
      else
      {
        LOBYTE(v3) = WheelForceParameterSet(0.0, 0.0, 0.0, 0.0);
      }
    }
  }
  else
  {
    if ( *(_DWORD *)(this + 448) )
    {
      SpeedValueSetterWithGlobalMirror(*(_DWORD *)(this + 440));
      if ( *(float *)(this + 440) > 0.0 && *(_DWORD *)(*(_DWORD *)this + 16488) == 9 )
        *(_DWORD *)(*(_DWORD *)this + 16488) = 0;
    }
    StateChangeNotify(this, 4);
    *(float *)(this + 424) = dbl_8AFEA0 - *(float *)(this + 416);
    if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(this + 4)
      && *(_DWORD *)(*(_DWORD *)this + 16484) != 1 )
    {
      sub_4D8760(6, 0);
    }
    if ( *(_DWORD *)(*(_DWORD *)this + 13000) == 1 )
    {
      PostPitCleanup(*(_DWORD *)this);
      AICommandMessageQueueDispatcher(*(int **)this, 15, 0);
    }
    WheelForceParameterSet(0.0, 0.0, 0.0, 0.0);
    LOBYTE(v3) = CameraModeSetter(0);
    v4 = *(_DWORD **)(this + 8);
    if ( v4 )
    {
      PerElementConditionalActionDispatcher(v4, 0);
      LOBYTE(v3) = dword_7CF884;
      if ( dword_7CF884 > 0 )
      {
        LOBYTE(v3) = *(_BYTE *)(*(_DWORD *)this + 4188);
        if ( (_BYTE)v3 != 1 )
        {
          v5 = *(_DWORD *)(*(_DWORD *)this + 4180);
          *(_BYTE *)(*(_DWORD *)this + 4188) = 1;
          LOBYTE(v3) = AudioSoundEffectController(v5);
        }
      }
    }
  }
  return v3;
}
