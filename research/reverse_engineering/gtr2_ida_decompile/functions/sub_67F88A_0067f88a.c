BOOL __thiscall sub_67F88A(int this, int *a2)
{
  return sub_67EC87((_DWORD *)this, (int)a2)
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 16), a2[4])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 20), a2[5])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 24), a2[6]);
}
