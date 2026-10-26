int __thiscall sub_4D5EE0(double *this, double a2, double a3, double a4)
{
  int result; // eax

  if ( a4 <= 0.0 && dword_7C569C != 5 && (unsigned __int8)StringSplitLoop(1, aDDevF119992002_4, 197) )
    DebugLogWrite(&dword_8AD25C, aTireLoadFactor);
  result = LODWORD(a4);
  this[2] = a4;
  *this = (a2 + a3) * 0.5;
  this[1] = (a2 - a3) * 0.5;
  this[3] = 1.0 / a4;
  return result;
}

