_DWORD *__thiscall sub_4AB5B0(_DWORD *this)
{
  _DWORD *v2; // ebx
  _DWORD *v3; // ebx
  int v4; // ebp
  CHAR *v5; // eax
  CHAR *v6; // eax
  int v8; // [esp+10h] [ebp-4h] BYREF

  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[14] = 0;
  this[15] = -1;
  this[27] = 0;
  this[26] = 0;
  this[25] = 0;
  this[24] = 0;
  this[23] = 0;
  this[22] = 0;
  this[21] = 0;
  this[28] = 0;
  v2 = this + 46;
  this[35] = 0;
  this[34] = 0;
  this[33] = 0;
  this[32] = 0;
  this[31] = 0;
  this[30] = 0;
  this[29] = 0;
  this[36] = 0;
  sub_506720(this + 46);
  v2[10] = 0;
  v2[11] = -1;
  v2[12] = 0;
  v2[13] = -1;
  sub_506BA0(v2);
  this[78] = 0;
  this[79] = 0;
  this[80] = 0;
  this[81] = 0;
  this[87] = 0;
  this[88] = 0;
  this[89] = 0;
  this[90] = 0;
  this[94] = -1;
  this[93] = 0;
  v3 = this + 127;
  v4 = 4;
  do
  {
    sub_4AFC60(v3);
    v3 += 3;
    --v4;
  }
  while ( v4 );
  sub_4AA640((int)(this + 148));
  unknown_libname_45(this + 274);
  this[275] = 0;
  this[276] = 0;
  this[277] = 0;
  this[278] = 0;
  this[279] = 0;
  this[280] = 0;
  this[281] = 0;
  this[282] = 0;
  *this = &off_5EA21C;
  sub_4AC840(this);
  this[65] = 0;
  v5 = (CHAR *)dword_62A098;
  if ( !dword_62A098 )
    v5 = &byte_629120;
  sub_591F10(v5);
  v8 = 0;
  if ( !sub_5924D0(dword_7DA988, (int)&v8, (int)aFontMas) )
  {
    if ( !sub_592A60(0, a2003tri14Tga, 0x20000) || !sub_592A60(0, a2003tri14Bmp, 0x20000) )
      this[65] = sub_592CD0(a2003tri14);
    sub_592750(v8);
  }
  v6 = (CHAR *)dword_62A098;
  if ( !dword_62A098 )
    v6 = &byte_629120;
  sub_592030(v6);
  return this;
}
