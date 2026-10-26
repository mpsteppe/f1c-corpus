void __thiscall sub_598FF0(int this, unsigned __int8 *a2)
{
  int v3; // eax
  int v4; // edi
  float *v5; // eax
  int v6; // ebp
  unsigned __int8 *v7; // edi
  _DWORD *v8; // eax
  float *v9; // eax
  double v10; // st7
  int v11; // edx
  float v12; // [esp+10h] [ebp-4h]

  v3 = *(_DWORD *)(this + 64);
  *(_DWORD *)(this + 60) = 0;
  if ( v3 )
  {
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)(this + 64) + 12);
      j__free(*(void **)(this + 64));
      *(_DWORD *)(this + 64) = v4;
    }
    while ( v4 );
  }
  v12 = dbl_FB1D18;
  v5 = (float *)operator new(0x10u);
  if ( v5 )
  {
    *v5 = 0.0;
    v5[1] = 20.0;
    v5[2] = 0.2;
    v5[3] = 0.0;
  }
  else
  {
    v5 = 0;
  }
  *(_DWORD *)(this + 64) = v5;
  *v5 = v12;
  *(_DWORD *)(*(_DWORD *)(this + 64) + 8) = *((_DWORD *)a2 + 3);
  *(_DWORD *)(*(_DWORD *)(this + 64) + 4) = *((_DWORD *)a2 + 2);
  *(_DWORD *)(this + 60) = *(_DWORD *)(this + 64);
  v6 = 1;
  if ( *a2 > 1u )
  {
    v7 = a2 + 24;
    do
    {
      v8 = operator new(0x10u);
      if ( v8 )
      {
        *v8 = 0;
        v8[1] = 1101004800;
        v8[2] = 1045220557;
        v8[3] = 0;
      }
      else
      {
        v8 = 0;
      }
      *(_DWORD *)(*(_DWORD *)(this + 60) + 12) = v8;
      v9 = *(float **)(*(_DWORD *)(this + 60) + 12);
      *(_DWORD *)(this + 60) = v9;
      v10 = v12 + *((float *)v7 - 2);
      ++v6;
      v7 += 12;
      *v9 = v10;
      *(_DWORD *)(*(_DWORD *)(this + 60) + 8) = *((_DWORD *)v7 - 3);
      *(_DWORD *)(*(_DWORD *)(this + 60) + 4) = *((_DWORD *)v7 - 4);
    }
    while ( v6 < *a2 );
  }
  sub_525140((int *)(this + 96));
  sub_598630();
  *(_DWORD *)(this + 52) = *((_DWORD *)a2 + 437);
  *(_DWORD *)(this + 36) = *((_DWORD *)a2 + 433);
  *(_DWORD *)(this + 48) = *((_DWORD *)a2 + 436);
  *(_DWORD *)(this + 44) = *((_DWORD *)a2 + 435);
  v11 = *(_DWORD *)(this + 64);
  *(_DWORD *)(this + 40) = *((_DWORD *)a2 + 434);
  *(_DWORD *)(this + 56) = *((_DWORD *)a2 + 438);
  *(_DWORD *)(this + 60) = v11;
  sub_592990((float *)this);
}
