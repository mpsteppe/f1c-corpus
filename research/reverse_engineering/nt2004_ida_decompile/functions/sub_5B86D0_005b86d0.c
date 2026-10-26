int __thiscall sub_5B86D0(int this)
{
  _DWORD *v2; // eax

  sub_5B8770(this);
  v2 = operator new(0x24u);
  if ( v2 )
  {
    v2[5] = 0;
    v2[4] = 0;
    v2[3] = 0;
    v2[2] = 0;
    v2[1] = 0;
    *v2 = 0;
    v2[7] = 0;
    v2[6] = 0;
    v2[8] = 0;
  }
  else
  {
    v2 = 0;
  }
  *(_DWORD *)(this + 12) = v2;
  *v2 = 34;
  *(_DWORD *)(*(_DWORD *)(this + 12) + 12) = 1152;
  *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = 66;
  *(_DWORD *)(*(_DWORD *)(this + 12) + 8) = 16;
  if ( !sub_5A7F10(dword_7E6B48, *(int **)(this + 12)) )
    return 0;
  sub_591C60(
    this,
    -1,
    "Error creating shadow vertex buffer for instance %s",
    *(const char **)(*(_DWORD *)(this + 28) + 312));
  return -1;
}
