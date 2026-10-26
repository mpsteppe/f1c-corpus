int __thiscall sub_48C550(float *this)
{
  float *v2; // eax
  float v4; // [esp+4h] [ebp-48h]
  char Buffer[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v6; // [esp+49h] [ebp-3h]
  char v7; // [esp+4Bh] [ebp-1h]

  v2 = (float *)(*(int (__thiscall **)(float *))(*(_DWORD *)this + 172))(this);
  if ( v2 )
  {
    v4 = (*v2 - this[72]) * 100.0 / (this[73] - this[72]);
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0x3Cu);
    v6 = 0;
    v7 = 0;
    sprintf(Buffer, "%d%%", (int)v4);
    sub_578600(Buffer);
  }
  return 0;
}
