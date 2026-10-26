int __thiscall sub_40DE60(int *this)
{
  int v2; // eax
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v16; // [esp+Ch] [ebp-8h]

  if ( *this == 4 )
  {
    v2 = this[34];
    *((float *)this + 39) = dbl_8AFE98 + *((float *)this + 39);
    *((float *)this + 38) = dbl_8AFE98 + *((float *)this + 38);
    if ( !v2 )
    {
LABEL_3:
      *this = -1;
      return *this;
    }
    v16 = 0;
    while ( v16++ < 10 )
    {
      v5 = this[34];
      switch ( *(_DWORD *)(v5 + 40) )
      {
        case 2:
          if ( *(int *)(v5 + 24) > 0 )
          {
            v12 = RandLCGRandomNumberGenerator();
            v13 = this[34];
            if ( (double)v12 * 0.000030518509 >= *(float *)(v13 + 12) )
            {
              *(_DWORD *)(v13 + 40) = 4;
            }
            else
            {
              if ( *(_DWORD *)(v13 + 36) == 10 )
                PhysicsConfigInit(this + 5);
              *(_DWORD *)(this[34] + 40) = 3;
            }
            v14 = this[34];
            if ( --*(_DWORD *)(v14 + 24) < 0 )
              *(_DWORD *)(v14 + 24) = 0;
          }
          else
          {
LABEL_43:
            *(_DWORD *)(v5 + 40) = 4;
          }
          break;
        case 3:
          if ( *(float *)(v5 + 16) > (double)*((float *)this + 39) )
            return *this;
          switch ( *(_DWORD *)(v5 + 36) )
          {
            case 2:
              v7 = this[1];
              if ( !v7 )
                goto LABEL_3;
              *(_BYTE *)(v7 + 36) = 1;
              v8 = this[34];
              *((_BYTE *)this + 160) = 1;
              *(_DWORD *)(v8 + 40) = 4;
              break;
            case 3:
              v9 = this[1];
              if ( !v9 )
                goto LABEL_3;
              if ( *((_BYTE *)this + 160) )
                *(_BYTE *)(v9 + 36) = 0;
              v10 = this[34];
              *((_BYTE *)this + 160) = 0;
              *(_DWORD *)(v10 + 40) = 4;
              break;
            case 4:
              v11 = this[1];
              if ( v11 )
                SessionPhaseDispatchWithCascadeChecks(v11, *(_DWORD *)(v5 + 44), 1);
              *(_DWORD *)(this[34] + 40) = 4;
              continue;
            case 5:
              if ( this[1] )
                SetPlayerVehicleIndex(*(_DWORD *)(v5 + 44));
              *(_DWORD *)(this[34] + 40) = 4;
              continue;
            case 6:
              this[36] = *(_DWORD *)(v5 + 44);
              *(_DWORD *)(v5 + 40) = 4;
              continue;
            case 7:
              switch ( *(_DWORD *)(v5 + 44) )
              {
                case 0:
                  DisplayMessage0x151(&dword_5EB978);
                  *(_DWORD *)(this[34] + 40) = 4;
                  break;
                case 1:
                  sub_41C440(&dword_5EB978);
                  *(_DWORD *)(this[34] + 40) = 4;
                  break;
                case 2:
                  PositionBasedMessageDisplay(0);
                  *(_DWORD *)(this[34] + 40) = 4;
                  break;
                case 3:
                  PitRaceStatusMessageDispatcher(&dword_5EB978);
                  *(_DWORD *)(this[34] + 40) = 4;
                  break;
                case 4:
                  DisplayMessage0x202(&dword_5EB978);
                  goto LABEL_38;
                default:
LABEL_38:
                  *(_DWORD *)(this[34] + 40) = 4;
                  break;
              }
              continue;
            case 9:
              goto LABEL_43;
            case 0xA:
              if ( !CarSelectionStateMachine(this + 5) )
                return *this;
              *(_DWORD *)(this[34] + 40) = 4;
              break;
            case 0xB:
              *(_DWORD *)(this[34] + 40) = 4;
              return *this;
            case 0xC:
              *this = 5;
              *(_DWORD *)(v5 + 40) = 4;
              continue;
            default:
              return *this;
          }
          break;
        case 4:
          if ( *(_DWORD *)(v5 + 36) == 10 )
            EngineGuardedInitializer(this + 5);
          v6 = this[34];
          if ( *(_BYTE *)(v6 + 32) )
            this[39] = 0;
          if ( *(int *)(v6 + 24) > 0 )
          {
            *(_DWORD *)(v6 + 40) = 2;
          }
          else if ( !ConditionalDelegation(this) )
          {
            *this = -1;
            return *this;
          }
          break;
        default:
          return *this;
      }
    }
  }
  return *this;
}
