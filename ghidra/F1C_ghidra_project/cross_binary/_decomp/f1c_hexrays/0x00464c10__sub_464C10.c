// f1c  0x00464c10  size=261
_DWORD *__thiscall sub_464C10(_DWORD *this)
{
  int v2; // edi
  int *v3; // eax
  int v5; // [esp+10h] [ebp-4h]

  sub_568BA0(this + 1);
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  v2 = (int)(this + 35);
  v5 = 104;
  do
  {
    sub_401000(v2, 1, 104, (int (__thiscall *)(int))sub_464D20);
    *(_DWORD *)(v2 + 544) = 0;
    *(_DWORD *)(v2 + 548) = 0;
    *(_WORD *)(v2 + 552) = 0;
    v3 = (int *)sub_587C03(8);
    if ( v3 )
    {
      *v3 = v2;
      v3[1] = -1082130432;
    }
    else
    {
      v3 = 0;
    }
    *(_DWORD *)(v2 + 556) = v3;
    sub_464A40(v2);
    v2 += 560;
    --v5;
  }
  while ( v5 );
  this[14700] = 0;
  this[14701] = 0;
  this[14702] = 0;
  this[14703] = 0;
  this[14704] = 0;
  this[14705] = 0;
  this[14706] = 0;
  this[14707] = 0;
  sub_568BE0(1);
  this[25] = 1065353216;
  this[24] = 1065353216;
  this[20] = -1;
  this[21] = -1;
  this[14595] = 0;
  memset(this + 14596, 0xFFu, 0x1A0u);
  return this;
}
