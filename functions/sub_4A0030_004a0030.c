int sub_4A0030()
{
  switch ( dword_7D0410 )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      GlobalStateSetter(1);
      LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMonitorpage, -1);
      break;
    case 5:
    case 6:
      GlobalStateSetter(1);
      break;
    default:
      break;
  }
  GlobalVTableDispatchByParam(1);
  PenaltyStructInit((int)&byte_7C56C0);
  return 0;
}
