double __thiscall sub_42F680(_DWORD *this)
{
  float v2; // [esp+0h] [ebp-18h] BYREF
  _BYTE v3[4]; // [esp+4h] [ebp-14h] BYREF
  _BYTE v4[4]; // [esp+8h] [ebp-10h] BYREF
  _BYTE v5[4]; // [esp+Ch] [ebp-Ch] BYREF
  _BYTE v6[4]; // [esp+10h] [ebp-8h] BYREF
  _BYTE v7[4]; // [esp+14h] [ebp-4h] BYREF

  if ( !this[4] )
    return 0.0;
  sub_5DA610(&v2, v3, v4, v5, v6, v7);
  return sub_403040(&flt_91BCA0, &v2);
}
