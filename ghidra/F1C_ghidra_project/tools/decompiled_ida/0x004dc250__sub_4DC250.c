// Address: 0x004dc250
// Size: 54 bytes
// Name: sub_4DC250
// Type: int()
// Source: IDA Hex-Rays decompilation

int sub_4DC250()
{
  int v0; // eax

  v0 = sub_4D7FA0(0);
  if ( v0 )
  {
    *(_DWORD *)(v0 + 72) = 16776960;
    sub_49F1C0(880, 140, 16776960, v0, dword_8B8DC8);
  }
  return 0;
}
