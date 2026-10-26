int __thiscall sub_5D09B0(int this, int a2, float a3)
{
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int result; // eax
  unsigned __int64 v8; // st7

  v4 = *(_DWORD *)this;
  if ( *(_DWORD *)this )
  {
    v5 = *(_DWORD *)(this + 8);
    if ( a3 > (double)*(float *)(v5 + 12 * (v4 >> 1) + 8) )
      v6 = sub_5D06C0(v4 >> 1, v4, a3, (_DWORD *)this);
    else
      v6 = sub_5D06C0(0, v4 >> 1, a3, (_DWORD *)this);
    if ( v6 == -1 )
    {
      sub_5D0760((__int16 *)(v5 + 12 * v4 - 12), (float *)a2);
      return a2;
    }
    else
    {
      if ( v6 + 1 <= v4 - 1 )
      {
        *(double *)&v8 = (a3 - *(float *)(*(_DWORD *)(this + 8) + 12 * v6 + 8))
                       / (*(float *)(*(_DWORD *)(this + 8) + 12 * v6 + 20)
                        - *(float *)(*(_DWORD *)(this + 8) + 12 * v6 + 8));
        (*(void (__thiscall **)(_DWORD, int, int, _DWORD, _DWORD))(**(_DWORD **)(this + 12) + 4))(
          *(_DWORD *)(this + 12),
          a2,
          v6,
          v8,
          HIDWORD(v8));
      }
      else
      {
        sub_5D0760((__int16 *)(v5 + 12 * v4 - 12), (float *)a2);
      }
      return a2;
    }
  }
  else
  {
    result = a2;
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = 0;
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = 1065353216;
  }
  return result;
}
