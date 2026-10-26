int __thiscall sub_526670(_DWORD *this, int a2, int a3)
{
  void *v4; // eax
  int v5; // eax
  double v6; // st7
  CHAR *v7; // eax
  CHAR *v8; // eax
  int v10; // [esp+0h] [ebp-Ch] BYREF
  float v11; // [esp+4h] [ebp-8h]
  float v12; // [esp+8h] [ebp-4h]

  this[1] = 2;
  this[2] = 0;
  this[3] = 0;
  this[4] = 1176255488;
  this[5] = 0;
  v4 = operator new(0x4Cu);
  if ( v4 )
    v5 = sub_5AC560(v4);
  else
    v5 = 0;
  this[6] = v5;
  sub_5AC5A0(1);
  *((_BYTE *)this + 44) = 0;
  v12 = (double)dword_7E8CE8 * 0.0009765625;
  v6 = (double)dword_7E8CEC;
  this[7] = 900;
  this[8] = 2;
  this[9] = 640;
  this[10] = 20;
  v7 = (CHAR *)dword_62A098;
  v11 = v6 * 0.0013020834;
  if ( !dword_62A098 )
    v7 = &byte_629120;
  sub_591F10(v7);
  v10 = 0;
  if ( !sub_5924D0(dword_7DA988, (int)&v10, (int)aFontMas) )
  {
    if ( !sub_592A60(0, aFtframerateBmp, 0x20000) )
    {
      sub_592D90(aFtframerate, 0xFFFFFF, 0, 64, 0, 2);
      sub_592DE0(aFtframerate, LODWORD(v12), LODWORD(v11));
      *this = 2;
    }
    sub_592750(v10);
  }
  v8 = (CHAR *)dword_62A098;
  if ( !dword_62A098 )
    v8 = &byte_629120;
  sub_592030(v8);
  return 0;
}
