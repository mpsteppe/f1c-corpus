int __thiscall sub_46F6C0(int *this)
{
  int v1; // edx
  float *v2; // eax
  char Buffer[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v5; // [esp+45h] [ebp-3h]
  char v6; // [esp+47h] [ebp-1h]

  v1 = *this;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3Cu);
  v5 = 0;
  v6 = 0;
  v2 = (float *)(*(int (__thiscall **)(int *))(v1 + 172))(this);
  if ( v2 )
    sprintf(Buffer, "%d%%", (unsigned int)(__int64)(*v2 * 100.0 + 0.5));
  sub_578600(Buffer);
  return 0;
}
