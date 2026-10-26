BOOL __thiscall sub_67EFC4(_DWORD *this, int a2)
{
  _DWORD *v2; // edx
  int v3; // ecx

  return sub_67EC87(this, a2)
      && *(_DWORD *)(v3 + 16) == v2[4]
      && *(_DWORD *)(v3 + 20) == v2[5]
      && *(_DWORD *)(v3 + 24) == v2[6]
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(v3 + 28), v2[7]) != 0;
}
