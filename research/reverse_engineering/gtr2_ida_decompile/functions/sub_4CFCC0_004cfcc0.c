int __thiscall sub_4CFCC0(_DWORD *this, int a2)
{
  int v3; // ebx
  _DWORD *v4; // edi
  char v5; // al
  int v6; // esi
  __int16 v8; // [esp+0h] [ebp-14h]
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-4h] BYREF

  v3 = this[3];
  v4 = this + 28;
  if ( a2 >= sub_4E3D00(this + 28) )
  {
    v6 = this[61];
    if ( !v6 )
      return -1;
    v5 = sub_4E3D10(v6 + 108, a2, v9, v10);
  }
  else
  {
    v5 = sub_4E3D10(v4, a2, v9, v10);
  }
  if ( v5 )
    return v3 + v8;
  return -1;
}
