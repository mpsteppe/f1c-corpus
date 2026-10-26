int __thiscall sub_60A3F0(_DWORD *this, int a2)
{
  int result; // eax

  result = this[55];
  if ( a2 != result && a2 != -1 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 276))(
                   dword_FB40C8,
                   this[51],
                   2,
                   3);
      }
      else
      {
        result = a2 - 2;
        if ( a2 == 2 )
          result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 276))(
                     dword_FB40C8,
                     this[51],
                     2,
                     2);
      }
    }
    else
    {
      result = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 276))(
                 dword_FB40C8,
                 this[51],
                 2,
                 1);
    }
    this[55] = a2;
  }
  return result;
}
