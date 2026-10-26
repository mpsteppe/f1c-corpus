int __thiscall sub_55FE30(int this)
{
  if ( *(_DWORD *)(this + 16) )
  {
    FileCloseWithLock(*(_DWORD *)(this + 16));
    *(_DWORD *)(this + 16) = 0;
  }
  if ( *(_DWORD *)(this + 296) )
  {
    FreeWrapper_7bcf(*(LPVOID *)(this + 296));
    *(_DWORD *)(this + 296) = 0;
  }
  return 0;
}
