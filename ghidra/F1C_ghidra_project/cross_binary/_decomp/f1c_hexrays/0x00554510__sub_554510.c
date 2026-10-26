// f1c  0x00554510  size=68
void __thiscall sub_554510(_DWORD *this, int a2)
{
  if ( a2 != -1 && a2 != this[15] )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 14, 3);
      }
      else if ( a2 == 2 )
      {
        (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 14, 2);
      }
    }
    else
    {
      (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_8B89A0 + 252))(dword_8B89A0, *this, 14, 1);
    }
    this[15] = a2;
  }
}
