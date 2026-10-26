char __thiscall sub_4E4250(int this)
{
  int v1; // ebx
  int v3; // ecx
  int v4; // edi
  int v5; // ecx
  CHAR *v6; // eax
  int v7; // edi
  CHAR *v8; // eax
  const char *v9; // ecx
  char *v10; // eax
  int v11; // esi
  CHAR **v12; // ebp
  CHAR *v13; // ebp
  int v15[4]; // [esp+10h] [ebp-30h] BYREF
  char Destination[32]; // [esp+20h] [ebp-20h] BYREF

  v1 = dword_769134;
  *(_DWORD *)(this + 30964) = 2;
  *(_DWORD *)(this + 30968) = -1;
  *(_DWORD *)(this + 30968) = sub_4E4840();
  sub_4E3A90(this + 30284);
  v3 = this + 16;
  v4 = 47;
  do
  {
    sub_4E3A90(v3);
    v3 = v5 + 644;
    --v4;
  }
  while ( v4 );
  sub_4CE010(byte_7663E0, Destination, 31);
  sub_578600(Destination);
  v6 = dword_7665D8;
  v7 = 0;
  if ( !dword_7665D8 )
    v6 = &byte_629120;
  sub_578600(v6);
  v8 = (CHAR *)dword_766610;
  if ( !dword_766610 )
    v8 = &byte_629120;
  sub_578600(v8);
  *(_DWORD *)(this + 30912) = v1;
  *(_DWORD *)(this + 30916) = v1;
  *(_DWORD *)(this + 30920) = 0;
  *(_BYTE *)(this + 30924) = 1;
  sub_504470(v15);
  v9 = *(const char **)dword_7696A8;
  if ( !*(_DWORD *)dword_7696A8 )
    v9 = &byte_629120;
  v10 = dword_7665D8;
  if ( !dword_7665D8 )
    v10 = &byte_629120;
  sub_4E2570(v15, v1, v10, v9);
  if ( v1 > 0 )
  {
    v11 = this + 24;
    do
    {
      v12 = (CHAR **)sub_4E28F0(v15, v7);
      sub_578600((char *)v12 + 246);
      v13 = *v12;
      if ( !v13 )
        v13 = &byte_629120;
      sub_578600(v13);
      sub_578600(&byte_629120);
      sub_578600(&byte_629120);
      *(_DWORD *)(v11 + 620) = v7;
      *(_DWORD *)(v11 + 624) = v7;
      *(_DWORD *)(v11 + 628) = 1;
      *(_BYTE *)(v11 + 632) = 1;
      ++v7;
      v11 += 644;
    }
    while ( v7 < v1 );
  }
  sub_4E2420(v15);
  return 0;
}
