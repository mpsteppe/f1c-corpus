int __thiscall sub_59A8A0(int *this, int a2, int a3)
{
  int v4; // ecx
  int v5; // eax
  int v6; // edx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  char Buffer[256]; // [esp+Ch] [ebp-100h] BYREF

  v4 = *(_DWORD *)(a3 + 172);
  if ( !v4 )
    return -1;
  v5 = *(_DWORD *)(a3 + 176);
  v6 = 0;
  if ( v4 <= 0 )
  {
LABEL_8:
    sprintf(Buffer, aNoReflectionMa);
    sub_591C60((int)this, -1, Buffer);
    return -1;
  }
  while ( ((unsigned int)&unk_800000 & *(_DWORD *)(v5 + 96)) == 0 )
  {
LABEL_7:
    v5 += 148;
    if ( ++v6 >= *(_DWORD *)(a3 + 172) )
      goto LABEL_8;
  }
  if ( (*(_BYTE *)(v5 + 64) & 2) == 0 )
  {
    sprintf(Buffer, aReflectionMapp);
    sub_591C60((int)this, -1, Buffer);
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
  v8 = operator new(0x27Cu);
  if ( v8 )
    v9 = sub_592FE0(v8);
  else
    v9 = 0;
  *this = (int)v9;
  sprintf(Buffer, aRefview);
  sub_593010(*this, Buffer);
  sub_593D20(*this, 1065353216, 1148846080);
  sub_593D50((_DWORD *)*this, 0, 0, 0);
  sub_593820(*this, 2.967236, 2.967236, 1);
  sub_593F30((int *)*this, *(_DWORD *)(this[1] + 16));
  sub_593430((_DWORD *)*this, 1);
  return 0;
}
