int __thiscall sub_44E8B0(int this)
{
  int v2; // eax
  int result; // eax

  if ( *(_DWORD *)this )
  {
    sub_5BE8AE(*(LPVOID *)this);
    *(_DWORD *)this = 0;
  }
  v2 = *(_DWORD *)(this + 4);
  if ( v2 )
  {
    sub_5BE8AE((LPVOID)(v2 - 4));
    *(_DWORD *)(this + 4) = 0;
  }
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 24) = 0;
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 20) = 0;
  result = 0;
  memset((void *)(this + 40), 0, 0x1000u);
  return result;
}
