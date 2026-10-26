// f1c  0x0042d260  size=232
int __thiscall sub_42D260(char *this)
{
  char *v2; // eax
  CHAR Filename[256]; // [esp+0h] [ebp-100h] BYREF

  if ( GetModuleFileNameA(0, Filename, 0x100u) )
    sub_568A60(7, this + 28);
  v2 = (char *)dword_5EC408;
  if ( !dword_5EC408 )
    v2 = &byte_5EA438;
  sub_423890((int *)byte_5EC4C0, (int)v2, 0);
  sub_4B3BD0(&dword_8AAE70);
  sub_4D7660(&dword_8AD254);
  sub_4C52C0(&unk_8AC368);
  if ( dword_8AC488 <= 0 )
  {
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_11, 326) )
      sub_4D7AA0(&unk_8AD25C, aNoSceneFilesFo);
    return 1;
  }
  sub_4C3D80(&unk_8AC388);
  if ( dword_8AC390 <= 0 )
  {
    if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_11, 335) )
      sub_4D7AA0(&unk_8AD25C, aNoVehicleFiles);
    return 1;
  }
  return 0;
}
