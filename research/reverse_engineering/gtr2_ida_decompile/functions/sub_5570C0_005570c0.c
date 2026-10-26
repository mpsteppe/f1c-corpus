int *__thiscall sub_5570C0(_DWORD *this, int a2)
{
  _DWORD *v2; // edx
  _DWORD *v3; // esi
  int v4; // edi
  int v5; // ebx
  int *result; // eax
  int v7; // edi

  v2 = (_DWORD *)this[84];
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 == v2 )
  {
LABEL_4:
    v4 = this[84];
    v5 = sub_4055D0();
    sub_557020();
    *(_DWORD *)(v4 + 4) = v5;
    result = *(int **)(v5 + 4);
    *result = v5;
  }
  else
  {
    while ( *(float *)(a2 + 104) >= (double)*(float *)(v3[2] + 104) )
    {
      v3 = (_DWORD *)*v3;
      if ( v3 == v2 )
        goto LABEL_4;
    }
    v7 = sub_4055D0();
    sub_557020();
    v3[1] = v7;
    result = *(int **)(v7 + 4);
    *result = v7;
  }
  return result;
}
