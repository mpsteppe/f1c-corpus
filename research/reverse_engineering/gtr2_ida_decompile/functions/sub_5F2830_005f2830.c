int __thiscall sub_5F2830(int this, int a2)
{
  int result; // eax

  result = *(_DWORD *)(this + 9432);
  if ( !result )
    return (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(this + 9548) + 84))(
             *(_DWORD *)(this + 9548),
             0,
             0,
             a2);
  return result;
}
