int __thiscall sub_491EE0(_DWORD *this)
{
  *this = sub_534B00(this + 3, aRb);
  if ( *((_BYTE *)this + 410) )
    this[1] = sub_587DB0(this + 35, aWt);
  if ( !this[1] && *((_BYTE *)this + 410) )
    *((_BYTE *)this + 410) = 0;
  if ( *this )
    AudioStreamBufferRead(0);
  if ( *((_BYTE *)this + 410) )
    sub_587F64(this[1], 0, 0);
  return 0;
}
