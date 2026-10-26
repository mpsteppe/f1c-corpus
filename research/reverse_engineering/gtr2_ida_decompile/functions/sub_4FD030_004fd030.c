void __thiscall sub_4FD030(int this, int a2)
{
  double v2; // st7
  char v4; // al
  _DWORD *v5; // ecx

  v2 = dbl_FB1D18;
  qmemcpy((void *)(this + 24), (const void *)a2, 0x40u);
  qmemcpy((void *)(this + 88), (const void *)(a2 + 64), 0x40u);
  qmemcpy((void *)(this + 152), (const void *)(a2 + 128), 0x40u);
  qmemcpy((void *)(this + 216), (const void *)(a2 + 192), 0x40u);
  qmemcpy((void *)(this + 280), (const void *)(a2 + 256), 0x40u);
  qmemcpy((void *)(this + 344), (const void *)(a2 + 320), 0x40u);
  qmemcpy((void *)(this + 408), (const void *)(a2 + 384), 0x40u);
  qmemcpy((void *)(this + 472), (const void *)(a2 + 448), 0x40u);
  qmemcpy((void *)(this + 536), (const void *)(a2 + 512), 0x40u);
  qmemcpy((void *)(this + 600), (const void *)(a2 + 576), 0x40u);
  *(_BYTE *)(this + 748) = *(_BYTE *)(a2 + 640);
  *(_BYTE *)(this + 749) = *(_BYTE *)(a2 + 641);
  *(_DWORD *)(this + 752) = *(_DWORD *)(a2 + 644);
  *(_DWORD *)(this + 756) = *(_DWORD *)(a2 + 648);
  *(float *)(this + 760) = v2 + *(float *)(a2 + 652);
  *(_BYTE *)(this + 764) = *(_BYTE *)(a2 + 656);
  *(_BYTE *)(this + 765) = *(_BYTE *)(a2 + 657);
  *(float *)(this + 780) = v2 + *(float *)(a2 + 660);
  *(float *)(this + 784) = v2 + *(float *)(a2 + 664);
  *(float *)(this + 788) = v2 + *(float *)(a2 + 668);
  *(float *)(this + 792) = v2 + *(float *)(a2 + 672);
  *(_DWORD *)(this + 796) = *(_DWORD *)(a2 + 676);
  *(float *)(this + 800) = v2 + *(float *)(a2 + 680);
  *(_DWORD *)(this + 804) = *(_DWORD *)(a2 + 684);
  *(_DWORD *)(this + 812) = *(_DWORD *)(a2 + 688);
  *(float *)(this + 816) = v2 + *(float *)(a2 + 692);
  *(_DWORD *)(this + 820) = *(_DWORD *)(a2 + 696);
  *(_DWORD *)(this + 824) = *(_DWORD *)(a2 + 700);
  *(_DWORD *)(this + 828) = *(_DWORD *)(a2 + 704);
  *(_DWORD *)(this + 832) = *(_DWORD *)(a2 + 708);
  *(_DWORD *)(this + 836) = *(_DWORD *)(a2 + 712);
  *(_DWORD *)(this + 840) = *(_DWORD *)(a2 + 716);
  *(_DWORD *)(this + 844) = *(_DWORD *)(a2 + 720);
  *(_DWORD *)(this + 848) = *(_DWORD *)(a2 + 724);
  *(_DWORD *)(this + 852) = *(_DWORD *)(a2 + 728);
  *(_DWORD *)(this + 856) = *(_DWORD *)(a2 + 732);
  *(_DWORD *)(this + 860) = *(_DWORD *)(a2 + 736);
  *(_DWORD *)(this + 864) = *(_DWORD *)(a2 + 740);
  *(float *)(this + 868) = v2 + *(float *)(a2 + 744);
  *(float *)(this + 872) = v2 + *(float *)(a2 + 748);
  *(_DWORD *)(this + 876) = *(_DWORD *)(a2 + 752);
  *(_DWORD *)(this + 880) = *(_DWORD *)(a2 + 756);
  *(_DWORD *)(this + 884) = *(_DWORD *)(a2 + 760);
  *(_DWORD *)(this + 888) = *(_DWORD *)(a2 + 764);
  *(_DWORD *)(this + 892) = *(_DWORD *)(a2 + 768);
  *(_DWORD *)(this + 896) = *(_DWORD *)(a2 + 772);
  *(_DWORD *)(this + 900) = *(_DWORD *)(a2 + 776);
  *(_DWORD *)(this + 904) = *(_DWORD *)(a2 + 780);
  *(_DWORD *)(this + 908) = *(_DWORD *)(a2 + 784);
  *(_DWORD *)(this + 912) = *(_DWORD *)(a2 + 788);
  *(_DWORD *)(this + 916) = *(_DWORD *)(a2 + 792);
  *(_DWORD *)(this + 920) = *(_DWORD *)(a2 + 796);
  if ( *(_BYTE *)(a2 + 800) )
    sub_413DA0();
  v4 = *(_BYTE *)(a2 + 801);
  *(_BYTE *)(this + 808) = v4;
  if ( v4 )
  {
    sub_4FCB90();
    if ( *(_DWORD *)(this + 924) != 1 )
      sub_416040(this + 924, a2 + 804);
  }
  v5 = *(_DWORD **)(this + 8);
  if ( v5 )
  {
    if ( *(_BYTE *)(a2 + 896) )
      sub_4F6E40(v5, a2 + 900);
  }
}
