int __thiscall sub_4A5330(int this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  int v7; // esi
  int v8; // edi
  bool v9; // cc
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // edx
  int v15; // edi
  int v16; // esi
  int v17; // esi
  int v18; // edi
  int v19; // eax
  _DWORD *v20; // ecx
  _DWORD *v21; // ecx

  qmemcpy((void *)(this + 88), (const void *)(a2 + 3248), 0x40u);
  *(_BYTE *)(this + 117) = 0;
  *(_DWORD *)(this + 108) = *(_DWORD *)(a2 + 6340);
  qmemcpy((void *)(this + 216), (const void *)(a2 + 4720), 0x40u);
  *(_DWORD *)(this + 240) = *(_DWORD *)(this + 236);
  *(_BYTE *)(this + 245) = 0;
  v3 = sub_4D7880(a2 + 112);
  v4 = *(_DWORD *)(this + 348);
  *(_DWORD *)(this + 344) = v3;
  if ( v4 < 0 && dword_7C56A4 >= 5 && dword_7C56A4 <= 7 )
  {
    v5 = *(_DWORD *)(a2 + 3012);
    if ( !*(_BYTE *)(sub_4D7570(v5) + 20) )
      *(_DWORD *)(this + 348) = v5;
  }
  sub_4A57F0(this);
  v6 = *(_DWORD *)(this + 168);
  v7 = 0;
  *(_DWORD *)(this + 172) = 0;
  if ( v6 > 0 )
  {
    do
    {
      v8 = sub_4D7570(*(_DWORD *)(a2 + 3012));
      if ( sub_4A5820(v7) == v8 )
        break;
      ++v7;
    }
    while ( v7 < *(_DWORD *)(this + 168) );
  }
  v9 = v7 < *(_DWORD *)(this + 168);
  *(_DWORD *)(this + 172) = v7;
  if ( !v9 )
    *(_DWORD *)(this + 172) = 1;
  sub_4A5660(0);
  sub_4A56B0(0);
  *(_DWORD *)(this + 352) = *(_DWORD *)(a2 + 6276);
  *(float *)(this + 380) = *(double *)(a2 + 6548);
  if ( *(double *)(a2 + 6548) == 0.0 )
  {
    v10 = *(_DWORD *)(a2 + 6340);
    *(_DWORD *)(this + 356) = 1024;
    *(_DWORD *)(this + 360) = v10;
    v11 = *(_DWORD *)(a2 + 6404);
    *(_DWORD *)(this + 364) = 2048;
    *(_DWORD *)(this + 368) = v11;
    v12 = *(_DWORD *)(a2 + 6468);
    *(_DWORD *)(this + 372) = 3072;
    *(_DWORD *)(this + 376) = v12;
  }
  else
  {
    v13 = sub_587BDC(((double)*(int *)(a2 + 3268) * *(double *)(a2 + 3256) + *(double *)(a2 + 3248)) * *(double *)(a2 + 6548));
    v14 = dword_7D0374;
    *(_DWORD *)(this + 360) = *(_DWORD *)(a2 + 6340);
    v15 = v13 - v14;
    *(_DWORD *)(this + 356) = v13 - v14;
    v16 = sub_587BDC(((double)*(int *)(a2 + 6340) * *(double *)(a2 + 6328) + *(double *)(a2 + 6320)) * *(double *)(a2 + 6548))
        - dword_7D0374;
    *(_DWORD *)(this + 368) = *(_DWORD *)(a2 + 6404);
    v17 = v15 + v16;
    *(_DWORD *)(this + 364) = v17;
    v18 = *(_DWORD *)(a2 + 6468);
    v19 = v17
        + sub_587BDC(((double)*(int *)(a2 + 6404) * *(double *)(a2 + 6392) + *(double *)(a2 + 6384)) * *(double *)(a2 + 6548))
        - dword_7D0374;
    *(_DWORD *)(this + 376) = v18;
    *(_DWORD *)(this + 372) = v19;
  }
  v20 = *(_DWORD **)(this + 12);
  *(_DWORD *)(this + 388) = 0;
  *(_DWORD *)(this + 392) = 0;
  *(_DWORD *)(this + 396) = 0;
  if ( v20 )
    sub_4A3440(v20);
  v21 = *(_DWORD **)(this + 16);
  if ( v21 )
    sub_4A3440(v21);
  return sub_4A5600(*(_DWORD *)(this + 12));
}
