char DriverTableIndexInitialization()
{
  int i; // ecx
  int v1; // eax

  if ( !GlobalSignCheck() )
    return 0;
  for ( i = 0; i < 104; dword_5F0730[4656 * v1] = i )
  {
    v1 = dword_7CD470[i];
    if ( v1 < 0 )
      break;
    ++i;
  }
  return 1;
}
