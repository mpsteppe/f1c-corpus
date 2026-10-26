char __thiscall sub_44A400(int this, int a2)
{
  char result; // al
  int v4; // ecx
  int v5; // eax
  double v7; // st7
  char *v8; // eax
  char Buffer[128]; // [esp+14h] [ebp-80h] BYREF

  result = *(_BYTE *)(this + 6240);
  if ( result )
  {
    sub_4731E0(&dword_B6CB98);
    if ( a2 <= 0 )
    {
      if ( a2 < 0 && --*(_DWORD *)(this + 6196) < 0 )
        *(_DWORD *)(this + 6196) = 0;
    }
    else
    {
      v4 = *(_DWORD *)(this + 6196) + 1;
      *(_DWORD *)(this + 6196) = v4;
      v5 = *(_DWORD *)(this + 6192);
      if ( v4 >= v5 )
        *(_DWORD *)(this + 6196) = v5 - 1;
    }
    v7 = (double)*(int *)(this + 6196) * *(double *)(this + 6184) + *(double *)(this + 6176);
    *(double *)(this + 6168) = v7;
    v8 = sub_41D840(&byte_91CC38, "BRAKE BIAS");
    sprintf(Buffer, "%s %4.1f:%4.1f", v8, 100.0 - v7 * 100.0, v7 * 100.0);
    return sub_4730C0(Buffer, 3, &byte_1020304, 1084227584);
  }
  return result;
}
