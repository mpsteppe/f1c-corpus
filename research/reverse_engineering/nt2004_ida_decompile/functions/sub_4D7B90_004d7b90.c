bool __stdcall sub_4D7B90(float a1)
{
  _DWORD Buffer[2]; // [esp+8h] [ebp-8h] BYREF

  sub_57A530(LODWORD(a1));
  strcpy((char *)Buffer, "xxxx");
  a1 = -1.0;
  sub_57A3D0(Buffer, 4u);
  sub_57A3D0(&a1, 4u);
  return !strcmp((const char *)Buffer, (const char *)off_60FE44) && a1 == flt_60FE48;
}
