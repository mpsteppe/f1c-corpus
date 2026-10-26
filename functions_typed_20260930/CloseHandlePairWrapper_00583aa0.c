char __thiscall sub_583AA0(int this)
{
  int v2; // eax

  if ( *(_BYTE *)(this + 36) && CloseHandle(*(HANDLE *)(this + 28)) )
    *(_DWORD *)(this + 28) = 0;
  LOBYTE(v2) = *(_BYTE *)(this + 20);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 12));
    if ( v2 )
      *(_DWORD *)(this + 12) = 0;
  }
  return v2;
}

