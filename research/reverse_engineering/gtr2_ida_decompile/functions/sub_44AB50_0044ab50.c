int __thiscall sub_44AB50(double *this)
{
  int result; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v5; // kr00_4
  __int32 v6; // eax
  const char *v7; // [esp+0h] [ebp-5Ch] BYREF
  float v8; // [esp+4h] [ebp-58h]
  char Buffer[80]; // [esp+Ch] [ebp-50h] BYREF

  result = dword_91E084;
  if ( !*(_DWORD *)(dword_91E084 + 14820) )
  {
    Buffer[0] = 0;
    sprintf(Buffer, "                              ");
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 0, 0, (int)dword_FB2790);
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 0, 17, (int)dword_FB2790);
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 0, 34, (int)dword_FB2790);
    sprintf(Buffer, "Throttle %%");
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 0, 0, (int)dword_FB2790);
    sprintf(Buffer, "Brakes %%");
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 0, 17, (int)dword_FB2790);
    sprintf(Buffer, "Steering %%");
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 0, 34, (int)dword_FB2790);
    v8 = this[1] * 100.0;
    v8 = COERCE_FLOAT(sub_4015C0(v8));
    v7 = (const char *)LODWORD(v8);
    v5 = __readeflags();
    v6 = __ROR4__(dword_16C6F2C, 37);
    __writeeflags(v5);
    _InterlockedExchange((volatile __int32 *)&v7, v6);
    sprintf(Buffer, v7);
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 100, 0, (int)dword_FB2790);
    v8 = this[2] * 100.0;
    v3 = sub_4015C0(v8);
    sprintf(Buffer, "%d", v3);
    sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 100, 17, (int)dword_FB2790);
    v8 = this[15] * *this * 100.0;
    v4 = sub_4015C0(v8);
    sprintf(Buffer, "%d", v4);
    return sub_5F1150(dword_FB1CE0, (char)"FTFRAMERATE", (int)Buffer, 100, 34, (int)dword_FB2790);
  }
  return result;
}
