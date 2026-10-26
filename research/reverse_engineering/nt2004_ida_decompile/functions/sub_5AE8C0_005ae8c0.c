int __thiscall sub_5AE8C0(int this)
{
  int v2; // ebx
  int v3; // edi
  _DWORD *v4; // ecx
  _DWORD *i; // eax
  int j; // edi
  float v8; // [esp+Ch] [ebp-4h]

  nullsub_6((void *)this);
  v2 = 0;
  if ( *(int *)(this + 344) > 0 )
  {
    v3 = 0;
    do
    {
      v4 = *(_DWORD **)(v3 + *(_DWORD *)(this + 348) + 16);
      if ( v4 )
        sub_5A2740(v4);
      ++v2;
      v3 += 24;
    }
    while ( v2 < *(_DWORD *)(this + 344) );
  }
  for ( i = *(_DWORD **)(this + 360); i; i = (_DWORD *)i[1] )
    *(_DWORD *)(*i + 40) &= ~8u;
  if ( (*(_DWORD *)(this + 240) & 0x800) != 0 )
  {
    sub_597B20((_DWORD *)this);
    if ( (*(_DWORD *)(this + 240) & 0x600000) != 0 )
      sub_5AE860((_DWORD *)this, *(_DWORD *)(this + 252));
    *(_DWORD *)(this + 240) &= 0xFFBFF7FF;
  }
  dword_7FEEA8 = 0;
  if ( !dword_7E8D04 )
    sub_5AB360(dword_7E6B48, 0);
  if ( *(int *)(this + 376) > 0 )
    sub_59ABA0((_DWORD *)this);
  for ( j = *(_DWORD *)(this + 252); j; j = *(_DWORD *)(j + 632) )
    sub_5AE610(j, (_DWORD *)this);
  if ( !dword_7E8D04 )
    sub_5AB3A0(dword_7E6B48, 0);
  v8 = sub_5ACA90(-1);
  *(float *)(this + 244) = v8;
  return sub_5A26B0((_DWORD *)this, v8);
}
