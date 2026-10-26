char __thiscall sub_44A420(int this, int a2)
{
  char result; // al
  int v4; // ecx
  int v5; // eax
  double v7; // st7
  char Buffer[128]; // [esp+1Ch] [ebp-80h] BYREF

  result = *(_BYTE *)(this + 6092);
  if ( result )
  {
    sub_45D290(&byte_764D68);
    if ( a2 <= 0 )
    {
      if ( a2 < 0 && --*(_DWORD *)(this + 6048) < 0 )
        *(_DWORD *)(this + 6048) = 0;
    }
    else
    {
      v4 = *(_DWORD *)(this + 6048) + 1;
      *(_DWORD *)(this + 6048) = v4;
      v5 = *(_DWORD *)(this + 6044);
      if ( v4 >= v5 )
        *(_DWORD *)(this + 6048) = v5 - 1;
    }
    v7 = (double)*(int *)(this + 6048) * *(double *)(this + 6036) + *(double *)(this + 6028);
    *(double *)(this + 6020) = v7;
    if ( sub_41F230(dword_62A170, aBrakeBias, Destination) )
    {
      strncpy(Destination, aBrakeBias, 0x1FFu);
      byte_62A37B = 0;
    }
    sprintf(Buffer, "%s %4.1f:%4.1f", Destination, 100.0 - v7 * 100.0, v7 * 100.0);
    return sub_45D100(Buffer, 3, 16909060, 0);
  }
  return result;
}
