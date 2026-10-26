// f1c  0x004b8090  size=165
bool __stdcall sub_4B8090(float a1)
{
  char v2[8]; // [esp+8h] [ebp-8h] BYREF

  sub_566D30(LODWORD(a1));
  strcpy(v2, "xxxx");
  a1 = -1.0;
  sub_566C00(v2, 4);
  sub_566C00(&a1, 4);
  return !strcmp(v2, off_5D2434) && a1 == flt_5D2438;
}
