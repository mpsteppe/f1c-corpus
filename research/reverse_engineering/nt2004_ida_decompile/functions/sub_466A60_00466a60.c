void *sub_466A60()
{
  if ( (byte_764EEC & 1) == 0 )
  {
    byte_764EEC |= 1u;
    sub_468720(&unk_764F18);
    atexit(unknown_libname_35);
  }
  return &unk_764F18;
}
