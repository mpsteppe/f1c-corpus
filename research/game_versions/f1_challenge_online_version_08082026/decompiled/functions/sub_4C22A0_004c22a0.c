char __thiscall sub_4C22A0(void *this, int a2)
{
  char v2; // bl
  _DWORD v5[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = 0;
  if ( a2 )
  {
    sub_5668B0(v5);
    if ( (unsigned __int8)sub_566B20(a2, 1) )
    {
      v2 = sub_4C1E80((int)this, v5);
      sub_566B90(v5);
    }
    sub_5668D0(v5);
  }
  return v2;
}
