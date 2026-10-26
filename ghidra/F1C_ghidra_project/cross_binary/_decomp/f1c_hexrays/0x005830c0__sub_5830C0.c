// f1c  0x005830c0  size=134
_DWORD *__thiscall sub_5830C0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edi

  v3 = (_DWORD *)sub_587C03(8316);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = 2;
    sub_58A6EB(v3 + 1, 4156, 2, sub_582110, nullsub_2);
    *this = v4;
  }
  else
  {
    *this = 0;
  }
  return this;
}
