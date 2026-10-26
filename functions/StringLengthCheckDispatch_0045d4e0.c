int __thiscall sub_45D4E0(_BYTE *this)
{
  void *v1; // esi
  int result; // eax

  if ( *this )
  {
    if ( this[1] )
    {
      v1 = off_5E4DFC;
      TickCountComparisonHandleInactivityTimeout(off_5E4DFC);
      return NetworkPacketReceive(v1);
    }
    else
    {
      return NetworkPacketReceive(off_5E4DFC);
    }
  }
  return result;
}
