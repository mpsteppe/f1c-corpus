void __thiscall sub_4EF930(int this, int a2)
{
  char v3; // al
  int v4; // ecx

  v3 = *(_BYTE *)(this + 14830);
  *(_BYTE *)(this + 14828) = 0;
  if ( !v3 )
  {
    if ( !a2 )
    {
      *(_DWORD *)(this + 14856) = 0;
      *(_DWORD *)(this + 14852) = 0;
      *(_DWORD *)(this + 14832) = 0;
      return;
    }
    if ( *(float *)(this + 14852) <= 0.0 )
    {
      v4 = this + 8;
      if ( a2 <= *(_DWORD *)(this + 14832) )
      {
        SoundEffectTrigger_89a0(v4);
        *(_DWORD *)(this + 14852) = *(_DWORD *)(this + 14848);
        if ( a2 >= 1
          && *(float *)(this + 13688) > 0.0
          && *(float *)(this + 14712) > 0.0
          && *(float *)(this + 14744) * 0.5 < *(float *)(this + 14740) )
        {
          PositionUpdateWithTelemetryRecording(this);
        }
      }
      else
      {
        SoundEffectTrigger(v4);
        *(_DWORD *)(this + 14852) = *(_DWORD *)(this + 14844);
        if ( a2 == 1 && !*(_DWORD *)(this + 14832) )
        {
          *(_DWORD *)(this + 14856) = 1;
          *(_DWORD *)(this + 14832) = 0;
          *(_BYTE *)(this + 14828) = 1;
          return;
        }
      }
      *(_DWORD *)(this + 14856) = a2;
      *(_DWORD *)(this + 14832) = 0;
    }
  }
}
