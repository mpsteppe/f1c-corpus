bool __thiscall sub_57A570(int *this)
{
  if ( this[4] )
    return sub_5369D0(*this, 0, 2) == 0;
  else
    return fseek((FILE *)*this, 0, 2) == 0;
}
