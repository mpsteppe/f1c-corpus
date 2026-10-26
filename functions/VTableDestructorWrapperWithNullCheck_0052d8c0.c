// attributes: thunk
char __thiscall VTableDestructorWrapperWithNullCheck(_DWORD *this)
{
  return VirtualCleanup(this);
}
