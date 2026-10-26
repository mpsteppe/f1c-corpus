int __thiscall sub_59BFA0(void *this)
{
  bool v1; // zf
  int result; // eax

  v1 = *((_DWORD *)this + 2) == 0;
  *(_DWORD *)this = &exception::`vftable';
  if ( !v1 )
    return FreeWrapper_7bcf(*((LPVOID *)this + 1));
  return result;
}

