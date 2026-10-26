int sub_4EB150()
{
  int result; // eax

  switch ( *(_DWORD *)dword_B72314 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      sub_4E1810((_DWORD *)dword_B6E090, (int)"MONITOR_SINGLE", 0);
      result = 0;
      break;
    case 5:
      if ( !(unsigned __int8)sub_4735E0(&dword_B6CBA8) )
      {
        sub_4E1810((_DWORD *)dword_B6E090, (int)"MONITOR_MPCLIENT", 0);
        goto LABEL_8;
      }
      sub_4E1810((_DWORD *)dword_B6E090, (int)"MONITOR_MPHOST", 0);
      result = 0;
      break;
    case 7:
      sub_4E1810((_DWORD *)dword_B6E090, (int)"MONITOR_TIMETRIAL", 0);
      result = 0;
      break;
    case 8:
      sub_4E1810((_DWORD *)dword_B6E090, (int)"MONITOR_SCHOOL", 0);
      result = 0;
      break;
    default:
LABEL_8:
      result = 0;
      break;
  }
  return result;
}
