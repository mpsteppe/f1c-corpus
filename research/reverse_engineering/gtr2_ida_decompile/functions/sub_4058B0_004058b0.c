_DWORD *__thiscall sub_4058B0(int this, _DWORD *a2, float a3)
{
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  _DWORD *result; // eax
  _DWORD *v8; // ecx
  double v9; // [esp+0h] [ebp-14h]

  v4 = *(_DWORD *)this;
  if ( !*(_DWORD *)this )
    return a2;
  v5 = *(_DWORD *)(this + 8);
  if ( a3 > (double)*(float *)(16 * (v4 >> 1) + v5 + 12) )
    v6 = sub_405170(v4 >> 1, v4, a3, (_DWORD *)this);
  else
    v6 = sub_405170(0, v4 >> 1, a3, (_DWORD *)this);
  if ( v6 == -1 || v6 + 1 > v4 - 1 )
  {
    result = a2;
    v8 = (_DWORD *)(16 * v4 + v5 - 16);
    *a2 = *v8;
    a2[1] = v8[1];
    a2[2] = v8[2];
  }
  else
  {
    v9 = (a3 - *(float *)(16 * v6 + *(_DWORD *)(this + 8) + 12))
       / (*(float *)(*(_DWORD *)(this + 8) + 16 * v6 + 28) - *(float *)(*(_DWORD *)(this + 8) + 16 * v6 + 12));
    (*(void (__stdcall **)(_DWORD *, int, _DWORD, _DWORD))(**(_DWORD **)(this + 12) + 4))(
      a2,
      v6,
      LODWORD(v9),
      HIDWORD(v9));
    return a2;
  }
  return result;
}
