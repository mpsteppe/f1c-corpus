char __thiscall sub_496750(int this, int a2, char a3)
{
  int v4; // eax
  char result; // al

  if ( a2 )
  {
    v4 = OperatorNewNhMallocWrapper(16);
    if ( v4 )
    {
      *(_DWORD *)v4 = a2;
      *(_DWORD *)(v4 + 4) = 0;
      *(_DWORD *)(v4 + 8) = 0;
      *(_BYTE *)(v4 + 12) = 0;
    }
    else
    {
      v4 = 0;
    }
    if ( *(_DWORD *)(this + 6332) )
    {
      *(_DWORD *)(*(_DWORD *)(this + 6336) + 4) = v4;
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(this + 6336);
    }
    else
    {
      *(_DWORD *)(this + 6332) = v4;
      *(_DWORD *)(this + 6340) = v4;
    }
    *(_DWORD *)(this + 6336) = v4;
    ++*(_DWORD *)(this + 6344);
  }
  result = a3;
  if ( a3 )
    *(_BYTE *)(this + 36) = 1;
  return result;
}
