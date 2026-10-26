char __thiscall ConditionalGeometryDisplayUpdate(_DWORD *this)
{
  int v2; // eax
  int **v3; // eax
  int v5; // [esp-10h] [ebp-14h]
  int v6; // [esp-Ch] [ebp-10h]
  int v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]

  v2 = (*(int (__thiscall **)(_DWORD *))(*this + 160))(this);
  if ( !v2 )
  {
    v8 = this[61];
    v7 = this[60];
    v6 = this[59];
    v5 = this[58];
    v3 = (int **)Accessor();
    LOBYTE(v2) = RenderSurfaceFillCopy(v3, v5, v6, v7, v8);
  }
  return v2;
}

