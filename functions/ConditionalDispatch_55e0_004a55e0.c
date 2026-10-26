int __thiscall sub_4A55E0(_DWORD *this)
{
  if ( this[11] )
    return PitstopStateTransition(this[4]);
  else
    return PitstopStateTransition(this[3]);
}
