void __thiscall sub_4C81A0(_DWORD *this)
{
  int v1; // edx
  int *v2; // eax
  bool v3; // zf
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int *v7; // eax

  v1 = this[3];
  if ( v1 )
  {
    v2 = *(int **)v1;
    v3 = *(_DWORD *)v1 == 0;
    *(_DWORD *)(v1 + 8) = *(_DWORD *)v1;
    if ( !v3 )
    {
      v4 = *v2;
      if ( v4 )
      {
        while ( *(_DWORD *)(v4 + 4) != dword_8ACFCC )
        {
          v5 = this[3];
          v6 = *(_DWORD *)(v5 + 8);
          if ( v6 )
            *(_DWORD *)(v5 + 8) = *(_DWORD *)(v6 + 4);
          v7 = *(int **)(v5 + 8);
          if ( v7 )
          {
            v4 = *v7;
            if ( v4 )
              continue;
          }
          return;
        }
        if ( *(_DWORD *)(v4 + 4) )
          *(_DWORD *)(v4 + 24) = 0;
      }
    }
  }
}
