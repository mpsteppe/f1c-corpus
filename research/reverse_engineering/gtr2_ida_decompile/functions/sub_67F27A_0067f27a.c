BOOL __thiscall sub_67F27A(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // ecx

  return sub_67EC87(this, a2)
      && *(_DWORD *)(v3 + 20) == *(_DWORD *)(v2 + 20)
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(v3 + 16), *(_DWORD *)(v2 + 16)) != 0;
}
