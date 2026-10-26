int __thiscall sub_446B00(int this, double a2)
{
  double v3; // st7
  int v4; // edx
  _DWORD *v5; // eax
  _DWORD *v6; // edi
  int v7; // esi
  bool v8; // zf
  int v10; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h]

  *(double *)(this + 8664) = *(double *)(this + 8656);
  *(double *)(this + 9152) = *(double *)(this + 9144);
  *(double *)(this + 896) = *(double *)(this + 888);
  qmemcpy((void *)(this + 976), (const void *)(this + 944), 0x20u);
  *(double *)(this + 912) = *(double *)(this + 904);
  *(double *)(this + 2176) = *(double *)(this + 2168);
  *(double *)(this + 2192) = *(double *)(this + 2184);
  *(double *)(this + 3456) = *(double *)(this + 3448);
  *(double *)(this + 3472) = *(double *)(this + 3464);
  *(double *)(this + 4736) = *(double *)(this + 4728);
  v3 = *(double *)(this + 4744);
  qmemcpy((void *)(this + 2256), (const void *)(this + 2224), 0x20u);
  *(double *)(this + 4752) = v3;
  qmemcpy((void *)(this + 3536), (const void *)(this + 3504), 0x20u);
  qmemcpy((void *)(this + 4816), (const void *)(this + 4784), 0x20u);
  v4 = 0;
  if ( *(int *)(this + 6244) > 0 )
  {
    v10 = 0;
    v11 = *(_DWORD *)(this + 6244);
    do
    {
      v5 = (_DWORD *)(v4 + *(_DWORD *)(this + 6248));
      v6 = (_DWORD *)(v10 + *(_DWORD *)(this + 6376));
      *v6 = v5[78];
      v6[1] = v5[79];
      v6[2] = v5[80];
      v6[3] = v5[81];
      v6[4] = v5[82];
      v7 = v5[83];
      v5 += 84;
      v6[5] = v7;
      v6[6] = *v5;
      v6[7] = v5[1];
      v6[8] = v5[2];
      v6[9] = v5[3];
      v6[10] = v5[4];
      v6[11] = v5[5];
      v4 += 584;
      v8 = v11 == 1;
      v10 += 48;
      --v11;
    }
    while ( !v8 );
  }
  sub_4445D0();
  sub_61DD30(this + 6244);
  sub_61DE90(this + 6244);
  sub_61E060(a2);
  return sub_446A80();
}
