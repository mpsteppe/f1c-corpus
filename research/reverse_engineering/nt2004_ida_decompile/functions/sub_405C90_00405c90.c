void *sub_405C90()
{
  if ( (byte_6291C8 & 1) == 0 )
  {
    byte_6291C8 |= 1u;
    sub_407860(&unk_629128);
    atexit(unknown_libname_3);
  }
  return &unk_629128;
}
