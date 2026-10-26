void __thiscall sub_4AC2D0(_DWORD *this, int a2)
{
  int v3; // eax
  int i; // ecx

  if ( a2 )
  {
    sub_4AC270(this, a2);
    *(_DWORD *)(a2 + 88) = 0;
    *(_DWORD *)(a2 + 92) = 0;
    v3 = this[5];
    if ( v3 )
    {
      for ( i = *(_DWORD *)(v3 + 88); i; i = *(_DWORD *)(i + 88) )
        v3 = i;
      this[6] = a2;
      *(_DWORD *)(v3 + 88) = a2;
      *(_DWORD *)(a2 + 92) = v3;
    }
    else
    {
      this[5] = a2;
      this[6] = a2;
    }
  }
}
