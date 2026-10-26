void __thiscall std::locale::~locale(std::locale::facet **this)
{
  std::locale::facet *v1; // ecx
  struct std::locale::facet *v2; // eax

  v1 = *this;
  if ( v1 )
  {
    v2 = std::locale::facet::_Decref(v1);
    if ( v2 )
      (**(void (__thiscall ***)(struct std::locale::facet *, int))v2)(v2, 1);
  }
}
