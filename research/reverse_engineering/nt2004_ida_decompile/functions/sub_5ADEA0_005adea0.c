int __thiscall sub_5ADEA0(int this)
{
  _DWORD *v2; // esi
  int v3; // esi
  void **v4; // ebp
  int result; // eax

  v2 = (_DWORD *)(this + 4);
  sub_592C40(*(char **)(this + 88));
  *v2 = 0;
  v3 = *(_DWORD *)(this + 16);
  *(_DWORD *)(this + 88) = 0;
  *(_BYTE *)(this + 24) = 0;
  while ( v3 )
  {
    v4 = (void **)v3;
    v3 = *(_DWORD *)(v3 + 52);
    sub_5ADE10(v4);
    sub_5BE8AE();
  }
  result = sub_5BE8AE();
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 16) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  return result;
}
