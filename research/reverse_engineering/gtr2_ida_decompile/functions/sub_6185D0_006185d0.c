int __thiscall sub_6185D0(int this, int a2)
{
  void *v3; // eax
  int result; // eax

  v3 = *(void **)(this + 16);
  *(_BYTE *)(this + 8) = 0;
  if ( v3 )
    j__free(v3);
  *(_DWORD *)(this + 16) = operator new(0x400u);
  result = a2;
  *(_DWORD *)(this + 4) = a2;
  *(_DWORD *)(this + 12) = a2;
  return result;
}
