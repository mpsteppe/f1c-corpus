int __thiscall sub_5BD020(void *this)
{
  int result; // eax

  if ( this )
    return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 16))(this, 1);
  return result;
}
