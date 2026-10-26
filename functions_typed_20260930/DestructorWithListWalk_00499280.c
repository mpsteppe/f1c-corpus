int __thiscall sub_499280(void *this)
{
  _DWORD *v2; // esi
  int v3; // eax
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v2 = (_DWORD *)*((_DWORD *)this + 17);
  for ( *(_DWORD *)this = &off_5ACA74; v2; *((_DWORD *)this + 17) = v2 )
  {
    v3 = StructFieldAccessor(v2);
    v4 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 17);
    v2 = (_DWORD *)v3;
    if ( v4 )
      (**v4)(v4, 1);
  }
  if ( *((_DWORD *)this + 24) )
    FreeWrapper_7bcf(*((LPVOID *)this + 24));
  if ( *((_DWORD *)this + 22) )
    FreeWrapper_7bcf(*((LPVOID *)this + 22));
  return ShortComputation_a990(this);
}

