double __thiscall sub_5D0FE0(int this, float a2)
{
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  double result; // st7
  int v7; // ecx
  unsigned __int64 v8; // st5

  v3 = *(_DWORD *)this;
  if ( !*(_DWORD *)this )
    return 0.0;
  v4 = *(_DWORD *)(this + 8);
  if ( a2 > (double)*(float *)(v4 + 8 * (v3 >> 1) + 4) )
    v5 = sub_5C6790(v3 >> 1, v3, a2, (_DWORD *)this);
  else
    v5 = sub_5C6790(0, v3 >> 1, a2, (_DWORD *)this);
  if ( v5 == -1 )
    return (double)*(unsigned __int8 *)(v4 + 8 * v3 - 8) * 0.0039215689;
  if ( v5 + 1 > v3 - 1 )
    return (double)*(unsigned __int8 *)(v4 + 8 * v3 - 8) * 0.0039215689;
  v7 = *(_DWORD *)(this + 8);
  result = *(float *)(v7 + 8 * v5 + 4);
  *(double *)&v8 = (a2 - result) / (*(float *)(v7 + 8 * v5 + 12) - result);
  (*(void (__thiscall **)(_DWORD, int, _DWORD, _DWORD))(**(_DWORD **)(this + 12) + 4))(
    *(_DWORD *)(this + 12),
    v5,
    v8,
    HIDWORD(v8));
  return result;
}
