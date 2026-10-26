int __thiscall sub_4992E0(_DWORD *this, int a2, char a3)
{
  int result; // eax
  int v4; // eax
  _DWORD *v5; // edx
  int v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // ebx
  int v10; // eax

  result = a2;
  if ( a2 )
  {
    this[19] = a2;
    if ( a3 )
    {
      v4 = *(_DWORD *)(a2 + 12);
      v5 = (_DWORD *)this[20];
      v6 = *(_DWORD *)(v4 + 28);
      v7 = *(_DWORD *)(v4 + 32);
      v8 = v5[4] - v5[3];
      if ( v8 <= 0 )
        v9 = 0;
      else
        v9 = v8 + 1;
      if ( v5[2] - v5[1] <= 0 )
        v10 = 0;
      else
        v10 = v5[2] - v5[1] + 1;
      return ScrollOffsetUpdateWithConditionalDispatch(v9 / 2 - this[3] - v6 / 2, v10 / 2 - this[1] - v7 / 2);
    }
  }
  return result;
}

