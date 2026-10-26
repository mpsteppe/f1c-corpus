void __thiscall sub_6189E0(int this)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax

  if ( *(_DWORD *)this )
  {
    j__free(*(void **)this);
    *(_DWORD *)this = 0;
  }
  v2 = *(void **)(this + 564);
  *(_DWORD *)(this + 552) = 0;
  *(_DWORD *)(this + 556) = 0;
  *(_DWORD *)(this + 560) = 0;
  if ( v2 )
  {
    j__free(v2);
    *(_DWORD *)(this + 564) = 0;
  }
  v3 = *(void **)(this + 572);
  *(_DWORD *)(this + 568) = 0;
  if ( v3 )
  {
    j__free(v3);
    *(_DWORD *)(this + 572) = 0;
  }
  v4 = *(void **)(this + 580);
  *(_DWORD *)(this + 576) = 0;
  if ( v4 )
  {
    j__free(v4);
    *(_DWORD *)(this + 580) = 0;
  }
}
