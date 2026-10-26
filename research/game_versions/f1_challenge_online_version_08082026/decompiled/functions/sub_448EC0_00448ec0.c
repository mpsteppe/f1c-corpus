__int16 __thiscall sub_448EC0(int this, int a2)
{
  __int16 result; // ax

  *(_BYTE *)(this + 25) = *(_BYTE *)a2;
  result = *(_WORD *)(a2 + 2);
  *(_WORD *)(this + 26) = result;
  return result;
}
