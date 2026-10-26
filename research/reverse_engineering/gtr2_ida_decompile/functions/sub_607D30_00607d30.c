int __thiscall sub_607D30(float *this, int a2)
{
  int v2; // edi
  double v3; // st7
  unsigned __int64 v4; // rax
  float *v5; // edi

  v2 = 0;
  if ( *(_DWORD *)(a2 + 288) )
  {
    do
    {
      LODWORD(v4) = sub_607D30(v2 + *(_DWORD *)(a2 + 288));
      v2 += 292;
    }
    while ( v2 < 1168 );
  }
  else
  {
    v3 = *(float *)(a2 + 32);
    *(_DWORD *)(a2 + 4) = (unsigned __int64)((*(float *)(a2 + 24) - this[3]) / this[9]);
    *(_DWORD *)(a2 + 8) = 0;
    v4 = (unsigned __int64)((v3 - this[5]) / this[11]);
    v5 = &this[292 * *(_DWORD *)(a2 + 4) + 13 + 73 * v4];
    *(_DWORD *)(a2 + 12) = v4;
    qmemcpy(v5, (const void *)a2, 0x124u);
  }
  return v4;
}
