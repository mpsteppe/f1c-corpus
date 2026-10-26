int sub_58FFA0()
{
  switch ( *(_DWORD *)dword_B640C8 )
  {
    case 0:
    case 1:
    case 2:
      sub_5E5B30(64, 0);
      sub_5E5B30(128, 1);
      return sub_5E5B30(256, 1);
    case 3:
    case 4:
      sub_5E5B30(64, 1);
      sub_5E5B30(128, 0);
      return sub_5E5B30(256, 1);
    case 5:
    case 6:
      sub_5E5B30(64, 1);
      sub_5E5B30(128, 1);
      return sub_5E5B30(256, 0);
    default:
      sub_5E5B30(64, 0);
      sub_5E5B30(128, 0);
      return sub_5E5B30(256, 0);
  }
}
