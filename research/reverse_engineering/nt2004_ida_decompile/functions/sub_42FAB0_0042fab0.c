int __thiscall sub_42FAB0(void *this)
{
  CHAR *v2; // eax
  const char *v3; // ecx
  const char *v4; // eax
  char *v5; // eax
  char *i; // eax
  char *v7; // eax
  char *j; // eax
  char Buffer[256]; // [esp+4h] [ebp-300h] BYREF
  CHAR Filename[512]; // [esp+104h] [ebp-200h] BYREF

  if ( GetModuleFileNameA(0, Filename, 0x200u) )
    sub_57B490(Filename, 123, (int)this + 28);
  if ( sub_4BB930(&unk_7661CC) )
    return 1;
  v2 = (CHAR *)dword_62A098;
  if ( !dword_62A098 )
    v2 = &byte_629120;
  sub_41F0C0((int)dword_62A170, (int)v2, 0);
  sub_4D19F0(&dword_7D3C50);
  sub_500B40(&dword_7D7918);
  v3 = (const char *)dword_62A130;
  if ( !dword_62A130 )
    v3 = &byte_629120;
  v4 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v4 = &byte_629120;
  sprintf(Buffer, "%s%s", v4, v3);
  sub_57AC50(Buffer, 0);
  v5 = *(char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v5 = &byte_629120;
  sub_578A30(aRcd, 1, v5, 0);
  for ( i = (char *)sub_578D80(&unk_7D7A0C); i; i = (char *)sub_578D80(&unk_7D7A0C) )
  {
    sub_57AC50(i, 0);
    sub_5789D0(&unk_7D7A0C);
  }
  v7 = *(char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v7 = &byte_629120;
  sub_578A30(aPit, 1, v7, 0);
  for ( j = (char *)sub_578D80(&unk_7D7A0C); j; j = (char *)sub_578D80(&unk_7D7A0C) )
  {
    sub_57AC50(j, 0);
    sub_5789D0(&unk_7D7A0C);
  }
  sub_4E8880(&byte_7D6A30);
  if ( dword_7D6B50 <= 0 )
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_2, 455) )
      sub_500FE0((int)&unk_7D7920, aNoSceneFilesFo, Buffer[0]);
    return 1;
  }
  sub_4E73E0(&unk_7D6A50);
  if ( dword_7D6A58 <= 0 )
  {
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_2, 464) )
      sub_500FE0((int)&unk_7D7920, aNoVehicleFiles, Buffer[0]);
    return 1;
  }
  return 0;
}
