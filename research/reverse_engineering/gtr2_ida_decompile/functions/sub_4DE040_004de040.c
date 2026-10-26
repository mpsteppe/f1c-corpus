void __thiscall sub_4DE040(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( a2 )
  {
    v2 = this[5];
    if ( v2 )
    {
      while ( v2 != a2 )
      {
        v2 = *(_DWORD *)(v2 + 88);
        if ( !v2 )
          return;
      }
      v3 = *(_DWORD *)(a2 + 92);
      if ( v3 )
      {
        *(_DWORD *)(v3 + 88) = *(_DWORD *)(a2 + 88);
      }
      else if ( this[5] == a2 )
      {
        this[5] = *(_DWORD *)(a2 + 88);
      }
      v4 = *(_DWORD *)(a2 + 88);
      if ( v4 )
      {
        *(_DWORD *)(v4 + 92) = *(_DWORD *)(a2 + 92);
      }
      else if ( this[6] == a2 )
      {
        this[6] = *(_DWORD *)(a2 + 92);
      }
    }
  }
}
