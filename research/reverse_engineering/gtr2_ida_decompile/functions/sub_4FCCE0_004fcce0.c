int __thiscall sub_4FCCE0(char *this, int a2)
{
  double v2; // st7
  bool v4; // al
  int result; // eax
  _DWORD *v6; // ebx

  v2 = dbl_FB1D18;
  qmemcpy((void *)a2, this + 24, 0x40u);
  qmemcpy((void *)(a2 + 64), this + 88, 0x40u);
  qmemcpy((void *)(a2 + 128), this + 152, 0x40u);
  qmemcpy((void *)(a2 + 192), this + 216, 0x40u);
  qmemcpy((void *)(a2 + 256), this + 280, 0x40u);
  qmemcpy((void *)(a2 + 320), this + 344, 0x40u);
  qmemcpy((void *)(a2 + 384), this + 408, 0x40u);
  qmemcpy((void *)(a2 + 448), this + 472, 0x40u);
  qmemcpy((void *)(a2 + 512), this + 536, 0x40u);
  qmemcpy((void *)(a2 + 576), this + 600, 0x40u);
  *(_BYTE *)(a2 + 640) = this[748];
  *(_BYTE *)(a2 + 641) = this[749];
  *(_DWORD *)(a2 + 644) = *((_DWORD *)this + 188);
  *(_DWORD *)(a2 + 648) = *((_DWORD *)this + 189);
  *(float *)(a2 + 652) = *((float *)this + 190) - v2;
  *(_BYTE *)(a2 + 656) = this[764];
  *(_BYTE *)(a2 + 657) = this[765];
  *(float *)(a2 + 660) = *((float *)this + 195) - v2;
  *(float *)(a2 + 664) = *((float *)this + 196) - v2;
  *(float *)(a2 + 668) = *((float *)this + 197) - v2;
  *(float *)(a2 + 672) = *((float *)this + 198) - v2;
  *(_DWORD *)(a2 + 676) = *((_DWORD *)this + 199);
  *(float *)(a2 + 680) = *((float *)this + 200) - v2;
  *(_DWORD *)(a2 + 684) = *((_DWORD *)this + 201);
  *(_DWORD *)(a2 + 688) = *((_DWORD *)this + 203);
  *(float *)(a2 + 692) = *((float *)this + 204) - v2;
  *(_DWORD *)(a2 + 696) = *((_DWORD *)this + 205);
  *(_DWORD *)(a2 + 700) = *((_DWORD *)this + 206);
  *(_DWORD *)(a2 + 704) = *((_DWORD *)this + 207);
  *(_DWORD *)(a2 + 708) = *((_DWORD *)this + 208);
  *(_DWORD *)(a2 + 712) = *((_DWORD *)this + 209);
  *(_DWORD *)(a2 + 716) = *((_DWORD *)this + 210);
  *(_DWORD *)(a2 + 720) = *((_DWORD *)this + 211);
  *(_DWORD *)(a2 + 724) = *((_DWORD *)this + 212);
  *(_DWORD *)(a2 + 728) = *((_DWORD *)this + 213);
  *(_DWORD *)(a2 + 732) = *((_DWORD *)this + 214);
  *(_DWORD *)(a2 + 736) = *((_DWORD *)this + 215);
  *(_DWORD *)(a2 + 740) = *((_DWORD *)this + 216);
  *(float *)(a2 + 744) = *((float *)this + 217) - v2;
  *(float *)(a2 + 748) = *((float *)this + 218) - v2;
  *(_DWORD *)(a2 + 752) = *((_DWORD *)this + 219);
  *(_DWORD *)(a2 + 756) = *((_DWORD *)this + 220);
  *(_DWORD *)(a2 + 760) = *((_DWORD *)this + 221);
  *(_DWORD *)(a2 + 764) = *((_DWORD *)this + 222);
  *(_DWORD *)(a2 + 768) = *((_DWORD *)this + 223);
  *(_DWORD *)(a2 + 772) = *((_DWORD *)this + 224);
  *(_DWORD *)(a2 + 776) = *((_DWORD *)this + 225);
  *(_DWORD *)(a2 + 780) = *((_DWORD *)this + 226);
  *(_DWORD *)(a2 + 784) = *((_DWORD *)this + 227);
  *(_DWORD *)(a2 + 788) = *((_DWORD *)this + 228);
  *(_DWORD *)(a2 + 792) = *((_DWORD *)this + 229);
  *(_DWORD *)(a2 + 796) = *((_DWORD *)this + 230);
  v4 = *(_DWORD *)this == ((_BYTE)dword_757C1C != 0 ? dword_91E084 : 0) && byte_91BF38;
  *(_BYTE *)(a2 + 800) = v4;
  *(_BYTE *)(a2 + 801) = this[808];
  result = sub_415F80();
  v6 = (_DWORD *)*((_DWORD *)this + 2);
  if ( v6 )
  {
    result = sub_4F6D00(v6, a2 + 900);
    *(_BYTE *)(a2 + 896) = 1;
  }
  else
  {
    *(_BYTE *)(a2 + 896) = 0;
  }
  return result;
}
