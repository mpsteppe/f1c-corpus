char __thiscall sub_499050(_DWORD *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int **v6; // eax

  v5 = *(_DWORD *)(this[21] + 40) - 2;
  if ( *(_DWORD *)(this[21] + 40) == 2 )
  {
    v6 = (int **)Accessor();
    LOBYTE(v5) = RenderSurfaceFillCopy(v6, a4, a2, a5 - a4, a3 - a2);
  }
  return v5;
}
