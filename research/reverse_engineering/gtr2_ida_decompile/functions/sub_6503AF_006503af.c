int __thiscall sub_6503AF(int this, int a2)
{
  unsigned int v3; // edi
  float *v4; // eax
  int v5; // esi
  int v6; // ebx
  float *v7; // ecx
  int result; // eax

  v3 = 0;
  if ( *(_DWORD *)(this + 104) )
  {
    v4 = (float *)(a2 + 8);
    v5 = -8 - a2;
    do
    {
      v6 = *(_DWORD *)(this + 92);
      v7 = (float *)((char *)v4 + v5 + v6 + 16);
      ++v3;
      *(v4 - 2) = *v7 + *(v4 - 2);
      *(v4 - 1) = *(float *)((char *)v4 + v5 + v6 + 20) + *(v4 - 1);
      *v4 = *(float *)((char *)v4 + v5 + v6 + 24) + *v4;
      v4 += 4;
      *(v4 - 3) = v7[3] + *(v4 - 3);
    }
    while ( v3 < *(_DWORD *)(this + 104) );
  }
  result = 0;
  memset(*(void **)(this + 92), 0, 16 * (*(_DWORD *)(this + 104) + 2));
  return result;
}
