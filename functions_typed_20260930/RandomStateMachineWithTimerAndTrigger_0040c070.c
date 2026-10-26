int __thiscall sub_40C070(int this)
{
  int v2; // edi
  double v3; // st7
  int v4; // ebx
  int v5; // edi

  v2 = 0;
  if ( !*(_BYTE *)(this + 36) )
  {
    v3 = *(float *)(this + 60) - ScoringGateConditionCheck(this);
    *(float *)(this + 60) = v3;
    if ( v3 <= 0.0 )
    {
      v4 = SessionPhaseDecode(this);
      switch ( RandLCGRandomNumberGenerator() % 4 )
      {
        case 0:
          v5 = 0;
          break;
        case 1:
          v5 = 3;
          break;
        case 2:
          v5 = 4;
          break;
        default:
          v5 = 5;
          break;
      }
      GameActionStateMachine(v5, 1);
      if ( v5 != v4 )
        GameActionStateMachine(v5, 1);
      if ( !(RandLCGRandomNumberGenerator() % 3) )
        CameraTargetRaceLeader(1);
      v2 = 1;
      ShortComputation_d360(*(_DWORD *)(this + 48), *(_DWORD *)(this + 52));
    }
  }
  return v2;
}

