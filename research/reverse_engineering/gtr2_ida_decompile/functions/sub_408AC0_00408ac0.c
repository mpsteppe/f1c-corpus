int __stdcall sub_408AC0(_DWORD *a1)
{
  int result; // eax

  result = sub_4087A0();
  if ( *a1 )
    result = (**(int (__thiscall ***)(_DWORD, int))*a1)(*a1, 1);
  *a1 = 0;
  return result;
}
