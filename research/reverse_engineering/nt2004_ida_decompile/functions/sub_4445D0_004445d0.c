int __thiscall sub_4445D0(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // eax
  double v8; // st7
  double v9; // st6
  double *v10; // ecx
  double v11; // st6
  double v12; // rt1
  double v13; // [esp+20h] [ebp-8h]
  double v14; // [esp+20h] [ebp-8h]

  sub_444560(this);
  result = sub_581DF0(this + 1524);
  v3 = this[1524];
  if ( v3 > 0 )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = this[1556];
      v7 = this[1525];
      v8 = *(double *)(v6 + v4) - *(double *)(v7 + v5 + 308);
      result = v5 + v7;
      v9 = *(double *)(v6 + v4 + 8);
      v10 = (double *)(v4 + v6);
      v11 = v9 - *(double *)(result + 316);
      v5 += 580;
      v4 += 48;
      --v3;
      v13 = v10[2] - *(double *)(result + 324);
      *(double *)(result + 308) = v8 + *(double *)(result + 308);
      *(double *)(result + 316) = v11 + *(double *)(result + 316);
      *(double *)(result + 324) = v13 + *(double *)(result + 324);
      v14 = v10[5] - *(double *)(result + 348);
      v12 = v10[4] - *(double *)(result + 340);
      *(double *)(result + 332) = v10[3] - *(double *)(result + 332) + *(double *)(result + 332);
      *(double *)(result + 340) = v12 + *(double *)(result + 340);
      *(double *)(result + 348) = v14 + *(double *)(result + 348);
    }
    while ( v3 );
  }
  return result;
}
