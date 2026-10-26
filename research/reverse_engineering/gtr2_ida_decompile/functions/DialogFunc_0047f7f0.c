INT_PTR __stdcall DialogFunc(HWND hWndParent, UINT a2, WPARAM a3, LPARAM a4)
{
  if ( a2 == 272 )
    EnumChildWindows(hWndParent, EnumFunc, 0);
  return 0;
}
