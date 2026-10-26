int __thiscall sub_5404F0(_BYTE *this)
{
  char v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\sound.cpp", 831) )
    sub_561210((int)byte_FAE910, "Entered Sound::Exit()", v3);
  sub_4EE0C0(dword_B6F1C8);
  if ( dword_BE1D10 )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_BE1D10 + 12))(dword_BE1D10);
  this[16] = 0;
  return sub_53FFE0();
}
