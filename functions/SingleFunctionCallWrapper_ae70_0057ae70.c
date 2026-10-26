int __usercall sub_57AE70@<eax>(int a1@<ebp>)
{
  int v1; // ecx
  char v2; // bl
  int v3; // eax

  SEHHandlerInit(&unk_8D3C18);
  *(_DWORD *)(a1 - 20) = v1;
  *(_DWORD *)(a1 - 16) = 0;
  sub_59A54D(a1 - 16);
  if ( dword_5EA04C < 0 )
  {
    dword_5EA04C = 1;
    v2 = 1;
  }
  else
  {
    ++dword_5EA04C;
    v2 = 0;
  }
  sub_59A5E9(a1 - 16);
  if ( v2 )
  {
    *(_DWORD *)(a1 - 16) = &unk_8D4510;
    *(_DWORD *)(a1 - 4) = 0;
    if ( &unk_8D4510 )
      LocaleObjectConstructorWithVTableSetup(&off_5E6748);
    *(_DWORD *)(a1 - 16) = &unk_8D44B8;
    *(_DWORD *)(a1 - 4) = 1;
    if ( &unk_8D44B8 )
      LocaleObjectConstructorWithVTableSetup(&unk_5E6768);
    *(_DWORD *)(a1 - 16) = &unk_8D45A0;
    *(_DWORD *)(a1 - 4) = 2;
    if ( &unk_8D45A0 )
      LocaleObjectConstructorWithVTableSetup(&unk_5E6788);
    *(_DWORD *)(a1 - 16) = &dword_8D4478;
    *(_DWORD *)(a1 - 4) = 3;
    if ( &dword_8D4478 )
      LocaleObjectAllocAndVtableSetup(&unk_8D4510, 1, 1);
    *(_DWORD *)(a1 - 16) = &byte_8D4568;
    *(_DWORD *)(a1 - 4) = 4;
    if ( &byte_8D4568 )
      CEHFrameSetup(&unk_8D44B8, 1, 1, 1);
    *(int *)((char *)&dword_8D4478 + *(_DWORD *)(dword_8D4478 + 4) + 44) = (int)&byte_8D4568;
    *(_DWORD *)(a1 - 16) = &dword_8D4400;
    *(_DWORD *)(a1 - 4) = 5;
    if ( &dword_8D4400 )
      CEHFrameSetup(&unk_8D45A0, 1, 1, 1);
    v3 = dword_8D4400;
    *(_DWORD *)(a1 - 16) = &dword_8D4440;
    *(int *)((char *)&dword_8D4400 + *(_DWORD *)(v3 + 4) + 44) = (int)&byte_8D4568;
    *(int *)((char *)&dword_8D4400 + *(_DWORD *)(dword_8D4400 + 4) + 12) |= 2u;
    *(_DWORD *)(a1 - 4) = 6;
    if ( &dword_8D4440 )
      CEHFrameSetup(&unk_8D45A0, 1, 1, 1);
    *(int *)((char *)&dword_8D446C + *(_DWORD *)(dword_8D4440 + 4)) = (int)&byte_8D4568;
  }
  return *(_DWORD *)(a1 - 20);
}
