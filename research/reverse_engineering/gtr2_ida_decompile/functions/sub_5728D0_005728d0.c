void __thiscall sub_5728D0(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  _DWORD *v3; // edx
  int v4; // ebp
  void *v5; // edi
  _DWORD *v6; // ecx
  _DWORD *v7; // eax
  int v8; // edx
  _DWORD *v9; // ebp
  char *v10; // edi
  char *v11; // eax
  bool v12; // zf
  char *v13; // ebp
  char *v14; // eax
  char *v15; // ebp
  _DWORD *v16; // eax
  int v17; // ecx
  void *v18; // eax
  int v19; // [esp+8h] [ebp-4h]

  v2 = (void (__thiscall ***)(_DWORD, int))this[638];
  if ( v2 )
  {
    (**v2)(v2, 1);
    this[638] = 0;
  }
  if ( dword_FB1D04 && this[2] )
  {
    sub_572420();
    sub_5DC6F0(this[2]);
    sub_417760(&dword_91BF88, *(_DWORD *)(*this + 22468), 0);
  }
  sub_56BC00();
  sub_569600();
  memset(this + 2, 0, 0x44u);
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  this[25] = 0;
  this[26] = 0;
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  this[35] = 0;
  this[36] = 0;
  this[37] = 0;
  sub_615860(WindowName);
  *((_BYTE *)this + 160) = 0;
  v3 = this + 93;
  v4 = 4;
  do
  {
    *(v3 - 5) = 0;
    *(v3 - 4) = 0;
    *(v3 - 3) = 0;
    *(v3 - 2) = 0;
    *(v3 - 1) = 0;
    *v3 = 0;
    v3[1] = 1048576000;
    v3[2] = 0;
    v3[3] = 0;
    v3[4] = 0;
    v3[5] = 0;
    v3[6] = 0;
    v3[7] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[10] = 0;
    v3[11] = 0;
    v3[12] = 0;
    v3[13] = 0;
    v3[14] = 0;
    v3[15] = 0;
    v3[16] = 0;
    v3[17] = 0;
    v3[18] = 0;
    v3[19] = 0;
    v3[20] = 0;
    v3[21] = 0;
    v3[22] = 0;
    v3[67] = 0;
    v3[62] = 0;
    v3[63] = 0;
    memset(v3 + 23, 0, 0x44u);
    v5 = v3 + 40;
    v3 += 74;
    --v4;
    memset(v5, 0, 0x44u);
  }
  while ( v4 );
  memset(this + 412, 0, 0x44u);
  memset(this + 429, 0, 0x44u);
  memset(this + 446, 0, 0x220u);
  this[607] = 0;
  this[608] = 0;
  this[609] = 0;
  this[610] = 0;
  this[611] = 0;
  this[612] = 0;
  this[613] = 0;
  this[614] = 0;
  this[615] = 0;
  this[616] = 0;
  this[618] = 0;
  this[617] = 0;
  this[620] = 0;
  this[622] = 0;
  this[621] = 0;
  this[619] = 0;
  this[624] = 0;
  this[623] = 0;
  this[625] = 0;
  this[628] = 0;
  v6 = this + 629;
  v7 = this + 626;
  v8 = 2;
  do
  {
    *v7 = 0;
    v9 = v6;
    *v6 = 0;
    v6[1] = 0;
    v6[2] = 0;
    ++v7;
    v6 += 4;
    --v8;
    v9[3] = 0;
  }
  while ( v8 );
  this[637] = 0;
  this[708] = 0;
  this[709] = 0;
  this[710] = 0;
  this[711] = 0;
  this[712] = 0;
  this[713] = 0;
  this[714] = 0;
  this[715] = 0;
  this[716] = 0;
  this[739] = 0;
  this[740] = 0;
  this[741] = 0;
  this[742] = 0;
  this[743] = 0;
  *((_WORD *)this + 1488) = 0;
  this[745] = 0;
  this[746] = 0;
  this[750] = 0;
  this[760] = 0;
  this[761] = 0;
  *((_BYTE *)this + 3049) = 0;
  *((_BYTE *)this + 3050) = 0;
  this[763] = 0;
  *((_BYTE *)this + 3056) = 0;
  *((_BYTE *)this + 3057) = 0;
  *((_BYTE *)this + 3058) = 0;
  *((_BYTE *)this + 3059) = 0;
  *((_BYTE *)this + 3060) = 0;
  *((_BYTE *)this + 3061) = 0;
  *((_BYTE *)this + 3062) = 0;
  *((_BYTE *)this + 3063) = 0;
  this[767] = 0;
  *((_BYTE *)this + 3072) = 0;
  this[769] = 0;
  this[771] = -8388609;
  this[772] = 1065353216;
  this[87] = -1082130432;
  this[952] = 0;
  this[766] = -1;
  this[770] = -1;
  this[949] = 0;
  this[950] = 0;
  this[951] = 0;
  this[953] = 0;
  this[954] = 0;
  this[955] = 0;
  this[956] = 0;
  this[957] = 0;
  this[958] = 0;
  this[959] = 0;
  this[960] = 0;
  this[961] = 0;
  this[962] = 0;
  this[963] = 0;
  this[964] = 0;
  this[965] = 0;
  this[966] = 0;
  this[967] = 0;
  v10 = (char *)(this + 971);
  v19 = 11;
  do
  {
    v11 = *(char **)v10;
    v12 = *(_DWORD *)v10 == 0;
    *((_DWORD *)v10 - 2) = 0;
    *((_DWORD *)v10 - 1) = 0;
    if ( !v12 )
    {
      v13 = v11 - 4;
      `eh vector destructor iterator'(
        v11,
        0xCu,
        *((_DWORD *)v11 - 1),
        (void (__thiscall *)(void *))Concurrency::details::TaskStack::~TaskStack);
      j_j__free(v13);
    }
    v14 = (char *)*((_DWORD *)v10 + 2);
    *(_DWORD *)v10 = 0;
    *((_DWORD *)v10 + 1) = 0;
    if ( v14 )
    {
      v15 = v14 - 4;
      `eh vector destructor iterator'(v14, 0x18u, *((_DWORD *)v14 - 1), (void (__thiscall *)(void *))sub_568D80);
      j_j__free(v15);
    }
    *((_DWORD *)v10 + 2) = 0;
    *((_DWORD *)v10 + 3) = 0;
    v10 += 748;
    --v19;
  }
  while ( v19 );
  *((_BYTE *)this + 3092) = 0;
  v16 = this + 777;
  v17 = 25;
  do
  {
    *((_BYTE *)v16 - 12) = 0;
    *((_BYTE *)v16 - 11) = 0;
    *(v16 - 2) = 0;
    *(v16 - 1) = 0;
    *v16 = 0;
    v16[1] = 0;
    v16[2] = 0;
    v16[3] = 0;
    v16 += 7;
    --v17;
  }
  while ( v17 );
  v18 = (void *)this[3026];
  this[3025] = 0;
  if ( v18 )
  {
    j_j__free(v18);
    this[3026] = 0;
  }
  *((_BYTE *)this + 12112) = 0;
}
