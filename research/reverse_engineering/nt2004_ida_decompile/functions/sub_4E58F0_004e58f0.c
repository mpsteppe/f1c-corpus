char __thiscall sub_4E58F0(void *this, char *Source)
{
  char v2; // bl
  _DWORD v5[7]; // [esp+Ch] [ebp-1Ch] BYREF

  v2 = 0;
  if ( Source )
  {
    sub_57A080(v5);
    if ( (unsigned __int8)sub_57A2F0(Source, 1) )
    {
      sub_4E5950(this);
      v2 = sub_4E5630((int)this, v5);
      sub_57A360(v5);
    }
    sub_57A0A0(v5);
  }
  return v2;
}
