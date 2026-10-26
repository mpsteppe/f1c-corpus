_DWORD *__thiscall sub_46C930(_DWORD *this)
{
  int v2; // edi
  int *v3; // eax
  int v5; // [esp+10h] [ebp-4h]

  sub_57B5D0(this + 1);
  this[27] = 0;
  this[28] = 0;
  this[29] = 0;
  this[30] = 0;
  this[31] = 0;
  this[32] = 0;
  this[33] = 0;
  this[34] = 0;
  v2 = (int)(this + 35);
  v5 = 49;
  do
  {
    sub_401000(v2, 1, 49, (int (__thiscall *)(int))sub_46CA40);
    *(_DWORD *)(v2 + 268) = 0;
    *(_DWORD *)(v2 + 272) = 0;
    *(_WORD *)(v2 + 276) = 0;
    v3 = (int *)operator new(8u);
    if ( v3 )
    {
      *v3 = v2;
      v3[1] = -1082130432;
    }
    else
    {
      v3 = 0;
    }
    *(_DWORD *)(v2 + 280) = v3;
    sub_46C710(v2);
    v2 += 284;
    --v5;
  }
  while ( v5 );
  this[3564] = 0;
  this[3565] = 0;
  this[3566] = 0;
  this[3567] = 0;
  this[3568] = 0;
  this[3569] = 0;
  this[3570] = 0;
  this[3571] = 0;
  sub_57B610(1);
  this[25] = 1065353216;
  this[24] = 1065353216;
  this[20] = -1;
  this[21] = -1;
  this[3514] = 0;
  memset(this + 3515, 0xFFu, 0xC4u);
  return this;
}
