char __thiscall sub_4C6E80(F1CVehicle *this)
{
  unsigned __int8 *v2; // edi
  int i; // edi

  v2 = &this->gap_0004[8];
  FunctionCallWrapper_0b40(dword_5EA560, (int)&this->gap_0004[8]);
  sub_4E4790((int)v2);
  VehicleResetClear((char *)this->RenderObject);
  UIComponentCleanup((int)this->gap_32CC);
  DoubleBufferFree((int)&this->gap_0004[16]);
  StructResetReinitializer((int)&this->gap_3D80[692]);
  for ( i = 0; i < dword_5C329C; ++i )
    AIDriverRandomSelector((int)*(&dword_7C54F0 + i), (int)this);
  this->PitTeamIndex = -1;
  *(_DWORD *)this->gap_48A8 = -1;
  VehicleDriverInfoClear(this);
  return sub_4D1670(dword_8ACEE0);
}

