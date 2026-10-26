void __thiscall sub_5609E0(double *this)
{
  void *v2; // eax
  void *v3; // esi

  sub_615860(WindowName);
  v2 = (void *)*((_DWORD *)this + 9);
  this[3] = 0.0;
  *((_DWORD *)this + 8) = 0;
  if ( v2 )
  {
    j_j__free(v2);
    *((_DWORD *)this + 9) = 0;
  }
  v3 = *(void **)this;
  if ( v3 )
    j_j__free(v3);
}
