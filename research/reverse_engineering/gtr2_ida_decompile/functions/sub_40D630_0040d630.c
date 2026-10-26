int __thiscall sub_40D630(void *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 24))(this);
  if ( result )
    return (*(int (__thiscall **)(int))(*(_DWORD *)result + 28))(result);
  return result;
}
