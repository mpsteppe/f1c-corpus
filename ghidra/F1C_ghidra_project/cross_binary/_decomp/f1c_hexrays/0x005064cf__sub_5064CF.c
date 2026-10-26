// f1c  0x005064cf  size=105
int __thiscall sub_5064CF(_DWORD *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = this[2];
  if ( v2 || (v2 = this[1]) != 0 )
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 40))(v2);
  v3 = this[1];
  if ( v3 )
  {
    v4 = this[2];
    if ( v4 )
    {
      v5 = this[3];
      if ( v5 )
      {
        if ( (*(_BYTE *)this & 1) == 0 )
          (*(void (__stdcall **)(int, int, _DWORD, _DWORD, int, _DWORD))(*(_DWORD *)v5 + 112))(v5, v4, 0, 0, v3, 0);
      }
    }
  }
  v6 = this[2];
  if ( v6 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(this[2]);
    this[2] = 0;
  }
  v7 = this[3];
  if ( v7 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 8))(this[3]);
    this[3] = 0;
  }
  this[1] = 0;
  return 0;
}
