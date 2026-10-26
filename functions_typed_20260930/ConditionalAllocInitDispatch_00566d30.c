bool __thiscall sub_566D30(int *this)
{
  if ( this[4] )
    return AudioStreamBufferRead(*this, 0, 0) == 0;
  else
    return sub_587F64(*this, 0, 0) == 0;
}

