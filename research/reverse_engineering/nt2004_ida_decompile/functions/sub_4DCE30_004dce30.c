void __thiscall sub_4DCE30(_DWORD *this)
{
  int v1; // eax

  if ( dword_75CBB0 != 7 )
  {
    v1 = *this;
    if ( *(_BYTE *)(*this + 17412) )
    {
      if ( this[29] == 2 )
      {
        this[29] = 1;
        if ( (unsigned __int8)sub_4EED40(v1) )
        {
          if ( sub_41F230(dword_62A170, aLapTimeWillNot, Destination) )
          {
            strncpy(Destination, aLapTimeWillNot, 0x1FFu);
            byte_62A37B = 0;
          }
          sub_45D100(&byte_764D68, (int)Destination, 3, 16909060, 0);
        }
      }
    }
  }
}
