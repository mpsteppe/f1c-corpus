void __thiscall sub_5DA690(int this)
{
  void *v1; // esi

  if ( *(_BYTE *)(this + 8) )
  {
    v1 = *(void **)this;
    if ( *(_DWORD *)this )
    {
      sub_5E64B0(*(void **)this);
      j__free(v1);
    }
  }
}
