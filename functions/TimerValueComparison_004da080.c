char __thiscall TimerValueComparison(int this)
{
  int v1; // eax
  char result; // al
  bool v3; // zf

  if ( *(float *)(this + 20) >= 0.0 )
  {
    v1 = *(_DWORD *)(this + 28);
    if ( v1 )
    {
      if ( *(_BYTE *)(this + 24) )
      {
        if ( v1 == *(_DWORD *)(dword_7C54E0 + 16592) )
          return 1;
      }
      else
      {
        v3 = v1 == *(_DWORD *)(dword_7C54E0 + 16596);
        result = 1;
        if ( v3 )
          return result;
      }
    }
  }
  return 0;
}
