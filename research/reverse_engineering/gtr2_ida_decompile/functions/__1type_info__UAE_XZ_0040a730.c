void __thiscall type_info::~type_info(type_info *this)
{
  void *v1; // ecx

  *(_DWORD *)this = &off_6F1E0C;
  v1 = (void *)*((_DWORD *)this + 1);
  if ( v1 )
    j_j__free(v1);
}
