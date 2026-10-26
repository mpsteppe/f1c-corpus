// f1c  0x00539690  size=131
int __thiscall sub_539690(int this)
{
  int result; // eax
  char v2; // bl
  int v3; // edx
  int v4; // edx

  result = *(_DWORD *)(this + 5805);
  if ( result == 16 )
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
  else if ( result >= 8 )
  {
    *(_BYTE *)(*(_DWORD *)(this + 8) + *(_DWORD *)(this + 20)) = *(_BYTE *)(this + 5803);
    v4 = *(_DWORD *)(this + 20);
    *(_WORD *)(this + 5803) = *(unsigned __int8 *)(this + 5804);
    result = *(_DWORD *)(this + 5805) - 8;
    *(_DWORD *)(this + 20) = v4 + 1;
    *(_DWORD *)(this + 5805) = result;
  }
  return result;
}
