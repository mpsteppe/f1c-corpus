void sub_540450()
{
  if ( dword_BE1D0C )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_BE1D0C + 56))(dword_BE1D0C, 2);
    if ( (*(int (__thiscall **)(int, HWND))(*(_DWORD *)dword_BE1D0C + 4))(dword_BE1D0C, hWndParent) )
    {
      dword_BE1D0C = 0;
    }
    else
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_BE1D0C + 44))(dword_BE1D0C, 1065353216);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_BE1D0C + 52))(dword_BE1D0C, dword_B70888);
    }
  }
}
