char __thiscall sub_4E4F70(int this)
{
  int v2; // eax

  LOBYTE(v2) = *(_BYTE *)(this + 30976);
  if ( (_BYTE)v2 )
  {
    v2 = sub_4E4840((CHAR ****)this);
    *(_DWORD *)(this + 30968) = v2;
    if ( v2 < 0 )
      *(_DWORD *)(this + 30964) = 3;
    *(_DWORD *)(this + 30972) = 4;
    *(_BYTE *)(this + 30976) = 0;
  }
  return v2;
}
