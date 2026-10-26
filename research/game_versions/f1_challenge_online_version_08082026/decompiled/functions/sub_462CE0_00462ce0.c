char __thiscall sub_462CE0(void *this, int a2, int a3)
{
  char result; // al

  if ( sub_57A580(*(_DWORD *)(*(_DWORD *)this + 16312), a2, a3) )
    return 0;
  result = 1;
  *(_BYTE *)(*(_DWORD *)this + 41) = 1;
  *(float *)(*(_DWORD *)this + 16) = 5.0;
  *(_DWORD *)(*(_DWORD *)this + 16324) = 4;
  return result;
}
