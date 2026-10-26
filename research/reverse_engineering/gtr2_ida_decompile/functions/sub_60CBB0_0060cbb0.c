int __thiscall sub_60CBB0(_DWORD **this, int a2, _DWORD *a3)
{
  int result; // eax

  result = a2;
  if ( this[a2 + 1219] != a3 )
  {
    this[a2 + 1219] = a3;
    return (*(int (__stdcall **)(_DWORD *, int, _DWORD *))(*this[2387] + 228))(this[2387], a2, a3);
  }
  return result;
}
