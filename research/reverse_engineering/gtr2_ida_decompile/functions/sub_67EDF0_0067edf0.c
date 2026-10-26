BOOL __thiscall sub_67EDF0(int this, int *a2)
{
  return sub_67EC87((_DWORD *)this, (int)a2)
      && *(_DWORD *)(this + 16) == a2[4]
      && *(_DWORD *)(this + 20) == a2[5]
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 8), a2[2])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 12), a2[3]) != 0;
}
