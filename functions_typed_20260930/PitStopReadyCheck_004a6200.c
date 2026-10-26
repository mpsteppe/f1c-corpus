void __thiscall PitStopReadyCheck(F1CPitMachine *this, float a2)
{
  float *vehicle; // ecx
  float v4; // eax
  double v5; // st7
  int v6; // eax
  float v7; // [esp+4h] [ebp-18h] BYREF
  float v8; // [esp+8h] [ebp-14h]
  float v9; // [esp+Ch] [ebp-10h]
  float v10[3]; // [esp+10h] [ebp-Ch] BYREF

  vehicle = (float *)this->vehicle;
  this->service_ready = 1;
  v7 = vehicle[3390];
  v4 = vehicle[3392];
  v8 = vehicle[3391];
  v9 = v4;
  if ( v8 * v8 + v4 * v4 + v7 * v7 > 0.040000003 )
    this->service_ready = 0;
  CameraModeSetter((_DWORD *)vehicle + 3, 1);
  if ( *((_DWORD *)this->vehicle + 3250) == 1 )
  {
    RaceStartCountdownStateUpdate((int)this->vehicle + 12, 0);
    this->service_ready = PitStopDecisionTireCompound((F1CVehicle *)this->vehicle);
  }
  else if ( dword_7CE048[0] == 1 )
  {
    this->service_ready = 0;
  }
  if ( this->service_ready )
  {
    this->stop_start_time = a2;
    v5 = PitStopOperationTimer(this);
    v6 = *(_DWORD *)this->gap_008;
    this->stop_end_time = v5 + this->stop_start_time;
    if ( v6 )
    {
      F_3DTransformWithMatrixMultiplication((float *)this->vehicle + 3, v10, &v7);
      sub_4A3320(*(_DWORD **)this->gap_008, v10, (int)&v7);
    }
    if ( this->vehicle == (void *)dword_7C54E8 && !this->operation_sound_latch && !dword_7CE814 )
    {
      this->operation_sound_latch = 1;
      if ( byte_5EA3EC )
        ShortComputation_d3c0((int)&dword_5EA510, 10);
      else
        ShortComputation_d3c0((int)&dword_5EA510, 9);
    }
  }
}

