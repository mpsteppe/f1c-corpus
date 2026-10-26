char __thiscall sub_582310(int this)
{
  int v2; // eax

  LOBYTE(v2) = *(_BYTE *)(this + 24);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 16));
    if ( v2 )
      *(_DWORD *)(this + 16) = 0;
  }
  return v2;
}

