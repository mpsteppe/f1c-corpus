int __thiscall sub_4B79C0(void *this)
{
  int result; // eax
  char v3; // [esp+0h] [ebp-8h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_7, 4313) )
    sub_500FE0((int)&unk_7D7920, aEnteredOnscree_1, v3);
  result = sub_4634F0(dword_764D70);
  if ( !(_BYTE)result )
  {
    sub_507310(&flt_7D79F4);
    sub_5018A0(&dword_7D7978);
    sub_45CF30((CHAR ***)&byte_764D68);
    sub_4B7E60(this);
    return sub_4B1850(-1);
  }
  return result;
}
