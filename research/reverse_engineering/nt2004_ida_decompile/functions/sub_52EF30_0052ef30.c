char __thiscall sub_52EF30(_DWORD *this, int a2, int a3, int a4)
{
  int v5; // eax

  if ( !*this )
  {
    if ( operator new(0x2D40u) )
      v5 = sub_52F7D0(a2, a3);
    else
      v5 = 0;
    *this = v5;
    if ( (*(int (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v5 + 4))(v5, 0, a4) != -1 )
      return 1;
    sub_52EFF0(this);
  }
  return 0;
}
