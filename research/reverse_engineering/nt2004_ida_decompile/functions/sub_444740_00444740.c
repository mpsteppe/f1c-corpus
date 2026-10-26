int __thiscall sub_444740(int *this, double a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // edx
  const void *v9; // esi
  void *v10; // edi
  int v11; // edx
  int v12; // eax
  const void *v13; // esi
  int v14; // eax
  int v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]

  v3 = this[1984];
  v4 = this[2103];
  v5 = this[1985];
  this[1986] = v3;
  v6 = this[2104];
  this[2105] = v4;
  this[2106] = v6;
  this[1987] = v5;
  v7 = this + 212;
  v8 = 4;
  do
  {
    *v7 = *(v7 - 2);
    v7[1] = *(v7 - 1);
    v7[4] = v7[2];
    v7[5] = v7[3];
    v9 = v7 + 12;
    v10 = v7 + 20;
    v7 += 314;
    --v8;
    qmemcpy(v10, v9, 0x20u);
  }
  while ( v8 );
  if ( this[1524] > 0 )
  {
    v17 = 0;
    v16 = 0;
    v18 = this[1524];
    do
    {
      v11 = v17 + this[1556];
      v12 = v16 + this[1525];
      qmemcpy((void *)v11, (const void *)(v12 + 308), 0x18u);
      v13 = (const void *)(v12 + 332);
      v14 = v18;
      qmemcpy((void *)(v11 + 24), v13, 0x18u);
      v16 += 580;
      v17 += 48;
      --v18;
    }
    while ( v14 != 1 );
  }
  sub_442AF0((int)this, a2);
  sub_581A80(this + 1524);
  sub_581BD0(this + 1524);
  sub_581DB0(a2);
  return sub_4446C0(this);
}
