int __stdcall sub_412E50(int a1, int a2, int a3, char a4)
{
  int result; // eax
  int v5; // edx
  unsigned int v6; // edx

  result = -1;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      switch ( a3 )
      {
        case 1:
          v5 = a4 != 0 ? 219 : 243;
          goto LABEL_56;
        case 2:
          v5 = a4 != 0 ? 220 : 244;
          goto LABEL_56;
        case 3:
          v5 = a4 != 0 ? 221 : 245;
          goto LABEL_56;
        case 4:
          v5 = a4 != 0 ? 222 : 246;
          goto LABEL_56;
        case 5:
          v5 = a4 != 0 ? 223 : 247;
          goto LABEL_56;
        case 6:
          v5 = a4 != 0 ? 224 : 248;
          goto LABEL_56;
        case 7:
          v5 = a4 != 0 ? 225 : 249;
          goto LABEL_56;
        case 8:
          v5 = a4 != 0 ? 226 : 250;
          goto LABEL_56;
        case 9:
          v5 = a4 != 0 ? 227 : 251;
          goto LABEL_56;
        case 10:
          v5 = a4 != 0 ? 228 : 252;
          goto LABEL_56;
        case 11:
          v5 = a4 != 0 ? 229 : 253;
          goto LABEL_56;
        case 12:
          v5 = a4 != 0 ? 230 : 254;
          goto LABEL_56;
        case 13:
          v5 = a4 != 0 ? 231 : 255;
          goto LABEL_56;
        case 14:
          v5 = a4 != 0 ? 232 : 256;
          goto LABEL_56;
        case 15:
          v5 = a4 != 0 ? 233 : 257;
          goto LABEL_56;
        case 16:
          v5 = a4 != 0 ? 234 : 258;
          goto LABEL_56;
        case 17:
          v5 = a4 != 0 ? 235 : 259;
          goto LABEL_56;
        case 18:
          v5 = a4 != 0 ? 236 : 260;
          goto LABEL_56;
        case 19:
          v5 = a4 != 0 ? 237 : 261;
          goto LABEL_56;
        case 20:
          v5 = a4 != 0 ? 238 : 262;
          goto LABEL_56;
        case 21:
          v5 = a4 != 0 ? 239 : 263;
          goto LABEL_56;
        case 22:
          v5 = a4 != 0 ? 240 : 264;
          goto LABEL_56;
        case 23:
          v6 = a4 != 0 ? 0xFFFFFFE8 : 0;
          goto LABEL_55;
        case 24:
          v5 = a4 != 0 ? 242 : 266;
          goto LABEL_56;
        default:
          return result;
      }
    }
  }
  else
  {
    switch ( a3 )
    {
      case 1:
        v5 = a4 != 0 ? 214 : 240;
        goto LABEL_56;
      case 2:
        v5 = a4 != 0 ? 215 : 241;
        goto LABEL_56;
      case 3:
        v5 = a4 != 0 ? 216 : 242;
        goto LABEL_56;
      case 4:
        v5 = a4 != 0 ? 217 : 243;
        goto LABEL_56;
      case 5:
        v5 = a4 != 0 ? 218 : 244;
        goto LABEL_56;
      case 6:
        v5 = a4 != 0 ? 219 : 245;
        goto LABEL_56;
      case 7:
        v5 = a4 != 0 ? 220 : 246;
        goto LABEL_56;
      case 8:
        v5 = a4 != 0 ? 221 : 247;
        goto LABEL_56;
      case 9:
        v5 = a4 != 0 ? 222 : 248;
        goto LABEL_56;
      case 10:
        v5 = a4 != 0 ? 223 : 249;
        goto LABEL_56;
      case 11:
        v5 = a4 != 0 ? 224 : 250;
        goto LABEL_56;
      case 12:
        v5 = a4 != 0 ? 225 : 251;
        goto LABEL_56;
      case 13:
        v5 = a4 != 0 ? 226 : 252;
        goto LABEL_56;
      case 14:
        v5 = a4 != 0 ? 227 : 253;
        goto LABEL_56;
      case 15:
        v5 = a4 != 0 ? 228 : 254;
        goto LABEL_56;
      case 16:
        v5 = a4 != 0 ? 229 : 255;
        goto LABEL_56;
      case 17:
        v5 = a4 != 0 ? 230 : 256;
        goto LABEL_56;
      case 18:
        v5 = a4 != 0 ? 231 : 257;
        goto LABEL_56;
      case 19:
        v5 = a4 != 0 ? 232 : 258;
        goto LABEL_56;
      case 20:
        v5 = a4 != 0 ? 233 : 259;
        goto LABEL_56;
      case 21:
        v5 = a4 != 0 ? 234 : 260;
        goto LABEL_56;
      case 22:
        v5 = a4 != 0 ? 235 : 261;
        goto LABEL_56;
      case 23:
        v5 = a4 != 0 ? 236 : 262;
        goto LABEL_56;
      case 24:
        v5 = a4 != 0 ? 237 : 263;
        goto LABEL_56;
      case 25:
        v5 = a4 != 0 ? 238 : 264;
        goto LABEL_56;
      case 26:
        v6 = a4 != 0 ? 0xFFFFFFE6 : 0;
LABEL_55:
        v5 = v6 + 265;
LABEL_56:
        if ( v5 >= 0 )
        {
          *(_DWORD *)(a1 + 8) = v5;
          *(_DWORD *)(a1 + 12) = sub_414180(a2);
          result = 1;
        }
        break;
      default:
        return result;
    }
  }
  return result;
}

