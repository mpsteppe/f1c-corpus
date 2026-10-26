int __thiscall sub_4859D0(int this, char a2)
{
  int v3; // esi
  LPVOID *v4; // edi
  bool v5; // zf

  v3 = *(_DWORD *)(this + 356);
  while ( v3 )
  {
    v4 = (LPVOID *)v3;
    v5 = *(_BYTE *)(v3 + 8) == 0;
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v5 )
      FreeWrapper_7bcf(*v4);
    FreeWrapper_7bcf(v4);
  }
  *(_DWORD *)(this + 356) = 0;
  *(_DWORD *)(this + 360) = 0;
  *(_DWORD *)(this + 364) = 0;
  *(_DWORD *)(this + 368) = 0;
  if ( *(_DWORD *)(this + 348) )
    FreeWrapper_7bcf(*(LPVOID *)(this + 348));
  ConditionalDualCleanup(this + 284);
  ConditionalDualCleanup(this + 224);
  sub_485EB0(this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
