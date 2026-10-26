int __thiscall sub_4A3220(_DWORD *this, int a2, int a3, int a4)
{
  char *v5; // esi
  unsigned int v6; // kr04_4
  char *i; // eax
  char *v8; // eax
  int v9; // esi
  char *v10; // eax
  int v12; // [esp+Ch] [ebp-Ch] BYREF
  char *v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  ArrayResourceCleanup(this);
  v13 = 0;
  v14 = -1;
  StringCopyWithBufferRealloc(a2);
  v5 = 0;
  v6 = strlen(byte_5EA438) + 1;
  if ( (int)(v6 - 1) > 0 )
  {
    for ( i = &byte_5EA438[v6 - 2]; i > byte_5EA438; --i )
    {
      if ( *i == 92 )
        break;
    }
    *i = 0;
    v5 = v13;
  }
  v8 = v5;
  if ( !v5 )
    v8 = byte_5EA438;
  StringRegistry(v8);
  v12 = 0;
  sub_53CBC0(&v12, aPitanimsMas);
  v9 = PitCrewAnimationLoader(this, a2, a3, a4);
  if ( v12 )
    PhysicsObjectLinkedListRemoval(v12);
  v10 = v13;
  if ( !v13 )
    v10 = byte_5EA438;
  StringMatchWithFlagSet(v10);
  if ( v13 )
    FreeWrapper_7bcf(v13);
  return v9;
}

