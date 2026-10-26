int __stdcall sub_504DC0(int a1, int a2, int a3, float a4, float a5)
{
  int v5; // esi
  char Destination[12]; // [esp+8h] [ebp-Ch] BYREF

  v5 = 16776960;
  if ( a1 == -1 )
  {
    if ( sub_41F230(dword_62A170, aR_0, ::Destination) )
    {
      strncpy(::Destination, aR_0, 0x1FFu);
      byte_62A37B = 0;
    }
LABEL_4:
    strncpy(Destination, ::Destination, 9u);
    Destination[9] = 0;
    goto LABEL_10;
  }
  if ( !a1 )
  {
    if ( sub_41F230(dword_62A170, aN, ::Destination) )
    {
      strncpy(::Destination, aN, 0x1FFu);
      byte_62A37B = 0;
    }
    goto LABEL_4;
  }
  sprintf(Destination, "%d", a1);
LABEL_10:
  if ( sub_4B2D40() >= 3 )
    v5 = 16711680;
  return sub_501610((int)Destination, a2, a3, v5, 3, 0, a4, a5);
}
