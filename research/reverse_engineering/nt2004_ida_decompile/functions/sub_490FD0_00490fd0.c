int __thiscall sub_490FD0(_DWORD *this)
{
  int result; // eax
  int v2; // eax
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  char Buffer[32]; // [esp+Ch] [ebp-20h] BYREF

  switch ( this[69] )
  {
    case 0x267:
      if ( !(unsigned __int8)sub_4CE6E0(0) )
        goto LABEL_57;
      goto LABEL_27;
    case 0x268:
      if ( (unsigned __int8)sub_4CE6E0(1) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x269:
      if ( (unsigned __int8)sub_4CE6E0(2) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x26A:
      if ( (unsigned __int8)sub_4CE6E0(3) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x26B:
      if ( (unsigned __int8)sub_4CE6E0(4) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x26C:
      if ( (unsigned __int8)sub_4CE6E0(5) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x26D:
      if ( (unsigned __int8)sub_4CE6E0(6) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x26E:
      if ( (unsigned __int8)sub_4CE6E0(7) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x26F:
      if ( (unsigned __int8)sub_4CE6E0(8) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x270:
      if ( (unsigned __int8)sub_4CE6E0(9) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x271:
      if ( (unsigned __int8)sub_4CE6E0(10) )
        goto LABEL_27;
      goto LABEL_57;
    case 0x272:
    case 0x273:
      sub_49EC60(&unk_6021C0);
      return 0;
    case 0x274:
      sprintf(Buffer, "%d%%", *(_DWORD *)dword_7684BC);
      sub_49EC60(Buffer);
      return 0;
    case 0x275:
      if ( !dword_7673C4 )
        goto LABEL_27;
      if ( dword_7673C4 == 1 )
        goto LABEL_57;
      v3 = sub_49D690(2);
      sub_49EC60(v3);
      return 0;
    case 0x276:
      v4 = dword_769320;
      goto LABEL_32;
    case 0x277:
      v4 = dword_769464;
LABEL_32:
      if ( v4 > 1 )
      {
        sprintf(Buffer, (const char *const)&off_6021BC, v4);
LABEL_39:
        sub_49EC60(Buffer);
        result = 0;
      }
      else
      {
        v5 = sub_49D690(v4);
        sub_49EC60(v5);
        result = 0;
      }
      break;
    case 0x278:
      v6 = sub_49D690(dword_766C20);
      sub_49EC60(v6);
      return 0;
    case 0x279:
      v7 = dword_769890;
      goto LABEL_38;
    case 0x27A:
      v7 = dword_769158;
LABEL_38:
      sprintf(Buffer, "%d", v7);
      goto LABEL_39;
    case 0x27B:
      switch ( dword_767508 )
      {
        case 0:
          if ( !sub_41F230(dword_62A170, aChanging, Destination) )
            goto LABEL_53;
          strncpy(Destination, aChanging, 0x1FFu);
          byte_62A37B = 0;
          sub_49EC60(Destination);
          result = 0;
          break;
        case 1:
          if ( !sub_41F230(dword_62A170, a2003Season, Destination) )
            goto LABEL_53;
          strncpy(Destination, a2003Season, 0x1FFu);
          byte_62A37B = 0;
          sub_49EC60(Destination);
          result = 0;
          break;
        case 2:
          if ( !sub_41F230(dword_62A170, aClear, Destination) )
            goto LABEL_53;
          strncpy(Destination, aClear, 0x1FFu);
          byte_62A37B = 0;
          sub_49EC60(Destination);
          result = 0;
          break;
        case 3:
          if ( !sub_41F230(dword_62A170, aCloudy, Destination) )
            goto LABEL_53;
          strncpy(Destination, aCloudy, 0x1FFu);
          byte_62A37B = 0;
          sub_49EC60(Destination);
          result = 0;
          break;
        case 4:
          if ( !sub_41F230(dword_62A170, aRain_0, Destination) )
            goto LABEL_53;
          strncpy(Destination, aRain_0, 0x1FFu);
          byte_62A37B = 0;
          sub_49EC60(Destination);
          result = 0;
          break;
        case 5:
          if ( sub_41F230(dword_62A170, aMonsoon, Destination) )
          {
            strncpy(Destination, aMonsoon, 0x1FFu);
            byte_62A37B = 0;
          }
LABEL_53:
          sub_49EC60(Destination);
          result = 0;
          break;
        default:
          sub_49EC60(asc_6021B0);
          result = 0;
          break;
      }
      return result;
    case 0x27C:
      sprintf(Buffer, "%0.0f%%", *(float *)&dword_768EAC * 100.0);
      sub_49EC60(Buffer);
      return 0;
    case 0x27D:
      if ( (unsigned __int8)sub_4CE6E0(11) )
      {
LABEL_27:
        v2 = sub_49D690(0);
        sub_49EC60(v2);
        result = 0;
      }
      else
      {
LABEL_57:
        v8 = sub_49D690(1);
        sub_49EC60(v8);
LABEL_58:
        result = 0;
      }
      break;
    default:
      goto LABEL_58;
  }
  return result;
}
