char __thiscall sub_577660(int this, int a2)
{
  unsigned int v3; // eax
  void *v4; // ebp
  void *v6; // [esp+8h] [ebp-4h] BYREF

  v3 = a2 + *(_DWORD *)(this + 4);
  v6 = 0;
  if ( sub_577560(v3, &v6) )
  {
    v4 = v6;
    qmemcpy(v6, *(const void **)this, *(_DWORD *)(this + 8));
    sub_5BE8AE();
    *(_DWORD *)this = v4;
  }
  return 0;
}
