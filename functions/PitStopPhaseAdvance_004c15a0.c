char __thiscall PitStopPhaseAdvance(int this)
{
  int v2; // eax

  v2 = *(_DWORD *)(this + 45388) - 1;
  switch ( *(_DWORD *)(this + 45388) )
  {
    case 1:
      *(_DWORD *)(this + 45388) = 2;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 2:
      *(_DWORD *)(this + 45388) = 3;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 3:
      *(_DWORD *)(this + 45388) = 4;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 4:
      *(_DWORD *)(this + 45388) = 5;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 5:
      *(_DWORD *)(this + 45388) = 6;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 6:
      *(_DWORD *)(this + 45388) = 7;
      *(_BYTE *)(this + 45392) = 0;
      break;
    case 7:
      j_RaceStandingsRankingsComputation(this);
      LOBYTE(v2) = TimerCountdownWithStateTransition(this);
      goto LABEL_9;
    default:
LABEL_9:
      *(_BYTE *)(this + 45392) = 0;
      break;
  }
  return v2;
}
