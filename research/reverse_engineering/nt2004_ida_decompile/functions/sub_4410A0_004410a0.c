void __thiscall sub_4410A0(int this)
{
  double *v2; // ecx
  int v3; // edx
  double v4; // st7
  int v5; // ecx
  int v6; // edx
  double *v7; // ecx
  int v8; // edx
  double v9; // st7
  int v10; // ecx
  int v11; // edx
  double *v12; // ecx
  int v13; // edx
  double v14; // st7
  int v15; // ecx
  int v16; // edx
  int v17; // eax
  double *v18; // eax
  double v19; // [esp+0h] [ebp-8h]

  if ( *(_DWORD *)(this + 8684)
    || *(_DWORD *)(this + 8688) != 1072693248
    || *(_DWORD *)(this + 8692)
    || *(_DWORD *)(this + 8696) != 1072693248 )
  {
    v2 = (double *)(this + 6604);
    v3 = 3;
    v19 = 1.0 / *(double *)(this + 8684);
    do
    {
      v4 = *v2++;
      --v3;
      *(v2 - 1) = v4 * *(double *)(this + 8692);
    }
    while ( v3 );
    v5 = this + 6628;
    v6 = 3;
    do
    {
      v5 += 8;
      --v6;
      *(double *)(v5 - 8) = v19 * *(double *)(v5 - 8);
    }
    while ( v6 );
    v7 = (double *)(this + 6652);
    v8 = 3;
    do
    {
      v9 = *v7++;
      --v8;
      *(v7 - 1) = v9 * *(double *)(this + 8692);
    }
    while ( v8 );
    v10 = this + 6676;
    v11 = 3;
    do
    {
      v10 += 8;
      --v11;
      *(double *)(v10 - 8) = v19 * *(double *)(v10 - 8);
    }
    while ( v11 );
    v12 = (double *)(this + 6700);
    v13 = 2;
    do
    {
      v14 = *v12++;
      --v13;
      *(v12 - 1) = v14 * *(double *)(this + 8692);
    }
    while ( v13 );
    v15 = this + 6716;
    v16 = 2;
    do
    {
      v15 += 8;
      --v16;
      *(double *)(v15 - 8) = v19 * *(double *)(v15 - 8);
    }
    while ( v16 );
    sub_438CE0(this + 6756, *(double *)(this + 8684), *(double *)(this + 8692));
    sub_438CE0(v17 + 6880, *(double *)(v17 + 8684), *(double *)(v17 + 8692));
    *(double *)((char *)v18 + 7052) = *(double *)((char *)v18 + 7052) * *(double *)((char *)v18 + 8692);
    *(double *)((char *)v18 + 7060) = *(double *)((char *)v18 + 7060) * *(double *)((char *)v18 + 8692);
    *(double *)((char *)v18 + 7260) = *(double *)((char *)v18 + 7260) * v19;
    v18[912] = *(double *)((char *)v18 + 8692) * v18[912];
    v18[937] = v18[937] * v19;
    v18[941] = v19 * v18[941];
    v18[942] = v19 * v18[942];
    v18[943] = v19 * v18[943];
    v18[965] = v18[965] * v19;
    *(double *)((char *)v18 + 7756) = *(double *)((char *)v18 + 8692) * *(double *)((char *)v18 + 7756);
    *(double *)((char *)v18 + 7764) = *(double *)((char *)v18 + 8692) * *(double *)((char *)v18 + 7764);
    *(double *)((char *)v18 + 7772) = *(double *)((char *)v18 + 8692) * *(double *)((char *)v18 + 7772);
    *(double *)((char *)v18 + 7780) = *(double *)((char *)v18 + 8692) * *(double *)((char *)v18 + 7780);
  }
}
