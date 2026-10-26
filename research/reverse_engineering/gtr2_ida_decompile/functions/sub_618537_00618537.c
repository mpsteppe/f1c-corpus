// positive sp value has been detected, the output may be wrong!
void __thiscall sub_618537(void **this)
{
  *this = &off_72EBB0;
  if ( --dword_FB414C <= 0 )
  {
    if ( Block )
      j__free(Block);
    Block = 0;
  }
  if ( this[4] )
    j__free(this[4]);
  *this = &off_72EB94;
}
