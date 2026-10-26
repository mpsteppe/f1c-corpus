int __thiscall sub_51FBF0(int *this)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  _DWORD **v6; // edi
  int j; // esi
  int v8; // eax
  int v9; // esi
  int k; // edx
  int v11; // edx
  int m; // esi
  int v13; // eax
  char v15[4]; // [esp+4h] [ebp-54h] BYREF
  char Buffer[60]; // [esp+8h] [ebp-50h] BYREF
  int i; // [esp+54h] [ebp-4h]

  *(_DWORD *)Buffer = operator new(0x1Cu);
  i = 0;
  if ( *(_DWORD *)Buffer )
    v2 = sub_51FAD0();
  else
    v2 = 0;
  *this = v2;
  v3 = 0;
  for ( i = -1; v3 < dword_91BDD8; ++v3 )
  {
    v4 = sub_401190();
    if ( v4 )
      sub_591DE0(v4);
  }
  v5 = *this;
  v6 = (_DWORD **)(*this + 20);
  sub_5F61A0((int)v6, (char)"ReflectionRenderToTextureTrack");
  sub_5F61A0(v5 + 24, (char)"ReflectionRenderToTextureCars");
  sub_51D6C0(*(_DWORD ***)(v5 + 16), *v6, *(_DWORD **)(v5 + 24));
  for ( j = 0; j < 99; ++j )
  {
    sprintf(Buffer, "RREFLECT%2.2d", j);
    v8 = sub_5DA9A0(Buffer, 0);
    if ( v8 )
    {
      *(_DWORD *)(v8 + 4) |= (unsigned int)&byte_800000;
      sub_51FA00();
    }
  }
  v9 = dword_757C10;
  for ( k = 0; k < v9; k = v11 + 1 )
    sub_51E910(*(_DWORD *)(*(&dword_91E088 + k) + 2712));
  for ( m = 0; m < 64; ++m )
  {
    sprintf(v15, "TUNNEL%2.2d", m);
    v13 = sub_5DA9A0(v15, 0);
    if ( v13 )
      sub_51E910(v13);
  }
  return sub_5E5B30(&dword_1000000, 1);
}
