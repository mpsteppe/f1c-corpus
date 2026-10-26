int __thiscall sub_566E20(int *this)
{
  if ( this[4] )
    return AudioStreamBufferRead(*this, 0, 1);
  else
    return FileSizeQueryWrapper(*this);
}

