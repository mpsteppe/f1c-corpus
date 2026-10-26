int __thiscall sub_4C6E80(_DWORD *this)
{
  _DWORD *v2; // edi
  int i; // edi

  v2 = this + 3;
  FunctionCallWrapper_0b40(dword_5EA560, (int)(this + 3));
  sub_4E4790(v2);
  VehicleResetClear(this + 444);
  UIComponentCleanup((int)(this + 3251));
  DoubleBufferFree(this + 5);
  StructResetReinitializer((int)(this + 4109));
  for ( i = 0; i < dword_5C329C; ++i )
    AIDriverRandomSelector(dword_7C54F0[i], (int)this);
  this[4649] = -1;
  this[4650] = -1;
  VehicleDriverInfoClear(this);
  return sub_4D1670(&dword_8ACEE0);
}
