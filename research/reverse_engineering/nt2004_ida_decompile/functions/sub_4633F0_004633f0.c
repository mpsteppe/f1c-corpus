void __thiscall sub_4633F0(int *this)
{
  int v2; // eax

  v2 = sub_4633A0(this);
  if ( v2 > 0 && v2 <= 3 )
  {
    *(float *)(*this + 648) = *(float *)(*this + 648) - dbl_7DA9C0;
    if ( !sub_56A630(*(_DWORD *)(*this + 6708)) && !*(_BYTE *)(*this + 40) )
    {
      if ( sub_41F230(dword_62A170, aConnectionLost, Destination) )
      {
        strncpy(Destination, aConnectionLost, 0x1FFu);
        byte_62A37B = 0;
      }
      sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
      *(_BYTE *)(*this + 40) = 1;
    }
  }
}
