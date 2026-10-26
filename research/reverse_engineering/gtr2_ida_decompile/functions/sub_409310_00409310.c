double __thiscall sub_409310(_DWORD *this)
{
  _BYTE v2[4]; // [esp+0h] [ebp-18h] BYREF
  float v3; // [esp+4h] [ebp-14h] BYREF
  _BYTE v4[4]; // [esp+8h] [ebp-10h] BYREF
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v6[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  if ( !this[4] )
    return 0.0;
  sub_5DA610(v5, v6, v7, v2, &v3, v4);
  return v3;
}
