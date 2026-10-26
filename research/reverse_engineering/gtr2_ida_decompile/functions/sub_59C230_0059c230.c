bool __thiscall sub_59C230(int this, _DWORD *a2)
{
  return *(_DWORD *)(this + 4) == a2[1] && *(_WORD *)(this + 2) == HIWORD(*a2)
      || *(_DWORD *)(this + 20) == a2[1] && *(_WORD *)(this + 18) == HIWORD(*a2);
}
