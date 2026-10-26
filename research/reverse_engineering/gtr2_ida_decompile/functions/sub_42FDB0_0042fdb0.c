_DWORD *__thiscall sub_42FDB0(_DWORD *this, _DWORD *a2)
{
  int v4; // ebp
  _DWORD *v5; // esi
  _DWORD *result; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // [esp+24h] [ebp+4h]

  v4 = sub_42FC90(a2, *(_DWORD *)(this[3] + 400));
  v5 = operator new(0x18u);
  result = 0;
  if ( v5 )
  {
    v7 = this[5];
    v8 = this[4];
    v9 = v7;
    sub_5BFC50(a2);
    *v5 = &off_6F3ADC;
    v5[3] = v4;
    v5[4] = v8;
    v5[5] = v9;
    return v5;
  }
  return result;
}
