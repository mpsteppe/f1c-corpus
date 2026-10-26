void __thiscall sub_5873A0(char *this, int a2, unsigned int a3, char *String2)
{
  double *v4; // esi
  double *v5; // ebx
  double *v6; // ebp

  v4 = (double *)&this[24 * a3];
  v5 = v4 + 2;
  v6 = v4 + 1;
  if ( sub_6136D0(String2, (int)v4, (int)(v4 + 1), (int)(v4 + 2), 0) && a3 <= dword_16C99F4 )
  {
    switch ( a3 )
    {
      case 0u:
        if ( *v4 > 0.0 && dword_B640C0 != dword_16C99F4 )
        {
          if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 386) )
            sub_561210((int)byte_FAE910, "+x force applied when moving in +x direction");
        }
        break;
      case 1u:
        if ( *v4 < 0.0
          && dword_B640C0 != dword_16C99F4
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 391) )
        {
          sub_561210((int)byte_FAE910, "-x force applied when moving in -x direction");
        }
        break;
      case 2u:
        if ( *v6 > 0.0
          && dword_B640C0 != dword_16C99F4
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 396) )
        {
          sub_561210((int)byte_FAE910, "+y force applied when moving in +y direction");
        }
        break;
      case 3u:
        if ( *v6 < 0.0
          && dword_B640C0 != dword_16C99F4
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 401) )
        {
          sub_561210((int)byte_FAE910, "-y force applied when moving in -y direction");
        }
        break;
      case 4u:
        if ( *v5 > 0.0
          && dword_B640C0 != dword_16C99F4
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 406) )
        {
          sub_561210((int)byte_FAE910, "+z force applied when moving in +z direction");
        }
        break;
      case 5u:
        if ( *v5 < 0.0
          && dword_B640C0 != dword_16C99F4
          && sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vehload.cpp", 411) )
        {
          sub_561210((int)byte_FAE910, "-z force applied when moving in -z direction");
        }
        break;
    }
  }
}
