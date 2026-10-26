int __thiscall sub_44C4C0(double *this, int a2)
{
  int v4; // ecx
  double v5; // st7
  double **v6; // eax
  unsigned int v8; // [esp+8h] [ebp-10h]
  unsigned int v9; // [esp+1Ch] [ebp+4h]

  v4 = *(_DWORD *)(a2 + 48);
  if ( !v4 || *(_BYTE *)(v4 + 88) || !QuadraticSurfaceCollisionTest((double *)v4, a2) )
  {
    v5 = *(double *)a2;
    *(_DWORD *)(a2 + 48) = 0;
    v9 = (int)((v5 - this[1]) * this[2]);
    v8 = (int)((*(double *)(a2 + 16) - this[3]) * this[4]);
    if ( v9 < 0x20 && v8 < 0x20 )
    {
      v6 = (double **)*((_DWORD *)&this[16 * v9 + 5] + v8);
      if ( v6 )
        BVHTreeTraversal(v6, (double *)a2);
    }
  }
  return *(_DWORD *)(a2 + 48);
}
