void __thiscall AICommandMessageQueueDispatcher(F1CVehicle *this, int a2, int a3)
{
  bool v4; // al
  int v5; // edi
  int v6; // ecx
  int v7; // eax
  _DWORD *v8; // edx
  bool v9; // cc

  switch ( a2 )
  {
    case 4:
      sub_4A46F0(dword_7CE2F0, (int)this, 1, 1);
      break;
    case 5:
      LOBYTE(this->PitLaneRouteFlag) = 0;
      sub_4A46F0(dword_7CE2F0, (int)this, 0, 0);
      break;
    case 1:
      *(float *)&this->PitDecisionTimer = dbl_8AFEA0 + 2.0;
      break;
    case 15:
      if ( dword_7C56A4 == 7 )
        v4 = *(_DWORD *)(LODWORD(this->postProcessInput) + 16484) == 0;
      else
        v4 = dword_7C56A8 != 8;
      if ( v4 )
      {
        if ( !LOBYTE(this->RetiredFlag) )
          SessionCleanupFlagClear(this);
      }
      else
      {
        SceneRenderUpdate((int *)LODWORD(this->postProcessInput), 0.0);
        PitStateChangeRequest((F1CPitMachine *)this->gap_32CC, 0);
      }
      *(_DWORD *)&this->gap_4540[4] = 0;
      ParameterValueSetter(this, 18);
      this->WaypointSetSelector = 1;
      LOBYTE(this->PitLaneRouteFlag) = 1;
      break;
  }
  v5 = *(_DWORD *)&this->gap_4454[84];
  if ( v5 )
  {
    v6 = *(_DWORD *)&this->gap_4454[92];
    v7 = 0;
    if ( v6 < 0 )
    {
LABEL_21:
      v9 = v6 + 1 < *(_DWORD *)&this->gap_4454[88];
      *(_DWORD *)&this->gap_4454[92] = v6 + 1;
      if ( v9 )
      {
        *(_DWORD *)(v5 + 8 * (v6 + 1)) = a2;
        *(_DWORD *)(*(_DWORD *)&this->gap_4454[84] + 8 * *(_DWORD *)&this->gap_4454[92] + 4) = a3;
        CommandQueueResponseHandler(this);
        *(_DWORD *)&this->gap_4454[92] = -1;
        if ( !a2 && this->FinishState == 2 )
          LOBYTE(this->AIControlFlag) = 0;
      }
      else
      {
        *(_DWORD *)&this->gap_4454[92] = v6;
      }
    }
    else
    {
      v8 = *(_DWORD **)&this->gap_4454[84];
      while ( *v8 != a2 )
      {
        ++v7;
        v8 += 2;
        if ( v7 > v6 )
          goto LABEL_21;
      }
    }
  }
}

