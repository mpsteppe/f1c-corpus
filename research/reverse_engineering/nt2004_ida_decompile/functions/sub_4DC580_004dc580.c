void __thiscall sub_4DC580(void *this, char *Source)
{
  char Destination[64]; // [esp+8h] [ebp-140h] BYREF
  char v3[64]; // [esp+48h] [ebp-100h] BYREF
  char Buffer[192]; // [esp+88h] [ebp-C0h] BYREF

  if ( Source && !*(_DWORD *)(*(_DWORD *)this + 16584) )
  {
    if ( sub_41F230(dword_62A170, aWarning_0, ::Destination) )
    {
      strncpy(::Destination, aWarning_0, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(Destination, ::Destination, 0x3Fu);
    Destination[63] = 0;
    if ( sub_41F230(dword_62A170, Source, ::Destination) )
    {
      strncpy(::Destination, Source, 0x1FFu);
      byte_62A37B = 0;
    }
    strncpy(v3, ::Destination, 0x3Fu);
    v3[63] = 0;
    sprintf(Buffer, "%s %s", Destination, v3);
    sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
    sub_41B4E0(Source);
  }
}
