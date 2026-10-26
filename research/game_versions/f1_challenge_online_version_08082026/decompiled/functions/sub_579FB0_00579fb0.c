int __usercall sub_579FB0@<eax>(int a1@<ebp>)
{
  int v1; // ecx
  char v2; // bl
  int v3; // eax
  int v4; // eax

  sub_58A5D8(&unk_8D3BF1);
  *(_DWORD *)(a1 - 20) = v1;
  *(_DWORD *)(a1 - 16) = 0;
  sub_59A54D(a1 - 16);
  if ( dword_5E9EF4 < 0 )
  {
    dword_5E9EF4 = 1;
    v2 = 1;
  }
  else
  {
    ++dword_5E9EF4;
    v2 = 0;
  }
  sub_59A5E9(a1 - 16);
  if ( v2 )
  {
    *(_DWORD *)(a1 - 16) = &unk_8D4370;
    *(_DWORD *)(a1 - 4) = 0;
    if ( &unk_8D4370 )
      sub_598BBC(&off_5E6748);
    *(_DWORD *)(a1 - 16) = &unk_8D4248;
    *(_DWORD *)(a1 - 4) = 1;
    if ( &unk_8D4248 )
      sub_598BBC(&unk_5E6768);
    *(_DWORD *)(a1 - 16) = &dword_8D4330;
    *(_DWORD *)(a1 - 4) = 2;
    if ( &dword_8D4330 )
      sub_598AF5(&unk_8D4370, 1, 1);
    *(_DWORD *)(a1 - 16) = &unk_8D42A0;
    *(_DWORD *)(a1 - 4) = 3;
    if ( &unk_8D42A0 )
      sub_5989D7(&unk_8D4248, 1, 1, 1);
    v3 = dword_8D4330;
    *(_DWORD *)(a1 - 16) = &unk_8D42D8;
    *(int *)((char *)&dword_8D4330 + *(_DWORD *)(v3 + 4) + 44) = (int)&unk_8D42A0;
    *(_DWORD *)(a1 - 4) = 4;
    if ( &unk_8D42D8 )
      sub_598BBC(&unk_5E6788);
    *(_DWORD *)(a1 - 16) = &dword_8D43C8;
    *(_DWORD *)(a1 - 4) = 5;
    if ( &dword_8D43C8 )
      sub_5989D7(&unk_8D42D8, 1, 1, 1);
    v4 = dword_8D43C8;
    *(_DWORD *)(a1 - 16) = &dword_8D4210;
    *(int *)((char *)&dword_8D43C8 + *(_DWORD *)(v4 + 4) + 44) = (int)&unk_8D42A0;
    *(int *)((char *)&dword_8D43C8 + *(_DWORD *)(dword_8D43C8 + 4) + 12) |= 2u;
    *(_DWORD *)(a1 - 4) = 6;
    if ( &dword_8D4210 )
      sub_5989D7(&unk_8D42D8, 1, 1, 1);
    *(int *)((char *)&dword_8D423C + *(_DWORD *)(dword_8D4210 + 4)) = (int)&unk_8D42A0;
  }
  return *(_DWORD *)(a1 - 20);
}
