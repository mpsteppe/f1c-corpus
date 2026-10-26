int sub_527F30()
{
  const char *v0; // eax
  int v1; // eax
  char *v2; // eax
  char *v3; // edx
  char v4; // cl
  int v5; // ecx
  char *i; // eax
  int v7; // ecx
  const char *v8; // ecx
  const char *v9; // eax
  int v10; // ecx
  char *v11; // eax
  const char *v12; // eax
  char v15[512]; // [esp+2h] [ebp-500h] BYREF
  char Buffer[512]; // [esp+202h] [ebp-300h] BYREF
  char v17[256]; // [esp+402h] [ebp-100h] BYREF

  if ( sub_500F90(&unk_7D7920, 2, aDDevNascar2004_26, 1149) )
    sub_500FE0((int)&unk_7D7920, aEnteredVidmanI);
  byte_7DA994 = 0;
  sub_592EF0(3 - dword_767A78);
  sub_592F20(dword_768030);
  sub_592F00(dword_768054);
  sub_5A9290(dword_767FAC >= 2);
  switch ( dword_767FAC )
  {
    case 1:
      sub_595430(1, 0);
      sub_595430(2, 0);
      break;
    case 2:
      sub_595430(1, 0);
      sub_595430(2, 1);
      break;
    case 3:
      sub_595430(1, 1);
      sub_595430(2, 1);
      break;
    default:
      sub_595430(1, 0);
      sub_595430(2, 0);
      sub_595430(4, 0);
      sub_595430(8, 0);
      sub_595430(16, 1);
      goto LABEL_11;
  }
  sub_595430(4, 1);
  sub_595430(8, 1);
  sub_595430(16, 0);
LABEL_11:
  v0 = dword_766594;
  if ( !dword_766594 )
    v0 = &byte_629120;
  sub_4E8C80(v0);
  v1 = 400 * dword_7D6B54 + dword_7D6B58;
  if ( v1 )
  {
    v2 = (char *)(v1 + 4);
    v3 = (char *)(v15 - v2);
    do
    {
      v4 = *v2;
      v2[(_DWORD)v3] = *v2;
      ++v2;
    }
    while ( v4 );
    v5 = strlen(v15);
    if ( v5 > 0 )
    {
      for ( i = &v15[v5 - 1]; i >= v15; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v7 = strlen(v15);
    if ( v7 > 0 && v15[v7 - 1] == 92 )
      v15[v7 - 1] = 0;
    sub_591F10(v15);
  }
  v8 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v8 = &byte_629120;
  v9 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v9 = &byte_629120;
  sprintf(Buffer, "%s%s", v9, v8);
  v10 = strlen(Buffer);
  if ( v10 > 0 && v15[v10 + 511] == 92 )
    v15[v10 + 511] = 0;
  sub_591F10(Buffer);
  sub_526D90((void *)1, 0.0);
  uTimerID = timeSetEvent(0x43u, 0xAu, (LPTIMECALLBACK)fptc, (DWORD_PTR)sub_526D90, 1u);
  v11 = dword_766578;
  if ( !dword_766578 )
    v11 = &byte_629120;
  if ( sub_598240(&dword_7DA9B8, v11, 0) )
  {
    sub_591C90(0, v17);
    if ( sub_500F90(&unk_7D7920, 1, aDDevNascar2004_26, 1249) )
    {
      v12 = dword_766578;
      if ( !dword_766578 )
        v12 = &byte_629120;
      sub_500FE0((int)&unk_7D7920, "CUBE error loading scene file %s: %s", v12, v17);
    }
    return 1;
  }
  else
  {
    sub_597BA0(2);
    sub_592030(v15);
    sub_592030(Buffer);
    return 0;
  }
}
