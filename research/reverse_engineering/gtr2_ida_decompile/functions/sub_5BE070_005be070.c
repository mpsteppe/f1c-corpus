int __thiscall sub_5BE070(void *this, int a2)
{
  int v2; // esi
  int v3; // edi
  int v5; // [esp+14h] [ebp-78h]
  char v6; // [esp+23h] [ebp-69h] BYREF
  _BYTE v7[12]; // [esp+24h] [ebp-68h] BYREF
  _BYTE v8[16]; // [esp+60h] [ebp-2Ch] BYREF
  _BYTE v9[16]; // [esp+70h] [ebp-1Ch] BYREF
  int v10; // [esp+88h] [ebp-4h]

  v2 = (int)this;
  if ( (*(int (__thiscall **)(void *, char *, int))(*(_DWORD *)this + 4))(this, &v6, 1) )
  {
    while ( v6 )
    {
      sub_5A88C0();
      if ( !(*(int (__thiscall **)(int, char *, int))(*(_DWORD *)v2 + 4))(v2, &v6, 1) )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v2 = sub_4050C0((int)off_906EB8);
    v10 = 0;
    v3 = sub_4050C0((int)"::");
    LOBYTE(v10) = 1;
    sub_4050C0((int)"Stream");
    LOBYTE(v10) = 2;
    sub_5BE180(v8, v3);
    LOBYTE(v10) = 3;
    v5 = *(_DWORD *)(sub_5BE180(v9, v2) + 4);
    LOBYTE(v10) = 4;
    sub_644540(
      "String cannot be read from stream, something went wrong while reading.\n"
      "Might be because we're reading past the end of the stream or something...",
      v5);
    sub_63153D(v7, &_TI1_AVException_MCore__);
  }
  return v2;
}
