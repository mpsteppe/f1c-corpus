char __thiscall sub_584130(_DWORD *this, int a2, int a3)
{
  char result; // al
  int *v4; // eax
  _DWORD *v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int *v9; // eax
  int v10; // esi
  int *v11; // eax
  int **v12; // edi
  int *v13; // eax
  bool v14; // zf
  int v15; // [esp-18h] [ebp-20h]
  int v16; // [esp-18h] [ebp-20h]

  result = 0;
  if ( a3 != -1 )
  {
    v4 = (int *)this[71];
    v5 = this + 71;
    this[73] = v4;
    if ( !v4 )
      goto LABEL_12;
    v6 = *v4;
    if ( !*v4 )
      goto LABEL_12;
    while ( 1 )
    {
      v7 = sub_587720(v6);
      if ( v7 == a3 || v7 == -1 )
        break;
      v8 = v5[2];
      if ( v8 )
        v5[2] = *(_DWORD *)(v8 + 4);
      v9 = (int *)v5[2];
      if ( v9 )
      {
        v6 = *v9;
        if ( *v9 )
          continue;
      }
      goto LABEL_12;
    }
    if ( !v6 )
    {
LABEL_12:
      v10 = 0;
      v11 = (int *)this[67];
      v12 = (int **)(this + 67);
      this[69] = v11;
      if ( v11 )
      {
        v10 = *v11;
        v15 = *v11;
        *((_BYTE *)v11 + 8) = 0;
        if ( !(unsigned __int8)sub_586670(v15, 1) )
          v10 = 0;
      }
      if ( !v10 )
      {
        sub_586320(this + 63);
        v13 = *v12;
        v14 = *v12 == 0;
        this[69] = this[67];
        if ( !v14 )
        {
          v10 = *v13;
          v16 = *v13;
          *((_BYTE *)v13 + 8) = 0;
          if ( !(unsigned __int8)sub_586670(v16, 1) )
            v10 = 0;
        }
      }
      *(_DWORD *)(v10 + 1044) = this;
      sub_586000(v10, 0);
    }
    sub_587710(a3);
    sub_587730(a2);
    return 1;
  }
  return result;
}
