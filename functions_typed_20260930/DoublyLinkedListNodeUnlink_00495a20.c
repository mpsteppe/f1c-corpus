void __thiscall sub_495A20(_DWORD *this, int a2)
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
        v2 = *(_DWORD *)(v2 + 100);
        if ( !v2 )
          return;
      }
      v3 = *(_DWORD *)(a2 + 104);
      if ( v3 )
      {
        *(_DWORD *)(v3 + 100) = *(_DWORD *)(a2 + 100);
      }
      else if ( this[5] == a2 )
      {
        this[5] = *(_DWORD *)(a2 + 100);
      }
      v4 = *(_DWORD *)(a2 + 100);
      if ( v4 )
      {
        *(_DWORD *)(v4 + 104) = *(_DWORD *)(a2 + 104);
      }
      else if ( this[6] == a2 )
      {
        this[6] = *(_DWORD *)(a2 + 104);
      }
    }
  }
}

