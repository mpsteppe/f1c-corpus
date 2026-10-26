_DWORD *__thiscall sub_53E290(int this, int a2)
{
  _DWORD *v3; // esi
  _DWORD *result; // eax
  int v5; // ebx
  int v6; // ebp
  int v7; // [esp+8h] [ebp-14h]

  v3 = operator new(0x24u);
  result = 0;
  if ( v3 )
  {
    v5 = *(_DWORD *)(this + 24);
    v6 = *(_DWORD *)(this + 32);
    v7 = *(_DWORD *)(this + 28);
    sub_5BFC50(a2);
    v3[8] = v6;
    v3[6] = v5;
    *v3 = &off_71E2B4;
    v3[7] = v7;
    result = v3;
  }
  result[1] = *(_DWORD *)(this + 4);
  *((_BYTE *)result + 8) = *(_BYTE *)(this + 8);
  result[3] = *(_DWORD *)(this + 12);
  result[4] = *(_DWORD *)(this + 16);
  result[5] = *(_DWORD *)(this + 20);
  result[6] = *(_DWORD *)(this + 24);
  result[7] = *(_DWORD *)(this + 28);
  result[8] = *(_DWORD *)(this + 32);
  return result;
}
