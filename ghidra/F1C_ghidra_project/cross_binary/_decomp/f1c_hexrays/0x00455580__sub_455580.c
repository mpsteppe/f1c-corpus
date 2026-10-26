// f1c  0x00455580  size=742
char __fastcall sub_455580(char a1, unsigned int a2)
{
  char result; // al

  switch ( a1 )
  {
    case -125:
      result = -97;
      break;
    case -95:
      result = -83;
      break;
    case -94:
      result = -67;
      break;
    case -93:
      result = -100;
      break;
    case -92:
      result = -49;
      break;
    case -91:
      result = -66;
      break;
    case -90:
      result = -77;
      break;
    case -89:
      result = -11;
      break;
    case -88:
      result = -7;
      break;
    case -87:
      result = -72;
      break;
    case -86:
      result = -90;
      break;
    case -85:
      result = -82;
      break;
    case -84:
      result = -86;
      break;
    case -83:
      result = -16;
      break;
    case -82:
      result = -87;
      break;
    case -81:
      result = -18;
      break;
    case -80:
      result = -8;
      break;
    case -79:
      result = -15;
      break;
    case -78:
      result = -3;
      break;
    case -77:
      result = -4;
      break;
    case -76:
      result = -17;
      break;
    case -75:
      result = -26;
      break;
    case -74:
      result = -12;
      break;
    case -73:
      result = -6;
      break;
    case -72:
      result = -9;
      break;
    case -71:
      result = -5;
      break;
    case -70:
      result = -89;
      break;
    case -69:
      result = -81;
      break;
    case -68:
      result = -84;
      break;
    case -67:
      result = -85;
      break;
    case -66:
      result = -13;
      break;
    case -65:
      result = -88;
      break;
    case -64:
      result = -73;
      break;
    case -63:
      result = -75;
      break;
    case -62:
      result = -74;
      break;
    case -61:
      result = -57;
      break;
    case -60:
      result = -114;
      break;
    case -59:
      result = -113;
      break;
    case -58:
      result = -110;
      break;
    case -57:
      result = 0x80;
      break;
    case -56:
      result = -44;
      break;
    case -55:
      result = -112;
      break;
    case -54:
      result = -46;
      break;
    case -53:
      result = -45;
      break;
    case -52:
      result = -34;
      break;
    case -51:
      result = -42;
      break;
    case -50:
      result = -41;
      break;
    case -49:
      result = -40;
      break;
    case -48:
      result = -47;
      break;
    case -47:
      result = -91;
      break;
    case -46:
      result = -29;
      break;
    case -45:
      result = -32;
      break;
    case -44:
      result = -30;
      break;
    case -43:
      result = -27;
      break;
    case -42:
      result = -103;
      break;
    case -41:
      result = -98;
      break;
    case -40:
      result = -99;
      break;
    case -39:
      result = -21;
      break;
    case -38:
      result = -23;
      break;
    case -37:
      result = -22;
      break;
    case -36:
      result = -102;
      break;
    case -35:
      result = -19;
      break;
    case -34:
      result = -24;
      break;
    case -33:
      result = -31;
      break;
    case -32:
      result = -123;
      break;
    case -31:
      result = -96;
      break;
    case -30:
      result = -125;
      break;
    case -29:
      result = -58;
      break;
    case -28:
      result = -124;
      break;
    case -27:
      result = -122;
      break;
    case -26:
      result = -111;
      break;
    case -25:
      result = -121;
      break;
    case -24:
      result = -118;
      break;
    case -23:
      result = -126;
      break;
    case -22:
      result = -120;
      break;
    case -21:
      result = -119;
      break;
    case -20:
      result = -115;
      break;
    case -19:
      result = -95;
      break;
    case -18:
      result = -116;
      break;
    case -17:
      result = -117;
      break;
    case -16:
      result = -48;
      break;
    case -15:
      result = -92;
      break;
    case -14:
      result = -107;
      break;
    case -13:
      result = -94;
      break;
    case -12:
      result = -109;
      break;
    case -11:
      result = -28;
      break;
    case -10:
      result = -108;
      break;
    case -9:
      result = -10;
      break;
    case -8:
      result = -101;
      break;
    case -7:
      result = -105;
      break;
    case -6:
      result = -93;
      break;
    case -5:
      result = -106;
      break;
    case -4:
      result = -127;
      break;
    case -3:
      result = -20;
      break;
    case -2:
      result = -25;
      break;
    case -1:
      result = -104;
      break;
    default:
      if ( (a2 & 0x8000) == 0 )
      {
LABEL_147:
        result = a1;
      }
      else
      {
        switch ( a2 & 0xFFF )
        {
          case 2u:
            result = ~(unsigned __int8)(a2 >> 11) & 0x10 | 0x21;
            break;
          case 3u:
            result = 64;
            break;
          case 4u:
            result = ~(unsigned __int8)(a2 >> 11) & 0x10 | 0x23;
            break;
          case 5u:
            result = ~(unsigned __int8)(a2 >> 11) & 0x10 | 0x24;
            break;
          case 6u:
            result = ~(unsigned __int8)(a2 >> 11) & 0x10 | 0x25;
            break;
          case 7u:
            result = 94;
            break;
          case 8u:
            result = 38;
            break;
          case 9u:
            result = 42;
            break;
          case 0xAu:
            result = 40;
            break;
          case 0xBu:
            result = 41;
            break;
          case 0xCu:
            result = 95;
            break;
          case 0xDu:
            result = 43;
            break;
          case 0x10u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x51;
            break;
          case 0x11u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x57;
            break;
          case 0x12u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x45;
            break;
          case 0x13u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x52;
            break;
          case 0x14u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x54;
            break;
          case 0x15u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x59;
            break;
          case 0x16u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x55;
            break;
          case 0x17u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x49;
            break;
          case 0x18u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x4F;
            break;
          case 0x19u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x50;
            break;
          case 0x1Au:
            result = (a2 >> 10) & 0x20 | 0x5B;
            break;
          case 0x1Bu:
            result = (a2 >> 10) & 0x20 | 0x5D;
            break;
          case 0x1Eu:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x41;
            break;
          case 0x1Fu:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x53;
            break;
          case 0x20u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x44;
            break;
          case 0x21u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x46;
            break;
          case 0x22u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x47;
            break;
          case 0x23u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x48;
            break;
          case 0x24u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x4A;
            break;
          case 0x25u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x4B;
            break;
          case 0x26u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x4C;
            break;
          case 0x27u:
            result = ((a2 & 0x8000) == 0) | 0x3A;
            break;
          case 0x28u:
            result = 34;
            break;
          case 0x29u:
            result = 126;
            break;
          case 0x2Bu:
            result = (a2 >> 10) & 0x20 | 0x5C;
            break;
          case 0x2Cu:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x5A;
            break;
          case 0x2Du:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x58;
            break;
          case 0x2Eu:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x43;
            break;
          case 0x2Fu:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x56;
            break;
          case 0x30u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x42;
            break;
          case 0x31u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x4E;
            break;
          case 0x32u:
            result = ~(unsigned __int8)(a2 >> 10) & 0x20 | 0x4D;
            break;
          case 0x33u:
            result = (a2 >> 11) & 0x10 | 0x2C;
            break;
          case 0x34u:
            result = (a2 >> 11) & 0x10 | 0x2E;
            break;
          case 0x35u:
            result = (a2 >> 11) & 0x10 | 0x2F;
            break;
          default:
            goto LABEL_147;
        }
      }
      break;
  }
  return result;
}
