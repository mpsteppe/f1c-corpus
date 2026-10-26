BOOL __thiscall sub_67F389(int this, _DWORD *a2)
{
  return sub_67EC87((_DWORD *)this, (int)a2)
      && *(_DWORD *)(this + 16) == a2[4]
      && *(_DWORD *)(this + 20) == a2[5]
      && *(_DWORD *)(this + 24) == a2[6]
      && *(_DWORD *)(this + 56) == a2[14]
      && *(_DWORD *)(this + 60) == a2[15]
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 28), a2[7])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 32), a2[8])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 36), a2[9])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 40), a2[10])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 44), a2[11])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 48), a2[12])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 52), a2[13]);
}
