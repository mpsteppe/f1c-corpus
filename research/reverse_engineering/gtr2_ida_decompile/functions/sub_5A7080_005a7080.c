char __thiscall sub_5A7080(int this, const void *a2, int Size)
{
  if ( Size > *(_DWORD *)(this + 4) )
  {
    if ( *(_DWORD *)this )
      j__free(*(void **)this);
    *(_DWORD *)this = operator new(Size);
    *(_DWORD *)(this + 4) = Size;
  }
  if ( *(_DWORD *)this && Size > 0 )
  {
    qmemcpy(*(void **)this, a2, Size);
    *(_DWORD *)(this + 8) = Size;
    return 1;
  }
  else
  {
    *(_DWORD *)(this + 8) = 0;
    return 1;
  }
}
