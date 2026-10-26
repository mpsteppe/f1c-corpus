// f1c  0x004f8d70  size=298
int __thiscall sub_4F8D70(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  double v6; // st7
  char *v7; // eax
  int v9; // [esp+8h] [ebp-Ch] BYREF
  float v10; // [esp+Ch] [ebp-8h]
  float v11; // [esp+10h] [ebp-4h]

  this[1] = 2;
  this[2] = 0;
  this[3] = 0;
  this[4] = 1176255488;
  this[5] = 0;
  v4 = sub_587C03(76);
  if ( v4 )
    v5 = sub_556220(v4);
  else
    v5 = 0;
  this[6] = v5;
  sub_556260(1);
  *((_BYTE *)this + 44) = 0;
  v11 = (double)dword_8B8DD4 * 0.0009765625;
  v6 = (double)dword_8B8DD8;
  this[7] = 900;
  this[8] = 2;
  this[9] = 640;
  this[10] = 20;
  v7 = (char *)dword_5EC408;
  v10 = v6 * 0.0013020834;
  if ( !dword_5EC408 )
    v7 = byte_5EA438;
  sub_53C800(v7);
  v9 = 0;
  if ( !sub_53CBC0(&v9, aFontMas) )
  {
    if ( !sub_53CFE0(0, aFtframerateBmp, 0x20000) )
    {
      sub_53D260(aFtframerate, 0xFFFFFF, 0, 64, 0, 2);
      sub_53D2B0(aFtframerate, LODWORD(v11), LODWORD(v10));
      *this = 2;
    }
    sub_53CE40(v9);
  }
  return 0;
}
