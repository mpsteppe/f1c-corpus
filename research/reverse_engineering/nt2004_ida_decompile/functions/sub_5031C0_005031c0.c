int __thiscall sub_5031C0(int this)
{
  double v3; // st7
  int v4; // edi
  int v5; // ebx
  char Buffer[128]; // [esp+18h] [ebp-80h] BYREF

  if ( *(_DWORD *)(this + 68) != *(_DWORD *)(dword_75AAC4 + 25248) )
    return 1;
  if ( *(float *)(dword_75AAC4 + 17448) > 0.0 && *(float *)(this + 56) < 0.0 )
    return 1;
  if ( *(_DWORD *)(dword_75AAC4 + 16584) )
    return 1;
  sub_506960(dword_7E8CDC);
  if ( *(_DWORD *)(dword_75AAC4 + 17416) == 3 )
  {
    v3 = dbl_7DA9D0 - *(float *)(dword_75AAC4 + 17440);
  }
  else
  {
    v3 = *(float *)(dword_75AAC4 + 17444) - *(float *)(dword_75AAC4 + 17440);
    *(float *)(this + 56) = *(float *)(this + 56) - dbl_7DA9C8;
  }
  v4 = *(_DWORD *)(this + 60) + 250;
  v5 = *(_DWORD *)(this + 64) + 45;
  sprintf(Buffer, "PIT STOP %.1f", v3);
  sub_501610((int)Buffer, v4, v5, 0xFFFFFF, 0, 1, 1.0, 1.0);
  return 0;
}
