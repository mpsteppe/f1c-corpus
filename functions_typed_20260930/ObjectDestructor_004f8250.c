int __stdcall sub_4F8250(_DWORD *a1)
{
  int result; // eax

  if ( *a1 )
  {
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*a1 + 8))(*a1);
    result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a1 + 24))(*a1);
    if ( *a1 )
      result = (**(int (__thiscall ***)(_DWORD, int))*a1)(*a1, 1);
    *a1 = 0;
  }
  return result;
}

