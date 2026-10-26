char __thiscall sub_44F460(unsigned __int8 *this, int a2)
{
  int v3; // eax

  if ( ConditionalFlagReturn(&dword_5EA43C) && dword_7C569C == 5 && a2 != 1 )
    LOBYTE(v3) = 0;
  else
    return (this[a2 + 892] >> 1) & 1;
  return v3;
}
