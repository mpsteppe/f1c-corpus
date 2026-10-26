int __thiscall sub_5ECB00(int this, int a2)
{
  int v3; // eax
  int v4; // esi
  int v5; // ebp
  int v7; // [esp+Ch] [ebp-4h]

  v3 = *(_DWORD *)(this + 452);
  v4 = *(_DWORD *)(v3 + 12);
  v5 = 0;
  v7 = 0;
  if ( *(int *)(v3 + 8) <= 0 )
    return 0;
  do
  {
    if ( *(_DWORD *)v4 == 32 )
    {
      ++v7;
    }
    else
    {
      sub_5D7810((float *)(v4 + 4), (float *)(v4 + 16), (float *)(this + 184));
      sub_5D7810((float *)(v4 + 28), (float *)(v4 + 40), (float *)(this + 184));
    }
    v4 += 116;
    ++v5;
  }
  while ( v5 < *(_DWORD *)(*(_DWORD *)(this + 452) + 8) );
  return v7;
}
