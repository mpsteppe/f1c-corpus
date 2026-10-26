BOOL __thiscall sub_67F64D(int this, int *a2)
{
  return sub_67EC87((_DWORD *)this, (int)a2)
      && *(_DWORD *)(this + 20) == a2[5]
      && *(_DWORD *)(this + 24) == a2[6]
      && *(_DWORD *)(this + 28) == a2[7]
      && *(_DWORD *)(this + 40) == a2[10]
      && sub_67EE40(a2 + 12, (_DWORD *)(this + 48))
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 16), a2[4])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 32), a2[8])
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 36), a2[9]);
}
