char __fastcall sub_5666C0(char *Buffer, int a2)
{
  char *v3; // eax
  char *v4; // eax
  char result; // al
  const char *v6; // [esp-4h] [ebp-4Ch]

  if ( a2 <= 100 )
  {
    if ( a2 != 100 )
    {
      switch ( a2 )
      {
        case 0:
          goto LABEL_11;
        case 1:
          goto LABEL_12;
        case 2:
          goto LABEL_13;
        case 3:
          goto LABEL_14;
        case 4:
          goto LABEL_17;
        case 5:
          JUMPOUT(0x5666E8);
        case 6:
          goto LABEL_19;
        default:
          return 0;
      }
    }
    v6 = "View again";
LABEL_23:
    v3 = sub_41D840(off_16C9B4C, v6);
LABEL_21:
    sprintf(Buffer, "%s", v3);
    return 0;
  }
  if ( a2 <= 400 )
  {
    if ( a2 != 400 )
    {
      switch ( a2 )
      {
        case 101:
        case 202:
        case 302:
          v6 = "Return to Garage";
          goto LABEL_23;
        case 102:
        case 203:
        case 303:
          break;
        case 200:
        case 300:
          v6 = "Try again";
          goto LABEL_23;
        case 201:
        case 301:
          goto LABEL_17;
        default:
          return 0;
      }
    }
LABEL_11:
    v6 = "Continue";
    goto LABEL_23;
  }
  switch ( a2 )
  {
    case 401:
    case 501:
LABEL_12:
      v6 = "Restart";
      goto LABEL_23;
    case 402:
    case 503:
LABEL_14:
      if ( *(_DWORD *)dword_B640C8 == 6 )
        v3 = sub_41D840(&byte_91CC38, "Quit");
      else
        v3 = sub_41D840(&byte_91CC38, "Return to Garage");
      goto LABEL_21;
    case 403:
    case 504:
LABEL_17:
      v4 = sub_41D840(&byte_91CC38, "Replay");
      sprintf(Buffer, "%s", v4);
      if ( dword_BE1204 == 1 )
        return 0;
      result = 1;
      break;
    case 404:
    case 505:
LABEL_19:
      v6 = "Hide Menu";
      goto LABEL_23;
    case 500:
      goto LABEL_11;
    case 502:
LABEL_13:
      v6 = "Save";
      goto LABEL_23;
    default:
      return 0;
  }
  return result;
}
