int __thiscall sub_46DD10(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int result; // eax
  int *v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  _DWORD *v10; // eax
  _DWORD *v11; // edi

  v3 = 0;
  result = 1;
  if ( a2 && a3 >= 4 )
  {
    sub_46C4A0((char **)this);
    *(_DWORD *)(this + 4) = a3;
    v6 = (int *)operator new(28 * a3 + 4);
    if ( v6 )
    {
      v3 = v6 + 1;
      *v6 = a3;
      sub_630A11(v6 + 1, 28, a3, sub_58C1C0, nullsub_7);
    }
    v7 = *(_DWORD *)(this + 4);
    v8 = 0;
    *(_DWORD *)this = v3;
    if ( v7 > 0 )
    {
      v9 = 0;
      v10 = a2;
      do
      {
        v11 = (_DWORD *)(v9 + *(_DWORD *)this);
        *v11 = *v10;
        v11[1] = v10[1];
        v11[2] = v10[2];
        ++v8;
        v10 += 3;
        v9 += 28;
      }
      while ( v8 < *(_DWORD *)(this + 4) );
    }
    sub_46C3C0((_DWORD *)this);
    return 0;
  }
  return result;
}
