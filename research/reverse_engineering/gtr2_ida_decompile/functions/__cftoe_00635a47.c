_BYTE *__cdecl _cftoe(_DWORD *a1, _BYTE *a2, int a3, int a4)
{
  int v5[4]; // [esp+8h] [ebp-2Ch] BYREF
  char Destination[24]; // [esp+18h] [ebp-1Ch] BYREF
  int v7; // [esp+30h] [ebp-4h]

  v7 = dword_912B08;
  sub_640B22(*a1, a1[1], (int)v5, Destination);
  _fptostr(&a2[(v5[0] == 45) + (a3 > 0)], a3 + 1, (int)v5);
  _cftoe2((int)v5, a2, a3, a4, 0);
  return a2;
}
