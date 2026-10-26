int __thiscall sub_465000(_DWORD *this)
{
  _DWORD *v1; // esi
  _DWORD *v2; // edi
  void *v3; // ebp
  _DWORD *v4; // edi
  void *v5; // ebp
  _DWORD *v6; // edi
  int v7; // ebp
  void *v8; // eax
  int v9; // edi
  LPVOID *v10; // ebp
  bool v11; // zf
  int v12; // edi
  LPVOID *v13; // ebp
  int result; // eax

  v1 = (_DWORD *)*this;
  if ( *this )
  {
    v2 = (_DWORD *)v1[14704];
    while ( v2 )
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      ConditionalFreeByFlagCheck((int)v3);
      FreeWrapper_7bcf(v3);
    }
    v1[14704] = 0;
    v1[14705] = 0;
    v1[14706] = 0;
    v1[14707] = 0;
    v4 = (_DWORD *)v1[14700];
    while ( v4 )
    {
      v5 = v4;
      v4 = (_DWORD *)v4[1];
      ConditionalFreeByFlagCheck((int)v5);
      FreeWrapper_7bcf(v5);
    }
    v1[14700] = 0;
    v1[14701] = 0;
    v1[14702] = 0;
    v1[14703] = 0;
    v6 = v1 + 14734;
    v7 = 104;
    do
    {
      v8 = (void *)*(v6 - 140);
      v6 -= 140;
      FreeWrapper_7bcf(v8);
      --v7;
    }
    while ( v7 );
    v9 = v1[31];
    while ( v9 )
    {
      v10 = (LPVOID *)v9;
      v11 = *(_BYTE *)(v9 + 8) == 0;
      v9 = *(_DWORD *)(v9 + 4);
      if ( !v11 )
        FreeWrapper_7bcf(*v10);
      FreeWrapper_7bcf(v10);
    }
    v1[31] = 0;
    v1[32] = 0;
    v1[33] = 0;
    v1[34] = 0;
    v12 = v1[27];
    while ( v12 )
    {
      v13 = (LPVOID *)v12;
      v11 = *(_BYTE *)(v12 + 8) == 0;
      v12 = *(_DWORD *)(v12 + 4);
      if ( !v11 )
        FreeWrapper_7bcf(*v13);
      FreeWrapper_7bcf(v13);
    }
    v1[27] = 0;
    v1[28] = 0;
    v1[29] = 0;
    v1[30] = 0;
    EmptyStub_0170();
    return FreeWrapper_7bcf(v1);
  }
  return result;
}

