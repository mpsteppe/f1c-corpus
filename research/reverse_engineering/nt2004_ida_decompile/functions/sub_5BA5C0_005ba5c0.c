__int16 __fastcall sub_5BA5C0(int a1, int a2, __int16 a3)
{
  __int16 result; // ax

  result = a3;
  *(_DWORD *)(a1 + 8) = a2;
  *(_WORD *)(a1 + 12) = a3;
  return result;
}
