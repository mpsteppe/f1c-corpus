int __thiscall sub_461CD0(void *this)
{
  if ( *(_DWORD *)(*(_DWORD *)this + 16324) != 4 )
    return *(_DWORD *)(*(_DWORD *)this + 16324);
  if ( SingleDelegationCall_a900(*(_DWORD *)(*(_DWORD *)this + 16312)) == 3 )
    *(_DWORD *)(*(_DWORD *)this + 16324) = 3;
  return *(_DWORD *)(*(_DWORD *)this + 16324);
}
