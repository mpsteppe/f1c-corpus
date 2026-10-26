__int16 __thiscall sub_4916E0(_WORD *this, __int16 a2, __int16 a3, __int16 a4, __int16 a5)
{
  __int16 result; // ax

  *this = a2;
  result = a4;
  this[1] = a3;
  this[2] = a4;
  this[3] = a5;
  return result;
}

