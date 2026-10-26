void __thiscall sub_5AA650(_DWORD *this, int a2)
{
  if ( a2 != -1 && a2 != this[14] )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_7E7CA8 + 252))(dword_7E7CA8, *this, 13, 3);
      }
      else if ( a2 == 2 )
      {
        (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_7E7CA8 + 252))(dword_7E7CA8, *this, 13, 2);
      }
    }
    else
    {
      (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_7E7CA8 + 252))(dword_7E7CA8, *this, 13, 1);
    }
    this[14] = a2;
  }
}
