BOOL __thiscall sub_67F062(int this, _DWORD *a2)
{
  return sub_67EC87((_DWORD *)this, (int)a2)
      && *(_DWORD *)(this + 16) == a2[4]
      && *(_DWORD *)(this + 20) == a2[5]
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 24), a2[6])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 28), a2[7])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 32), a2[8]);
}
