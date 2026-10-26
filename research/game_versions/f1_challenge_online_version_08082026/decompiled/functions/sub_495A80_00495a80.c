void __thiscall sub_495A80(_DWORD *this, int a2)
{
  int v3; // eax
  int i; // ecx

  if ( a2 )
  {
    sub_495A20(this, a2);
    *(_DWORD *)(a2 + 100) = 0;
    *(_DWORD *)(a2 + 104) = 0;
    v3 = this[5];
    if ( v3 )
    {
      for ( i = *(_DWORD *)(v3 + 100); i; i = *(_DWORD *)(i + 100) )
        v3 = i;
      this[6] = a2;
      *(_DWORD *)(v3 + 100) = a2;
      *(_DWORD *)(a2 + 104) = v3;
    }
    else
    {
      this[5] = a2;
      this[6] = a2;
    }
  }
}
