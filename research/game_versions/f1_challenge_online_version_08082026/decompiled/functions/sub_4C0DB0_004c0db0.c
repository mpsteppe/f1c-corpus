char __thiscall sub_4C0DB0(int this)
{
  int v1; // ebx
  int v3; // ecx
  int v4; // edi
  int v5; // ecx
  char *v6; // eax
  int v7; // edi
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // esi
  char **v12; // ebp
  char *v13; // ebp
  int v15[4]; // [esp+18h] [ebp-30h] BYREF
  _BYTE v16[32]; // [esp+28h] [ebp-20h] BYREF

  v1 = dword_7D0A20;
  *(_DWORD *)(this + 45380) = 2;
  *(_DWORD *)(this + 45384) = 0;
  sub_4C07F0(this + 44908);
  v3 = this;
  v4 = 103;
  do
  {
    sub_4C07F0(v3);
    v3 = v5 + 436;
    --v4;
  }
  while ( v4 );
  sub_4B0B20(byte_7CE498, v16, 31);
  sub_566650(v16);
  v6 = (char *)dword_7CE64C;
  v7 = 0;
  if ( !dword_7CE64C )
    v6 = byte_5EA438;
  sub_566650(v6);
  *(_DWORD *)(this + 45328) = v1;
  *(_DWORD *)(this + 45332) = v1;
  *(_DWORD *)(this + 45336) = 0;
  *(_BYTE *)(this + 45340) = 1;
  v8 = (char *)dword_7D0DCC;
  if ( !dword_7D0DCC )
    v8 = byte_5EA438;
  sub_566650(v8);
  sub_5665B0(&word_5C32D8);
  v9 = sub_5681F0(aGameFilter);
  sub_5665B0(v9);
  sub_4BF630(v15);
  v10 = (char *)dword_7CE64C;
  if ( !dword_7CE64C )
    v10 = byte_5EA438;
  sub_4BF790(v15, v1, (int)v10, byte_5EA438);
  if ( v1 > 0 )
  {
    v11 = this + 16;
    do
    {
      v12 = (char **)sub_4BFCD0(v15, v7);
      sub_566650(v12 + 47);
      v13 = *v12;
      if ( !v13 )
        v13 = byte_5EA438;
      sub_566650(v13);
      sub_566650(byte_5EA438);
      *(_DWORD *)(v11 + 404) = v7;
      *(_DWORD *)(v11 + 408) = v7;
      *(_DWORD *)(v11 + 412) = 1;
      *(_BYTE *)(v11 + 416) = 1;
      ++v7;
      v11 += 436;
    }
    while ( v7 < v1 );
  }
  sub_4BF640(v15);
  return 0;
}
