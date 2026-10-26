double *__thiscall sub_619A40(int this)
{
  _DWORD *v2; // ecx
  int v3; // esi
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  double *v8; // eax
  double *v9; // edx

  v2 = (_DWORD *)(this + 360);
  *(_DWORD *)(this + 8) = *v2;
  *(_DWORD *)(this + 12) = v2[1];
  *(_DWORD *)(this + 16) = v2[2];
  *(_DWORD *)(this + 20) = v2[3];
  v3 = v2[4];
  v4 = v2[5];
  *(_DWORD *)(this + 24) = v3;
  *(_DWORD *)(this + 28) = v4;
  qmemcpy((void *)(this + 32), (const void *)(this + 384), 0x60u);
  *(_DWORD *)(this + 152) = *(_DWORD *)(this + 480);
  *(_DWORD *)(this + 156) = *(_DWORD *)(this + 484);
  *(_DWORD *)(this + 160) = *(_DWORD *)(this + 488);
  *(_DWORD *)(this + 164) = *(_DWORD *)(this + 492);
  v5 = *(_DWORD *)(this + 500);
  *(_DWORD *)(this + 168) = *(_DWORD *)(this + 496);
  *(_DWORD *)(this + 172) = v5;
  *(_DWORD *)(this + 312) = *(_DWORD *)(this + 504);
  *(_DWORD *)(this + 316) = *(_DWORD *)(this + 508);
  *(_DWORD *)(this + 320) = *(_DWORD *)(this + 512);
  *(_DWORD *)(this + 324) = *(_DWORD *)(this + 516);
  v6 = *(_DWORD *)(this + 524);
  *(_DWORD *)(this + 328) = *(_DWORD *)(this + 520);
  *(_DWORD *)(this + 332) = v6;
  *(_DWORD *)(this + 336) = *(_DWORD *)(this + 528);
  *(_DWORD *)(this + 340) = *(_DWORD *)(this + 532);
  *(_DWORD *)(this + 344) = *(_DWORD *)(this + 536);
  *(_DWORD *)(this + 348) = *(_DWORD *)(this + 540);
  v7 = *(_DWORD *)(this + 548);
  *(_DWORD *)(this + 352) = *(_DWORD *)(this + 544);
  *(_DWORD *)(this + 356) = v7;
  sub_618D20((double *)this);
  return sub_46FE60(v8, v9, v8 + 16);
}
