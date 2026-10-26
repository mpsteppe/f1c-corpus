int __thiscall sub_58F430(_DWORD *this, int a2, int a3)
{
  double v4; // st7
  const CHAR *v5; // eax
  const CHAR *v6; // eax
  void *Block; // [esp+Ch] [ebp-Ch] BYREF
  float v9; // [esp+10h] [ebp-8h]
  float v10; // [esp+14h] [ebp-4h]

  this[1] = 2;
  this[2] = 0;
  this[3] = 0;
  this[4] = 1176255488;
  this[5] = 0;
  this[6] = sub_5F5CE0(1);
  *((_BYTE *)this + 44) = 0;
  v10 = (double)*(int *)(dword_FB27A4 + 9408) * 0.0009765625;
  v4 = (double)*(int *)(dword_FB27A4 + 9412);
  this[7] = 900;
  this[8] = 2;
  this[9] = 640;
  this[10] = 20;
  v5 = *(const CHAR **)dword_91CAB0;
  v9 = v4 * 0.0013020834;
  if ( !*(_DWORD *)dword_91CAB0 )
    v5 = WindowName;
  sub_5D9420(dword_FB1CE0, v5, 0);
  Block = 0;
  if ( !sub_5EE940((int)&Block, (char)"UIASSETS.GTR", 0) )
  {
    if ( !sub_5F0D70(dword_FB1CE0, "FTFRAMERATE.BMP", 1, 0) )
    {
      sub_5F05E0("FTFRAMERATE", byte_FFFFFF, 0, 64, 0, 2);
      sub_5F05B0("FTFRAMERATE", LODWORD(v10), LODWORD(v9));
      *this = 2;
    }
    sub_5EEA30(dword_FB1CE0, Block, 0);
  }
  v6 = *(const CHAR **)dword_91CAB0;
  if ( !*(_DWORD *)dword_91CAB0 )
    v6 = WindowName;
  sub_5D9900(dword_FB1CE0, v6, 0);
  return 0;
}
