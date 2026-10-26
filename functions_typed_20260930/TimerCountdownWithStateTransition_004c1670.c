char __thiscall sub_4C1670(int this)
{
  int v2; // eax

  LOBYTE(v2) = *(_BYTE *)(this + 45392);
  if ( (_BYTE)v2 )
  {
    ++*(_DWORD *)(this + 45384);
    v2 = SceneOrderReader();
    if ( *(_DWORD *)(this + 45384) >= v2 )
      *(_DWORD *)(this + 45380) = 3;
    *(_DWORD *)(this + 45388) = 1;
    *(_BYTE *)(this + 45392) = 0;
  }
  return v2;
}

