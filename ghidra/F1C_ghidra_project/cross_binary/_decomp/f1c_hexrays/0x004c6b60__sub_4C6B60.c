// f1c  0x004c6b60  size=216
int __thiscall sub_4C6B60(int *this, char a2)
{
  int *v3; // edi
  char v4; // bl
  int v5; // ecx
  int v6; // ecx
  int result; // eax
  _BYTE v8[12]; // [esp+Ch] [ebp-18h] BYREF
  _BYTE v9[12]; // [esp+18h] [ebp-Ch] BYREF

  v3 = this + 4109;
  sub_4BB8E0(this + 4109);
  v4 = sub_4D1180(this, v9, v8);
  if ( a2 || !sub_4BC9B0(v3, 0, 0) )
  {
    sub_4EF7C0(v9, v8);
    sub_4E9600(this + 3);
    LOBYTE(v5) = v4 == 0;
    sub_4F1C00(v5);
    v6 = (int)(this + 3251);
    if ( v4 )
    {
      sub_4A5E80(v6);
    }
    else
    {
      sub_4A5E60(v6);
      if ( this[4645] == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
        sub_40D100(&dword_5EA510);
    }
  }
  result = sub_424B20((int)this);
  if ( dword_7C56A4 == 7 )
  {
    result = dword_7C56A8;
    if ( dword_7C56A8 == 3 || dword_7C56A8 == 4 )
      return sub_4EFA40(1);
  }
  return result;
}
