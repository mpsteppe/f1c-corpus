int *__thiscall sub_4582E0(int *this, _DWORD *a2)
{
  _DWORD *v2; // ebp
  int v3; // esi
  int *v4; // ebx
  int v5; // edi
  int *v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // ecx
  int v11; // [esp+10h] [ebp-8h]

  v2 = a2;
  v3 = 0;
  v4 = this;
  if ( *a2 )
  {
    v5 = a2[1];
    if ( v5 >= 4 )
    {
      UtilityFunction_8020(this);
      v4[1] = v5;
      v6 = (int *)OperatorNewNhMallocWrapper(28 * v5 + 4);
      if ( v6 )
      {
        *v6 = v5;
        v7 = v6 + 1;
      }
      else
      {
        v7 = 0;
      }
      *v4 = (int)v7;
      v11 = 0;
      while ( 1 )
      {
        v8 = StridedArrayElementPointer(v2, v3);
        v9 = v11 + *v4;
        *(_DWORD *)v9 = *(_DWORD *)v8;
        *(_DWORD *)(v9 + 4) = *(_DWORD *)(v8 + 4);
        *(_DWORD *)(v9 + 8) = *(_DWORD *)(v8 + 8);
        *(_DWORD *)(v9 + 12) = *(_DWORD *)(v8 + 12);
        *(_DWORD *)(v9 + 16) = *(_DWORD *)(v8 + 16);
        *(_DWORD *)(v9 + 20) = *(_DWORD *)(v8 + 20);
        v4 = this;
        *(float *)(v9 + 24) = *(float *)(v8 + 24);
        ++v3;
        v11 += 28;
        if ( v3 >= v5 )
          break;
        v2 = a2;
      }
      sub_457EE0((float *)this);
    }
  }
  return v4;
}

