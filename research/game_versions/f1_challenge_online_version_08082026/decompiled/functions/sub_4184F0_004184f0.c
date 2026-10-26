int __thiscall sub_4184F0(int this)
{
  int v2; // eax

  if ( *(_BYTE *)(this + 2800) )
    return 0;
  if ( *(_DWORD *)(this + 2804) )
    return 1;
  if ( !dword_8AC4C4 )
    return 1;
  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C4 + 96))(dword_8AC4C4);
  *(_DWORD *)(this + 2804) = v2;
  if ( !v2 )
    return 1;
  sub_418970(flt_7CF3C8);
  sub_4116B0();
  sub_415090(&dword_5EA5E8);
  *(_BYTE *)(this + 2800) = 1;
  return 0;
}
