int __thiscall sub_60CFA0(int this, int a2)
{
  int result; // eax

  result = *(_DWORD *)(a2 + 28);
  if ( result != *(_DWORD *)(this + 9640) )
  {
    *(_DWORD *)(this + 9640) = result;
    result = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 9548) + 416))(
               *(_DWORD *)(this + 9548),
               *(_DWORD *)(a2 + 28));
    *(_DWORD *)(this + 8) = result;
    ++*(_DWORD *)(a2 + 20);
  }
  return result;
}
