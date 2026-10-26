void __thiscall sub_42BC50(_DWORD *this, char *a2)
{
  char *v3; // eax
  char v4; // cl
  const char *v5; // eax
  double v6; // st7
  bool v7; // zf
  int v8; // edx
  char *v9; // edi
  const char *v10; // [esp+1Ch] [ebp-B8h] BYREF
  float v11[2]; // [esp+20h] [ebp-B4h] BYREF
  double v12; // [esp+38h] [ebp-9Ch]
  double v13; // [esp+40h] [ebp-94h]
  double v14; // [esp+50h] [ebp-84h]
  double v15; // [esp+58h] [ebp-7Ch]
  double v16; // [esp+60h] [ebp-74h]
  int v17; // [esp+C8h] [ebp-Ch]

  sub_4309C0(&dword_B640C0, 1);
  dword_B640C0 = 5;
  dword_FADE4C = this[267];
  sub_594840(&dword_FB1EF8);
  if ( byte_B73990 )
    sub_463BC0(&unk_B6A328);
  *((_BYTE *)this + 1027) = 0;
  sub_42A8C0();
  this[265] = 0;
  this[266] = 0;
  v3 = a2;
  do
  {
    v4 = *v3;
    v3[(char *)this - a2 + 760] = *v3;
    ++v3;
  }
  while ( v4 );
  sub_5401B0(&unk_BE1D30);
  v11[0] = 0.0;
  v11[1] = NAN;
  v17 = 0;
  sub_42A7F0();
  sub_615A50(a2);
  sub_615A50(&off_6F3620);
  v5 = v10;
  if ( !v10 )
    v5 = WindowName;
  if ( sub_42AED0((double *)this, v5) )
  {
    v6 = *((float *)this + 110);
    *((_BYTE *)this + 1040) = 0;
    this[263] = 0;
    *((_BYTE *)this + 496) = v6 < 1.0;
    sub_42B8D0(this, *((_BYTE *)this + 496));
    sub_5284C0(0, 0);
    sub_42A7F0();
    sub_615A50(a2);
    sub_615A50(".DSI");
    v7 = *((_BYTE *)this + 496) == 0;
    v11[0] = *((float *)this + 106);
    if ( !v7 && *((_BYTE *)this + 1024) )
      v11[0] = v11[0] - 4.0;
    sub_52A620(1, LODWORD(v11[0]), 0);
    if ( *((_BYTE *)this + 1024) )
      sub_414450(&dword_91BF20, 0);
    else
      sub_414450(&dword_91BF20, 1);
    LOBYTE(v8) = *((_BYTE *)this + 1024) != 1;
    *((_BYTE *)this + 481) = 0;
    *((_BYTE *)this + 468) = 0;
    sub_53F190(&unk_925CF8, v8, &v10, v11);
    if ( *((_BYTE *)this + 1024) )
    {
      v9 = (char *)&unk_B66308;
      do
      {
        sub_4398C0(v11);
        v14 = *((double *)this + 54);
        v15 = *((double *)this + 54);
        v16 = *((double *)this + 54);
        v12 = *((double *)this + 54);
        v13 = 200.0;
        sub_439970(v11);
        v9 += 1280;
      }
      while ( (int)v9 < (int)byte_B67708 );
      sub_57DE20(*this, *this + 24);
      *((_BYTE *)this + 480) = 0;
      *((_BYTE *)this + 1048) = 0;
      sub_44A3C0(&dbl_B66040, 0, 0);
      byte_B660D0 = 1;
      sub_4226C0((float *)dword_91E084, 99999);
      if ( *((_BYTE *)this + 496) == 1 )
      {
        sub_4226C0((float *)dword_91E084, 0);
        if ( *(_DWORD *)(dword_91E084 + 14820) )
        {
          sub_583170(dword_91E084 + 16, 0, 1);
          dword_B6C3D0 = *(_DWORD *)(dword_91E084 + 16152);
        }
        if ( *((_BYTE *)this + 496) || sub_410B50(&dword_91BF20) == 5 )
        {
          sub_412EB0(off_16C9A20, 0, 1);
          sub_412520(this[261], 1, 1);
        }
      }
      else
      {
        sub_57F840(*(float *)(*this + 48));
        sub_4226C0((float *)dword_91E084, (unsigned __int64)*(float *)(*this + 48));
        sub_53E6A0(dword_91E084, 4);
        *((_BYTE *)this + 1048) = 1;
        sub_412EB0(&dword_91BF20, 5, 1);
      }
      sub_44A3C0(&dbl_B66040, 0, 0);
      *((_BYTE *)this + 1026) = 1;
    }
    else
    {
      sub_53E550(dword_91E084, 1, 1);
      sub_583170(dword_91E084 + 16, 0, 1);
      byte_B660D0 = 0;
      *((_BYTE *)this + 480) = 1;
    }
  }
  else
  {
    sub_4E5FC0(&dword_B6E4D0, 5);
    byte_B699B4 = 0;
    byte_B699BC = 0;
    if ( !*((_BYTE *)this + 1024) )
      dword_B6E4D8 = 100;
    if ( *((_BYTE *)this + 1024) == 1 )
      dword_B6E4D8 = 200;
    if ( *((_BYTE *)this + 1024) == 2 )
      dword_B6E4D8 = 300;
    byte_B660D0 = 1;
  }
  j_j__free((void *)1);
}
