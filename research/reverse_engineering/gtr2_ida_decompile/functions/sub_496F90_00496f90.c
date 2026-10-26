int __thiscall sub_496F90(_BYTE *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // eax

  if ( this[276] )
    v2 = sub_5944B0(&dword_FB1EF8);
  else
    v2 = sub_5943E0(&dword_FB1EF8);
  v3 = v2 - 2;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v4 = *(_DWORD *)this;
      *((_DWORD *)this + 67) = 2;
    }
    else
    {
      v4 = *(_DWORD *)this;
      *((_DWORD *)this + 67) = 0;
    }
    (*(void (__thiscall **)(_BYTE *, _DWORD))(v4 + 44))(this, *((_DWORD *)this + 67));
    return 0;
  }
  else
  {
    v6 = *(_DWORD *)this;
    *((_DWORD *)this + 67) = 1;
    (*(void (__thiscall **)(_BYTE *, _DWORD))(v6 + 44))(this, *((_DWORD *)this + 67));
    return 0;
  }
}
