// f1c  0x004e24a0  size=156
int __thiscall sub_4E24A0(float *this, int a2, float a3, float a4, float a5)
{
  double v5; // st7
  int v6; // eax
  double v7; // st7
  int v8; // ebx
  bool v9; // c3
  float v11; // [esp-10h] [ebp-10h]
  float v12; // [esp+10h] [ebp+10h]

  v5 = a3 - this[19];
  v6 = 74 * a2;
  this[v6 + 83] = v5;
  this[v6 + 100] = v5;
  v7 = a5 + this[74 * a2 + 115];
  v8 = (int)&this[74 * a2 + 53];
  v12 = v7;
  v9 = v7 == this[74 * a2 + 103];
  this[74 * a2 + 116] = a4;
  if ( !v9 )
  {
    v11 = this[74 * a2 + 104];
    this[74 * a2 + 103] = v12;
    sub_5670D0(v12, v11);
  }
  qmemcpy((void *)(v8 + 140), (const void *)(v8 + 208), 0x24u);
  return sub_567340(a4, v8 + 128);
}
