bool __thiscall sub_566D70(int *this)
{
  if ( this[4] )
    return AudioStreamBufferRead(*this, 0, 2) == 0;
  else
    return sub_587F64(*this, 0, 2) == 0;
}

