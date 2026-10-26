_DWORD *__stdcall sub_675F77(int a1, unsigned __int16 *a2, int a3, int a4)
{
  void *v4; // edi
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // eax
  int *v8; // eax
  _DWORD *v9; // esi

  v4 = 0;
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 8) & 0xFFFF0000;
  if ( *(_WORD *)(a3 + 10) )
  {
    if ( v5 != -131072 )
    {
      if ( v5 != -65536 )
        goto LABEL_75;
      if ( a2[2] )
      {
        v6 = a2[2] - 1;
        if ( a2[2] != 1 )
        {
LABEL_68:
          if ( v6 == 1 )
            v4 = sub_6738DB;
          goto LABEL_75;
        }
        goto LABEL_70;
      }
      goto LABEL_27;
    }
    if ( a2[2] )
    {
      v7 = a2[2] - 1;
      if ( a2[2] != 1 )
      {
LABEL_35:
        if ( v7 == 1 )
          v4 = sub_673C5D;
        goto LABEL_75;
      }
      goto LABEL_45;
    }
    goto LABEL_74;
  }
  if ( v5 != 1415053312 )
  {
    if ( v5 != -131072 )
    {
      if ( v5 != -65536 )
        goto LABEL_75;
      if ( a2[2] )
      {
        if ( a2[2] != 1 )
        {
          if ( a2[2] != 2 )
            goto LABEL_75;
          if ( !*(_WORD *)(a3 + 2) )
          {
            v4 = sub_6738DB;
            goto LABEL_75;
          }
          if ( *(_WORD *)(a3 + 2) == 1 )
          {
            v4 = sub_6738F9;
            goto LABEL_75;
          }
          v6 = *(unsigned __int16 *)(a3 + 2) - 2;
          if ( *(_WORD *)(a3 + 2) == 2 )
          {
            v4 = sub_673943;
            goto LABEL_75;
          }
          goto LABEL_68;
        }
        if ( !*(_WORD *)(a3 + 2) )
        {
          v4 = sub_673813;
          goto LABEL_75;
        }
        if ( *(_WORD *)(a3 + 2) == 1 )
        {
          v4 = sub_673831;
          goto LABEL_75;
        }
        if ( *(_WORD *)(a3 + 2) != 2 )
        {
          if ( *(_WORD *)(a3 + 2) == 3 )
            v4 = sub_673875;
          goto LABEL_75;
        }
LABEL_70:
        v4 = sub_673813;
        goto LABEL_75;
      }
      if ( !*(_WORD *)(a3 + 2) )
      {
        v4 = sub_673D00;
        goto LABEL_75;
      }
      if ( *(_WORD *)(a3 + 2) != 1 )
      {
        if ( *(_WORD *)(a3 + 2) == 2 )
        {
          v4 = sub_673D1E;
        }
        else if ( *(_WORD *)(a3 + 2) == 3 )
        {
          v4 = sub_673D5F;
        }
        goto LABEL_75;
      }
LABEL_27:
      v4 = sub_673D00;
      goto LABEL_75;
    }
    if ( a2[2] )
    {
      if ( a2[2] != 1 )
      {
        if ( a2[2] != 2 )
          goto LABEL_75;
        if ( !*(_WORD *)(a3 + 2) )
        {
          v4 = sub_673C5D;
          goto LABEL_75;
        }
        if ( *(_WORD *)(a3 + 2) == 1 )
        {
          v4 = sub_673C7B;
          goto LABEL_75;
        }
        v7 = *(unsigned __int16 *)(a3 + 2) - 2;
        if ( *(_WORD *)(a3 + 2) == 2 )
        {
          v4 = sub_673CC5;
          goto LABEL_75;
        }
        goto LABEL_35;
      }
      if ( !*(_WORD *)(a3 + 2) )
      {
        v4 = sub_673B95;
        goto LABEL_75;
      }
      if ( *(_WORD *)(a3 + 2) == 1 )
      {
        v4 = sub_673BB3;
        goto LABEL_75;
      }
      if ( *(_WORD *)(a3 + 2) != 2 )
      {
        if ( *(_WORD *)(a3 + 2) == 3 )
          v4 = sub_673BF7;
        goto LABEL_75;
      }
LABEL_45:
      v4 = sub_673B95;
      goto LABEL_75;
    }
    if ( !*(_WORD *)(a3 + 2) )
    {
      v4 = sub_673AE4;
      goto LABEL_75;
    }
    if ( *(_WORD *)(a3 + 2) != 1 )
    {
      if ( *(_WORD *)(a3 + 2) == 2 )
      {
        v4 = sub_673B02;
      }
      else if ( *(_WORD *)(a3 + 2) == 3 )
      {
        v4 = sub_673B43;
      }
      goto LABEL_75;
    }
LABEL_74:
    v4 = sub_673AE4;
    goto LABEL_75;
  }
  if ( a2[2] == 2 )
  {
    if ( *(_WORD *)(a3 + 2) )
    {
      switch ( *(_WORD *)(a3 + 2) )
      {
        case 1:
          v4 = sub_6739BB;
          break;
        case 2:
          v4 = sub_673A1F;
          break;
        case 3:
          v4 = sub_67397E;
          break;
      }
    }
    else
    {
      v4 = sub_67397E;
    }
  }
LABEL_75:
  v8 = (int *)operator new(0x44u);
  if ( v8 )
    v9 = sub_6734BB(v8, a1, a2, a3, (int)v4, a4);
  else
    v9 = 0;
  if ( !v9 )
    return 0;
  if ( sub_67620F(v9) < 0 )
  {
    sub_673A75(v9, 1);
    return 0;
  }
  return v9;
}
