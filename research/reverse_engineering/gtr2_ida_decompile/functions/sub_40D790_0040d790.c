char __thiscall sub_40D790(void *this, int a2)
{
  bool v2; // zf
  char result; // al

  if ( !a2 )
    return 0;
  v2 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 28))(this, a2) == 0;
  result = 1;
  if ( v2 )
    return 0;
  return result;
}
