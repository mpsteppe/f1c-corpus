_WORD *__thiscall sub_537EC0(int this)
{
  _WORD *v1; // eax
  int v2; // edx
  _WORD *v3; // eax
  int v4; // edx
  _WORD *result; // eax
  int v6; // edx

  v1 = (_WORD *)(this + 138);
  v2 = 286;
  do
  {
    *v1 = 0;
    v1 += 2;
    --v2;
  }
  while ( v2 );
  v3 = (_WORD *)(this + 2430);
  v4 = 30;
  do
  {
    *v3 = 0;
    v3 += 2;
    --v4;
  }
  while ( v4 );
  result = (_WORD *)(this + 2674);
  v6 = 19;
  do
  {
    *result = 0;
    result += 2;
    --v6;
  }
  while ( v6 );
  *(_DWORD *)(this + 5791) = 0;
  *(_DWORD *)(this + 5787) = 0;
  *(_DWORD *)(this + 5795) = 0;
  *(_DWORD *)(this + 5779) = 0;
  *(_WORD *)(this + 1162) = 1;
  return result;
}

