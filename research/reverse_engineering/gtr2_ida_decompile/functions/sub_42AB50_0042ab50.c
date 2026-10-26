char __thiscall sub_42AB50(int this)
{
  int v3; // edi
  float *v4; // ecx
  float v5[3]; // [esp+10h] [ebp-18h] BYREF

  if ( !*(_DWORD *)(this + 8) )
    return 0;
  if ( *(_BYTE *)(this + 468) == 1 )
    return 1;
  v3 = sub_42AAB0((_DWORD *)this);
  v4 = *(float **)(v3 + 56);
  if ( !v4 )
    return 1;
  sub_401290(v4, (float *)v3, v5);
  return off_16C9798(*(_DWORD *)(this + 24));
}
