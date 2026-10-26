void __thiscall sub_4DCCC0(int *this, char *Source)
{
  _DWORD *v3; // ecx
  int v4; // [esp+0h] [ebp-154h]
  char Destination[64]; // [esp+14h] [ebp-140h] BYREF
  char v6[64]; // [esp+54h] [ebp-100h] BYREF
  char Buffer[192]; // [esp+94h] [ebp-C0h] BYREF

  if ( this[14] != 3 )
  {
    if ( Source && !*(_DWORD *)(*this + 16584) )
    {
      if ( sub_41F230(dword_62A170, aDisqualified, ::Destination) )
      {
        strncpy(::Destination, aDisqualified, 0x1FFu);
        byte_62A37B = 0;
      }
      strncpy(Destination, ::Destination, 0x3Fu);
      Destination[63] = 0;
      if ( sub_41F230(dword_62A170, Source, ::Destination) )
      {
        strncpy(::Destination, Source, 0x1FFu);
        byte_62A37B = 0;
      }
      strncpy(v6, ::Destination, 0x3Fu);
      v6[63] = 0;
      sprintf(Buffer, "%s %s", Destination, v6);
      sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
    }
    sub_4F81A0(*this);
    if ( dword_79FC40 >= 1023 )
    {
      v3 = (_DWORD *)dword_7D3C44;
    }
    else
    {
      ++dword_79FC40;
      v3 = (_DWORD *)dword_7D3C44;
      dword_7D3C44 += 208;
    }
    *(float *)&v4 = dbl_7DA9D0;
    sub_4D0D00(v3, 4, 28, 0, this[1], v4, 0);
    sub_41B5B0(*this, (int)Source);
  }
}
