int __thiscall sub_4F8C70(void *this)
{
  if ( !VFXSetVideoMode )
    return 4;
  VFXSetVideoMode(this);
  return 0;
}
