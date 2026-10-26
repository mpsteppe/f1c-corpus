int sub_4A0030()
{
  switch ( dword_7D0410 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      sub_4A0D30(1);
      sub_497940((_DWORD *)dword_7CD8C0, (int)aMonitorpage, -1);
      break;
    case 5:
    case 6:
      sub_4A0D30(1);
      break;
    default:
      break;
  }
  sub_4C8D90(1);
  sub_42E400((int)&byte_7C56C0);
  return 0;
}
