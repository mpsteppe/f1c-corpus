int __usercall sub_4E2220@<eax>(int *a1@<ecx>, int a2@<ebp>)
{
  int i; // eax
  int v4; // esi
  int v5; // ecx
  void (__thiscall **v6)(int, int); // eax
  int v7; // ebp
  void **v8; // esi
  void *v9; // eax
  bool v10; // zf
  _DWORD *v11; // esi
  void *v12; // ebp
  int *v13; // eax
  int v14; // esi
  int v15; // eax
  int *v16; // eax
  _DWORD v18[6]; // [esp+0h] [ebp-40h] BYREF
  int v19; // [esp+18h] [ebp-28h] BYREF
  char v20[4]; // [esp+1Ch] [ebp-24h] BYREF
  int v21; // [esp+20h] [ebp-20h]
  char v22; // [esp+2Ch] [ebp-14h]
  char v23; // [esp+30h] [ebp-10h]
  int v24; // [esp+3Ch] [ebp-4h]

  sub_4E2C00(v20);
  v24 = 0;
  sub_4E3D50(v20, a1);
  for ( i = sub_4FB7D0(&v19); i; i = sub_4FB7D0(&v19) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)i + 128))(i);
    sub_4E2C70(&v19);
  }
  sub_4D5D40(a1 + 1);
  v4 = a1[7];
  while ( v4 )
  {
    v5 = v4;
    v6 = *(void (__thiscall ***)(int, int))v4;
    v4 = *(_DWORD *)(v4 + 140);
    (*v6)(v5, 1);
  }
  v18[0] = a2;
  v7 = a1[83];
  a1[7] = 0;
  while ( v7 )
  {
    v8 = (void **)v7;
    v7 = *(_DWORD *)(v7 + 40);
    sub_4E2820(v8, 1);
    v18[3] = v8;
    v23 = 1;
    sub_4E2820(v8, 1);
    v9 = *v8;
    v10 = *v8 == 0;
    v22 = 0;
    if ( !v10 )
      j_j__free(v9);
    j__free(v8);
  }
  v11 = (_DWORD *)a1[85];
  while ( v11 )
  {
    v12 = v11;
    v11 = (_DWORD *)v11[21];
    sub_4E2850(v12);
    j__free(v12);
  }
  sub_4E1880();
  if ( a1[43] )
  {
    sub_4DD9C0();
    a1[43] = 0;
  }
  if ( a1[44] )
  {
    sub_4DD9C0();
    a1[44] = 0;
  }
  sub_45DD50((HCURSOR *)dword_B6A328);
  v13 = (int *)a1[78];
  a1[80] = (int)v13;
  if ( v13 )
  {
    v14 = *v13;
    if ( *v13 )
    {
      do
      {
        sub_4DDA00();
        *(_DWORD *)(v14 + 8) = 0;
        v15 = a1[80];
        if ( !v15 )
          break;
        v16 = *(int **)(v15 + 4);
        a1[80] = (int)v16;
        if ( !v16 )
          break;
        v14 = *v16;
      }
      while ( *v16 );
    }
  }
  v21 = -1;
  nullsub_7(v18);
  return 0;
}
