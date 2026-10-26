void __thiscall sub_663D19(int this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = *(void (__thiscall ****)(_DWORD, int))(this + 8);
  if ( v2 )
    (**v2)(v2, 1);
  j__free(*(void **)(this + 24));
  j__free(*(void **)(this + 136));
  j__free(*(void **)(this + 144));
  j__free(*(void **)(this + 152));
}
