bool __thiscall sub_5D1330(int *this, int a2, float *a3, float *a4, _DWORD *a5, _DWORD *a6, int *a7)
{
  int v8; // ecx
  _DWORD *v9; // eax

  v8 = *(_DWORD *)(*(_DWORD *)(this[1] + 320) + 8 * a2 + 4);
  return v8
      && (v9 = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 12))(v8)) != 0
      && sub_5C32E0(v9, a3, this[1], a4, a5, a6, a7) != 0;
}
