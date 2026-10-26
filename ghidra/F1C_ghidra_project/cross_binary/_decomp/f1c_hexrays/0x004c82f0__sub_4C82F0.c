// f1c  0x004c82f0  size=84
void sub_4C82F0()
{
  if ( dword_8AC4C4 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_8AC4C4 + 56))(dword_8AC4C4, 2);
    if ( (*(int (__thiscall **)(int, HWND))(*(_DWORD *)dword_8AC4C4 + 4))(dword_8AC4C4, hWnd) )
    {
      dword_8AC4C4 = 0;
    }
    else
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_8AC4C4 + 44))(dword_8AC4C4, 1065353216);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)dword_8AC4C4 + 52))(dword_8AC4C4, dword_7CF230);
    }
  }
}
