void __thiscall sub_470400(_DWORD *this)
{
  char v1[61]; // [esp+4h] [ebp-C0h] BYREF
  __int16 v2; // [esp+41h] [ebp-83h]
  char v3; // [esp+43h] [ebp-81h]
  char v4[128]; // [esp+44h] [ebp-80h] BYREF

  if ( this[193] == 435 && SessionStateCheckWrapper(dword_7CD25C) )
  {
    v1[0] = byte_5EA438[0];
    memset(&v1[1], 0, 0x3Cu);
    v2 = 0;
    v3 = 0;
    sub_4B0B20(v1, 64);
    StringFormatWrapper(v1, (int)v4, 128);
    BoundedFieldSetter(159 - strlen(v4));
  }
}

