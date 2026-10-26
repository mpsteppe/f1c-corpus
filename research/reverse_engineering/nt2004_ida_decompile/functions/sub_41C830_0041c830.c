char __thiscall sub_41C830(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // eax
  _DWORD *v5; // eax

  ((void (*)(void))sub_41C880)();
  v4 = operator new(0x14u);
  if ( v4 )
    v5 = sub_41BF10(v4);
  else
    v5 = 0;
  *this = v5;
  if ( v5 && sub_41BF30(v5, a2, a3) )
    return 1;
  sub_41C880(this);
  return 0;
}
