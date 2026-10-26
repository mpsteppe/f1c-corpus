// Address: 0x0057aea0
// Size: 26 bytes
// Name: sub_57AEA0
// Type: LRESULT __stdcall(HWND, UINT, WPARAM, LPARAM)
// Source: IDA Hex-Rays decompilation

LRESULT __stdcall sub_57AEA0(HWND a1, UINT a2, WPARAM a3, LPARAM a4)
{
  if ( a2 == 6666 )
    return 0;
  else
    return DefWindowProcA(a1, a2, a3, a4);
}
