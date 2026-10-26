int __usercall SingleFunctionCallWrapper_5e10@<eax>(_DWORD *a1@<ebp>)
{
  int v1; // ecx
  char v2; // bl
  int v3; // eax
  int v4; // eax

  SEHHandlerInit();
  *(a1 - 5) = v1;
  *(a1 - 4) = 0;
  sub_59A54D(a1 - 4);
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
  sub_59A5E9();
  if ( v2 )
  {
    *(a1 - 4) = &unk_8D4370;
    *(a1 - 1) = 0;
    if ( &unk_8D4370 )
      ObjectConstructorWithSEHVTableInitChain((int)a1, (int)&off_5E6748);
    *(a1 - 4) = &unk_8D4248;
    *(a1 - 1) = 1;
    if ( &unk_8D4248 )
      ObjectConstructorWithSEHVTableInitChain((int)a1, (int)&unk_5E6768);
    *(a1 - 4) = &dword_8D4330;
    *(a1 - 1) = 2;
    if ( &dword_8D4330 )
      ObjectConstructorWithVTableSetupAndSEH(a1, (int)&unk_8D4370, 1, 1);
    *(a1 - 4) = &unk_8D42A0;
    *(a1 - 1) = 3;
    if ( &unk_8D42A0 )
      LocaleObjectConstructorWithVtableInit((int)a1, (int)&unk_8D4248, 1, 1, 1);
    v3 = dword_8D4330;
    *(a1 - 4) = &unk_8D42D8;
    *(int *)((char *)&dword_8D4330 + *(_DWORD *)(v3 + 4) + 44) = (int)&unk_8D42A0;
    *(a1 - 1) = 4;
    if ( &unk_8D42D8 )
      ObjectConstructorWithSEHVTableInitChain((int)a1, (int)&unk_5E6788);
    *(a1 - 4) = &dword_8D43C8;
    *(a1 - 1) = 5;
    if ( &dword_8D43C8 )
      LocaleObjectConstructorWithVtableInit((int)a1, (int)&unk_8D42D8, 1, 1, 1);
    v4 = dword_8D43C8;
    *(a1 - 4) = dword_8D4210;
    *(int *)((char *)&dword_8D43C8 + *(_DWORD *)(v4 + 4) + 44) = (int)&unk_8D42A0;
    *(int *)((char *)&dword_8D43C8 + *(_DWORD *)(dword_8D43C8 + 4) + 12) |= 2u;
    *(a1 - 1) = 6;
    if ( dword_8D4210 )
      LocaleObjectConstructorWithVtableInit((int)a1, (int)&unk_8D42D8, 1, 1, 1);
    *(int *)((char *)&dword_8D423C + *(_DWORD *)(dword_8D4210[0] + 4)) = (int)&unk_8D42A0;
  }
  return *(a1 - 5);
}

