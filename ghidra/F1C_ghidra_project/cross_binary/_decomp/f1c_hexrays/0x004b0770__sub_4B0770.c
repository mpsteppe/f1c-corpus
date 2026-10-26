// f1c  0x004b0770  size=448
int __thiscall sub_4B0770(int *this, int a2)
{
  char *v3; // ecx
  _DWORD v5[7]; // [esp+Ch] [ebp-11Ch] BYREF
  CHAR FileName[256]; // [esp+28h] [ebp-100h] BYREF

  sub_568620(256);
  sub_566650(FileName);
  v3 = &byte_5EA438[strlen(byte_5EA438)];
  if ( v3 > byte_5EA438 )
  {
    while ( *v3 != 46 )
    {
      if ( --v3 <= byte_5EA438 )
        goto LABEL_6;
    }
    *v3 = 0;
  }
LABEL_6:
  sub_5665B0(aTmp);
  sub_58BA36(FileName, 128);
  sub_58BA36(byte_5EA438, 128);
  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_20, 1766) )
    sub_4D7AA0(&unk_8AD25C, aAttemptingToSa);
  sub_5668B0(v5);
  sub_566940(byte_5EA438, 0, 1, 1);
  if ( v5[0] )
    sub_4A1D50(this, (int)v5, (int)asc_5D2018);
  sub_566B90(v5);
  sub_4B0930(this);
  sub_4330D0(&dword_7C73E8, (int)this);
  sub_58986E(FileName);
  sub_5898D3(byte_5EA438, FileName);
  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_20, 1789) )
    sub_4D7AA0(&unk_8AD25C, aRetcodeDForRen);
  sub_5668D0(v5);
  return 0;
}
