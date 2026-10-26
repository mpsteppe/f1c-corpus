int __thiscall sub_4944A0(int this, int a2, char a3, char a4, int a5)
{
  int result; // eax
  const char *v7; // eax
  const char *v8; // eax
  int v9; // edi
  _BYTE v10[256]; // [esp+8h] [ebp-100h] BYREF

  if ( !a2 )
    return -1;
  strcpy((char *)(this + 12), (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)a2 + 12))(a2));
  *(_BYTE *)(this + 408) = a3;
  *(_DWORD *)(this + 420) = a2;
  *(_BYTE *)(this + 409) = a4;
  *(_BYTE *)(this + 410) = 0;
  result = sub_491EE0((_DWORD *)this);
  if ( result != -1 )
  {
    sub_4920B0((_DWORD *)this);
    if ( byte_5CC2CC )
    {
      v7 = (const char *)dword_5EC418;
      if ( !dword_5EC418 )
        v7 = byte_5EA438;
      sub_58815F(v10, "%s%s", v7, aEasBik);
      sub_4F9B70(v10, 0);
      sub_4F9D60((int)aLegalBmp, 3.0, 0);
      v8 = (const char *)dword_5EC418;
      if ( !dword_5EC418 )
        v8 = byte_5EA438;
      sub_58815F(v10, "%s%s", v8, aEaintroBik);
      sub_4F9B70(v10, 1);
    }
    sub_496380(a2);
    v9 = sub_492160(this);
    sub_491F60((int *)this);
    if ( byte_5CC2CC )
    {
      byte_5CC2CC = 0;
      sub_41B970();
    }
    return v9;
  }
  return result;
}
