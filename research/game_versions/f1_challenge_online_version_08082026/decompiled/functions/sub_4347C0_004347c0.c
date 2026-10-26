char __thiscall sub_4347C0(int this)
{
  char result; // al

  result = *(_BYTE *)(this + 2);
  if ( !result )
  {
    sub_4D8760(-1, 0);
    sub_4D8760(1, 1);
    if ( dword_5EB10C )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
    sub_4186A0(flt_5EA618);
    result = sub_40D1B0((int)&dword_5EA510, *(_DWORD *)(this + 8), 1);
    *(_BYTE *)(this + 2) = 1;
  }
  return result;
}
