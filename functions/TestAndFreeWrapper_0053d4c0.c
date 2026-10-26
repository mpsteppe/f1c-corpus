int __thiscall sub_53D4C0(void **this)
{
  if ( GlobalResourceCleanup(*this) )
    return -1;
  if ( *this )
    FreeWrapper_7bcf(*this);
  return 0;
}
