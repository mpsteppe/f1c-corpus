int __thiscall sub_5F3060(int this, int a2)
{
  int result; // eax

  result = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 9548) + 172))(
             *(_DWORD *)(this + 9548),
             0,
             0,
             1,
             *(_DWORD *)(*(_DWORD *)(a2 + 272) + 140),
             0,
             0);
  *(_DWORD *)(this + 8) = result;
  return result;
}
