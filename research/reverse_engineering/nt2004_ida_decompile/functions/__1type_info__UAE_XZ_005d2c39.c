void __thiscall type_info::~type_info(type_info *this)
{
  void *v2; // esi

  *(_DWORD *)this = &type_info::`vftable';
  _lock(27);
  v2 = (void *)*((_DWORD *)this + 1);
  if ( v2 )
    sub_5C1B88(v2);
  _unlock(27);
}
