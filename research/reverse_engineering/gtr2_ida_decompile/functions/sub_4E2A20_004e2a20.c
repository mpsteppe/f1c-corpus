int __thiscall sub_4E2A20(void *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  bool v3; // zf
  int result; // eax

  while ( *(_DWORD *)this )
  {
    v2 = *(int (__thiscall ****)(_DWORD, int))this;
    v3 = *(_DWORD *)this == 0;
    result = *(_DWORD *)(*(_DWORD *)this + 104);
    *(_DWORD *)this = result;
    if ( !v3 )
      result = (**v2)(v2, 1);
  }
  return result;
}
