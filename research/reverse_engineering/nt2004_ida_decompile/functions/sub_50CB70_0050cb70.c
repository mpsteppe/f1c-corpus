int __thiscall sub_50CB70(float *this, int a2, float a3, float a4, float a5)
{
  double v5; // st7
  int v6; // eax
  double v7; // st7
  int v8; // ebx
  bool v9; // c3
  float v11; // [esp-10h] [ebp-10h]
  float v12; // [esp+10h] [ebp+10h]

  v5 = a3 - this[19];
  v6 = 76 * a2;
  this[v6 + 87] = v5;
  this[v6 + 104] = v5;
  v7 = a5 + this[76 * a2 + 119];
  v8 = (int)&this[76 * a2 + 55];
  v12 = v7;
  v9 = v7 == this[76 * a2 + 107];
  this[76 * a2 + 120] = a4;
  if ( !v9 )
  {
    v11 = this[76 * a2 + 108];
    this[76 * a2 + 107] = v12;
    sub_5798E0(v12, v11);
  }
  qmemcpy((void *)(v8 + 148), (const void *)(v8 + 216), 0x24u);
  return sub_579B50(a4, v8 + 136);
}
