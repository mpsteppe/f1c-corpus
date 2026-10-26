// f1c  0x0043ec80  size=660
void __thiscall sub_43EC80(double *this)
{
  double v1; // st7
  double v2; // st7
  double *v3; // ecx
  double v4; // st7
  double v5; // st7
  double *v6; // ecx
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // [esp+0h] [ebp-8h]
  double v11; // [esp+0h] [ebp-8h]
  double v12; // [esp+0h] [ebp-8h]

  v1 = this[897];
  if ( v1 <= this[757] )
  {
    if ( this[757] > v1 )
      this[757] = v1;
  }
  else
  {
    this[757] = v1;
  }
  v2 = this[898];
  if ( v2 <= this[760] )
  {
    if ( this[760] > v2 )
      this[760] = v2;
  }
  else
  {
    this[760] = v2;
  }
  sub_43BB30(this, this[896]);
  v10 = v3[900] + 0.15;
  v4 = v3[900];
  if ( v4 <= v3[769] )
  {
    if ( v3[769] > v10 )
      v3[769] = v10;
  }
  else
  {
    v3[769] = v4;
  }
  v11 = v3[901] + 0.12;
  v5 = v3[901];
  if ( v5 <= v3[771] )
  {
    if ( v3[771] > v11 )
      v3[771] = v11;
  }
  else
  {
    v3[771] = v5;
  }
  sub_43BBD0(v3, v3[899]);
  v12 = v6[902] + 0.25;
  v7 = v6[902];
  if ( v7 <= v6[888] )
  {
    if ( v6[888] > v12 )
      v6[888] = v12;
  }
  else
  {
    v6[888] = v7;
  }
  v8 = v6[904];
  if ( v8 <= v6[763] )
  {
    if ( v6[763] > v8 )
      v6[763] = v8;
  }
  else
  {
    v6[763] = v8;
  }
  v9 = v6[905];
  if ( v9 <= v6[766] )
  {
    if ( v6[766] > v9 )
      v6[766] = v9;
  }
  else
  {
    v6[766] = v9;
  }
  sub_43BB80(v6, v6[903]);
}
