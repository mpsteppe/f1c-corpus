// f1c  0x00455f00  size=132
int __thiscall sub_455F00(HCURSOR *this)
{
  int result; // eax

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_13, 5321) )
    sub_4D7AA0(&unk_8AD25C, aEnteredHwinput_4);
  sub_44FBE0(this + 1121);
  sub_44FBE0(this + 866);
  sub_44F5F0(this + 815);
  sub_44EFE0(this + 1);
  result = (int)*this;
  if ( *this )
  {
    result = (*(int (__stdcall **)(HCURSOR))(*(_DWORD *)result + 8))(*this);
    *this = 0;
  }
  if ( byte_7D13A0 == 1 )
  {
    result = sub_4F8C90();
    this[1732] = (HCURSOR)-1;
  }
  return result;
}
