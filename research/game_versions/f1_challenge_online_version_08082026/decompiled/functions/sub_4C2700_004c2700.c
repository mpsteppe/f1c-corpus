char __thiscall sub_4C2700(_DWORD *this, int a2)
{
  char v2; // bl
  _DWORD v5[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = 0;
  if ( a2 )
  {
    sub_5668B0(v5);
    if ( (unsigned __int8)sub_566940(a2, 0, 1, 1) )
    {
      v2 = sub_4C2420(this, v5, (int)aCareer);
      sub_566B90(v5);
    }
    sub_5668D0(v5);
  }
  return v2;
}
