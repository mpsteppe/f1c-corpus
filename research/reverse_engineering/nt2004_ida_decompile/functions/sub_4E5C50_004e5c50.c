char __thiscall sub_4E5C50(void *this, char *Source)
{
  char v2; // bl
  _DWORD v5[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = 0;
  if ( Source )
  {
    sub_57A080(v5);
    if ( (unsigned __int8)sub_57A110(Source, 0, 1, 1) )
    {
      v2 = sub_4E5A30((int)this, v5, aCareer);
      sub_57A360(v5);
    }
    sub_57A0A0(v5);
  }
  return v2;
}
