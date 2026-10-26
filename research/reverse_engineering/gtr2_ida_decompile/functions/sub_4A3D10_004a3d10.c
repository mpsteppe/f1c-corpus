int __thiscall sub_4A3D10(_DWORD *this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ebp
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  char v7; // cl
  char *v8; // edx
  int RoomRaceLength; // eax
  char *RoomRaceLaps; // edi
  int result; // eax
  int RoomDataRate; // eax
  char *v13; // eax
  int RoomFlagRules; // eax
  int v15; // eax
  const char *v16; // [esp+0h] [ebp-13Ch] BYREF
  char *v17; // [esp+4h] [ebp-138h]
  int RoomMechFails; // [esp+8h] [ebp-134h]
  int RoomTyreWear; // [esp+Ch] [ebp-130h]
  char Buffer[32]; // [esp+1Ch] [ebp-120h] BYREF
  char v22[252]; // [esp+3Ch] [ebp-100h] BYREF
  __int16 v23; // [esp+138h] [ebp-4h]
  char v24; // [esp+13Ah] [ebp-2h]
  int _13C; // [esp+13Ch] [ebp+0h] BYREF

  memset(v22, 0, sizeof(v22));
  v4 = this[12];
  v23 = 0;
  v24 = 0;
  v5 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 28))(v4, 36);
  if ( v5 )
  {
    v6 = sub_4CE170(v5);
    if ( v6 )
    {
      v7 = *(_BYTE *)v6;
      if ( *(_BYTE *)v6 != 9 )
      {
        v8 = &v22[-v6];
        do
        {
          v8[v6] = v7;
          v7 = *(_BYTE *)++v6;
        }
        while ( v7 != 9 );
      }
    }
  }
  if ( strlen(v22) )
  {
    switch ( this[72] )
    {
      case 0x243:
        RoomRaceLength = CINet::GetRoomRaceLength((CINet *)dword_B6CBB0, v22);
        if ( RoomRaceLength )
        {
          RoomMechFails = RoomRaceLength % 60;
          v17 = (char *)(RoomRaceLength / 60);
          v16 = "%d:%.02d";
        }
        else
        {
          RoomRaceLaps = (char *)CINet::GetRoomRaceLaps((CINet *)dword_B6CBB0, v22);
          RoomMechFails = (int)sub_41D840(&byte_91CC38, "laps");
          v17 = RoomRaceLaps;
          v16 = (const char *)&_13C;
          v1 = __readeflags();
          v2 = __ROL4__(dword_16C6C68, dword_16E218B);
          __writeeflags(v1);
          _InterlockedExchange((volatile __int32 *)&v16, v2);
        }
        sprintf(Buffer, v16, v17, RoomMechFails);
        sub_4907C0((int)Buffer);
        return 0;
      case 0x244:
        if ( CINet::GetRoomCollisions((CINet *)dword_B6CBB0, v22) )
          v13 = sub_41D840(&byte_91CC38, "On");
        else
          v13 = sub_41D840(&byte_91CC38, off_6F1D6C);
        sub_4907C0((int)v13);
        return 0;
      case 0x245:
        RoomDataRate = CINet::GetRoomDataRate((CINet *)dword_B6CBB0, v22);
        sprintf(Buffer, "%d", RoomDataRate);
        sub_4907C0((int)Buffer);
        return 0;
      case 0x246:
        switch ( CINet::GetRoomWeather((CINet *)dword_B6CBB0, v22) )
        {
          case 0:
            sub_4907C0((int)"Changeable");
            result = 0;
            break;
          case 1:
            sub_4907C0((int)&off_6F6EA8);
            result = 0;
            break;
          case 2:
            sub_4907C0((int)"Raining");
            result = 0;
            break;
          case 3:
            sub_4907C0((int)"Monsoon");
            result = 0;
            break;
          default:
            sub_4907C0((int)"...");
            result = 0;
            break;
        }
        return result;
      case 0x247:
        RoomTyreWear = CINet::GetRoomTyreWear((CINet *)dword_B6CBB0, v22);
        sub_490800();
        return 0;
      case 0x248:
        RoomTyreWear = CINet::GetRoomFuelUsage((CINet *)dword_B6CBB0, v22);
        sub_490800();
        return 0;
      case 0x249:
        RoomFlagRules = CINet::GetRoomFlagRules((CINet *)dword_B6CBB0, v22);
        if ( RoomFlagRules >= 0 )
        {
          if ( RoomFlagRules > 2 )
            RoomFlagRules = 2;
          RoomMechFails = RoomFlagRules;
        }
        else
        {
          RoomMechFails = 0;
        }
        break;
      case 0x24A:
        RoomMechFails = CINet::GetRoomMechFails((CINet *)dword_B6CBB0, v22);
        break;
      case 0x24B:
        RoomMechFails = 5;
        v17 = v22;
        goto LABEL_40;
      case 0x24C:
        RoomMechFails = 8;
        goto LABEL_39;
      case 0x24D:
        RoomMechFails = 2;
        v17 = v22;
        goto LABEL_40;
      case 0x24E:
        RoomMechFails = 7;
        v17 = v22;
        goto LABEL_40;
      case 0x24F:
        RoomMechFails = 9;
        goto LABEL_39;
      case 0x250:
        RoomMechFails = 4;
        v17 = v22;
        goto LABEL_40;
      case 0x251:
        RoomMechFails = 3;
        v17 = v22;
        goto LABEL_40;
      case 0x252:
        RoomMechFails = 1;
LABEL_39:
        v17 = v22;
LABEL_40:
        RoomMechFails = !CINet::GetRoomDrivingAssist((CINet *)dword_B6CBB0, v17, RoomMechFails);
        break;
      case 0x253:
        RoomMechFails = !CINet::GetRoomDrivingAssist((CINet *)dword_B6CBB0, v22, 0);
        break;
      default:
        return 0;
    }
    v15 = sub_4CFC00(RoomMechFails);
    sub_4907C0(v15);
  }
  return 0;
}
