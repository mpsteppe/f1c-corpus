void __thiscall sub_63160F(void *this)
{
  bool v1; // zf

  v1 = *((_DWORD *)this + 2) == 0;
  *(_DWORD *)this = &off_730210;
  if ( !v1 )
    free(*((void **)this + 1));
}
