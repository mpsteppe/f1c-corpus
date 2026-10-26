// f1c  0x00418900  size=57
int __thiscall sub_418900(_DWORD *this)
{
  int result; // eax
  int (__thiscall ***v3)(_DWORD, int); // ecx

  sub_411740(0);
  sub_411740(1);
  result = sub_4150C0(&dword_5EA5E8);
  v3 = (int (__thiscall ***)(_DWORD, int))this[701];
  if ( v3 )
  {
    result = (**v3)(v3, 1);
    this[701] = 0;
  }
  return result;
}
