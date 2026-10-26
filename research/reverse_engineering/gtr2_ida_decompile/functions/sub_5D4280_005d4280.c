int __thiscall sub_5D4280(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  int v6; // edi
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // [esp+0h] [ebp-8h]
  _DWORD *v10; // [esp+4h] [ebp-4h]

  result = this[17];
  v10 = this;
  if ( result > 0 )
  {
    v3 = 0;
    v9 = this[17];
    while ( 1 )
    {
      v4 = *(_DWORD *)(a2 + 444);
      v5 = 0;
      if ( v4 > 0 )
      {
        v6 = *(_DWORD *)(this[19] + v3 + 4);
        v7 = *(_DWORD *)(a2 + 452);
        while ( *(_DWORD *)(*(_DWORD *)v7 + 400) != v6 )
        {
          ++v5;
          v7 += 4;
          if ( v5 >= v4 )
            goto LABEL_11;
        }
        v8 = *(_DWORD **)(*(_DWORD *)(a2 + 452) + 4 * v5);
        if ( v8 )
          sub_5D4200(v8);
      }
LABEL_11:
      v3 += 48;
      result = --v9;
      if ( !v9 )
        break;
      this = v10;
    }
  }
  return result;
}
