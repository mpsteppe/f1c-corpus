void __thiscall sub_5544C0(_DWORD *this, int a2)
{
  if ( a2 != -1 && a2 != this[14] )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 13, 3);
      }
      else if ( a2 == 2 )
      {
        (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 13, 2);
      }
    }
    else
    {
      (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 13, 1);
    }
    this[14] = a2;
  }
}
