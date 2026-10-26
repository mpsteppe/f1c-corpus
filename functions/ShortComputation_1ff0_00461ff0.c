int __thiscall sub_461FF0(void *this)
{
  if ( VehicleStateQueryAtLargeOffset(this) )
    return 0;
  else
    return SingleDelegationCall(*(_DWORD *)(*(_DWORD *)this + 112540));
}
