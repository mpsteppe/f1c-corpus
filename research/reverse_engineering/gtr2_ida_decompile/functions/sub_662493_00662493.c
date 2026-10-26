void __thiscall sub_662493(_DWORD *this, int a2)
{
  int v2; // eax

  if ( a2 )
  {
    this[34] = *(_DWORD *)(a2 - 8);
    v2 = *(_DWORD *)(a2 - 8 + 4);
    if ( v2 <= 0 )
    {
      this[35] = -v2;
      j__free((void *)(a2 - 8));
    }
    else
    {
      this[35] = v2;
    }
  }
}
