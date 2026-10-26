BOOL __stdcall sub_612E50(HINSTANCE hInstance, HWND a2, HWND hWnd)
{
  BOOL result; // eax

  if ( !hWnd || (DestroyWindow(hWnd), result = UnregisterClassA("CUBERealtime", hInstance), a2 != hWnd) )
  {
    if ( a2 )
    {
      DestroyWindow(a2);
      return UnregisterClassA("CUBEApp", hInstance);
    }
  }
  return result;
}
