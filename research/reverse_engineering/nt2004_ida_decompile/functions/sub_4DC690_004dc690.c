void __thiscall sub_4DC690(int *this, char *Source, int a3, char a4)
{
  int v5; // esi
  int v6; // [esp+0h] [ebp-158h]
  char Destination[63]; // [esp+18h] [ebp-140h] BYREF
  char v8; // [esp+57h] [ebp-101h]
  char v9[64]; // [esp+58h] [ebp-100h] BYREF
  char Buffer[192]; // [esp+98h] [ebp-C0h] BYREF

  if ( Source && !*(_DWORD *)(*this + 16584) )
  {
    if ( a3 == 2 )
    {
      if ( sub_41F230(dword_62A170, aPassThroughPen, ::Destination) )
      {
        strncpy(::Destination, aPassThroughPen, 0x1FFu);
        byte_62A37B = 0;
      }
      strncpy(Destination, ::Destination, 0x3Fu);
      v8 = 0;
      if ( sub_41F230(dword_62A170, Source, ::Destination) )
      {
        strncpy(::Destination, Source, 0x1FFu);
        byte_62A37B = 0;
      }
    }
    else if ( a3 == 3 )
    {
      if ( sub_41F230(dword_62A170, aStartAtEndOfLo, ::Destination) )
      {
        strncpy(::Destination, aStartAtEndOfLo, 0x1FFu);
        byte_62A37B = 0;
      }
      strncpy(Destination, ::Destination, 0x3Fu);
      v8 = 0;
      if ( sub_41F230(dword_62A170, Source, ::Destination) )
        sub_431E20(::Destination, Source, 0x1FFu);
    }
    else
    {
      if ( sub_41F230(dword_62A170, aStopGoPenalty, ::Destination) )
        sub_431E20(::Destination, aStopGoPenalty, 0x1FFu);
      strncpy(Destination, ::Destination, 0x3Fu);
      v8 = 0;
      if ( sub_41F230(dword_62A170, Source, ::Destination) )
        sub_431E20(::Destination, Source, 0x1FFu);
    }
    strncpy(v9, ::Destination, 0x3Fu);
    v9[63] = 0;
    sprintf(Buffer, "%s %s", Destination, v9);
    sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
  }
  v5 = dword_7D3C44;
  if ( dword_79FC40 < 1023 )
  {
    ++dword_79FC40;
    dword_7D3C44 += 208;
  }
  *(float *)&v6 = dbl_7DA9D0;
  sub_4D0D00((_DWORD *)v5, 4, 23, 2, this[1], v6, 0);
  *(_BYTE *)(v5 + 9) = a4;
  *(_BYTE *)(v5 + 8) = a3;
  sub_41B5B0(*this, (int)Source);
}
