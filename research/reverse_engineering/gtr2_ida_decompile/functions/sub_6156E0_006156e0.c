int __fastcall sub_6156E0(int a1, int a2)
{
  int v3; // esi
  int v5; // ecx
  int v6; // edx
  _DWORD *v7; // edi
  bool v8; // zf
  int v9; // ecx
  int v10; // edi
  int v11; // edx

  v3 = 0;
  if ( a2 <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = *(_DWORD *)(a1 + 4 * v3);
    if ( *(double *)(v5 + 8 * v3) == 0.0 )
      break;
LABEL_20:
    v9 = *(_DWORD *)(a1 + 4 * v3);
    if ( *(double *)(v9 + 8 * v3) != 1.0 )
      sub_615570(v9, v3 + 1, 1.0 / *(double *)(v9 + 8 * v3), a2);
    v10 = 0;
    do
    {
      if ( v3 != v10 )
      {
        v11 = *(_DWORD *)(a1 + 4 * v10);
        if ( *(double *)(v11 + 8 * v3) != 0.0 )
          sub_6155E0(*(_DWORD *)(a1 + 4 * v10), *(_DWORD *)(a1 + 4 * v3), -*(double *)(v11 + 8 * v3), v3 + 1, a2);
      }
      ++v10;
    }
    while ( v10 < a2 );
    if ( ++v3 >= a2 )
      return 0;
  }
  v6 = v3 + 1;
  if ( a2 - (v3 + 1) < 4 )
  {
LABEL_10:
    v8 = v6 == a2;
    if ( v6 >= a2 )
      goto LABEL_18;
    do
    {
      if ( *(double *)(*(_DWORD *)(a1 + 4 * v6) + 8 * v3) != 0.0 )
        break;
      ++v6;
    }
    while ( v6 < a2 );
  }
  else
  {
    v7 = (_DWORD *)(a1 + 4 * v6 + 8);
    while ( *(double *)(*(v7 - 2) + 8 * v3) == 0.0 )
    {
      if ( *(double *)(*(v7 - 1) + 8 * v3) != 0.0 )
      {
        ++v6;
        break;
      }
      if ( *(double *)(*v7 + 8 * v3) != 0.0 )
      {
        v6 += 2;
        break;
      }
      if ( *(double *)(v7[1] + 8 * v3) != 0.0 )
      {
        v6 += 3;
        break;
      }
      v6 += 4;
      v7 += 4;
      if ( v6 >= a2 - 3 )
        goto LABEL_10;
    }
  }
  v8 = v6 == a2;
LABEL_18:
  if ( !v8 )
  {
    sub_6154D0(v5, *(_DWORD *)(a1 + 4 * v6), v3, a2);
    goto LABEL_20;
  }
  return -1;
}
