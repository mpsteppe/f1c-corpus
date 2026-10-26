// f1c  0x004f8c70  size=24
int __thiscall sub_4F8C70(void *this)
{
  if ( !VFXSetVideoMode )
    return 4;
  VFXSetVideoMode(this);
  return 0;
}
