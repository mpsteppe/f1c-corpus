char __thiscall sub_4B44A0(_DWORD *this, int a2)
{
  this[1] = ResourceLookupDispatcher(a2);
  FileWriteWithBackendDispatch(this, 4);
  FileWriteWithBackendDispatch(this + 2, 2);
  return 1;
}

