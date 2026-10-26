int __thiscall sub_409F40(void *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 24))(this);
  if ( result )
    return (*(int (__thiscall **)(int))(*(_DWORD *)result + 28))(result);
  return result;
}
