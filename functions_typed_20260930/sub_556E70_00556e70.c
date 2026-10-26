void __thiscall sub_556E70(int this, _DWORD *a2)
{
  int v2; // ebx
  void (__thiscall *v4)(_DWORD); // eax
  int i; // esi
  int v6; // eax
  int v7; // ebp
  int ii; // esi
  int v9; // eax
  int v10; // ebp
  int j; // esi
  int k; // ebp
  int v13; // esi
  int m; // esi
  int v15; // ebp
  int n; // esi
  int jj; // esi

  v2 = (int)a2;
  if ( (*(_BYTE *)(this + 128) & 8) == 0 )
    goto LABEL_52;
  sub_5572B0(a2);
  v4 = *(void (__thiscall **)(_DWORD))(this + 420);
  if ( v4 )
    v4(*(_DWORD *)(this + 424));
  TransformWheelForcesToChassis((float *)this);
  CameraProjectionUpdate(this, 14);
  for ( i = a2[66]; i; i = *(_DWORD *)(i + 76) )
  {
    if ( (*(_BYTE *)(i + 60) & 2) == 0 )
      RecursiveStateTraversalWithFlagCheck((_DWORD *)i, this);
  }
  v6 = a2[59] & 0x3000;
  if ( v6 == 4096 )
  {
    v9 = SpatialTreeNearestNeighborQuery(a2, (float *)this);
    v10 = v9;
    if ( v9 )
    {
      for ( j = *(_DWORD *)(v9 + 236); j; j = *(_DWORD *)(j + 76) )
      {
        if ( (*(_BYTE *)(j + 60) & 2) == 0 )
          RecursiveStateTraversalWithFlagCheck((_DWORD *)j, this);
      }
      for ( k = *(_DWORD *)(v10 + 248); k; k = *(_DWORD *)(k + 20) )
      {
        v13 = *(_DWORD *)(k + 16);
        SphereVsFrustumVisibilityTest(v13, (float *)this);
        if ( (*(_BYTE *)(v13 + 4) & 4) != 0 )
          TestFrustumPlanes((float *)v13, this);
        if ( (*(_BYTE *)(v13 + 4) & 5) != 0 )
        {
          for ( m = *(_DWORD *)(v13 + 236); m; m = *(_DWORD *)(m + 76) )
          {
            if ( (*(_BYTE *)(m + 60) & 2) == 0 )
              RecursiveStateTraversalWithFlagCheck((_DWORD *)m, this);
          }
        }
      }
      goto LABEL_49;
    }
    v15 = a2[64];
    a2[105] = 0;
    if ( v15 )
    {
      do
      {
        if ( (*(_BYTE *)(v15 + 4) & 0x40) == 0 )
        {
          SphereVsFrustumVisibilityTest(v15, (float *)this);
          if ( (*(_BYTE *)(v15 + 4) & 4) != 0 )
            TestFrustumPlanes((float *)v15, this);
          if ( (*(_BYTE *)(v15 + 4) & 5) != 0 || (*(_DWORD *)(this + 128) & 0x800) != 0 )
          {
            for ( n = *(_DWORD *)(v15 + 236); n; n = *(_DWORD *)(n + 76) )
            {
              if ( (*(_BYTE *)(n + 60) & 2) == 0 )
                RecursiveStateTraversalWithFlagCheck((_DWORD *)n, this);
            }
          }
        }
        v15 = *(_DWORD *)(v15 + 260);
      }
      while ( v15 );
      goto LABEL_48;
    }
  }
  else if ( v6 == 0x2000 )
  {
    v7 = a2[64];
    if ( v7 )
    {
      do
      {
        if ( (*(_BYTE *)(v7 + 4) & 0x40) == 0 )
        {
          SphereVsFrustumVisibilityTest(v7, (float *)this);
          if ( (*(_BYTE *)(v7 + 4) & 4) != 0 )
            TestFrustumPlanes((float *)v7, this);
          if ( (*(_BYTE *)(v7 + 4) & 5) != 0 || (*(_DWORD *)(this + 128) & 0x800) != 0 )
          {
            for ( ii = *(_DWORD *)(v7 + 236); ii; ii = *(_DWORD *)(ii + 76) )
            {
              if ( (*(_BYTE *)(ii + 60) & 2) == 0 )
                RecursiveStateTraversalWithFlagCheck((_DWORD *)ii, this);
            }
          }
        }
        v7 = *(_DWORD *)(v7 + 260);
      }
      while ( v7 );
LABEL_48:
      v2 = (int)a2;
    }
  }
LABEL_49:
  sub_5550E0(dword_8B78A0, v2, (_DWORD *)this);
  if ( (*(_BYTE *)(this + 128) & 0x20) != 0 )
  {
    for ( jj = *(_DWORD *)(v2 + 328); jj; jj = *(_DWORD *)(jj + 104) )
      sub_558E70(v2, this);
  }
LABEL_52:
  if ( *(_DWORD *)(this + 432) )
  {
    sub_556E70(v2);
    CameraProjectionUpdate(this, 14);
  }
}

