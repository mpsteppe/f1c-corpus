int __thiscall sub_5F2AE0(int this, int a2, int a3)
{
  int result; // eax

  if ( a2 == 1 )
  {
    result = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 9548) + 176))(
               *(_DWORD *)(this + 9548),
               256,
               a3 + 4);
  }
  else if ( a2 == 2 )
  {
    result = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 9548) + 176))(
               *(_DWORD *)(this + 9548),
               2,
               a3 + 4);
  }
  else
  {
    result = a2 - 4;
    if ( a2 != 4 )
      return result;
    result = (*(int (__stdcall **)(_DWORD, int, int))(**(_DWORD **)(this + 9548) + 176))(
               *(_DWORD *)(this + 9548),
               3,
               a3 + 4);
  }
  *(_DWORD *)(this + 8) = result;
  return result;
}
