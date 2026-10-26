int __thiscall sub_491AB0(int this)
{
  double v2; // st7
  int result; // eax
  char Buffer[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v5; // [esp+45h] [ebp-3h]
  char v6; // [esp+47h] [ebp-1h]

  v2 = *(float *)(this + 304) * 100.0;
  memset(Buffer, 0, sizeof(Buffer));
  v5 = 0;
  v6 = 0;
  sprintf(Buffer, "%d%%", (unsigned int)(unsigned __int64)(v2 + 0.5));
  sub_615860(Buffer);
  result = 0;
  **(float **)(this + 312) = *(float *)(this + 308) * *(float *)(this + 304);
  return result;
}
