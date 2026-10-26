int __fastcall sub_563260(_DWORD *a1, const char *a2, int a3, int a4, int a5)
{
  int v6; // ebp
  int v7; // edi
  int result; // eax
  int *v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // eax

  inet_addr(a2);
  v6 = a3;
  v7 = sub_5631A0(a1, a3);
  if ( *a1 )
  {
    if ( v7 == -1 )
    {
      sub_5633D0(v6, a1[28], a5);
      if ( *a1 == 1 || *a1 == 2 )
      {
        ++a1[38];
        return 0;
      }
    }
    else
    {
      v9 = (int *)sub_5648B0(a1[1], v7);
      v10 = a1[28];
      v11 = *v9;
      a3 = v11;
      if ( v7 < v10 )
      {
        *(_DWORD *)(v11 + 8) = a5;
        *(_WORD *)(a3 + 6) = 9999;
        v12 = sub_563230((int)a1, a3);
        if ( v12 != -1 )
          *(_DWORD *)(a1[2] + 28 * v12 + 4) = 0;
        sub_5648D0(a1[28]);
        sub_564990(a1[1], v7);
        --a1[28];
      }
    }
  }
  else
  {
    result = sub_562D20(a1);
    if ( result )
      return result;
    if ( v7 == -1 )
    {
      sub_563160(a1, v6, a5);
    }
    else
    {
      a3 = *(_DWORD *)sub_5648B0(a1[1], v7);
      *(_DWORD *)(a3 + 8) = a5;
      *(_WORD *)(a3 + 6) = 9999;
      sub_564990(a1[1], v7);
      sub_5648C0(a1[1], &a3);
    }
    a1[28] = sub_563E70(a1[1]) - 1;
    a1[29] = 0;
    sub_562FE0((int)a1, 3);
    if ( !a4 )
    {
      sub_563000(a1);
      return 0;
    }
  }
  return 0;
}
