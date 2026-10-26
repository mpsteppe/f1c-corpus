bool __stdcall sub_4DA470(char *Source)
{
  bool v1; // bl
  _BYTE v3[28]; // [esp+4h] [ebp-1Ch] BYREF

  sub_57A080(v3);
  if ( (unsigned __int8)sub_57A2F0(Source, 0) )
  {
    v1 = sub_4D7B90(COERCE_FLOAT(v3));
    sub_57A0A0(v3);
    return v1;
  }
  else
  {
    sub_57A0A0(v3);
    return 0;
  }
}
