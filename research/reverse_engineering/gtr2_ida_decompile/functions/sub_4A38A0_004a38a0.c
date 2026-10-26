int __thiscall sub_4A38A0(_DWORD *this)
{
  int v1; // eax
  int result; // eax
  int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax
  _DWORD v7[9]; // [esp-1Ch] [ebp-50h] BYREF
  char Buffer[32]; // [esp+14h] [ebp-20h] BYREF

  switch ( this[72] )
  {
    case 0x229:
      if ( !(unsigned __int8)sub_501D80(&byte_B6F530, 0) )
        goto LABEL_24;
      goto LABEL_23;
    case 0x22A:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 1) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x22B:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 2) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x22C:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 3) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x22D:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 4) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x22E:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 5) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x22F:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 6) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x230:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 7) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x231:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 8) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x232:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 9) )
        goto LABEL_23;
      goto LABEL_24;
    case 0x233:
      if ( (unsigned __int8)sub_501D80(&byte_B6F530, 10) )
      {
LABEL_23:
        v1 = sub_4CFC00(0);
        sub_4907C0(v1);
        return 0;
      }
      else
      {
LABEL_24:
        v3 = sub_4CFC00(1);
        sub_4907C0(v3);
        return 0;
      }
    case 0x234:
    case 0x235:
      sub_4907C0((int)"---");
      return 0;
    case 0x236:
      sprintf(Buffer, "%d%%", dword_B71DEC);
      sub_4907C0((int)Buffer);
      return 0;
    case 0x237:
      v4 = dword_B70588;
      if ( dword_B70588 >= 0 )
      {
        if ( dword_B70588 > 2 )
          v4 = 2;
LABEL_31:
        v6 = sub_4CFC00(v4);
        sub_4907C0(v6);
        result = 0;
      }
      else
      {
        v5 = sub_4CFC00(0);
        sub_4907C0(v5);
        result = 0;
      }
      break;
    case 0x238:
      v4 = dword_B72EBC;
      goto LABEL_34;
    case 0x239:
      v4 = dword_B73000;
LABEL_34:
      if ( v4 < 2 )
        goto LABEL_31;
      sprintf(Buffer, (const char *const)&off_6FB240, v4);
LABEL_39:
      sub_4907C0((int)Buffer);
      result = 0;
      break;
    case 0x23A:
      v4 = dword_B6FE20;
      goto LABEL_31;
    case 0x23B:
      sprintf(Buffer, "%d", dword_B732B8);
      goto LABEL_39;
    case 0x23C:
      qmemcpy(v7, &unk_B72C08, sizeof(v7));
      sprintf(Buffer, "%d");
      sub_4907C0((int)Buffer);
      return 0;
    case 0x23D:
      switch ( dword_B706CC )
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
    case 0x23E:
      sprintf(Buffer, "%0.0f%%", *(float *)&dword_B72958 * 100.0);
      sub_4907C0((int)Buffer);
      goto LABEL_48;
    default:
LABEL_48:
      result = 0;
      break;
  }
  return result;
}
