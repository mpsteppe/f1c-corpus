char __thiscall sub_6442F0(int this, int a2, signed int Size)
{
  void *v4; // eax
  size_t v6; // [esp-10h] [ebp-14h]

  *(_DWORD *)(this + 4) = a2;
  *(_DWORD *)(this + 8) = a2;
  *(_DWORD *)(this + 12) = Size;
  *(_DWORD *)(this + 16) = Size;
  *(_DWORD *)(this + 20) = 1024;
  if ( a2 )
  {
    *(_BYTE *)(this + 24) = 0;
  }
  else
  {
    *(_BYTE *)(this + 24) = 1;
    if ( Size > 0 )
    {
      sub_4F14D0(Size);
      v4 = sub_5A8CE0(v6, 0, 16, 0);
      *(_DWORD *)(this + 4) = v4;
      *(_DWORD *)(this + 8) = v4;
      return 1;
    }
  }
  return 1;
}
