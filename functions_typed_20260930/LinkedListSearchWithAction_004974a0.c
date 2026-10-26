int __thiscall sub_4974A0(int this, int a2)
{
  int *v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int *v7; // eax

  v3 = *(int **)(this + 4);
  *(_DWORD *)(this + 12) = v3;
  if ( v3 )
  {
    v4 = *v3;
    if ( *v3 )
    {
      if ( a2 )
      {
        do
        {
          if ( v4 == a2 )
          {
            SimpleSetter_fc40(1);
            v5 = FieldGetter_8e30(v4);
            SetterVirtualCall(v5);
          }
          v6 = *(_DWORD *)(this + 12);
          if ( !v6 )
            break;
          v7 = *(int **)(v6 + 4);
          *(_DWORD *)(this + 12) = v7;
          if ( !v7 )
            break;
          v4 = *v7;
        }
        while ( *v7 );
      }
    }
  }
  ShortComputation_7250((_BYTE *)this, 1);
  return 0;
}

