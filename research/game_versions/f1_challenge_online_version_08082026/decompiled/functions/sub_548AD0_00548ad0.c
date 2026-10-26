int __thiscall sub_548AD0(int *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  char v10[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = *(_DWORD *)(a3 + 164);
  if ( !v4 )
    return -1;
  v5 = *(_DWORD *)(a3 + 168);
  v6 = 0;
  if ( v4 <= 0 )
  {
LABEL_8:
    sub_58815F(v10, aNoReflectionMa);
    sub_53C590(-1, v10);
    return -1;
  }
  while ( ((unsigned int)&unk_800000 & *(_DWORD *)(v5 + 96)) == 0 )
  {
LABEL_7:
    v5 += 148;
    if ( ++v6 >= *(_DWORD *)(a3 + 164) )
      goto LABEL_8;
  }
  if ( (*(_BYTE *)(v5 + 64) & 2) == 0 )
  {
    sub_58815F(v10, aReflectionMapp);
    sub_53C590(-1, v10);
    return -1;
  }
  if ( a2 != 2 )
  {
    this[5] = 0;
    this[6] = 0;
    goto LABEL_7;
  }
  this[1] = *(_DWORD *)(v5 + 140);
  this[3] = 0;
  v8 = (_DWORD *)sub_587C03(444);
  if ( v8 )
    v9 = sub_5418B0(v8);
  else
    v9 = 0;
  *this = (int)v9;
  sub_58815F(v10, aRefview);
  sub_5418E0(*this, v10);
  sub_5423C0(*this, 1065353216, 1148846080);
  sub_5423E0((_DWORD *)*this, 0, 0, 0);
  sub_542050(*this, 2.967236, 2.967236, 1);
  sub_542560((int *)*this, *(_DWORD *)(this[1] + 84));
  sub_541CA0((_DWORD *)*this, 1);
  return 0;
}
