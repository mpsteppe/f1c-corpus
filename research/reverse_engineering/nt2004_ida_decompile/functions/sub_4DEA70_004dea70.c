int __thiscall sub_4DEA70(int this, char a2)
{
  int result; // eax

  result = 0;
  if ( a2 )
  {
    if ( *(_DWORD *)(this + 8) != 10 )
    {
      *(_DWORD *)(this + 8) = 10;
      *(_DWORD *)(this + 328) = -99;
      *(_BYTE *)(this + 284) = 0;
      *(_BYTE *)(this + 285) = 1;
      *(_DWORD *)(this + 288) = 0;
      *(_DWORD *)(this + 292) = 0;
      *(_DWORD *)(this + 296) = 0;
      *(_DWORD *)(this + 300) = 0;
      *(_DWORD *)(this + 304) = -8388609;
      *(_DWORD *)(this + 308) = 0x7FFFFFFF;
      *(_DWORD *)(this + 312) = -8388609;
      return sub_421590(*(_DWORD *)this, 16, 0);
    }
  }
  else if ( *(_DWORD *)(this + 8) != dword_75CBB4 )
  {
    *(_DWORD *)(this + 8) = 5;
    return sub_421590(*(_DWORD *)this, 16, 0);
  }
  return result;
}
