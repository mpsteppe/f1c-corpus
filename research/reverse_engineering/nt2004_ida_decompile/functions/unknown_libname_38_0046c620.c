// Microsoft VisualC 2-14/net runtime
void __cdecl unknown_libname_38()
{
  _DWORD *v0; // esi
  _DWORD *v1; // edi
  void *v2; // ebp
  _DWORD *v3; // edi
  void *v4; // ebp
  _DWORD *v5; // edi
  int v6; // ebp
  void *v7; // eax
  int v8; // edi
  LPVOID *v9; // ebp
  bool v10; // zf
  int v11; // edi
  LPVOID *v12; // ebp

  v0 = (_DWORD *)dword_7652D8;
  if ( dword_7652D8 )
  {
    v1 = *(_DWORD **)(dword_7652D8 + 14272);
    while ( v1 )
    {
      v2 = v1;
      v1 = (_DWORD *)v1[1];
      sub_4A82F0(v2);
      sub_5BE8AE(v2);
    }
    v0[3568] = 0;
    v0[3569] = 0;
    v0[3570] = 0;
    v0[3571] = 0;
    v3 = (_DWORD *)v0[3564];
    while ( v3 )
    {
      v4 = v3;
      v3 = (_DWORD *)v3[1];
      sub_4A82F0(v4);
      sub_5BE8AE(v4);
    }
    v0[3564] = 0;
    v0[3565] = 0;
    v0[3566] = 0;
    v0[3567] = 0;
    v5 = v0 + 3584;
    v6 = 49;
    do
    {
      v7 = (void *)*(v5 - 71);
      v5 -= 71;
      sub_5BE8AE(v7);
      --v6;
    }
    while ( v6 );
    v8 = v0[31];
    while ( v8 )
    {
      v9 = (LPVOID *)v8;
      v10 = *(_BYTE *)(v8 + 8) == 0;
      v8 = *(_DWORD *)(v8 + 4);
      if ( !v10 )
        sub_5BE8AE(*v9);
      sub_5BE8AE(v9);
    }
    v0[31] = 0;
    v0[32] = 0;
    v0[33] = 0;
    v0[34] = 0;
    v11 = v0[27];
    while ( v11 )
    {
      v12 = (LPVOID *)v11;
      v10 = *(_BYTE *)(v11 + 8) == 0;
      v11 = *(_DWORD *)(v11 + 4);
      if ( !v10 )
        sub_5BE8AE(*v12);
      sub_5BE8AE(v12);
    }
    v0[27] = 0;
    v0[28] = 0;
    v0[29] = 0;
    v0[30] = 0;
    nullsub_6(v0 + 1);
    sub_5BE8AE(v0);
  }
}
