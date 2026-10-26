int __usercall sub_585E50@<eax>(_DWORD *a1@<ebp>)
{
  int v1; // ecx
  char v2; // bl
  int v3; // eax

  SEHHandlerInit();
  *(a1 - 5) = v1;
  *(a1 - 4) = 0;
  sub_59A54D(a1 - 4);
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
  sub_59A5E9();
  if ( v2 )
  {
    *(a1 - 4) = &unk_8D4510;
    *(a1 - 1) = 0;
    if ( &unk_8D4510 )
      LocaleObjectConstructorWithVTableSetup((int)a1, (int)&off_5E6748);
    *(a1 - 4) = &unk_8D44B8;
    *(a1 - 1) = 1;
    if ( &unk_8D44B8 )
      LocaleObjectConstructorWithVTableSetup((int)a1, (int)&unk_5E6768);
    *(a1 - 4) = &unk_8D45A0;
    *(a1 - 1) = 2;
    if ( &unk_8D45A0 )
      LocaleObjectConstructorWithVTableSetup((int)a1, (int)&unk_5E6788);
    *(a1 - 4) = &dword_8D4478;
    *(a1 - 1) = 3;
    if ( &dword_8D4478 )
      LocaleObjectAllocAndVtableSetup(a1, (int)&unk_8D4510, 1, 1);
    *(a1 - 4) = byte_8D4568;
    *(a1 - 1) = 4;
    if ( byte_8D4568 )
      CEHFrameSetup((int)a1, (int)&unk_8D44B8, 1, 1, 1);
    *(int *)((char *)&dword_8D4478 + *(_DWORD *)(dword_8D4478 + 4) + 44) = (int)byte_8D4568;
    *(a1 - 4) = dword_8D4400;
    *(a1 - 1) = 5;
    if ( dword_8D4400 )
      CEHFrameSetup((int)a1, (int)&unk_8D45A0, 1, 1, 1);
    v3 = dword_8D4400[0];
    *(a1 - 4) = dword_8D4440;
    *(int *)((char *)&dword_8D4400[11] + *(_DWORD *)(v3 + 4)) = (int)byte_8D4568;
    *(int *)((char *)&dword_8D4400[3] + *(_DWORD *)(dword_8D4400[0] + 4)) |= 2u;
    *(a1 - 1) = 6;
    if ( dword_8D4440 )
      CEHFrameSetup((int)a1, (int)&unk_8D45A0, 1, 1, 1);
    *(int *)((char *)&dword_8D446C + *(_DWORD *)(dword_8D4440[0] + 4)) = (int)byte_8D4568;
  }
  return *(a1 - 5);
}

