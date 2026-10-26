void __thiscall sub_51B7F0(float *this)
{
  int v2; // edi
  int v3; // ebp
  double **v4; // ebx
  double *v5; // edx
  double *v6; // eax
  float v7; // [esp+14h] [ebp-4Ch] BYREF
  float v8; // [esp+18h] [ebp-48h]
  float v9; // [esp+1Ch] [ebp-44h]
  float v10[3]; // [esp+20h] [ebp-40h] BYREF
  double v11[3]; // [esp+2Ch] [ebp-34h] BYREF
  int v12; // [esp+44h] [ebp-1Ch]
  int v13; // [esp+48h] [ebp-18h]
  int v14; // [esp+4Ch] [ebp-14h]
  int v15; // [esp+50h] [ebp-10h]
  double v16; // [esp+54h] [ebp-Ch]
  double *v17; // [esp+5Ch] [ebp-4h]

  if ( (*(_DWORD *)(*(_DWORD *)this + 25296) & 2) != 0 )
  {
    v2 = 0;
    v3 = (int)(this + 507);
    v4 = (double **)(this + 4481);
    do
    {
      v7 = this[462] * this[v2 + 540] + this[461] * this[v2 + 539] + this[v2 + 538] * this[460];
      v8 = this[v2 + 538] * this[463] + this[464] * this[v2 + 539] + this[v2 + 540] * this[465];
      v9 = this[468] * this[v2 + 540] + this[v2 + 539] * this[467] + this[466] * this[v2 + 538];
      sub_518460(&v7, this + 454);
      v5 = *v4;
      v11[0] = v7;
      v11[1] = v8;
      v11[2] = v9;
      v12 = -1610612736;
      v13 = 1069128089;
      v14 = 0x40000000;
      v15 = 1201543096;
      v17 = v5;
      v6 = sub_44E990(dbl_760B48, v11, v10);
      if ( v6 )
      {
        v8 = v16 + 0.050000001;
        *v4 = v6;
        sub_4F5C10(*((int **)v6 + 21), v3, &v7, v10);
      }
      v2 += 76;
      v4 += 62;
      v3 += 304;
    }
    while ( v2 < 304 );
  }
}
