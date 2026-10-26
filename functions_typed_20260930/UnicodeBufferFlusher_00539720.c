int __thiscall sub_539720(int this)
{
  int v1; // edx
  char v2; // bl
  int v3; // edx
  int result; // eax

  v1 = *(_DWORD *)(this + 5805);
  if ( v1 <= 8 )
  {
    result = 0;
    if ( v1 > 0 )
      *(_BYTE *)(*(_DWORD *)(this + 8) + (*(_DWORD *)(this + 20))++) = *(_BYTE *)(this + 5803);
    *(_WORD *)(this + 5803) = 0;
    *(_DWORD *)(this + 5805) = 0;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(this + 8) + *(_DWORD *)(this + 20)) = *(_BYTE *)(this + 5803);
    v2 = *(_BYTE *)(this + 5804);
    v3 = *(_DWORD *)(this + 20) + 1;
    *(_DWORD *)(this + 20) = v3;
    *(_BYTE *)(v3 + *(_DWORD *)(this + 8)) = v2;
    ++*(_DWORD *)(this + 20);
    result = 0;
    *(_WORD *)(this + 5803) = 0;
    *(_DWORD *)(this + 5805) = 0;
  }
  return result;
}

