BOOL __thiscall sub_67F9AB(int this, int a2)
{
  return sub_67EC87((_DWORD *)this, a2)
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 16), *(_DWORD *)(a2 + 16))
      && sub_67ECA2(*(int (__thiscall ****)(_DWORD, int))(this + 20), *(_DWORD *)(a2 + 20));
}
