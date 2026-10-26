int __thiscall sub_5F2D50(void *this, int a2)
{
  int result; // eax

  result = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 440))(this, a2);
  if ( result )
    return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 436))(this, result);
  return result;
}
