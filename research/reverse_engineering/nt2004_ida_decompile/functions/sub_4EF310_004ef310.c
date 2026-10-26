void sub_4EF310()
{
  if ( dword_7D6BB0 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_7D6BB0 + 60))(dword_7D6BB0, 2);
    if ( (*(int (__thiscall **)(int, HWND))(*(_DWORD *)dword_7D6BB0 + 4))(dword_7D6BB0, hWndParent) )
    {
      dword_7D6BB0 = 0;
    }
    else
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_7D6BB0 + 48))(dword_7D6BB0, 1065353216);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_7D6BB0 + 56))(dword_7D6BB0, dword_7677C0);
    }
  }
}
