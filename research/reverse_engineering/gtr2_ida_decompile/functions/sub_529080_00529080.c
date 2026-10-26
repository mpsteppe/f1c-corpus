char __thiscall sub_529080(int this)
{
  int v3; // eax
  int i; // edi
  char *v5; // esi
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-8h]

  sub_5272D0((int *)this);
  if ( *(float *)(this + 2892848) - *(float *)(this + 2892844) <= 0.0 )
    return 0;
  *(_DWORD *)(this + 2892860) = sub_614040(this + 1780);
  v3 = *(_DWORD *)(this + 2892916);
  *(_BYTE *)(this + 2892961) = 1;
  *(_DWORD *)(this + 2892920) = v3;
  *(_DWORD *)(this + 2892916) = 0;
  for ( i = sub_42DA10(&unk_920488); dword_920480 < 105; i = sub_42DA60(&unk_920488) )
  {
    v5 = (char *)&unk_9204A0 + 22616 * i;
    sub_56BD70(v5 + 2704, *(_DWORD *)(this + 2892844));
    sub_56B670(v5 + 2704);
    *(_DWORD *)(this + 4 * i + 1916) = *((_DWORD *)v5 + 3705);
    *(_BYTE *)(i + this + 2336) = v5[5754];
    *(_BYTE *)(i + this + 2441) = (*((_DWORD *)v5 + 5645) & 2) != 0;
    *(_BYTE *)(i + this + 2546) = v5[5753];
    sub_4FCCE0(v5 + 14824, 27504 * i + this + 2656);
    if ( v5[5753] != 1 )
    {
      v6 = *((_DWORD *)v5 + 1436);
      v5[5753] = 1;
      sub_56AE80(v6, 1);
    }
    sub_53E6A0(v5, 3);
  }
  *(float *)&v7 = dbl_FB1D18;
  sub_522980((void *)this, v7);
  sub_561B20(0);
  *(_BYTE *)(this + 2892960) = 1;
  sub_40D520((int)&flt_757718, 0.0);
  return 1;
}
