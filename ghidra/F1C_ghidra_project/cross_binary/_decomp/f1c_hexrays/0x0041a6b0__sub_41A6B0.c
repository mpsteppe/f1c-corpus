// f1c  0x0041a6b0  size=107
void sub_41A6B0()
{
  float v0[8]; // [esp+0h] [ebp-20h] BYREF

  if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
  {
    if ( dword_5EB10C )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
    sub_4186A0(flt_5EA618);
    sub_4144F0(v0, 275, -1, -1, -1, -1, -2.0, -2.0);
    sub_418560(flt_5EA618, v0);
  }
}
