int sub_4B9710()
{
  int result; // eax

  if ( !dword_7655CC )
    return -1;
  switch ( *(_DWORD *)dword_7689CC )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
      sub_4AD720((_DWORD *)dword_7655CC, aMonitorpage, 1);
      result = 0;
      break;
    case 5:
      if ( !sub_4634D0(dword_764D70) )
      {
        sub_4AD720((_DWORD *)dword_7655CC, a2003MultiClien, 1);
        goto LABEL_8;
      }
      sub_4AD720((_DWORD *)dword_7655CC, a2003MultiHostM, 1);
      result = 0;
      break;
    default:
LABEL_8:
      result = 0;
      break;
  }
  return result;
}
