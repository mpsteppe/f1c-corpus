int __thiscall sub_4DC3F0(int this)
{
  void *v2; // eax
  int result; // eax

  if ( *(_DWORD *)(this + 160) )
  {
    sub_5BE8AE(*(LPVOID *)(this + 160));
    *(_DWORD *)(this + 160) = 0;
  }
  v2 = *(void **)(this + 164);
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 156) = 0;
  if ( v2 )
  {
    sub_5BE8AE(v2);
    *(_DWORD *)(this + 164) = 0;
  }
  if ( *(_DWORD *)(this + 168) )
  {
    sub_5BE8AE(*(LPVOID *)(this + 168));
    *(_DWORD *)(this + 168) = 0;
  }
  result = -1;
  memset((void *)(this + 332), 0xFFu, 0x28u);
  return result;
}
