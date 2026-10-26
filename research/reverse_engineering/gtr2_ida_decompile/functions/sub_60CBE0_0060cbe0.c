int __thiscall sub_60CBE0(int this, _DWORD *a2)
{
  int result; // eax
  int v4; // ecx
  int v5; // edi

  result = (int)a2;
  v4 = a2[6];
  v5 = a2[8];
  if ( *(_DWORD *)(this + 4 * v4 + 9608) != v5 )
  {
    *(_DWORD *)(this + 4 * v4 + 9608) = v5;
    result = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 9548) + 400))(
               *(_DWORD *)(this + 9548),
               v4,
               a2[8],
               0,
               a2[5]);
    *(_DWORD *)(this + 8) = result;
  }
  return result;
}
