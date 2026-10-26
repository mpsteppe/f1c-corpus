int __thiscall sub_4054A0(int this)
{
  StructInitWithVTableDispatchAndZeroFill();
  if ( *(_DWORD *)(this + 12) )
  {
    FileCloseWithLock(*(_DWORD *)(this + 12));
    *(_DWORD *)(this + 12) = 0;
  }
  if ( *(_DWORD *)(this + 24) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 24));
  return CameraViewStructInitializer((_DWORD *)this);
}

