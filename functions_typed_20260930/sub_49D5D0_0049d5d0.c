char __thiscall sub_49D5D0(_DWORD *this, char a2)
{
  int v2; // eax

  LOBYTE(v2) = dword_7CE048;
  switch ( dword_7CE048 )
  {
    case 0:
    case 1:
    case 3:
    case 4:
      v2 = this[5];
      if ( v2 )
      {
        if ( this[6] )
        {
          if ( this[2] )
          {
            ClippedRectRender(0.0, 0.0, *(_DWORD *)(v2 + 84), 0.0, 0.0, 1.0, 1.0, 0, 0);
            LOBYTE(v2) = a2;
            if ( !a2 )
            {
              LOBYTE(v2) = dword_7CE048;
              switch ( dword_7CE048 )
              {
                case 0:
                  LOBYTE(v2) = dword_7C56A4;
                  switch ( dword_7C56A4 )
                  {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                      LOBYTE(v2) = UtilityFunction_d8b0(this);
                      break;
                    case 6:
                      LOBYTE(v2) = TimestampedRenderStringUpdate(this);
                      break;
                    case 7:
                      LOBYTE(v2) = sub_49D700(this);
                      break;
                    default:
                      return v2;
                  }
                  break;
                case 1:
                  LOBYTE(v2) = ConditionalDispatch(this);
                  break;
                case 3:
                  v2 = this[3];
                  if ( v2 )
                    LOBYTE(v2) = FormatStringBatchDisplay(this);
                  break;
                case 4:
                  LOBYTE(v2) = BrakeWaterTemperatureHUDDisplay(this);
                  break;
                default:
                  return v2;
              }
            }
          }
        }
      }
      break;
    case 2:
      LOBYTE(v2) = sub_49DE40(a2);
      break;
    default:
      return v2;
  }
  return v2;
}

