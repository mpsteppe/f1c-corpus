int __thiscall ShortComputation(int this)
{
  if ( *(_DWORD *)(this + 336) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 336));
  if ( *(_DWORD *)(this + 340) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 340));
  if ( *(_DWORD *)(this + 344) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 344));
  return ObjectReleaseArrayIterator((_DWORD *)this);
}

