_DWORD *__thiscall sub_5C1660(_DWORD *this, _DWORD *a2)
{
  int v4; // ebx
  int v5; // ebp
  _DWORD *v6; // eax
  _DWORD *result; // eax
  int v8; // [esp+24h] [ebp+4h]

  v4 = sub_42FC90(a2, *(_DWORD *)(this[9] + 400));
  v5 = sub_42FC90(a2, *(_DWORD *)(this[10] + 400));
  v8 = sub_42FC90(a2, *(_DWORD *)(this[11] + 400));
  v6 = operator new(0x38u);
  if ( v6 )
    result = (_DWORD *)sub_5C15B0(v6, (int)a2, v4, v5, v8);
  else
    result = 0;
  result[12] = this[12];
  result[3] = this[3];
  result[4] = this[4];
  result[5] = this[5];
  return result;
}
