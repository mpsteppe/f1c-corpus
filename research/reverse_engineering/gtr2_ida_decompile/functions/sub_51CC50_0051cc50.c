int sub_51CC50()
{
  int result; // eax
  float v1; // [esp+0h] [ebp-1Ch]
  float v2; // [esp+0h] [ebp-1Ch]
  int v3; // [esp+Ch] [ebp-10h] BYREF
  float v4; // [esp+10h] [ebp-Ch] BYREF
  int v5; // [esp+14h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+18h] [ebp-4h] BYREF

  if ( dword_BE10B4 )
  {
    sub_5E4DB0(&v3, v6);
    sub_5E4DD0(&v5, &v4);
    sub_5E5240(v3, *(float *)&v3, 0);
    v1 = v4 * 0.5;
    sub_5E54E0(v5, LODWORD(v1));
    sub_5E5240(v3, *(float *)&v3, 0);
    v2 = v4 * 0.5;
    return sub_5E54E0(v5, LODWORD(v2));
  }
  return result;
}
