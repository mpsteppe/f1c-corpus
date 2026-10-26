int __thiscall sub_40CE50(int this)
{
  _DWORD *v2; // ecx
  char *v3; // eax
  int *v4; // eax
  int v5; // ecx
  double v6; // st7
  int v8; // [esp+Ch] [ebp-24h] BYREF
  int v9; // [esp+14h] [ebp-1Ch]
  unsigned int v10; // [esp+18h] [ebp-18h]

  v2 = *(_DWORD **)(this + 84);
  if ( !v2 )
    return 1;
  v3 = *(char **)(this + 4);
  if ( !v3 )
    v3 = (char *)WindowName;
  v4 = sub_40CB90(v2, v3, *(_DWORD *)(this + 12), *(_DWORD *)(this + 16));
  *(_DWORD *)(this + 92) = v4;
  if ( !v4 )
    return 1;
  if ( AIL_WAV_info(*v4, &v8) == 1 )
  {
    v5 = v9;
    *(float *)(this + 68) = (float)v10;
    v6 = (double)v9;
    if ( v5 < 0 )
      v6 = v6 + 4294967300.0;
    *(float *)(this + 76) = v6;
  }
  return 0;
}
