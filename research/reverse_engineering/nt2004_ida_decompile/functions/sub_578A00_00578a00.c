bool __thiscall sub_578A00(int *this)
{
  int v1; // ecx
  _DWORD *v2; // eax
  bool v3; // zf

  v1 = *this;
  v2 = *(_DWORD **)v1;
  v3 = *(_DWORD *)v1 == 0;
  *(_DWORD *)(v1 + 8) = *(_DWORD *)v1;
  return !v3 && *v2;
}
