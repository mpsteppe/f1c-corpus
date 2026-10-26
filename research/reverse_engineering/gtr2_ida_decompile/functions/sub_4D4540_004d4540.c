int __usercall sub_4D4540@<eax>(int *a1@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  int v5; // edx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // ecx
  const CHAR *v13; // eax
  const CHAR *v14; // edi
  const CHAR *v15; // edx
  const CHAR *v16; // ecx
  int v17; // [esp+24h] [ebp-8h] BYREF
  int v18; // [esp+28h] [ebp-4h] BYREF

  if ( *((_BYTE *)a1 + 100) )
    return 0;
  sub_4DE540(&v18, &v17);
  v5 = *a1;
  *((_BYTE *)a1 + 548) = 0;
  *((_BYTE *)a1 + 549) = 0;
  *((_BYTE *)a1 + 550) = 0;
  if ( (*(int (__thiscall **)(int *, int))(v5 + 12))(a1, a3) <= 0 )
    v6 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
  else
    v6 = a1[4];
  v7 = (*(int (__thiscall **)(int *))(*a1 + 4))(a1);
  if ( v18 > v7 && v18 <= v6 )
  {
    v8 = (*(int (__thiscall **)(int *))(*a1 + 8))(a1);
    if ( v17 >= v8 )
    {
      v9 = (*(int (__thiscall **)(int *))(*a1 + 16))(a1);
      if ( v17 >= v9 )
      {
        *((_BYTE *)a1 + 549) = 1;
        sub_4D3E00(a1);
      }
      else if ( a1[143] )
      {
        v10 = a1[140] + (*(int (__thiscall **)(int *))(*a1 + 8))(a1);
        if ( v17 < v10 )
        {
          sub_4D3E60(a1);
          sub_4CE500();
        }
        else if ( v17 > v10 + a1[143] )
        {
          sub_4D3EE0(a1);
          sub_4CE500();
        }
        else
        {
          *((_BYTE *)a1 + 550) = 1;
        }
      }
    }
    else
    {
      *((_BYTE *)a1 + 548) = 1;
      sub_4D3DA0(a1);
    }
    return off_16C97E8();
  }
  if ( *((_BYTE *)a1 + 268) )
  {
    if ( a1[142] )
    {
      v11 = sub_4D0D20(a1, v17);
      v12 = (_DWORD *)a1[36];
      a1[146] = v11;
      if ( v11 <= 0 )
      {
LABEL_23:
        if ( v12 )
        {
          v13 = (const CHAR *)v12[73];
          if ( !v13 )
            v13 = WindowName;
          v14 = (const CHAR *)v12[69];
          if ( !v14 )
            v14 = WindowName;
          v15 = (const CHAR *)v12[42];
          if ( !v15 )
            v15 = WindowName;
          v16 = (const CHAR *)v12[40];
          if ( !v16 )
            v16 = WindowName;
          (*(void (__thiscall **)(int *, const CHAR *, const CHAR *, const CHAR *, const CHAR *, int))(*a1 + 172))(
            a1,
            v16,
            v15,
            v14,
            v13,
            a2);
        }
      }
      else
      {
        while ( v12 )
        {
          v12 = (_DWORD *)v12[35];
          if ( --v11 <= 0 )
            goto LABEL_23;
        }
      }
    }
    return off_16C97E8();
  }
  (*(void (__thiscall **)(int *, _DWORD))(*a1 + 44))(a1, 0);
  return -1;
}
