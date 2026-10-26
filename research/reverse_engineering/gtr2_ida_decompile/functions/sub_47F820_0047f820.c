INT_PTR __stdcall sub_47F820(HWND hWndParent, UINT a2, WPARAM a3, LPARAM a4)
{
  if ( a2 == 16 )
  {
    PostQuitMessage(0);
    if ( byte_B6CEA3 )
      TerminateProcess(ProcessInformation, 0);
  }
  else if ( a2 == 272 )
  {
    EnumChildWindows(hWndParent, EnumFunc, 0);
    return 0;
  }
  return 0;
}
