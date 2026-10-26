int __thiscall sub_46F750(float *this)
{
  float v2; // edx
  int *v3; // eax
  double v4; // st7
  char Buffer[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v7; // [esp+45h] [ebp-3h]
  char v8; // [esp+47h] [ebp-1h]

  v2 = *this;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x3Cu);
  v7 = 0;
  v8 = 0;
  v3 = (int *)(*(int (__thiscall **)(float *))(LODWORD(v2) + 172))(this);
  if ( *((_BYTE *)this + 284) )
    v4 = (double)*v3 / (this[73] - this[72]);
  else
    v4 = *(float *)v3 / (this[73] - this[72]);
  sprintf(Buffer, "%d%%", (unsigned int)(__int64)(v4 * 100.0));
  sub_578600(Buffer);
  return 0;
}
