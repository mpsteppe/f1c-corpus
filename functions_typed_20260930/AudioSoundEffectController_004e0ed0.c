char __thiscall sub_4E0ED0(_DWORD *this, int a2)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // edi
  _DWORD *v6; // edi
  int v7; // ebp
  bool v9; // [esp+14h] [ebp+4h]

  v3 = 3;
  if ( (*(_DWORD *)(*this + 18620) & 2) != 0 )
    v3 = a2;
  this[601] = v3;
  v9 = 1;
  if ( byte_7CE254 )
    v9 = dword_7D0410 == 6;
  switch ( v3 )
  {
    case 0:
      if ( this[1] )
        FlagFieldBitManipulation(1, 1, 1, 0);
      if ( this[547] )
        FlagFieldBitManipulation(0, 0, 0, 0);
      if ( this[1] )
      {
        if ( *(_DWORD *)(*this + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
          UIWidgetRecursiveStateUpdate(dword_7CF860 > 1, 1, 0);
        else
          UIWidgetRecursiveStateUpdate(dword_7CF860 > 2, 1, 0);
      }
      if ( !*((_BYTE *)this + 2412) )
      {
        if ( this[81] )
          FlagFieldBitManipulation(0, 0, 0, 0);
        if ( this[155] )
          FlagFieldBitManipulation(0, 0, 0, 0);
        if ( this[229] )
          FlagFieldBitManipulation(0, 0, 0, 0);
        if ( this[303] )
          FlagFieldBitManipulation(0, 0, 0, 0);
      }
      if ( dword_7C54E0 == *this )
      {
        switch ( SessionPhaseDecode(&dword_5EA510) )
        {
          case 2:
          case 4:
          case 7:
          case 8:
            if ( v9 && *(_BYTE *)(*this + 196) != 1 )
              StateHandlerDispatch(1);
            if ( dword_5EA518 == dword_5EA528 && *(_DWORD *)(dword_5EA528 + 52) == 2 && !byte_7CF710 )
            {
              if ( this[394] && *((_BYTE *)this + 1640) )
                FlagFieldBitManipulation(0, 0, 0, 0);
              if ( this[229] )
                FlagFieldBitManipulation(0, 0, 0, 0);
              if ( this[303] )
                FlagFieldBitManipulation(0, 0, 0, 0);
            }
            break;
          default:
            goto LABEL_39;
        }
      }
      else
      {
        SessionPhaseDecode(&dword_5EA510);
LABEL_39:
        if ( v9 && *(_BYTE *)(*this + 196) )
          StateHandlerDispatch(0);
      }
      LOBYTE(v3) = *((_BYTE *)this + 2413);
      if ( !(_BYTE)v3 )
      {
        if ( this[549] )
          LOBYTE(v3) = FlagFieldBitManipulation(0, 0, 0, 0);
        if ( this[551] )
          LOBYTE(v3) = FlagFieldBitManipulation(0, 0, 0, 0);
        if ( this[550] )
          LOBYTE(v3) = FlagFieldBitManipulation(0, 0, 0, 0);
      }
      v4 = this + 411;
      v5 = 8;
      do
      {
        if ( *v4 )
        {
          LOBYTE(v3) = *((_BYTE *)v4 + 64);
          if ( (_BYTE)v3 )
          {
            LOBYTE(v3) = *((_BYTE *)v4 + 65);
            if ( !(_BYTE)v3 )
              LOBYTE(v3) = FlagFieldBitManipulation(0, 0, 0, 0);
          }
        }
        v4 += 17;
        --v5;
      }
      while ( v5 );
      return v3;
    case 1:
      if ( this[1] )
      {
        FlagFieldBitManipulation(0, 0, 1, 0);
        FlagFieldBitManipulation(1, 0, 0, 0);
      }
      if ( this[377] && *((_BYTE *)this + 1572) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( byte_7CF710 )
      {
        if ( this[394] && *((_BYTE *)this + 1640) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[229] && *((_BYTE *)this + 980) && *((_BYTE *)this + 2412) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[303] && *((_BYTE *)this + 1276) && *((_BYTE *)this + 2412) )
          FlagFieldBitManipulation(1, 1, 0, 0);
      }
      if ( dword_7CFCEC )
      {
        if ( this[81] && *((_BYTE *)this + 388) && *((_BYTE *)this + 2412) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[98] && *((_BYTE *)this + 456) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[155] && *((_BYTE *)this + 684) && *((_BYTE *)this + 2412) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[172] && *((_BYTE *)this + 752) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[548] )
          FlagFieldBitManipulation(1, 1, 0, 0);
      }
      if ( this[550] && *((_BYTE *)this + 2413) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[552] )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[547] )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( !this[1] )
        goto LABEL_161;
      goto LABEL_160;
    case 2:
      if ( this[1] )
      {
        FlagFieldBitManipulation(0, 0, 1, 0);
        FlagFieldBitManipulation(1, 0, 0, 0);
      }
      if ( byte_7CF710 )
      {
        if ( this[394] && *((_BYTE *)this + 1640) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[229] && *((_BYTE *)this + 980) && *((_BYTE *)this + 2412) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        if ( this[303] && *((_BYTE *)this + 1276) && *((_BYTE *)this + 2412) )
          FlagFieldBitManipulation(1, 1, 0, 0);
      }
      if ( this[377] && *((_BYTE *)this + 1572) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[81] && *((_BYTE *)this + 388) && *((_BYTE *)this + 2412) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[98] && *((_BYTE *)this + 456) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[155] && *((_BYTE *)this + 684) && *((_BYTE *)this + 2412) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[172] && *((_BYTE *)this + 752) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[548] )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[550] && *((_BYTE *)this + 2413) )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[552] )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[547] )
        FlagFieldBitManipulation(1, 1, 0, 0);
      if ( this[1] )
        UIWidgetRecursiveStateUpdate(0, 1, 0);
      if ( this[81] && *((_BYTE *)this + 388) )
      {
        if ( *(_DWORD *)(*this + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
          UIWidgetRecursiveStateUpdate(dword_7CF860 > 1, 0, 0);
        else
          UIWidgetRecursiveStateUpdate(dword_7CF860 > 2, 0, 0);
      }
      if ( this[155] && *((_BYTE *)this + 684) )
      {
        if ( *(_DWORD *)(*this + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
          UIWidgetRecursiveStateUpdate(dword_7CF860 > 1, 0, 0);
        else
          UIWidgetRecursiveStateUpdate(dword_7CF860 > 2, 0, 0);
      }
      v6 = this + 411;
      v7 = 8;
      do
      {
        if ( *v6 && *((_BYTE *)v6 + 64) && *((_BYTE *)v6 + 65) )
          FlagFieldBitManipulation(1, 1, 0, 0);
        v6 += 17;
        --v7;
      }
      while ( v7 );
      goto LABEL_161;
    case 3:
      if ( this[1] )
      {
        FlagFieldBitManipulation(0, 0, 1, 0);
        FlagFieldBitManipulation(1, 0, 0, 0);
LABEL_160:
        UIWidgetRecursiveStateUpdate(0, 1, 0);
      }
LABEL_161:
      LOBYTE(v3) = v9;
      if ( v9 )
      {
        LOBYTE(v3) = *(_BYTE *)(*this + 196);
        if ( (_BYTE)v3 != 1 )
          LOBYTE(v3) = StateHandlerDispatch(1);
      }
      break;
    default:
      return v3;
  }
  return v3;
}

