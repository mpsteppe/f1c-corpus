double *__thiscall sub_619590(int this, double a2)
{
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // ecx
  int v9; // ecx
  double v10; // st6
  double *v11; // ecx
  double v13[3]; // [esp+8h] [ebp-18h] BYREF

  v3 = (_DWORD *)(this + 8);
  v4 = *(_DWORD *)(this + 8);
  v5 = (_DWORD *)(this + 360);
  *v5 = v4;
  v5[1] = v3[1];
  v5[2] = v3[2];
  v5[3] = v3[3];
  v5[4] = v3[4];
  v5[5] = v3[5];
  qmemcpy((void *)(this + 384), (const void *)(this + 32), 0x58u);
  v6 = *(_DWORD *)(this + 124);
  *(_DWORD *)(this + 472) = *(_DWORD *)(this + 120);
  *(_DWORD *)(this + 476) = v6;
  *(_DWORD *)(this + 480) = *(_DWORD *)(this + 152);
  *(_DWORD *)(this + 484) = *(_DWORD *)(this + 156);
  *(_DWORD *)(this + 488) = *(_DWORD *)(this + 160);
  *(_DWORD *)(this + 492) = *(_DWORD *)(this + 164);
  v7 = *(_DWORD *)(this + 172);
  *(_DWORD *)(this + 496) = *(_DWORD *)(this + 168);
  *(_DWORD *)(this + 500) = v7;
  *(_DWORD *)(this + 504) = *(_DWORD *)(this + 312);
  *(_DWORD *)(this + 508) = *(_DWORD *)(this + 316);
  *(_DWORD *)(this + 512) = *(_DWORD *)(this + 320);
  *(_DWORD *)(this + 516) = *(_DWORD *)(this + 324);
  v8 = *(_DWORD *)(this + 332);
  *(_DWORD *)(this + 520) = *(_DWORD *)(this + 328);
  *(_DWORD *)(this + 524) = v8;
  *(_DWORD *)(this + 528) = *(_DWORD *)(this + 336);
  *(_DWORD *)(this + 532) = *(_DWORD *)(this + 340);
  *(_DWORD *)(this + 536) = *(_DWORD *)(this + 344);
  *(_DWORD *)(this + 540) = *(_DWORD *)(this + 348);
  v9 = *(_DWORD *)(this + 356);
  *(_DWORD *)(this + 544) = *(_DWORD *)(this + 352);
  *(_DWORD *)(this + 548) = v9;
  *(double *)(this + 8) = a2 * *(double *)(this + 104) + *(double *)(this + 8);
  *(double *)(this + 16) = a2 * *(double *)(this + 112) + *(double *)(this + 16);
  *(double *)(this + 24) = a2 * *(double *)(this + 120) + *(double *)(this + 24);
  v10 = a2 * *(double *)(this + 184);
  *(double *)(this + 104) = v10 * *(double *)(this + 312) + *(double *)(this + 104);
  *(double *)(this + 112) = v10 * *(double *)(this + 320) + *(double *)(this + 112);
  *(double *)(this + 120) = v10 * *(double *)(this + 328) + *(double *)(this + 120);
  v13[0] = a2 * *(double *)(this + 128);
  v13[1] = a2 * *(double *)(this + 136);
  v13[2] = a2 * *(double *)(this + 144);
  sub_61BAD0(v13);
  *(double *)(this + 152) = a2 * *(double *)(this + 336) + *(double *)(this + 152);
  *(double *)(this + 160) = a2 * *(double *)(this + 344) + *(double *)(this + 160);
  *(double *)(this + 168) = a2 * *(double *)(this + 352) + *(double *)(this + 168);
  sub_618D20((double *)this);
  return sub_46FE60(v11, (double *)(this + 152), (double *)(this + 128));
}
