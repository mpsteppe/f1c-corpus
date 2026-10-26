_WORD *__fastcall sub_62CD30(int a1, int a2)
{
  _WORD *v2; // eax
  int v3; // ecx
  _WORD *v4; // eax
  int v5; // ecx
  _WORD *result; // eax
  int v7; // ecx

  v2 = (_WORD *)(a2 + 138);
  v3 = 286;
  do
  {
    *v2 = 0;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  v4 = (_WORD *)(a2 + 2430);
  v5 = 30;
  do
  {
    *v4 = 0;
    v4 += 2;
    --v5;
  }
  while ( v5 );
  result = (_WORD *)(a2 + 2674);
  v7 = 19;
  do
  {
    *result = 0;
    result += 2;
    --v7;
  }
  while ( v7 );
  *(_DWORD *)(a2 + 5791) = 0;
  *(_DWORD *)(a2 + 5787) = 0;
  *(_DWORD *)(a2 + 5795) = 0;
  *(_DWORD *)(a2 + 5779) = 0;
  *(_WORD *)(a2 + 1162) = 1;
  return result;
}
