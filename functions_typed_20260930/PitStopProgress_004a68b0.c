char __thiscall PitStopProgress(F1CPitMachine *this, float a2)
{
  unsigned int tire_change_active; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // ecx
  int v6; // edx
  double v7; // st7
  float fuel_target; // [esp+0h] [ebp-4h]
  float v10; // [esp+0h] [ebp-4h]
  float v11; // [esp+8h] [ebp+4h]

  if ( a2 < (double)this->stop_end_time )
  {
    if ( this->operation_sound_latch && this->stop_end_time - 2.0 <= a2 )
    {
      this->operation_sound_latch = 0;
      ShortComputation_d410((int)&dword_5EA510);
    }
    if ( this->refuel_active && a2 > (double)this->fuel_start_time )
    {
      v7 = (a2 - this->fuel_start_time) * 12.0 + this->fuel_start;
      fuel_target = v7;
      if ( v7 > this->fuel_target )
        fuel_target = this->fuel_target;
      SpeedValueSetterWithGlobalMirror((int)this->vehicle + 12, fuel_target);
    }
    tire_change_active = this->tire_change_active;
    if ( tire_change_active )
    {
      if ( a2 <= (double)this->tire_service_end_time )
      {
        if ( this->tire_service_start_time + 0.80000001 >= a2 )
        {
          if ( this->tire_service_start_time + 0.2 >= a2 )
            v10 = 0.0;
          else
            v10 = (a2 - this->tire_service_start_time - 0.2) * 0.16;
        }
        else
        {
          v10 = 0.096000001;
        }
        if ( this->tire_service_start_time + 2.0 >= a2 )
        {
          if ( this->tire_service_start_time + 1.4 >= a2 )
            v11 = 0.0;
          else
            v11 = (a2 - this->tire_service_start_time - 1.4) * 0.16;
        }
        else
        {
          v11 = 0.096000001;
        }
        WheelForceParameterSet((int)this->vehicle + 12, v10, v10, v11, v11);
      }
      else
      {
        WheelForceParameterSet((int)this->vehicle + 12, 0.0, 0.0, 0.0, 0.0);
      }
    }
  }
  else
  {
    if ( this->refuel_active )
    {
      SpeedValueSetterWithGlobalMirror((int)this->vehicle + 12, this->fuel_target);
      if ( this->fuel_target > 0.0 && *((_DWORD *)this->vehicle + 4122) == 9 )
        *((_DWORD *)this->vehicle + 4122) = 0;
    }
    PitStateChangeRequest(this, 4);
    *(float *)&this->operation_flags = dbl_8AFEA0 - this->stop_start_time;
    if ( (*(&dword_7C54F0 + dword_7C54DC))->VehicleSceneSlotId == this->pit_team_index
      && *((_DWORD *)this->vehicle + 4121) != 1 )
    {
      sub_4D8760(&dword_8AD298, 6, 0);
    }
    if ( *((_DWORD *)this->vehicle + 3250) == 1 )
    {
      PostPitCleanup((F1CVehicle *)this->vehicle);
      AICommandMessageQueueDispatcher((F1CVehicle *)this->vehicle, 15, 0);
    }
    WheelForceParameterSet((int)this->vehicle + 12, 0.0, 0.0, 0.0, 0.0);
    LOBYTE(tire_change_active) = CameraModeSetter((_DWORD *)this->vehicle + 3, 0);
    v4 = *(_DWORD **)this->gap_008;
    if ( v4 )
    {
      PerElementConditionalActionDispatcher(v4, 0);
      LOBYTE(tire_change_active) = dword_7CF884;
      if ( dword_7CF884 > 0 )
      {
        LOBYTE(tire_change_active) = *((_BYTE *)this->vehicle + 4188);
        v5 = (char *)this->vehicle + 1776;
        if ( (_BYTE)tire_change_active != 1 )
        {
          v6 = *((_DWORD *)this->vehicle + 1045);
          *((_BYTE *)this->vehicle + 4188) = 1;
          LOBYTE(tire_change_active) = AudioSoundEffectController(v5, v6);
        }
      }
    }
  }
  return tire_change_active;
}

