// f1c  0x004ef180  size=348
void __thiscall sub_4EF180(float *this)
{
  int v2; // edi
  int v3; // ebp
  double **v4; // ebx
  double *v5; // eax
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

  v2 = 0;
  v3 = (int)(this + 494);
  v4 = (double **)(this + 3482);
  do
  {
    v7 = this[451] * this[v2 + 525] + this[450] * this[v2 + 524] + this[v2 + 523] * this[449];
    v8 = this[v2 + 523] * this[452] + this[453] * this[v2 + 524] + this[v2 + 525] * this[454];
    v9 = this[457] * this[v2 + 525] + this[v2 + 524] * this[456] + this[455] * this[v2 + 523];
    sub_4EC020(&v7, this + 443);
    v5 = *v4;
    v11[0] = v7;
    v11[1] = v8;
    v11[2] = v9;
    v12 = -1610612736;
    v13 = 1069128089;
    v14 = 0x40000000;
    v15 = 1201543096;
    v17 = v5;
    v6 = sub_44C550(dbl_7C9360, v11, v10);
    if ( v6 )
    {
      v8 = v16 + 0.050000001;
      *v4 = v6;
      sub_4CE110(*((int **)v6 + 21), v3, &v7, v10);
    }
    v2 += 74;
    v4 += 62;
    v3 += 296;
  }
  while ( v2 < 296 );
}
