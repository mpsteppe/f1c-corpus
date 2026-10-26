int __stdcall sub_4B1850(int a1)
{
  const char *v1; // eax
  int result; // eax
  int i; // ebp
  char *v4; // esi
  void *v5; // eax
  int v6; // edi
  int v7; // ecx
  void *v8; // esi
  int v9; // [esp+0h] [ebp-204h] BYREF
  char Buffer[512]; // [esp+4h] [ebp-200h] BYREF

  v1 = *(const char **)dword_62A068;
  Buffer[0] = 0;
  if ( !*(_DWORD *)dword_62A068 )
    v1 = &byte_629120;
  sprintf(Buffer, "%s%s", v1, (const char *)off_609054);
  v9 = 0;
  result = sub_5924D0(dword_7DA988, (int)&v9, (int)Buffer);
  if ( !result )
  {
    for ( i = 0; i < 19; ++i )
    {
      if ( a1 >= 0 )
        i = a1;
      v4 = 0;
      switch ( i )
      {
        case 0:
          v4 = aVehicledisplay;
          break;
        case 1:
          v4 = aNetproblemBmp;
          break;
        case 2:
          v4 = aNexttrackBmp;
          break;
        case 3:
          v4 = aNextsessionBmp;
          break;
        case 4:
          v4 = aStopgoBmp;
          break;
        case 5:
          v4 = aLongestlineBmp;
          break;
        case 6:
          v4 = aPassthroughBmp;
          break;
        case 7:
          v4 = aFlagYellowBmp;
          break;
        case 8:
          v4 = aFlagBlueBmp;
          break;
        case 9:
          v4 = aFlagBlackBmp;
          break;
        case 10:
          v4 = aFlagDisBmp;
          break;
        case 11:
          v4 = aFlagWhiteBmp;
          break;
        case 12:
          v4 = aFlagCheckBmp;
          break;
        case 13:
          v4 = aFlagGreenBmp;
          break;
        case 14:
          v4 = aLowfuelBmp;
          break;
        case 15:
          v4 = aPitopenBmp;
          break;
        case 16:
          v4 = aPitclosedBmp;
          break;
        case 17:
          v4 = aFollowBmp;
          break;
        case 18:
          v4 = aE3logoTga;
          break;
        default:
          break;
      }
      if ( !dword_766080[i] )
      {
        v5 = operator new(0x28u);
        v6 = (int)v5;
        if ( v5 )
        {
          sub_506720(v5);
          v7 = v6;
        }
        else
        {
          v7 = 0;
        }
        dword_766080[i] = v7;
        if ( sub_506750(-16777216, v4, 0, 0, 0, 32, 32, 0, 0) )
        {
          v8 = (void *)dword_766080[i];
          if ( v8 )
          {
            sub_506920(dword_766080[i]);
            sub_5BE8AE(v8);
          }
          dword_766080[i] = 0;
        }
      }
      if ( a1 >= 0 )
        break;
    }
    return sub_592750(v9);
  }
  return result;
}
