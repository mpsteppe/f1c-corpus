int __thiscall sub_409640(_DWORD *this)
{
  int result; // eax
  int v3; // [esp+18h] [ebp-38h]
  float v4; // [esp+20h] [ebp-30h] BYREF
  float v5; // [esp+24h] [ebp-2Ch] BYREF
  float v6; // [esp+28h] [ebp-28h] BYREF
  int v7; // [esp+2Ch] [ebp-24h] BYREF
  int v8; // [esp+30h] [ebp-20h] BYREF
  int v9; // [esp+34h] [ebp-1Ch] BYREF
  _BYTE v10[4]; // [esp+44h] [ebp-Ch] BYREF

  sub_4095D0((int)v10, v3);
  result = sub_4031C0();
  if ( result )
  {
    if ( this[4] )
      sub_5DA610(&v4, &v5, &v6, &v7, &v8, &v9);
    return off_16C92E8();
  }
  return result;
}
