int __thiscall sub_57A620(int *this)
{
  if ( this[4] )
    return sub_5369D0(*this, 0, 1);
  else
    return ftell((FILE *)*this);
}
