int __thiscall sub_64E558(_DWORD *this)
{
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = this[2];
  if ( v2 || (v2 = this[1]) != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 56))(v2);
  if ( this[1] )
  {
    if ( this[2] )
    {
      if ( this[4] )
      {
        if ( (*(_BYTE *)this & 1) == 0 )
        {
          sub_5AF533(1);
          v3 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[4] + 120))(
                 this[4],
                 this[2],
                 0,
                 this[1],
                 0);
          sub_5AF533(0);
          if ( v3 < 0 )
          {
            sub_5AF533(1);
            sub_64E479(0, this[2], this[1]);
            sub_5AF533(0);
          }
        }
      }
    }
  }
  v4 = this[2];
  if ( v4 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(this[2]);
    this[2] = 0;
  }
  v5 = this[3];
  if ( v5 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(this[3]);
    this[3] = 0;
  }
  v6 = this[4];
  if ( v6 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(this[4]);
    this[4] = 0;
  }
  v7 = this[1];
  if ( v7 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(this[1]);
    this[1] = 0;
  }
  return 0;
}
