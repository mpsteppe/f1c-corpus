int __thiscall sub_457F90(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int *v5; // eax
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // edi

  result = 1;
  if ( a2 && a3 >= 4 )
  {
    UtilityFunction_8020();
    *(_DWORD *)(this + 4) = a3;
    v5 = (int *)OperatorNewNhMallocWrapper(28 * a3 + 4);
    if ( v5 )
    {
      *v5 = a3;
      v6 = v5 + 1;
    }
    else
    {
      v6 = 0;
    }
    *(_DWORD *)this = v6;
    v7 = 0;
    if ( *(int *)(this + 4) > 0 )
    {
      v8 = 0;
      v9 = a2;
      do
      {
        v10 = (_DWORD *)(v8 + *(_DWORD *)this);
        *v10 = *v9;
        v10[1] = v9[1];
        v10[2] = v9[2];
        ++v7;
        v9 += 3;
        v8 += 28;
      }
      while ( v7 < *(_DWORD *)(this + 4) );
    }
    sub_457EE0((float *)this);
    return 0;
  }
  return result;
}
