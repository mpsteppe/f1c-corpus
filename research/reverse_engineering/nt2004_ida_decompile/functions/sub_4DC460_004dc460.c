void __thiscall sub_4DC460(float *this, char *Source, float a3)
{
  char Destination[64]; // [esp+Ch] [ebp-140h] BYREF
  char v5[64]; // [esp+4Ch] [ebp-100h] BYREF
  char Buffer[192]; // [esp+8Ch] [ebp-C0h] BYREF

  if ( Source && !*(_DWORD *)(*(_DWORD *)this + 16584) )
  {
    if ( sub_41F230(dword_62A170, aPenalty, ::Destination) )
    {
      strncpy(::Destination, aPenalty, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(Destination, ::Destination, 0x3Fu);
    Destination[63] = 0;
    if ( sub_41F230(dword_62A170, Source, ::Destination) )
    {
      strncpy(::Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(v5, ::Destination, 0x3Fu);
    v5[63] = 0;
    sprintf(Buffer, "%s %s", Destination, v5);
    sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
  }
  this[46] = a3 + this[46];
}
