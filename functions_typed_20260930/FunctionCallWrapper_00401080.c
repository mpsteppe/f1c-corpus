_DWORD *FunctionCallWrapper()
{
  _DWORD *result; // eax
  int v1; // ecx
  _DWORD *v2; // edx

  result = dword_5EA2C0;
  v1 = 0;
  v2 = &dword_5EA2C0[2];
  do
    *v2++ = ++v1;
  while ( v1 < 4 );
  byte_5EA3EC = 0;
  dword_5EA3F0 = 0;
  *(_DWORD *)algn_5EA3F4 = 0;
  flt_5EA3F8[0] = 0.0;
  flt_5EA408 = 0.0;
  flt_5EA40C = 0.0;
  dword_5EA2C0[0] = 1083703296;
  dword_5EA2C0[1] = 1082785792;
  flt_5EA3E8 = 0.995;
  unk_5EA420 = 104;
  unk_5EA424 = 52;
  unk_5EA428 = 3;
  unk_5EA41C = 1;
  return result;
}

