// f1c  0x0057aea0  size=26
LRESULT __stdcall sub_57AEA0(HWND a1, UINT a2, WPARAM a3, LPARAM a4)
{
  if ( a2 == 6666 )
    return 0;
  else
    return DefWindowProcA(a1, a2, a3, a4);
}
