_DWORD *__thiscall sub_5B8910(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // eax
  _DWORD *result; // eax
  int v6; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+4h] [ebp-8h] BYREF
  int v8; // [esp+8h] [ebp-4h] BYREF

  v4 = this[7];
  if ( *(_DWORD *)(v4 + 316) )
    sub_59E5E0(*(_DWORD **)(v4 + 312), &v6, &v7, &v8);
  else
    sub_59E0C0(*(_DWORD **)(v4 + 312), &v6, &v7, &v8);
  if ( a2 )
    *a2 = v6;
  if ( a3 )
    *a3 = v7;
  result = a4;
  if ( a4 )
    *a4 = v8;
  return result;
}
