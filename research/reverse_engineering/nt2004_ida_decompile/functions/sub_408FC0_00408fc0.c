char __thiscall sub_408FC0(int this)
{
  int v2; // eax

  LOBYTE(v2) = *(_BYTE *)(this + 12);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 4));
    if ( v2 )
      *(_DWORD *)(this + 4) = 0;
  }
  return v2;
}
