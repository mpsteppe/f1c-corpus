int __thiscall sub_466910(int *this)
{
  int v1; // edx
  float *v2; // eax
  int v3; // eax
  _BYTE v5[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v6; // [esp+45h] [ebp-3h]
  char v7; // [esp+47h] [ebp-1h]

  v1 = *this;
  v5[0] = byte_5EA438[0];
  memset(&v5[1], 0, 0x3Cu);
  v6 = 0;
  v7 = 0;
  v2 = (float *)(*(int (__thiscall **)(int *))(v1 + 180))(this);
  if ( v2 )
  {
    v3 = sub_587BDC(*v2 * 100.0 + 0.5);
    sub_58815F(v5, "%d%%", v3);
  }
  sub_566650(v5);
  return 0;
}
