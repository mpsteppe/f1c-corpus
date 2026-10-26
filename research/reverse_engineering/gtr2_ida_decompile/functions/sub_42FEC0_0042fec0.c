char *__fastcall sub_42FEC0(int a1, char a2, char a3)
{
  char *result; // eax

  if ( a3 )
  {
    if ( a2 )
    {
      switch ( a1 )
      {
        case -2:
          goto LABEL_4;
        case 0:
          result = "Open Practice";
          break;
        case 1:
          result = (char *)&dword_6F3B78;
          break;
        case 2:
          result = (char *)&dword_6F3B6C;
          break;
        case 3:
          result = "Qualify 1";
          break;
        case 4:
          result = "Qualify 2";
          break;
        case 5:
          goto LABEL_10;
        case 6:
          goto LABEL_11;
        default:
          goto LABEL_34;
      }
    }
    else
    {
      switch ( a1 )
      {
        case -2:
LABEL_4:
          result = "Loading";
          break;
        case 0:
          result = "TestDay";
          break;
        case 1:
          result = "Practice1";
          break;
        case 2:
          result = "Practice2";
          break;
        case 3:
          result = "Qualify1";
          break;
        case 4:
          result = "Qualify2";
          break;
        case 5:
LABEL_10:
          result = (char *)&dword_6F3B4C;
          break;
        case 6:
LABEL_11:
          result = (char *)&dword_6F3B44;
          break;
        default:
          goto LABEL_34;
      }
    }
  }
  else if ( a2 )
  {
    switch ( a1 )
    {
      case -2:
        goto LABEL_26;
      case 0:
        result = sub_41D840(&byte_91CC38, "Open Practice");
        break;
      case 1:
        result = sub_41D840(&byte_91CC38, (const char *)&dword_6F3B78);
        break;
      case 2:
        result = sub_41D840(&byte_91CC38, (const char *)&dword_6F3B6C);
        break;
      case 3:
        result = sub_41D840(&byte_91CC38, "Qualify 1");
        break;
      case 4:
        result = sub_41D840(&byte_91CC38, "Qualify 2");
        break;
      case 5:
        goto LABEL_32;
      case 6:
        goto LABEL_33;
      default:
        goto LABEL_34;
    }
  }
  else
  {
    switch ( a1 )
    {
      case -2:
LABEL_26:
        result = sub_41D840(&byte_91CC38, "Loading");
        break;
      case 0:
        result = sub_41D840(&byte_91CC38, "TestDay");
        break;
      case 1:
        result = sub_41D840(&byte_91CC38, "Practice1");
        break;
      case 2:
        result = sub_41D840(&byte_91CC38, "Practice2");
        break;
      case 3:
        result = sub_41D840(&byte_91CC38, "Qualify1");
        break;
      case 4:
        result = sub_41D840(&byte_91CC38, "Qualify2");
        break;
      case 5:
LABEL_32:
        result = sub_41D840(&byte_91CC38, (const char *)&dword_6F3B4C);
        break;
      case 6:
LABEL_33:
        result = sub_41D840(&byte_91CC38, (const char *)&dword_6F3B44);
        break;
      default:
LABEL_34:
        result = (char *)&dword_6F2618;
        break;
    }
  }
  return result;
}
