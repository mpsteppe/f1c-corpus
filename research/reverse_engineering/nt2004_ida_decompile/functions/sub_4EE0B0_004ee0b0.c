_DWORD *__thiscall sub_4EE0B0(char *this, char a2)
{
  char Destination[64]; // [esp+4h] [ebp-40h] BYREF

  sub_509B10(a2);
  if ( (unsigned __int8)sub_4EED40(this) && !*((_DWORD *)this + 4146) )
    sub_4B4210(&dword_765E90);
  sub_525C50(this + 92);
  sub_4C00C0((int)(this + 16588));
  sub_4DC0B0((_DWORD *)this + 5209);
  sub_41F400(flt_62BC28);
  *((_DWORD *)this + 6316) = -1;
  *((_DWORD *)this + 6317) = -1;
  if ( !*((_DWORD *)this + 4146) )
  {
    sub_4CE010(byte_7663E0, Destination, 63);
    sub_4EDDD0(this, Destination);
  }
  nullsub_6(this);
  return sub_417C10(dword_6291D0, (int)(this + 84));
}
