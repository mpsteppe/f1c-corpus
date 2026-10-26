// f1c  0x00566cf0  size=52
bool __thiscall sub_566CF0(int *this, const char *a2)
{
  if ( this[4] )
    return sub_5352B0(*this, a2) != -1;
  else
    return sub_58BABB(a2, *this) != -1;
}
