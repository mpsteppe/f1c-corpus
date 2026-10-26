// Address: 0x0047c860
// Size: 156 bytes
// Name: sub_47C860
// Type: int __thiscall(int *this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_47C860(int *this)
{
  int v2; // edx
  float *v3; // eax
  float *v4; // edi
  int v5; // eax
  _BYTE v7[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v8; // [esp+45h] [ebp-3h]
  char v9; // [esp+47h] [ebp-1h]

  v2 = *this;
  v7[0] = byte_5EA438;
  memset(&v7[1], 0, 0x3Cu);
  v8 = 0;
  v9 = 0;
  v3 = (float *)(*(int (__thiscall **)(int *))(v2 + 180))(this);
  v4 = v3;
  if ( v3 )
  {
    v5 = sub_587BDC(*v3 * 100.0 + 0.5);
    sub_58815F(v7, "%d%%", v5);
    if ( this[63] == 230 )
    {
      sub_418970(*v4);
    }
    else if ( this[63] == 232 )
    {
      sub_4C8900(*(_DWORD *)v4);
    }
  }
  sub_566650(v7);
  return 0;
}
