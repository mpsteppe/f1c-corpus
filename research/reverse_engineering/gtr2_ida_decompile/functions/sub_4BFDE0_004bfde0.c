_DWORD *__thiscall sub_4BFDE0(_DWORD *this, int a2)
{
  int v2; // esi
  _DWORD *result; // eax
  _DWORD *v5; // eax

  v2 = a2 - 1;
  if ( a2 - 1 < 0 || v2 >= 868 || this[v2 + 365] )
    return 0;
  if ( a2 > 123 )
  {
    if ( a2 > 727 )
    {
      if ( a2 == 753 )
      {
        if ( operator new(0x118u) )
        {
          result = (_DWORD *)sub_494390();
          this[v2 + 365] = result;
          return result;
        }
        goto LABEL_141;
      }
      if ( a2 == 857 )
      {
        if ( operator new(0x25Cu) )
        {
          result = (_DWORD *)sub_4BEB20();
          this[v2 + 365] = result;
          return result;
        }
        goto LABEL_141;
      }
    }
    else
    {
      switch ( a2 )
      {
        case 727:
          if ( operator new(0x11Cu) )
          {
            result = (_DWORD *)sub_492780();
            this[v2 + 365] = result;
            return result;
          }
          goto LABEL_141;
        case 477:
          if ( operator new(0x330u) )
          {
            result = (_DWORD *)sub_48D130();
            this[v2 + 365] = result;
            return result;
          }
          goto LABEL_141;
        case 578:
          if ( operator new(0x71Cu) )
          {
            result = (_DWORD *)sub_493D60();
            this[v2 + 365] = result;
            return result;
          }
          goto LABEL_141;
      }
    }
    return (_DWORD *)this[v2 + 365];
  }
  if ( a2 == 123 )
  {
    if ( operator new(0x118u) )
    {
      result = (_DWORD *)sub_495570();
      this[v2 + 365] = result;
      return result;
    }
LABEL_141:
    this[v2 + 365] = 0;
    return (_DWORD *)this[v2 + 365];
  }
  switch ( a2 )
  {
    case 1:
      if ( !operator new(0x25Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_499340();
      this[v2 + 365] = result;
      return result;
    case 2:
      if ( !operator new(0x480u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BFA80();
      this[v2 + 365] = result;
      return result;
    case 3:
      v5 = operator new(0x268u);
      if ( !v5 )
        goto LABEL_141;
      result = sub_48C030(v5);
      this[v2 + 365] = result;
      return result;
    case 4:
      if ( !operator new(0x37Cu) )
        goto LABEL_141;
      goto LABEL_8;
    case 5:
      if ( !operator new(0x37Cu) )
        goto LABEL_141;
LABEL_8:
      result = (_DWORD *)sub_48C0A0();
      this[v2 + 365] = result;
      return result;
    case 6:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
      goto LABEL_24;
    case 7:
    case 8:
    case 9:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
      goto LABEL_24;
    case 10:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
      goto LABEL_24;
    case 11:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
      goto LABEL_24;
    case 12:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
      goto LABEL_24;
    case 13:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
      goto LABEL_24;
    case 14:
      if ( !operator new(0x1B4u) )
        goto LABEL_141;
LABEL_24:
      result = (_DWORD *)sub_4BFA60();
      this[v2 + 365] = result;
      return result;
    case 15:
      if ( !operator new(0x25Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_48C110();
      this[v2 + 365] = result;
      return result;
    case 16:
      if ( !operator new(0x2F8u) )
        goto LABEL_141;
      result = (_DWORD *)sub_499D10();
      this[v2 + 365] = result;
      return result;
    case 18:
    case 20:
    case 21:
      if ( !operator new(0x268u) )
        goto LABEL_141;
      goto LABEL_66;
    case 19:
      if ( !operator new(0x268u) )
        goto LABEL_141;
      goto LABEL_66;
    case 22:
      if ( !operator new(0x268u) )
        goto LABEL_141;
LABEL_66:
      result = (_DWORD *)sub_48C1C0();
      this[v2 + 365] = result;
      return result;
    case 23:
      if ( !operator new(0x25Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_48D970();
      this[v2 + 365] = result;
      return result;
    case 24:
      if ( !operator new(0x254u) )
        goto LABEL_141;
      goto LABEL_56;
    case 25:
      if ( !operator new(0x254u) )
        goto LABEL_141;
      goto LABEL_56;
    case 26:
      if ( !operator new(0x118u) )
        goto LABEL_141;
      goto LABEL_46;
    case 27:
      if ( !operator new(0x118u) )
        goto LABEL_141;
      goto LABEL_46;
    case 31:
      if ( !operator new(0x118u) )
        goto LABEL_141;
      goto LABEL_46;
    case 32:
      if ( !operator new(0x118u) )
        goto LABEL_141;
      goto LABEL_46;
    case 33:
      if ( !operator new(0x118u) )
        goto LABEL_141;
LABEL_46:
      result = (_DWORD *)sub_4BC440();
      this[v2 + 365] = result;
      return result;
    case 34:
      if ( !operator new(0x254u) )
        goto LABEL_141;
      goto LABEL_56;
    case 35:
      if ( !operator new(0x254u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BC460();
      this[v2 + 365] = result;
      return result;
    case 36:
      if ( !operator new(0x264u) )
        goto LABEL_141;
      result = (_DWORD *)sub_491FC0();
      this[v2 + 365] = result;
      return result;
    case 37:
      if ( !operator new(0x25Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_492270();
      this[v2 + 365] = result;
      return result;
    case 38:
      if ( !operator new(0x254u) )
        goto LABEL_141;
LABEL_56:
      result = (_DWORD *)sub_4BC420();
      this[v2 + 365] = result;
      return result;
    case 39:
      if ( !operator new(0x264u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BFB80();
      this[v2 + 365] = result;
      return result;
    case 40:
      if ( !operator new(0x14Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_48EEF0();
      this[v2 + 365] = result;
      return result;
    case 41:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_48F480();
      this[v2 + 365] = result;
      return result;
    case 42:
      if ( !operator new(0x264u) )
        goto LABEL_141;
      goto LABEL_80;
    case 43:
      if ( !operator new(0x264u) )
        goto LABEL_141;
      goto LABEL_80;
    case 44:
      if ( !operator new(0x264u) )
        goto LABEL_141;
      goto LABEL_80;
    case 45:
      if ( !operator new(0x264u) )
        goto LABEL_141;
LABEL_80:
      result = (_DWORD *)sub_4BD7B0();
      this[v2 + 365] = result;
      return result;
    case 46:
    case 50:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_48CA40();
      this[v2 + 365] = result;
      return result;
    case 47:
    case 51:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_48CB30();
      this[v2 + 365] = result;
      return result;
    case 48:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_494750();
      this[v2 + 365] = result;
      return result;
    case 49:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_494880();
      this[v2 + 365] = result;
      return result;
    case 52:
      if ( !operator new(0x254u) )
        goto LABEL_141;
      goto LABEL_86;
    case 53:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_497280();
      this[v2 + 365] = result;
      return result;
    case 54:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4949A0();
      this[v2 + 365] = result;
      return result;
    case 55:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BEB00();
      this[v2 + 365] = result;
      return result;
    case 56:
      if ( !operator new(0x254u) )
        goto LABEL_141;
LABEL_86:
      result = (_DWORD *)sub_494EB0();
      this[v2 + 365] = result;
      return result;
    case 57:
      if ( !operator new(0x268u) )
        goto LABEL_141;
      result = (_DWORD *)sub_497B80();
      this[v2 + 365] = result;
      return result;
    case 58:
      if ( !operator new(0x258u) )
        goto LABEL_141;
      result = (_DWORD *)sub_498050();
      this[v2 + 365] = result;
      return result;
    case 59:
      if ( !operator new(0x114u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4D8C10(0);
      this[v2 + 365] = result;
      return result;
    case 60:
      if ( !operator new(0x268u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4B8FE0();
      this[v2 + 365] = result;
      return result;
    case 61:
      if ( !operator new(0x14Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BDD60();
      this[v2 + 365] = result;
      return result;
    case 62:
      if ( !operator new(0x350u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BDDA0();
      this[v2 + 365] = result;
      return result;
    case 63:
      if ( !operator new(0x260u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BE250();
      this[v2 + 365] = result;
      return result;
    case 64:
      if ( !operator new(0x268u) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BE320();
      this[v2 + 365] = result;
      return result;
    case 65:
      if ( !operator new(0x270u) )
        goto LABEL_141;
      goto LABEL_116;
    case 66:
    case 67:
      if ( !operator new(0x270u) )
        goto LABEL_141;
LABEL_116:
      result = (_DWORD *)sub_4BFCF0();
      this[v2 + 365] = result;
      break;
    case 68:
      if ( !operator new(0x27Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BBB30();
      this[v2 + 365] = result;
      break;
    case 69:
      if ( !operator new(0x25Cu) )
        goto LABEL_141;
      result = (_DWORD *)sub_4BE460();
      this[v2 + 365] = result;
      break;
    default:
      return (_DWORD *)this[v2 + 365];
  }
  return result;
}
