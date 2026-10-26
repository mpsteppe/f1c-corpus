int *__thiscall sub_47E540(_DWORD *this, int *a2, int a3)
{
  int *v3; // eax
  int *v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  int *v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int *v14; // eax
  char v15; // al
  int v16; // eax
  bool v17; // zf
  int v18; // eax
  int *result; // eax
  int *Block; // [esp+Ch] [ebp-54h]
  void **v21; // [esp+2Ch] [ebp-34h] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  v3 = (int *)a3;
  if ( *(_BYTE *)(a3 + 21) )
  {
    sub_406190();
    retaddr = 0;
    sub_4062A0();
    v21 = &std::out_of_range::`vftable';
    v3 = (int *)sub_63153D(&v21, &_TI3_AVout_of_range_std___0);
  }
  v5 = v3;
  Block = v3;
  sub_476240(&a3);
  if ( *(_BYTE *)(*v5 + 21) )
  {
    v6 = v5[2];
LABEL_8:
    v8 = v5[1];
    if ( !*(_BYTE *)(v6 + 21) )
      *(_DWORD *)(v6 + 4) = v8;
    v9 = this[1];
    if ( *(int **)(v9 + 4) == v5 )
    {
      *(_DWORD *)(v9 + 4) = v6;
    }
    else if ( *(int **)v8 == v5 )
    {
      *(_DWORD *)v8 = v6;
    }
    else
    {
      *(_DWORD *)(v8 + 8) = v6;
    }
    v10 = (int *)this[1];
    if ( (int *)*v10 == Block )
    {
      if ( *(_BYTE *)(v6 + 21) )
        v11 = v8;
      else
        v11 = sub_4898F0(v6);
      *v10 = v11;
    }
    v12 = this[1];
    if ( *(int **)(v12 + 8) == Block )
    {
      if ( *(_BYTE *)(v6 + 21) )
        *(_DWORD *)(v12 + 8) = v8;
      else
        *(_DWORD *)(v12 + 8) = sub_59C2E0(v6);
    }
    goto LABEL_35;
  }
  if ( *(_BYTE *)(v5[2] + 21) )
  {
    v6 = *v5;
    goto LABEL_8;
  }
  v7 = a3;
  v6 = *(_DWORD *)(a3 + 8);
  if ( (int *)a3 == v5 )
    goto LABEL_8;
  *(_DWORD *)(*v5 + 4) = a3;
  *(_DWORD *)v7 = *v5;
  if ( v7 == v5[2] )
  {
    v8 = v7;
  }
  else
  {
    v8 = *(_DWORD *)(v7 + 4);
    if ( !*(_BYTE *)(v6 + 21) )
      *(_DWORD *)(v6 + 4) = v8;
    *(_DWORD *)v8 = v6;
    *(_DWORD *)(v7 + 8) = v5[2];
    *(_DWORD *)(v5[2] + 4) = v7;
  }
  v13 = this[1];
  if ( *(int **)(v13 + 4) == v5 )
  {
    *(_DWORD *)(v13 + 4) = v7;
  }
  else
  {
    v14 = (int *)v5[1];
    if ( (int *)*v14 == v5 )
      *v14 = v7;
    else
      v14[2] = v7;
  }
  *(_DWORD *)(v7 + 4) = v5[1];
  v15 = *(_BYTE *)(v7 + 20);
  *(_BYTE *)(v7 + 20) = *((_BYTE *)v5 + 20);
  *((_BYTE *)v5 + 20) = v15;
LABEL_35:
  if ( *((_BYTE *)Block + 20) == 1 )
  {
    if ( v6 != *(_DWORD *)(this[1] + 4) )
    {
      do
      {
        if ( *(_BYTE *)(v6 + 20) != 1 )
          break;
        v16 = *(_DWORD *)v8;
        if ( v6 == *(_DWORD *)v8 )
        {
          v16 = *(_DWORD *)(v8 + 8);
          if ( !*(_BYTE *)(v16 + 20) )
          {
            *(_BYTE *)(v16 + 20) = 1;
            *(_BYTE *)(v8 + 20) = 0;
            sub_489B20(v8);
            v16 = *(_DWORD *)(v8 + 8);
          }
          if ( *(_BYTE *)(v16 + 21) )
            goto LABEL_53;
          if ( *(_BYTE *)(*(_DWORD *)v16 + 20) != 1 || *(_BYTE *)(*(_DWORD *)(v16 + 8) + 20) != 1 )
          {
            if ( *(_BYTE *)(*(_DWORD *)(v16 + 8) + 20) == 1 )
            {
              *(_BYTE *)(*(_DWORD *)v16 + 20) = 1;
              *(_BYTE *)(v16 + 20) = 0;
              sub_59D4E0(v16);
              v16 = *(_DWORD *)(v8 + 8);
            }
            *(_BYTE *)(v16 + 20) = *(_BYTE *)(v8 + 20);
            *(_BYTE *)(v8 + 20) = 1;
            *(_BYTE *)(*(_DWORD *)(v16 + 8) + 20) = 1;
            sub_489B20(v8);
            break;
          }
        }
        else
        {
          if ( !*(_BYTE *)(v16 + 20) )
          {
            *(_BYTE *)(v16 + 20) = 1;
            *(_BYTE *)(v8 + 20) = 0;
            sub_59D4E0(v8);
            v16 = *(_DWORD *)v8;
          }
          if ( *(_BYTE *)(v16 + 21) )
            goto LABEL_53;
          if ( *(_BYTE *)(*(_DWORD *)(v16 + 8) + 20) != 1 || *(_BYTE *)(*(_DWORD *)v16 + 20) != 1 )
          {
            if ( *(_BYTE *)(*(_DWORD *)v16 + 20) == 1 )
            {
              *(_BYTE *)(*(_DWORD *)(v16 + 8) + 20) = 1;
              *(_BYTE *)(v16 + 20) = 0;
              sub_489B20(v16);
              v16 = *(_DWORD *)v8;
            }
            *(_BYTE *)(v16 + 20) = *(_BYTE *)(v8 + 20);
            *(_BYTE *)(v8 + 20) = 1;
            *(_BYTE *)(*(_DWORD *)v16 + 20) = 1;
            sub_59D4E0(v8);
            break;
          }
        }
        *(_BYTE *)(v16 + 20) = 0;
LABEL_53:
        v6 = v8;
        v17 = v8 == *(_DWORD *)(this[1] + 4);
        v8 = *(_DWORD *)(v8 + 4);
      }
      while ( !v17 );
    }
    *(_BYTE *)(v6 + 20) = 1;
  }
  j__free(Block);
  v18 = this[2];
  if ( v18 )
    this[2] = v18 - 1;
  result = a2;
  *a2 = a3;
  return result;
}
